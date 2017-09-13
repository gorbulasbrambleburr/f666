%option     outfile="scanner.cxx"
%option header-file="scanner.hxx"

%option c++
%option 8bit warn nodefault
%option noyywrap

/* code that only goes into the implementation file */
%{
    #include <stdexcept>
    #include "parser.hxx"
    #include "scanner.hpp"

    // utility macros to simplify the actions
    #define YIELD_TOKEN(tok, val, type)     yylval->build<type>(val); \
                                            return yy::parser::token::T_##tok;

    #define YY_TXT                  std::string(yytext, yyleng)
    #define YY_INT                  std::atoi(yytext)
    #define YY_FLOAT                std::atof(yytext)

    #define TOKEN(tok, val)     YIELD_TOKEN(tok, val, int)
    #define INT_TOKEN(tok)          YIELD_TOKEN(tok, YY_INT, int)
    #define FLOAT_TOKEN(tok)        YIELD_TOKEN(tok, YY_FLOAT, float)
    #define STR_TOKEN(tok)          YIELD_TOKEN(tok, YY_TXT, std::string)
    #define LITERAL                 return yytext[0];

    #define YY_USER_ACTION          yylloc->columns(yyleng);
%}

letter      [A-Za-z]
digit       [0-9]
integer     [-+]?{digit}+
real        [-+]?({digit}*\.?{digit}+|{digit}+\.)([E]?[-+]?{digit}+)?
id          {letter}({letter}|{digit}|_)*
sliteral    \'([^\\\']|\\.)*\'
comment     "//".*\n
ws          [ \t]+


%%

/* code to be executed at every yylex() call */
%{
    yylloc->step();
%}

"PROGRAM"     { return( yy::parser::token::T_##PROGRAM ); }
"SUBROUTINE"  { return( yy::parser::token::T_##SUBROUTINE ); }
"FUNCTION"    { return( yy::parser::token::T_##FUNCTION ); }
"STOP"        { return( yy::parser::token::T_##STOP ); }
"RETURN"      { return( yy::parser::token::T_##RETURN ); }
"END"         { return( yy::parser::token::T_##END ); }
"PARAMETER"   { return( yy::parser::token::T_##PARAMETER ); }
"INTEGER"     { return( yy::parser::token::T_##INTEGER ); }
"REAL"        { return( yy::parser::token::T_##REAL ); }
"CYCLE"       { return( yy::parser::token::T_##CYCLE ); }
"EXIT"        { return( yy::parser::token::T_##EXIT ); }
"IF"          { return( yy::parser::token::T_##IF ); }
"ELSE"        { return( yy::parser::token::T_##ELSE ); }
"ELSEIF"      { return( yy::parser::token::T_##ELSEIF ); }
"ENDIF"       { return( yy::parser::token::T_##ENDIF ); }
"WHILE"       { return( yy::parser::token::T_##WHILE ); }
"DO"          { return( yy::parser::token::T_##DO ); }
"ENDDO"       { return( yy::parser::token::T_##ENDDO ); }
"PRINT"       { return( yy::parser::token::T_##PRINT ); }
"READ"        { return( yy::parser::token::T_##READ ); }
"CALL"        { return( yy::parser::token::T_##CALL ); }

"+"           TOKEN(yy::parser::token::T_##ADD, ast::SIGN_SUM)
"-"           TOKEN(yy::parser::token::T_##SUB, ast::SIGN_SUB)
"*"           TOKEN(yy::parser::token::T_##TIMES, ast::SIGN_TIMES)
"/"           TOKEN(yy::parser::token::T_##DIV, ast::SIGN_DIV)
"="           TOKEN(yy::parser::token::T_##ASSIGN, ast::SIGN_ASSIGN)
".EQ."        TOKEN(yy::parser::token::T_##EQ, ast::REL_EQ)
".NE."        TOKEN(yy::parser::token::T_##NE, ast::REL_NE)
".GT."        TOKEN(yy::parser::token::T_##GT, ast::REL_GT)
".GE."        TOKEN(yy::parser::token::T_##GE, ast::REL_GE)
".LT."        TOKEN(yy::parser::token::T_##LT, ast::REL_LT)
".LE."        TOKEN(yy::parser::token::T_##LE, ast::REL_LE)
".TRUE."      TOKEN(yy::parser::token::T_##TRUE, ast::BOOLEAN_TRUE)
".FALSE."     TOKEN(yy::parser::token::T_##FALSE, ast::BOOLEAN_FALSE)
","           TOKEN(yy::parser::token::T_##COMMA, ast::COMMA)
"("           TOKEN(yy::parser::token::T_##LP, ast::LP)
")"           TOKEN(yy::parser::token::T_##RP, ast::RP)

{ws}        ;
{comment}   ;

{sliteral}  { 
              auto content = std::string(yytext);
              content = content.substr(1, content.size() - 2);
              yylval->build<std::string>( content );
              return( yy::parser::token::T_##STRING );
            }

{id}        STR_TOKEN(ID)

{integer}   { 
              yylval->build<int>(std::atoi(yytext));
              return( yy::parser::token::T_##INT );
            }

{real}      { 
              yylval->build<float>(std::atof(yytext));
              return( yy::parser::token::T_##FLOAT );
            }

\n          { yylloc->lines(1); return( token::EOL); }

.           { return( yy::parser::token::T_##ERR ); }



==?         TOKEN(REL, ast::REL_EQ)
\<=         TOKEN(REL, ast::REL_LE)
\>=         TOKEN(REL, ast::REL_GE)

%%

yy::scanner::scanner(std::istream* in, std::ostream* out)
    : yyFlexLexer(in, out)
{
}

int yyFlexLexer::yylex()
{
    throw std::logic_error(
        "The yylex() exists for technical reasons and must not be used.");
}
