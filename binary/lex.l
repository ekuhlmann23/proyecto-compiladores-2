%{
#include "y.tab.h"
#include <stdio.h>
extern FILE* yyin;
extern void yyerror(char* s);
%}
%%
[A-Z]+ {
    yylval.stringValue = strdup(yytext);
    return instruccion;
}
[Rr][0-9][0-5]*  {
    yylval.stringValue = strdup(yytext);
    return registro;
}

[0-9][0-5]* {
    yylval.stringValue = strdup(yytext);
    return numero;
}
[()\[\]\n] return *yytext;
[ \t] ;
. yyerror("Símbolo no reconocido.");

%%
int yywrap(void) { return 1; }