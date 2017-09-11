%option noyywrap
%{
#include <stdio.h>
%}

letter      [A-Za-z]
digit       [0-9]
number      [-+]?({digit}*\.?{digit}+|{digit}+\.)([E]?[-+]?{digit}+)?
id          {letter}({letter}|{digit}|_)*
sliteral    \'([^\\\']|\\.)*\'
comment     "//".*\n
ws          [ \t]+
%%

"PROGRAM"       { printf(" RES "); }
"SUBROUTINE"    { printf(" RES "); }
"FUNCTION"      { printf(" RES "); }
"STOP"          { printf(" RES "); }
"RETURN"        { printf(" RES "); }
"END"           { printf(" RES "); }
"PARAMETER"     { printf(" RES "); }
"INTEGER"       { printf(" RES "); }
"REAL"          { printf(" RES "); }
"CYCLE"         { printf(" RES "); }
"EXIT"          { printf(" RES "); }
"IF"            { printf(" RES "); }
"ELSE"          { printf(" RES "); }
"ELSEIF"        { printf(" RES "); }
"ENDIF"         { printf(" RES "); }
"WHILE"         { printf(" RES "); }
"DO"            { printf(" RES "); }
"ENDDO"         { printf(" RES "); }
"PRINT"         { printf(" RES "); }
"READ"          { printf(" RES "); }
"CALL"          { printf(" RES "); }

"+"     { printf(" OP "); }
"-"     { printf(" OP "); }
"*"     { printf(" OP "); }
"/"     { printf(" OP "); }
"="     { printf(" OP "); }
".EQ."  { printf(" OP "); }
".NE."  { printf(" OP "); }
".GT."  { printf(" OP "); }
".GE."  { printf(" OP "); }
".LT."  { printf(" OP "); }
".LE."  { printf(" OP "); }

"," { printf(" PUNK "); }
"(" { printf(" PUNK "); }
")" { printf(" PUNK "); }

".TRUE." { printf(" LOG_VALUE "); }
".FALSE." { printf(" LOG_VALUE "); }

{ws}        { /* ignore whitespace */ }
{comment}   { printf(" COMMENT EOL\n"); }
{sliteral}  { printf(" STRING_LITERAL "); }
{id}        { printf(" ID "); }
{number}    { printf(" NUM "); }
\n          { printf(" EOL\n"); }
.           { printf(" ERR "); }

%%

int main (int argc, char *argv[]) {
    if (argc > 1) {
        if (!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return (1);
        }
    } else {
        printf("Missing input file.\n");
        return (1);
    }
    yylex();
    printf("\n");
    return (0);
}
