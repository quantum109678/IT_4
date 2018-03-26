%{
#include "y.tab.h"
#include<string.h>
%}

%%

"return"    {return Return;}
"if"        {return If;}
"while"     {return While;}
[a-zA-Z]+   {strcpy(yylval.na,yytext); return symb;}
[0-9]+      {yylval.num = atoi(yytext); return value;}
[\n]        {return yytext[0];}
[ \t]       {;}
"=="	    {yylval.id='e'; return OP;}
[\*+<]       {yylval.id=yytext[0] ; return OP;}
[\]\[=]     {return yytext[0] ;}
[;]	    {return yytext[0];}
.           {ECHO; yyerror ("unexpected character");}

%%
int yywrap (void) {return 1;}

