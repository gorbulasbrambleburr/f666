%skeleton "lalr1.cc"
%require "3.0"
%debug
%defines
%define api.namespace {Fortran}
%define parser_class_name "Parser"

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

/* Parameters for the yylex function */
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%code {
    #include <iostream>
    #include <cstdlib>
    #include <fstream>

    /* Include for all driver functions */
    #include "driver.hpp"

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
    : SubroutinePrefix "(" ParameterList ")" Body SubroutineSuffix
    ;

Function
    : FunctionPrefix "(" ParameterList ")" Body FunctionSuffix
    ;

MainProgramPrefix
    : "PROGRAM" Name
    ;

MainProgramSuffix
    : "STOP" "END"
    ;

SubroutinePrefix
    : "SUBROUTINE" Name
    ;

SubroutineSuffix
    : "RETURN" "END"
    ;

FunctionPrefix
    : Type "FUNCTION" Name
    ;

FunctionSuffix
    : "RETURN" "END"
    ;

Name
    : Letter
    | Name Letter
    ;

Letter
    : [a-zA-Z]
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
    : Identifier
    | Identifier "(" Integer ")"
    ;

Identifier
    : Letter
    | Identifier Alphanumeric
    ;

Alphanumeric
    : Letter
    | Digit
    ;

Digit
    : [0-9]
    ;

ParameterStatement
    : "PARAMETER" "(" ConstantList ")"
    ;

ConstantList
    : ConstantDefinition
    | ConstantList "," ConstantDefinition
    ;

ConstantDefinition
    : Identifier "=" ConstantExpression
    ;

ConstantExpression
    : Number
    | StringLiteral
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
    : Identifier "=" Expression
    | Identifier "(" Integer ")" "=" Expression
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
    : "(" Expression ")"
    | Identifier "(" ExpressionList ")"
    | Identifier "(" ")"
    | Identifier
    | Number
    | "-" Term
    ;

ExpressionList
    : Expression
    | ExpressionList "," Expression
    ;

Number
    : Integer
    | Real
    ;

Integer
    : Digit
    | Integer Digit
    ;

Real
    : Integer '.' Integer
    | Integer '.'
    | '.' Integer 
    ;

PrintStatement
    : "PRINT" PrintList
    ;

PrintList
    : PrintItem
    | PrintList "," PrintItem
    ;

PrintItem
    : StringLiteral
    | Expression
    ;

StringLiteral
    : "'' Text "''
    ;

Text
    : TextChar
    | TextChar Text
    ;

TextChar
    : [\x20-\x26]
    | [\x28-\x7E]
    | [\xA]
    ;

ReadStatement
    : "READ" IdentifierList
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

EndIFStatement
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
     LogicalConstant
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
    : Identifier "=" Expression "," Expression
    | Identifier "=" Expression "," Expression "," Expression
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
    : "CALL" Name "(" IdentifierList ")"
    | "CALL" Name "(" ")"
    ;

CycleStatement
    : "CONTINUE"
    ;

ExitStatement
    : "EXIT"
    ;

%%

void Fortran::Parser::error( const location_type &l, const std::string &err_message ) {
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}













