%skeleton "lalr1.cc"
%require "3.0"       // Bison version

//%output "src/f_parser.cpp" 
%defines// "include/f_parser.hpp"

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

// Parameters given to the Parser constructor
%parse-param { Fortran::Scanner &scanner }
%parse-param { Fortran::Driver &driver }

// Code to be placed in the beggining of the parser implementation file
%code {
    #include <iostream>
    #include "f_scanner.hpp"
    #include "f_parser.hpp"
    #include "f_driver.hpp"
    #include "location.hh"

    // This function is called only inside Bison, so we make it static to limit
    // symbol visibility for the linker to avoid potential linking conflicts.
    static Fortran::Parser::symbol_type yylex(Fortran::Scanner &scanner,
                                              Fortran::Driver &driver) {
        return scanner.getNextToken();
    }
}

// Parameters to flex and bison
%lex-param { Fortran::Scanner &scanner }
%lex-param { Fortran::Driver &driver }
//%parse-param { Fortran::Scanner &scanner }
//%parse-param { Fortran::Driver &driver }

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
%token NEWLINE "new line"
%token EOF 0   "end of file" 
%token COMMA   "comma"
%token LP      "left parenthesis"
%token RP      "right parenthesis"

// Arithmetic operators
%token<Fortran::op::arithmetic> PLUS   "+";
%token<Fortran::op::arithmetic> MINUS  "-";
%token<Fortran::op::arithmetic> TIMES  "*";
%token<Fortran::op::arithmetic> DIVIDE "/";
%token<Fortran::op::arithmetic> ASSIGN "=";

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
%type<AST::node_ptr> Parameter
%type<AST::node_ptr> Type
%type<AST::node_ptr> Body
%type<AST::node_ptrs> ParameterList

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
    : PROGRAM ID Body STOP END {
        $$ = driver.createNode<MainProgram>(std::move($2), std::move($3));
    };

Subroutine
    : SUBROUTINE ID LP ParameterList RP Body RETURN END {
        $$ = driver.createNode<Subroutine>(std::move($2), std::move($4), std::move($6));
    }
    | SUBROUTINE ID LP RP Body RETURN END {
        $$ = driver.createNode<Subroutine>(std::move($2), {}, std::move($5));
    };

Function
    : Type FUNCTION ID LP ParameterList RP Body RETURN END {
        $$ = driver.createNode<Function>(std::move($1), std::move($3), std::move($5), std::move($7));
    }
    | Type FUNCTION ID LP RP Body RETURN END {
        $$ = driver.createNode<Function>(std::move($1), std::move($3), {}, std::move($6));
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
    : ID {
        $$ = driver.createNode<Identifier>(std::move($1));
    };

Type
    : INTEGER {
        $$ = driver.createNode<Type>($1);
    }
    | REAL {
        $$ = driver.createNode<Type>($1);
    }
    | BOOLEAN {
        $$ = driver.createNode<Type>($1);
    };

Body: %empty {
        $$ = driver.createNode<Body>({});
    };

/*
    : BodyConstruct                                        { $$ = $1; }
    | Body BodyConstruct                                   { $$ = std::move($3); }
    ;

BodyConstruct
    : SpecificationConstruct                               { $$ = driver.specificationConstruct($1); }
    | ExecutableConstruct                                  { $$ = driver.executableConstruct($1); }
    ;

SpecificationConstruct
    : DeclarationConstruct                                 { $$ = $1; }
    | ParameterStatement                                   { $$ = $1; }
    ;

DeclarationConstruct
    : Declaration                                          { $$ = driver.declarationConstruct($1); }
    | DeclarationConstruct Declaration                     { $$ = driver.declarationConstruct($1, std::move($2)); }
    ;

Declaration
    : Type IdentifierDeclarationList                       { $$ = driver.declaration($1,$2); }

IdentifierDeclarationList
    : IdentifierDeclaration                                  { $$ = $1; }
    | IdentifierDeclarationList COMMA IdentifierDeclaration  { $$ = driver.identifierDeclarationList($1, $3); }
    ;

IdentifierDeclaration
    : ID                                                   { $$ = driver.identifier($1); }
    | ID LP INT RP                                         { $$ = driver.arrayIdentifier($1, $3); }
    ;

ParameterStatement
    : PARAMETER LP ConstantList RP                         { $$ = driver.parameterStatement($3); }
    ;

ConstantList
    : ConstantDefinition                                   { $$ = driver.constantList($1); }
    | ConstantList COMMA ConstantDefinition                { $$ = driver.constantList($1, $3); }
    ;

ConstantDefinition
    : ID ASSIGN ConstantExpression                         { $$ = driver.constantDefinition($1, $3); }
    ;

ConstantExpression
    : Number                                               { $$ = driver.constantExpression($1); }
    | STRING                                               { $$ = driver.stringLiteral($1); }
    ;

Number
    : INT                                                  { $$ = driver.intNumeber($1); }
    | FLOAT                                                { $$ = driver.floatNumber($1); }
    ;

ExecutableConstruct
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

AssignmentStatement
    : ID "=" Expression
    | ID LP INT RP "=" Expression
    ;

Expression
    : Factor
    | Expression "+" Factor
    | Expression "-" Factor
    ;

Factor
    : Term
    | Factor "*" Term
    | Factor "/" Term
    ;

Term
    : LP Expression RP
    | ID LP ExpressionList RP
    | ID LP RP
    | ID
    | Number
    | "-" Term
    ;

ExpressionList
    : Expression
    | ExpressionList "," Expression
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
    : "READ" ParameterList
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

LogicalExpression
    : Expression Op Expression
    | LogicalConstant
    ;

Op
    : ".AND."
    | ".OR."
    | ".EQ."
    | ".NE."
    | ".GT."
    | ".GE."
    | ".LT."
    | ".LE."
    ;

LogicalConstant
    : ".TRUE."
    | ".FALSE."
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
    : "CALL" ID LP ParameterList RP
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