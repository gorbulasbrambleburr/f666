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
}

// Code to be placed in the beggining of the parser implementation file
%code top {
    #include <iostream>
    #include "f_scanner.hpp"
    #include "f_parser.hpp"
    #include "f_driver.hpp"
    #include "location.hh"

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
%type<AST::node_ptrs> ArgumentList
%type<AST::node_ptr> Argument
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
%type<AST::node_ptr> LogicalExpression
%type<AST::node_ptr> NumericExpression
%type<AST::node_ptr> Factor
%type<AST::node_ptr> Term
%type<AST::node_ptr> Number

// Order of expressions
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
    : PROGRAM Identifier Body STOP END {
        $$ = driver.createNode<MainProgram>(std::move($2), std::move($3));
    };

Subroutine
    : SUBROUTINE Identifier LP ArgumentList RP Body RETURN END {
        $$ = driver.createNode<Subroutine>(std::move($2), std::move($4), std::move($6));
    }
    | SUBROUTINE Identifier LP RP Body RETURN END {
        $$ = driver.createNode<Subroutine>(std::move($2), node_ptrs{}, std::move($5));
    };

Function
    : Type FUNCTION Identifier LP ArgumentList RP Body RETURN END {
        $$ = driver.createNode<Function>(std::move($1), std::move($3), std::move($5), std::move($7));
    }
    | Type FUNCTION Identifier LP RP Body RETURN END {
        $$ = driver.createNode<Function>(std::move($1), std::move($3), node_ptrs{}, std::move($6));
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
        $$ = driver.createNode<DeclarationStatement>(std::move($1), std::move($2));
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
        $$ = driver.createNode<AssignmentStatement>(std::move($1), std::move($3));
    }
    | Identifier LP Expression RP ASSIGN Expression {
        $$ = driver.createNode<AssignmentStatement>(std::move($1), std::move($3), std::move($6));
    };

Expression
    : LogicalExpression {
        $$ = std::move($1);
    }
    | NumericExpression {
        $$ = std::move($1);
    };

LogicalExpression
    : Expression COMPARISON Expression {
        $$ = driver.createNode<LogicalExpression>(std::move($1), std::move($2), std::move($3));
    }
    | BOOLEAN {
        $$ = driver.createNode<LogicalExpression>($1);
    };


NumericExpression
    : Factor {
        $$ = driver.createNode<NumericExpression>(std::move($1));
    }
    | NumericExpression PLUS Factor {
        $$ = driver.createNode<Factor>(std::move($1), $2, std::move($3));
    }
    | NumericExpression MINUS Factor {
        $$ = driver.createNode<Factor>(std::move($1), $2, std::move($3));
    };

Factor
    : Term {
        $$ = driver.createNode<Factor>(std::move($1));
    }
    | Factor TIMES Term {
        $$ = driver.createNode<Factor>(std::move($1), $2, std::move($3));
    }
    | Factor DIVIDE Term {
        $$ = driver.createNode<Factor>(std::move($1), $2, std::move($3));
    };

Term
    : LP NumericExpression RP {
        $$ = driver.createNode<Term>(std::move($2));
    }
    | Identifier {
        $$ = driver.createNode<Term>(std::move($1));
    }
    | Number {
        $$ = driver.createNode<Term>(std::move($1));
    }
    | MINUS Term {
        $$ = driver.createNode<Term>($1, std::move($2));
    };

Number
    : INTEGER {
        $$ = driver.createNode<Number>($1);
    }
    | REAL {
        $$ = driver.createNode<Number>($1);
    };

/*
ExpressionList
    : Expression
    | ExpressionList "," Expression
    ;
*/
ExecutableConstruct
    : %empty {
        $$ = driver.createNode<ExecutableConstruct>(node_ptrs{});
    };

/*
    : Statement
    | ExecutableConstruct Statement
    ;

Statement
    : AssignmentStatement
    | PrintStatement
    | ReadStatement
    | IfConstruct
    | DoConstruct
    | WhileConstruct
    | CallStatement
    | CycleStatement
    | ExitStatement
    ;

PrintStatement
    : "PRINT" PrintList
    ;

PrintList
    : PrintItem
    | PrintList "," PrintItem
    ;

PrintItem
    : STRING
    | Expression
    ;

ReadStatement
    : "READ" ArgumentList
    ;

IfConstruct
    : IfThenStatement ThenConstruct
    ;

IfThenStatement
    : "IF" LogicalExpression "THEN"
    ;

ThenConstruct
    : Statement EndIfStatement
    | Statement ElseIfConstruct
    | Statement ElseConstruct
    ;

EndIfStatement
    : "ENDIF"
    ;

ElseIfConstruct
    : ElseIfStatement ThenConstruct
    ;

ElseIfStatement
    : "ELSEIF" Expression "THEN"
    ;

ElseConstruct
    : "ELSE" Expression "END"
    ;

DoConstruct
    : DoStatement DoLoopControl EndDoStatement
    ;

DoStatement
    : "DO"
    ;

DoLoopControl
    : ID "=" Expression "," Expression
    | ID "=" Expression "," Expression "," Expression
    ;

EndDoStatement
    : Statement "ENDDO"
    ;

WhileConstruct
    : WhileStatement EndWhileStatement
    ;

WhileStatement
    : "WHILE" LogicalExpression "DO"
    ;

EndWhileStatement
    : Statement "ENDDO"
    ;

CallStatement
    : "CALL" ID LP ArgumentList RP
    | "CALL" ID LP RP
    ;

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
   std::cerr << "Error: " << message << " at " << driver.location() << "\n";
}