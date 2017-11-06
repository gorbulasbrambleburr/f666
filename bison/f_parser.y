%skeleton "lalr1.cc"
%require "3.0"       // Bison version
%defines

%define api.token.constructor
%define api.token.prefix {TOKEN_}
%define api.value.type variant
%define api.namespace { Fortran }
%define parser_class_name { Parser }
%define parse.trace
%define parse.error verbose
%define parse.assert  // Correct cleanup of semantic value objects

// Code to be placed in the parser header file
%code requires {
    #include <iostream>
    #include <string>
    #include <vector>
    #include <stdint.h>
    #include "Types.hpp"
    #include "Operators.hpp"
    #include "ast/AST.hpp"

    namespace Fortran {
        class Driver;
        class Scanner;
    }
    class Mapper;
}

// Code to be placed in the beggining of the parser implementation file
%code top {
    #include <iostream>
    #include "f_scanner.hpp"
    #include "f_parser.hpp"
    #include "f_driver.hpp"
    #include "location.hh"
    #include "../include/Mapper.hpp"

    // This function is called only inside Bison, so we make it static to limit
    // symbol visibility for the linker to avoid potential linking conflicts.
    static Fortran::Parser::symbol_type yylex(Fortran::Scanner &scanner) {
        return scanner.getNextToken();
    }
}

// Parameters to flex and bison
%lex-param { Fortran::Scanner &scanner }
%parse-param { Fortran::Scanner &scanner }
%parse-param { Fortran::Driver &driver }

%locations

// Keywords
%token PROGRAM     "PROGRAM keyword";
%token SUBROUTINE  "SUBROUTINE keyword";
%token FUNCTION    "FUNCTION keyword";
%token STOP        "STOP keyword";
%token RETURN      "RETURN keyword";
%token END         "END keyword";
%token PARAMETER   "PARAMETER keyword";
%token CYCLE       "CYCLE keyword";
%token EXIT        "EXIT keyword";
%token IF          "IF keyword";
%token THEN        "THEN keyword";
%token ELSE        "ELSE keyword";
%token ELSEIF      "ELSEIF keyword";
%token ENDIF       "ENDIF keyword";
%token WHILE       "WHILE keyword";
%token DO          "DO keyword";
%token ENDDO       "ENDDO keyword";
%token PRINT       "PRINT keyword";
%token READ        "READ keyword";
%token CALL        "CALL keyword";
%token ERR         "ERR keyword";

// Other
%token NEWLINE "new line";
%token EOF 0   "end of file" ;
%token COMMA   "comma";
%token LP      "left parenthesis";
%token RP      "right parenthesis";
%token ASSIGN  "=";

// Arithmetic operators
%token<Fortran::op::arithmetic> PLUS   "+";
%token<Fortran::op::arithmetic> MINUS  "-";
%token<Fortran::op::arithmetic> TIMES  "*";
%token<Fortran::op::arithmetic> DIVIDE "/";

// Logical operators
%token<Fortran::op::logic> AND "&&";
%token<Fortran::op::logic> OR  "||";
%token<Fortran::op::logic> NOT "!";

// Token semantic types
%token<Fortran::type> TYPE           "TYPE identifier";
%token<Fortran::integer> INTEGER     "INTEGER value";
%token<Fortran::real> REAL           "REAL value";
%token<Fortran::boolean> BOOLEAN     "BOOLEAN value";
%token<Fortran::string> STRING       "STRING value";
%token<Fortran::string> ID           "ID identifier";
%token<Fortran::op::comp> COMPARISON "COMPARISON operator";

// AST node types
%type<AST::node_ptr> ExecutableProgram
%type<AST::node_ptr> Subprogram
%type<AST::node_ptr> MainProgram
%type<AST::node_ptr> Subroutine
%type<AST::node_ptr> Function
%type<AST::node_ptr> Identifier
%type<AST::node_ptr> ProgramIdentifier
%type<AST::node_ptr> SubroutineIdentifier
%type<AST::node_ptr> FunctionIdentifier
%type<AST::node_ptrs> ArgumentList
%type<AST::node_ptr> Argument
%type<AST::node_ptrs> ParameterList
%type<AST::node_ptr> Parameter
%type<AST::node_ptr> Type
%type<AST::node_ptr> Body
%type<AST::node_ptr> SpecificationConstruct
%type<AST::node_ptr> ExecutableConstruct
%type<AST::node_ptrs> SpecificationList
%type<AST::node_ptr> Specification
%type<AST::node_ptr> DeclarationStatement
%type<AST::node_ptr> ParameterStatement
%type<AST::node_ptr> IdentifierDeclaration
%type<AST::node_ptrs> IdentifierDeclarationList
%type<AST::node_ptrs> AssignmentStatementList
%type<AST::node_ptr> AssignmentStatement
%type<AST::node_ptr> Expression
%type<AST::node_ptr> Literal
%type<AST::node_ptrs> ExecutableList
%type<AST::node_ptr> Statement
%type<AST::node_ptrs> StatementList
%type<AST::node_ptr> IfStatement
%type<AST::node_ptrs> ElseStatement
%type<AST::node_ptr> ElseIfStatement
%type<AST::node_ptrs> ElseIfStatementList
%type<AST::node_ptr> DoStatement
%type<AST::node_ptr> WhileStatement
%type<AST::node_ptr> ReadStatement
%type<AST::node_ptr> PrintStatement
%type<AST::node_ptrs> PrintList
%type<AST::node_ptr> CallStatement
%type<AST::node_ptr> FunctionCall

// Order of expressions
%left COMPARISON
%left PLUS MINUS
%left TIMES DIVIDE

%start ExecutableProgram

%locations

%%

ExecutableProgram
    : ExecutableProgram Subprogram {
        $$ = std::move($1);
        $$->addChild(std::move($2));
    }
    | Subprogram {
        $$ = driver.createRoot();
        $$->addChild(std::move($1));
    };

Subprogram
    : MainProgram {
        $$ = std::move($1);
    }
    | Subroutine {
        $$ = std::move($1);
    }
    | Function {
        $$ = std::move($1);
    };

MainProgram
    : PROGRAM ProgramIdentifier Body STOP END {
        $$ = driver.createNode<MainProgram>(std::move($2), std::move($3));
        Mapper::instance().reset();
    }
    | PROGRAM error STOP END {
        yyerrok;
    };

Subroutine
    : SUBROUTINE SubroutineIdentifier LP ArgumentList RP Body RETURN END {
        $$ = driver.createNode<Subroutine>(std::move($2), std::move($4), std::move($6));
        Mapper::instance().reset();
    }
    | SUBROUTINE SubroutineIdentifier LP RP Body RETURN END {
        $$ = driver.createNode<Subroutine>(std::move($2), node_ptrs{}, std::move($5));
        Mapper::instance().reset();
    }
    | SUBROUTINE error RETURN END {
        yyerrok;
    };

Function
    : Type FUNCTION FunctionIdentifier LP ArgumentList RP Body RETURN END {
        std::string error_msg = "";
        bool any_error = false;

        // Function id should be declared inside function body as a variable
        if (Mapper::instance().lookup_var($3->id())) {
            Entry tmp = Mapper::instance().var_entry($3->id());
            
            // Check function return type
            if (tmp.type() == $1->var_type()) {
                
                // Check arguments declarations
                std::string args = "";
                for (auto& arg : $5) {
                    if (!Mapper::instance().lookup_var(arg->id())) {
                        args += arg->id() + ", ";
                        any_error = true;
                    }
                }
                if (any_error) {
                    error_msg += "argument ids [" + args + "] were not defined in function body";
                } else {
                    Entry entry(Fortran::symbol::type::FUNCTION, $1->var_type(), tmp.dimension(), $5);
                    bool inserted = Mapper::instance().insert_fun($3->id(), entry);
                    if (inserted) {
                        $$ = driver.createNode<Function>(std::move($1), std::move($3), std::move($5), std::move($7));
                    } else {
                        error_msg += "redefinition of function id '" + $3->id() + "'";
                        any_error = true;
                    }
                }
            } else {
                error_msg += "type mismatch between var id '" + $3->id() + "' and function return type.";
                any_error = true;
            }
        } else {
            error_msg += "function id '" + $3->id() + "' was not defined in function body.";
            any_error = true;
        }

        // Create fake node
        if(any_error) {
            $$ = driver.createNode<ErrorNode>(error_msg);
            driver.semantic_error(error_msg);
        }
        Mapper::instance().reset();
    }
    | Type FUNCTION FunctionIdentifier LP RP Body RETURN END {
        std::string error_msg = "";
        bool any_error = false;

        // Function id should be declared inside function body as a variable
        if (Mapper::instance().lookup_var($3->id())) {
            Entry tmp = Mapper::instance().var_entry($3->id());
            
            // Check function return type
            if (tmp.type() == $1->var_type()) {

                Entry entry(Fortran::symbol::type::FUNCTION, $1->var_type(), tmp.dimension(), node_ptrs{});
                bool inserted = Mapper::instance().insert_fun($3->id(), entry);
                if (inserted) {
                    $$ = driver.createNode<Function>(std::move($1), std::move($3), node_ptrs{}, std::move($6));
                } else {
                    error_msg += "redefinition of function id '" + $3->id() + "'";
                    any_error = true;
                }
            } else {
                error_msg += "type mismatch between var id '" + $3->id() + "' and function return type.";
                any_error = true;
            }
        } else {
            error_msg += "function id '" + $3->id() + "' was not defined in function body.";
            any_error = true;
        }

        // Create fake node
        if(any_error) {
            $$ = driver.createNode<ErrorNode>(error_msg);
            driver.semantic_error(error_msg);
        }
        Mapper::instance().reset();
    }
    | Type FUNCTION error RETURN END {
        yyerrok;
        std::string error_msg = "syntax error";
        $$ = driver.createNode<ErrorNode>(error_msg);
    };

FunctionIdentifier
    : ID {
        Mapper::instance().create_scope();
        $$ = driver.createNode<Identifier>(std::move($1), Fortran::symbol::type::FUNCTION);
    };

SubroutineIdentifier
    : ID {
        Entry entry(Fortran::symbol::type::SUBROUTINE);
        bool inserted = Mapper::instance().insert_fun($1, entry);
        Mapper::instance().create_scope();
        if (!inserted) {
            std::string error = "redefinition of subroutine id '" + $1 + "'";
            driver.semantic_error(error);
            $$ = driver.createNode<ErrorNode>(error);
        } else {
            $$ = driver.createNode<Identifier>(std::move($1), Fortran::symbol::type::SUBROUTINE);
        }
    };

ProgramIdentifier
    : ID {
        Entry entry(Fortran::symbol::type::PROGRAM);
        bool inserted = Mapper::instance().insert_fun($1, entry);
        Mapper::instance().create_scope();
        if (!inserted) {
            std::string error = "redefinition of program id '" + $1 + "'";
            driver.semantic_error(error);
            $$ = driver.createNode<ErrorNode>(error);
        } else {
            $$ = driver.createNode<Identifier>(std::move($1), Fortran::symbol::type::PROGRAM);
        }
    };

Identifier
    : ID {
        $$ = driver.createNode<Identifier>(std::move($1));
    };

ArgumentList
    : Argument {
        $$ = driver.createNodeList(std::move($1));
    }
    | ArgumentList COMMA Argument {
        $$ = std::move($1);
        $$.emplace_back(std::move($3));
    };

Argument
    : ID {
        $$ = driver.createNode<Identifier>(std::move($1));
    };

ParameterList
    : Parameter {
        $$ = driver.createNodeList(std::move($1));
    }
    | ParameterList COMMA Parameter {
        $$ = std::move($1);
        $$.emplace_back(std::move($3));
    };

Parameter
    : Identifier {
        $$ = std::move($1);
    }
    | Literal {
        $$ = std::move($1);
    };

Type
    : TYPE {
        $$ = driver.createNode<Type>($1);
    };

Body
    : SpecificationConstruct ExecutableConstruct {
        $$ = driver.createNode<Body>(std::move($1), std::move($2));
    };

SpecificationConstruct
    : SpecificationList {
        $$ = driver.createNode<SpecificationConstruct>(std::move($1));
    }
    | %empty {
        $$ = driver.createNode<SpecificationConstruct>(node_ptrs{});
    };

SpecificationList
    : Specification {
        $$ = driver.createNodeList(std::move($1));
    }
    | SpecificationList Specification {
        $$ = std::move($1);
        $$.emplace_back(std::move($2));
    };

Specification
    : DeclarationStatement {
        $$ = std::move($1);
    }
    | ParameterStatement {
        $$ = std::move($1);
    };

DeclarationStatement
    : Type IdentifierDeclarationList {
        bool any_error = false;
        for (auto& node : $2) {
            Entry entry($1->var_type(), node->struct_type(), Fortran::symbol::type::VARIABLE);
            bool inserted = Mapper::instance().insert_var(node->id(), entry);
            if (!inserted) {
                std::string error_msg = "redeclaration of variable id '" + node->id() + "'";
                driver.semantic_error(error_msg);
                any_error = true;
            }
        }
        if(any_error) {
            std::string error_msg = "redeclaration of variable(s)";
            $$ = driver.createNode<ErrorNode>(error_msg);
        } else {
            $$ = driver.createNode<DeclarationStatement>(std::move($1), std::move($2));
        }
    };

IdentifierDeclarationList
    : IdentifierDeclaration {
        $$ = driver.createNodeList(std::move($1));
    }
    | IdentifierDeclarationList COMMA IdentifierDeclaration {
        $$ = std::move($1);
        $$.emplace_back(std::move($3));
    };

IdentifierDeclaration
    : Identifier {
        $$ = driver.createNode<IdentifierDeclaration>(std::move($1));
    }
    | Identifier LP INTEGER RP {
        $$ = driver.createNode<IdentifierDeclaration>(std::move($1), $3);
    }
    | Identifier LP Identifier RP {
        $$ = driver.createNode<IdentifierDeclaration>(std::move($1), std::move($3));
    };

ParameterStatement
    : PARAMETER LP AssignmentStatementList RP {
        $$ = driver.createNode<ParameterStatement>(std::move($3));
    };

AssignmentStatementList
    : AssignmentStatement {
        $$ = driver.createNodeList(std::move($1));
    }
    | AssignmentStatementList COMMA AssignmentStatement {
        $$ = std::move($1);
        $$.emplace_back(std::move($3));
    };

AssignmentStatement
    : Identifier ASSIGN Expression {
        std::string error_msg = "";
        bool any_error = false;
        bool declared = Mapper::instance().lookup_var($1->id());
        if (!declared) {
            error_msg += "variable id '" + $1->id() + "' not declared";
            any_error = true;
        } else {
            if (Mapper::instance().var_entry($1->id()).type() == $3->var_type()) {
                $$ = driver.createNode<AssignmentStatement>(std::move($1), std::move($3));
            } else {
                error_msg += "type mismatch";
                any_error = true;
            }
        }
        if (any_error) {
            driver.semantic_error(error_msg);
            $$ = driver.createNode<ErrorNode>(error_msg);
        }
    }
    | Identifier LP Expression RP ASSIGN Expression {
        $$ = driver.createNode<AssignmentStatement>(std::move($1), std::move($3), std::move($6));
    };

Expression
    : Expression COMPARISON Expression {
        $$ = driver.createNode<Comparison>(std::move($1), std::move($3), $2);
    }
    | Expression PLUS Expression {
        $$ = driver.createNode<Expression>(std::move($1), std::move($3), $2);
    }
    | Expression MINUS Expression {
        $$ = driver.createNode<Expression>(std::move($1), std::move($3), $2);
    }
    | Expression TIMES Expression {
        $$ = driver.createNode<Expression>(std::move($1), std::move($3), $2);
    }
    | Expression DIVIDE Expression {
        $$ = driver.createNode<Expression>(std::move($1), std::move($3), $2);
    }
    | Expression AND Expression {
        $$ = driver.createNode<Expression>(std::move($1), std::move($3), $2);
    }
    | Expression OR Expression {
        $$ = driver.createNode<Expression>(std::move($1), std::move($3), $2);
    }
    | NOT Expression {
        $$ = driver.createNode<Expression>(std::move($2), $1);
    }
    | LP Expression RP {
        $$ = std::move($2);
    }
    | FunctionCall {
        $$ = std::move($1);
    }
    | Identifier {
        if (!Mapper::instance().lookup_var($1->id())) {
            std::string error_msg = "variable id '" + $1->id() + "' not declared";
            driver.semantic_error(error_msg);
            $$ = driver.createNode<ErrorNode>(error_msg);
        } else {
            $$ = std::move($1);
        }
    }
    | Literal {
        $$ = std::move($1);
    };

FunctionCall
    : Identifier LP ParameterList RP {
        std::cout << "Creating a function call." << std::endl;
        std::string error_msg = "";
        bool any_error = false;
        if (Mapper::instance().lookup_fun($1->id())) {
            Entry entry = Mapper::instance().fun_entry($1->id());

            if (entry.args().size() == $3.size()) {

                // Check parameter types
                std::string params = "";
                for (unsigned int i = 0; i < $3.size(); i++) {
                    if ($3[i]->var_type() != entry.args()[i]->var_type()) {
                        params += $3[i]->id() + ", ";
                        any_error = true;
                    }
                }
                if (any_error) {
                    error_msg += "type mismatch in function call with paramater ids [" + params + "]";
                } else {
                    $$ = driver.createNode<FunctionCall>(std::move($1), std::move($3));
                }
            } else {
                error_msg += "function id '" + $1->id() + "' expects " + std::to_string(entry.args().size()) + " parameters.";
                any_error = true;
            }
        } else {
            error_msg += "function id '" + $1->id() + "' not declared";
            any_error = true;
        }
        if (any_error) {
            driver.semantic_error(error_msg);
            $$ = driver.createNode<ErrorNode>(error_msg);
        }
    }
    | Identifier LP RP {
        std::cout << "Creating a function call." << std::endl;
        std::string error_msg = "";
        bool any_error = false;
        if (Mapper::instance().lookup_fun($1->id())) {
            Entry entry = Mapper::instance().fun_entry($1->id());

            // Check arguments
            if (entry.args().size() == 0) {
                $$ = driver.createNode<FunctionCall>(std::move($1), node_ptrs{});
            } else {
                error_msg += "function id '" + $1->id() + "' expects " + std::to_string(entry.args().size()) + " parameters.";
                any_error = true;
            }
        } else {
            error_msg += "function id '" + $1->id() + "' not declared";
            any_error = true;
        }
        if (any_error) {
            driver.semantic_error(error_msg);
            $$ = driver.createNode<ErrorNode>(error_msg);
        }

    };

Literal
    : INTEGER {
        $$ = driver.createNode<Literal>($1);
    }
    | REAL {
        $$ = driver.createNode<Literal>($1);
    }
    | BOOLEAN {
        $$ = driver.createNode<Literal>($1);
    }
    | STRING {
        $$ = driver.createNode<Literal>($1);
    };

/*
ExpressionList
    : Expression
    | ExpressionList "," Expression
    ;
*/
ExecutableConstruct
    : ExecutableList {
        $$ = driver.createNode<ExecutableConstruct>(std::move($1));
    }
    | %empty {
        $$ = driver.createNode<ExecutableConstruct>(node_ptrs{});
    };

ExecutableList
    : Statement {
        $$ = driver.createNodeList(std::move($1));
    }
    | ExecutableList Statement {
        $$ = std::move($1);
        $$.emplace_back(std::move($2));
    };

Statement
    : AssignmentStatement {
        $$ = std::move($1);
    }
    | IfStatement {
        $$ = std::move($1);
    }
    | DoStatement {
        $$ = std::move($1);
    }
    | WhileStatement {
        $$ = std::move($1);
    }
    | ReadStatement {
        $$ = std::move($1);
    }
    | PrintStatement {
        $$ = std::move($1);
    }
    | CallStatement {
        $$ = std::move($1);
    }
    /*
    | CycleStatement {
        $$ = std::move($1);
    }
    | ExitStatement {
        $$ = std::move($1);
    };
    */
    ;

IfStatement
    : IF LP Expression RP THEN StatementList ENDIF {
        $$ = driver.createNode<IfStatement>(std::move($3), std::move($6), node_ptrs{}, node_ptrs{});
    }
    | IF LP Expression RP THEN StatementList ElseIfStatementList ElseStatement {
        $$ = driver.createNode<IfStatement>(std::move($3), std::move($6), std::move($7), std::move($8));
    }
    | IF LP Expression RP THEN StatementList ElseStatement {
        $$ = driver.createNode<IfStatement>(std::move($3), std::move($6), node_ptrs{}, std::move($7));
    };

ElseIfStatementList
    : ElseIfStatement {
        $$ = driver.createNodeList(std::move($1));
    }
    | ElseIfStatementList ElseIfStatement {
        $$ = std::move($1);
        $$.emplace_back(std::move($2));
    };

ElseIfStatement
    : ELSEIF LP Expression RP THEN StatementList {
        $$ = driver.createNode<ElseIfStatement>(std::move($3), std::move($6));
    };

ElseStatement
    : ELSE StatementList ENDIF {
        $$ = std::move($2);
    };

StatementList
    : Statement {
        $$ = driver.createNodeList(std::move($1));
    }
    | StatementList Statement {
        $$ = std::move($1);
        $$.emplace_back(std::move($2));
    };

ReadStatement
    : READ ArgumentList {
        $$ = driver.createNode<ReadStatement>(std::move($2));
    };

PrintStatement
    : PRINT PrintList {
        $$ = driver.createNode<PrintStatement>(std::move($2));
    };

PrintList
    : Expression {
        $$ = driver.createNodeList(std::move($1));
    }
    | PrintList COMMA Expression {
        $$ = std::move($1);
        $$.emplace_back(std::move($3));
    };

DoStatement
    : DO Identifier ASSIGN Expression COMMA Expression StatementList ENDDO {
        node_ptr unitary = driver.createNode<Literal>(1);
        $$ = driver.createNode<DoStatement>(std::move($2),
            std::move($4), std::move($6), std::move(unitary), std::move($7));
    }
    | DO Identifier ASSIGN Expression COMMA Expression COMMA Expression StatementList ENDDO {
        $$ = driver.createNode<DoStatement>(std::move($2),
            std::move($4), std::move($6), std::move($8), std::move($9));
    };

WhileStatement
    : WHILE LP Expression RP DO StatementList ENDDO {
        $$ = driver.createNode<WhileStatement>(std::move($3), std::move($6));
    };

CallStatement
    : CALL Identifier LP ArgumentList RP {
        $$ = driver.createNode<CallStatement>(std::move($2), std::move($4));
    }
    | CALL Identifier LP RP {
        $$ = driver.createNode<CallStatement>(std::move($2), std::move(node_ptrs{}));
    };
/*
CycleStatement
    : "CONTINUE"
    ;

ExitStatement
    : "EXIT"
    ;
*/

%%

void Fortran::Parser::error(const location &loc, const std::string &message) {
   //std::cerr << "Error: " << message << " at " << loc << "\n";
   //std::cerr << "Error: " << message << " at " << driver.location() << "\n";
   driver.printError(message);
}