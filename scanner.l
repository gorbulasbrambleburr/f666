%{
    #include <string>

    /* Implementation of yyFlexScanner */ 
    #include "include/f_scanner.hpp"
    #undef  YY_DECL
    #define YY_DECL int Fortran::Scanner::yylex(Fortran::Parser::semantic_type * const lval,\
                                                Fortran::Parser::location_type *location )

    using token = Fortran::Parser::token;

    /* Default is YY_NULL */
    #define yyterminate() return( token::EOF )

    /* msvc2010 requires that we exclude this header file. */
    #define YY_NO_UNISTD_H

    /* update location on matching */
    #define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option debug
%option nodefault
%option yyclass="Fortran::Scanner"
%option noyywrap
%option c++

letter      [A-Za-z]
digit       [0-9]
integer     [-+]?{digit}+
real        [-+]?({digit}*\.?{digit}+|{digit}+\.)([E]?[-+]?{digit}+)?
id          {letter}({letter}|{digit}|_)*
sliteral    \'([^\\\']|\\.)*\'
comment     "//".*\n
ws          [ \t]+

%%

%{          /** Code executed at the beginning of yylex **/
            yylval = lval;
%}

"PROGRAM"     { return( token::PROGRAM ); }
"SUBROUTINE"  { return( token::SUBROUTINE ); }
"FUNCTION"    { return( token::FUNCTION ); }
"STOP"        { return( token::STOP ); }
"RETURN"      { return( token::RETURN ); }
"END"         { return( token::END ); }
"PARAMETER"   { return( token::PARAMETER ); }
"INTEGER"     { return( token::TYPE_INTEGER ); }
"REAL"        { return( token::TYPE_REAL ); }
"CYCLE"       { return( token::CYCLE ); }
"EXIT"        { return( token::EXIT ); }
"IF"          { return( token::IF ); }
"ELSE"        { return( token::ELSE ); }
"ELSEIF"      { return( token::ELSEIF ); }
"ENDIF"       { return( token::ENDIF ); }
"WHILE"       { return( token::WHILE ); }
"DO"          { return( token::DO ); }
"ENDDO"       { return( token::ENDDO ); }
"PRINT"       { return( token::PRINT ); }
"READ"        { return( token::READ ); }
"CALL"        { return( token::CALL ); }

"+"           { return( token::SUM ); }
"-"           { return( token::SUB ); }
"*"           { return( token::TIMES ); }
"/"           { return( token::DIV ); }
"="           { return( token::ASSIGN ); }
".EQ."        { return( token::EQ ); }
".NE."        { return( token::NE ); }
".GT."        { return( token::GT ); }
".GE."        { return( token::GE ); }
".LT."        { return( token::LT ); }
".LE."        { return( token::LE ); }
".TRUE."      { return( token::TRUE ); }
".FALSE."     { return( token::FALSE ); }
","           { return( token::COMMA ); }
"("           { return( token::LP ); }
")"           { return( token::RP ); }


{ws}        ;
{comment}   ;

{sliteral}  { 
              auto content = std::string(yytext);
              content = content.substr(1, content.size() - 2);
              yylval->build<std::string>(content);
              return( token::STRING );
            }

{id}        {
              yylval->build<std::string>(yytext);
              return(token::ID);
            }

{integer}   { 
              yylval->build<int>(std::atoi(yytext));
              return(token::INTEGER);
            }

{real}      { 
              yylval->build<float>(std::atof(yytext));
              return(token::REAL);
            }

\n          { loc->lines(); return( token::EOL); }

.           { return(token::ERR); }

%%