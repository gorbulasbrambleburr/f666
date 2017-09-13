%skeleton "lalr1.cc"
%require "3.0"
%debug
%defines
%define api.namespace { Fortran }
%define parser_class_name { Parser }

%code requires {
    namespace Fortran {
        class Driver;
        class Scanner;
    }

    // The following definitions are missing when %locations isn't used
    # ifndef YY_NULLPTR
    #   if defined __cplusplus && 201103L <= __cplusplus
    #     define YY_NULLPTR nullptr
    #   else
    #     define YY_NULLPTR 0
    #   endif
    # endif
}

/* Parameters given to the Parser constructor */
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%code {
    #include <iostream>
    #include <cstdlib>
    #include <fstream>
    #include "include/Types.hpp"

    /* Include for all driver functions */
    #include "include/f_driver.hpp"

    #undef yylex
    #define yylex scanner.yylex
}

%define api.value.type variant
%define parse.assert

%token PROGRAM
%token SUBROUTINE
%token FUNCTION
%token STOP
%token RETURN
%token END
%token PARAMETER
%token TYPE_INTEGER
%token TYPE_REAL
%token CYCLE
%token EXIT
%token IF
%token ELSE
%token ELSEIF
%token ENDIF
%token WHILE
%token DO
%token ENDDO
%token PRINT
%token READ
%token CALL
%token ERR
%token EOL
%token EOF 0

%token ADD
%token SUB
%token TIMES
%token DIV
%token ASSIGN
%token EQ
%token NE
%token GT
%token GE
%token LT
%token LE
%token TRUE
%token FALSE
%token COMMA
%token LP
%token RP

%token <ast::type> INTEGER
%token <ast::type> REAL
%token <std::string> ID
%token <std::string> STRING

%type <AST> ExecutableProgram
%type <AST> MainProgram
%type <AST> Subroutine
%type <AST> Function

%start ExecutableProgram

%locations

%%

ExecutableProgram
    : MainProgram                                          { $$ = $1; }
    | ExecutableProgram Subprogram                         { $$ = $1; }
    ;

Subprogram
    : Subroutine                                           { $$ = $1; }
    | Function                                             { $$ = $1; }
    ;

MainProgram
    : PROGRAM ID Body STOP END                             { $$ = driver.mainProgram($2, $3); }
    ;

Subroutine
    : SUBROUTINE ID LP ParameterList RP Body RETURN END    { $$ = driver.subroutine($2, $4, $6); }
    : SUBROUTINE ID LP RP Body RETURN END                  { $$ = driver.subroutine($2, $5); }
    ;

Function
    : Type FUNCTION ID LP ParameterList RP Body RETURN END { $$ = driver.function($1, $3, $5, $7); }
    | Type FUNCTION ID LP RP Body RETURN END               { $$ = driver.function($1, $3, $6); }
    ;

ParameterList
    : Parameter                                            { $$ = driver.parameterList($1); }
    | ParameterList COMMA Parameter                        { $$ = driver.parameterList($1, $3); }
    ;

Parameter
    : ID                                                   { $$ = driver.identifier($1); }
    ;

Type
    : INTEGER                                              { $$ = driver.type($1); }
    | REAL                                                 { $$ = driver.type($1); }

Body: %empty                                               { $$ = nullptr; }
    ;

/*
    : BodyConstruct                                        { $$ = $1; }
    | Body BodyConstruct                                   { $$ = $3; } 
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
    | DeclarationConstruct Declaration                     { $$ = driver.declarationConstruct($1, $2); }
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

void Fortran::Parser::error(const location_type &loc, const std::string &err_message) {
   std::cerr << "Error: " << err_message << " at " << loc << "\n";
}