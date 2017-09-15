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

    using std::move;

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

// Control
%token PROGRAM
%token SUBROUTINE
%token FUNCTION
%token STOP
%token RETURN
%token END
%token PARAMETER
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

// Arithmetic operators
%token PLUS
%token MINUS
%token TIMES
%token DIVIDE
%token ASSIGN

// Comparison
%token EQ
%token NE
%token GT
%token GE
%token LT
%token LE

// Boolean
%token TRUE
%token FALSE

// Other
%token NEWLINE
%token EOF 0
%token COMMA
%token LP
%token RP

// Types
%token <Fortran::type> TYPE
%token <Fortran::integer> INTEGER
%token <Fortran::real> REAL
%token <std::string> ID
%token <std::string> STRING

%type <node_ptr> ExecutableProgram
%type <node_ptr> Subprogram
%type <node_ptr> MainProgram
%type <node_ptr> Subroutine
%type <node_ptr> Function
%type <node_ptr> Parameter
%type <node_ptr> Type
%type <node_ptr> Body
%type <node_ptrs> ParameterList

%start ExecutableProgram

%locations

%%

ExecutableProgram
    : ExecutableProgram Subprogram                         { $$ = move($1); $$->addChild(move($2)); }
    | Subprogram                                           { $$ = driver.createNode<ExecutableProgram>(); $$->addChild(move($1)); }
    ;

Subprogram
    : MainProgram                                          { $$ = move($1); }
    | Subroutine                                           { $$ = move($1); }
    | Function                                             { $$ = move($1); }
    ;

MainProgram
    : PROGRAM ID Body STOP END                             { $$ = driver.createNode<MainProgram>(move($2), move($3)); }
    ;

Subroutine
    : SUBROUTINE ID LP ParameterList RP Body RETURN END    { $$ = driver.createNode<Subroutine>(move($2), $4, move($6); }
    : SUBROUTINE ID LP RP Body RETURN END                  { $$ = driver.createNode<Subroutine>(move($2), {}, move($5); }
    ;

Function
    : Type FUNCTION ID LP ParameterList RP Body RETURN END { $$ = driver.createNode<Function>(move($1), move($3), $5, move($7); }
    | Type FUNCTION ID LP RP Body RETURN END               { $$ = driver.createNode<Function>(move($1), move($3), {}, move($6); }
    ;

ParameterList
    : Parameter                                            { $$ = driver.createNodeList(move($1)); }
    | ParameterList COMMA Parameter                        { $$ = move($1); $$.emplace_back(move($3)); }
    ;

Parameter
    : ID                                                   { $$ = driver.createNode<Identifier>(move($1)); }
    ;

Type
    : INTEGER                                              { $$ = driver.createNode<Type>(move($1)); }
    | REAL                                                 { $$ = driver.createNode<Type>(move($1)); }

Body: %empty                                               { $$ = driver.createNode<Body>(std::nullptr_t); }
    ;

/*
    : BodyConstruct                                        { $$ = $1; }
    | Body BodyConstruct                                   { $$ = move($3); }
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
    | DeclarationConstruct Declaration                     { $$ = driver.declarationConstruct($1, move($2)); }
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