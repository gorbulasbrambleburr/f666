%{
    #include <iostream>
    #include <cstdlib>
    #include "include/f_scanner.hpp"
    #include "include/f_driver.hpp"
    #include "parser.hpp"
    #include "location.hh"

    #include <string>

    // Original yyterminate() macro returns int. Since we're using Bison 3 variants
    // as tokens, we must redefine it to change type from `int` to `Parser::semantic_type`
    #define yyterminate() Fortran::Parser::make_END(EzAquarii::location());

    // This will track current scanner location.
    // Action is called when length of the token is known.
    #define YY_USER_ACTION m_driver.increaseLocation(yyleng);

    using token = Fortran::Parser::token;

%}

%option debug
%option nodefault
%option noyywrap
%option c++
%option yyclass="Scanner"
%option prefix="Fortran_"

letter      [A-Za-z]
digit       [0-9]
integer     [-+]?{digit}+
real        [-+]?({digit}*\.?{digit}+|{digit}+\.)([E]?[-+]?{digit}+)?
id          {letter}({letter}|{digit}|_)*
sliteral    \'([^\\\']|\\.)*\'
comment     "//".*\n
ws          [ \t]+

%%

"PROGRAM" {
    return Fortran::Parser::make_PROGRAM(falk::location());
}

"SUBROUTINE" {
    return Fortran::Parser::make_SUBROUTINE(falk::location());
}

"FUNCTION" {
    return Fortran::Parser::make_FUNCTION(falk::location());
}

"STOP" {
    return Fortran::Parser::make_STOP(falk::location());
}

"RETURN" {
    return Fortran::Parser::make_RETURN(falk::location());
}

"END" {
    return Fortran::Parser::make_END(falk::location());
}

"PARAMETER" {
    return Fortran::Parser::make_PARAMETER(falk::location());
}

"INTEGER" {
    return Fortran::Parser::make_TYPE(ast::type::INTEGER, falk::location());
}

"REAL" {
    return Fortran::Parser::make_TYPE(ast::type::REAL, falk::location());
}

"BOOLEAN" {
    return Fortran::Parser::make_TYPE(ast::type::BOOLEAN, falk::location());
}

"CYCLE" {
    return Fortran::Parser::make_CYCLE(falk::location());
}

"EXIT" {
    return Fortran::Parser::make_EXIT(falk::location());
}

"IF" {
    return Fortran::Parser::make_IF(falk::location());
}

"ELSE" {
    return Fortran::Parser::make_ELSE(falk::location());
}

"ELSEIF" {
    return Fortran::Parser::make_ELSEIF(falk::location());
}

"ENDIF" {
    return Fortran::Parser::make_ENDIF(falk::location());
}

"WHILE" {
    return Fortran::Parser::make_WHILE(falk::location());
}

"DO" {
    return Fortran::Parser::make_DO(falk::location());
}

"ENDDO" {
    return Fortran::Parser::make_ENDDO(falk::location());
}

"PRINT" {
    return Fortran::Parser::make_PRINT(falk::location());
}

"READ" {
    return Fortran::Parser::make_READ(falk::location());
}

"CALL" {
    return Fortran::Parser::make_CALL(falk::location());
}


"+" {
    return Fortran::Parser::make_PLUS(Fortran::op::arithmetic::ADD, falk::location());
}

"-" {
    return Fortran::Parser::make_MINUS(Fortran::op::arithmetic::SUB, falk::location());
}

"*" {
    return Fortran::Parser::make_TIMES(Fortran::op::arithmetic::MULT, falk::location());
}

"/" {
    return Fortran::Parser::make_DIVIDE(Fortran::op::arithmetic::DIV, falk::location());
}

"=" {
    return Fortran::Parser::make_ASSIGN(falk::location());
}

".EQ." {
    return Fortran::Parser::make_COMPARISON(Fortran::op::arithmetic::EQ, falk::location());
}

".NE." {
    return Fortran::Parser::make_COMPARISON(Fortran::op::arithmetic::NE, falk::location());
}

".GT." {
    return Fortran::Parser::make_COMPARISON(Fortran::op::arithmetic::GT, falk::location());
}

".GE." {
    return Fortran::Parser::make_COMPARISON(Fortran::op::arithmetic::GE, falk::location());
}

".LT." {
    return Fortran::Parser::make_COMPARISON(Fortran::op::arithmetic::LT, falk::location());
}

".LE." {
    return Fortran::Parser::make_COMPARISON(Fortran::op::arithmetic::LE, falk::location());
}

".TRUE." {
    auto rvalue = driver.createBoolean(yytext);
    return Fortran::Parser::make_BOOL(std::move(rvalue), falk::location());
}

".FALSE." {
    auto rvalue = driver.createBoolean(yytext);
    return Fortran::Parser::make_BOOL(std::move(rvalue), falk::location());
}

"," {
    return Fortran::Parser::make_COMMA(falk::location());
}

"(" {
    return Fortran::Parser::make_LP(falk::location());
}

")" {
    return Fortran::Parser::make_RP(falk::location());
}



{ws}        ;
{comment}   ;

{sliteral} {
    auto content = std::string(yytext);
    content = content.substr(1, content.size() - 2);
    return Fortran::Parser::make_STRING(content, falk::location());
}

{id} {
    return Fortran::Parser::make_ID(yytext, falk::location());
}

{integer} { 
    auto rvalue = driver.createInteger(yytext);
    return Fortran::Parser::make_INTEGER(std::move(rvalue), falk::location());
}

{real} {
    auto rvalue = driver.createReal(yytext);
    return Fortran::Parser::make_REAL(std::move(rvalue), falk::location());
}

\n {
    return Fortran::Parser::make_NEWLINE(falk::location());
}

. {
    cout << "Scanner: unknown character [" << yytext << "]" << endl;
}

<<EOF>>     { return yyterminate(); }

%%