%{
    #include <iostream>
    #include <cstdlib>
    #include "f_scanner.hpp"
    #include "f_driver.hpp"
    #include "f_parser.hpp"
    #include "location.hh"

    #include <string>

    // Original yyterminate() macro returns int. Since we're using Bison 3 variants
    // as tokens, we must redefine it to change type from `int` to `Parser::semantic_type`
    #define yyterminate() Fortran::Parser::make_EOF(Fortran::location());

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
newline     \n

%%

"PROGRAM" {
    return Fortran::Parser::make_PROGRAM(Fortran::location());
}

"SUBROUTINE" {
    return Fortran::Parser::make_SUBROUTINE(Fortran::location());
}

"FUNCTION" {
    return Fortran::Parser::make_FUNCTION(Fortran::location());
}

"STOP" {
    return Fortran::Parser::make_STOP(Fortran::location());
}

"RETURN" {
    return Fortran::Parser::make_RETURN(Fortran::location());
}

"END" {
    return Fortran::Parser::make_END(Fortran::location());
}

"PARAMETER" {
    return Fortran::Parser::make_PARAMETER(Fortran::location());
}

"INTEGER" {
    return Fortran::Parser::make_TYPE(Fortran::type::INTEGER, Fortran::location());
}

"REAL" {
    return Fortran::Parser::make_TYPE(Fortran::type::REAL, Fortran::location());
}

"BOOLEAN" {
    return Fortran::Parser::make_TYPE(Fortran::type::BOOLEAN, Fortran::location());
}

"CYCLE" {
    return Fortran::Parser::make_CYCLE(Fortran::location());
}

"EXIT" {
    return Fortran::Parser::make_EXIT(Fortran::location());
}

"IF" {
    return Fortran::Parser::make_IF(Fortran::location());
}

"THEN" {
    return Fortran::Parser::make_THEN(Fortran::location());
}

"ELSE" {
    return Fortran::Parser::make_ELSE(Fortran::location());
}

"ELSEIF" {
    return Fortran::Parser::make_ELSEIF(Fortran::location());
}

"ENDIF" {
    return Fortran::Parser::make_ENDIF(Fortran::location());
}

"WHILE" {
    return Fortran::Parser::make_WHILE(Fortran::location());
}

"DO" {
    return Fortran::Parser::make_DO(Fortran::location());
}

"ENDDO" {
    return Fortran::Parser::make_ENDDO(Fortran::location());
}

"PRINT" {
    return Fortran::Parser::make_PRINT(Fortran::location());
}

"READ" {
    return Fortran::Parser::make_READ(Fortran::location());
}

"CALL" {
    return Fortran::Parser::make_CALL(Fortran::location());
}


"+" {
    return Fortran::Parser::make_PLUS(Fortran::op::arithmetic::ADD, Fortran::location());
}

"-" {
    return Fortran::Parser::make_MINUS(Fortran::op::arithmetic::SUB, Fortran::location());
}

"*" {
    return Fortran::Parser::make_TIMES(Fortran::op::arithmetic::MUL, Fortran::location());
}

"/" {
    return Fortran::Parser::make_DIVIDE(Fortran::op::arithmetic::DIV, Fortran::location());
}

"=" {
    return Fortran::Parser::make_ASSIGN(Fortran::location());
}

".EQ." {
    return Fortran::Parser::make_COMPARISON(Fortran::op::comp::EQ, Fortran::location());
}

".NE." {
    return Fortran::Parser::make_COMPARISON(Fortran::op::comp::NE, Fortran::location());
}

".GT." {
    return Fortran::Parser::make_COMPARISON(Fortran::op::comp::GT, Fortran::location());
}

".GE." {
    return Fortran::Parser::make_COMPARISON(Fortran::op::comp::GE, Fortran::location());
}

".LT." {
    return Fortran::Parser::make_COMPARISON(Fortran::op::comp::LT, Fortran::location());
}

".LE." {
    return Fortran::Parser::make_COMPARISON(Fortran::op::comp::LE, Fortran::location());
}

".TRUE." {
    auto rvalue = m_driver.createBoolean(yytext);
    return Fortran::Parser::make_BOOLEAN(std::move(rvalue), Fortran::location());
}

".FALSE." {
    auto rvalue = m_driver.createBoolean(yytext);
    return Fortran::Parser::make_BOOLEAN(std::move(rvalue), Fortran::location());
}

"," {
    return Fortran::Parser::make_COMMA(Fortran::location());
}

"(" {
    return Fortran::Parser::make_LP(Fortran::location());
}

")" {
    return Fortran::Parser::make_RP(Fortran::location());
}



{ws}      ;
{comment} ;
{newline} ;

{sliteral} {
    auto content = std::string(yytext);
    content = content.substr(1, content.size() - 2);
    return Fortran::Parser::make_STRING(content, Fortran::location());
}

{id} {
    return Fortran::Parser::make_ID(yytext, Fortran::location());
}

{integer} { 
    auto rvalue = m_driver.createInteger(yytext);
    return Fortran::Parser::make_INTEGER(std::move(rvalue), Fortran::location());
}

{real} {
    auto rvalue = m_driver.createReal(yytext);
    return Fortran::Parser::make_REAL(std::move(rvalue), Fortran::location());
}

. {
    std::cout << "Scanner: unknown character [" << yytext << "]" << std::endl;
}

<<EOF>>     { return yyterminate(); }

%%