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

    /* Include for all driver functions */
    #include "include/f_driver.hpp"

    #undef yylex
    #define yylex scanner.yylex
}

%define api.value.type variant
%define parse.assert

%token PROGRAM       "program keyword"
%token SUBROUTINE    "subroutine  keyword"
%token FUNCTION      "function  keyword"
%token STOP          "stop keyword"
%token RETURN        "return keyword"
%token END           "end keyword"
%token PARAMETER     "parameter"
%token INTEGER       "integer keyword"
%token REAL          "real keyword"
%token CYCLE         "cycle keyword"
%token EXIT          "exit keyword"
%token IF            "if keyword"
%token ELSE          "else keyword"
%token ELSEIF        "elseif keyword"
%token ENDIF         "endif keyword"
%token WHILE         "while keyword"
%token DO            "do keyword"
%token ENDDO         "enddo keyword"
%token PRINT         "print keyword"
%token READ          "read keyword"
%token CALL          "call keyword"
%token ERR           "error"
%token EOL           "end of line"
%token END 0         "end of file"

%token SUM           "+"
%token SUB           "-"
%token TIMES         "*"
%token DIV           "/"
%token ASSIGN        "="
%token EQ            ".EQ."
%token NE            ".NE."
%token GT            ".GT."
%token GE            ".GE."
%token LT            ".LT."
%token LE            ".LE."
%token TRUE          ".TRUE."
%token FALSE         ".FALSE."
%token COMMA         ","
%token LP            "("
%token RP            ")"

%token <int> INT            "integer number"
%token <float> FLOAT        "number number"
%token <std::string> ID     "id"
%token <std::string> STRING "string"

%locations

%%

ExecutableProgram
    : MainProgram
    | ExecutableProgram Subprogram
    ;

Subprogram
    : Subroutine
    | Function
    ;

MainProgram
    : MainProgramPrefix Body MainProgramSuffix
    ;

Subroutine
    : SubroutinePrefix LP ParameterList RP Body SubroutineSuffix
    ;

Function
    : FunctionPrefix LP ParameterList RP Body FunctionSuffix
    ;

MainProgramPrefix
    : "PROGRAM" ID
    ;

MainProgramSuffix
    : "STOP" "END"
    ;

SubroutinePrefix
    : "SUBROUTINE" ID
    ;

SubroutineSuffix
    : "RETURN" "END"
    ;

FunctionPrefix
    : Type "FUNCTION" ID
    ;

FunctionSuffix
    : "RETURN" "END"
    ;

ParameterList
    : ID
    | ParameterList "," ID
    ;

Body
    : BodyConstruct
    | Body BodyConstruct
    ;

BodyConstruct
    : SpecificationConstruct
    | ExecutableConstruct
    ;

SpecificationConstruct
    : DeclarationConstruct
    | ParameterStatement
    ;

DeclarationConstruct
    : Declaration
    | DeclarationConstruct Declaration
    ;

Declaration
    : Type IdentifierDeclarationList

Type
    : "INTEGER"
    | "REAL"
    | "CHARACTER"
    | "LOGICAL"
    ;

IdentifierDeclarationList
    : IdentifierDeclaration
    | IdentifierDeclarationList "," IdentifierDeclaration
    ;

IdentifierDeclaration
    : ID
    | ID LP INT RP
    ;

ParameterStatement
    : "PARAMETER" LP ConstantList RP
    ;

ConstantList
    : ConstantDefinition
    | ConstantList "," ConstantDefinition
    ;

ConstantDefinition
    : ID "=" ConstantExpression
    ;

ConstantExpression
    : Number
    | STRING
    ;

Number
    : INT
    | FLOAT
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

%%

void Fortran::Parser::error(const location_type &loc, const std::string &err_message) {
   std::cerr << "Error: " << err_message << " at " << loc << "\n";
}