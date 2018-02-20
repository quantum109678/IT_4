%{
void yyerror (char *s);
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include<string.h>
int evaluate(char operator, int a, int b);
struct symbol_table
{ char name[10];
  int Value;
}symbols[10],temp;
int symbolVal(char symbol[]);
int ccount=0;
void updateSymbolVal(char symbol[], int val);
int flagif=1;
%}

%union {int num; char id; char na[10];}         /* Yacc definitions */
%start start
%token Return
%token If
%token While
%token <num> value
%token <id> OP
%token <na> symb
%type <num>   exp 


%%

/* descriptions of expected inputs     corresponding actions (in C) */

start	: prog | exp

prog 	: '[' '=' symb exp ']'    { 
				    if (flagif)
				    updateSymbolVal($3,$4);
				    }
	| '[' ';' prog prog ']'   	 		
 

	| '[' Return exp ']' 		       {  if(flagif)
 						  { printf("%d\n",$3); exit(0);}}
						 
	| prog '\n'			         {exit(0);}
	
	| '[' U prog ']'			

U 	: T prog                { flagif=1;}

 T 	:  If exp   	{  if ($2==0) 
			    {flagif=0;} }


exp    	: '[' OP exp exp ']'                {if(flagif) $$=evaluate($2,$3,$4);}
       	               
	| symb                                 {if(flagif) $$=symbolVal($1);}
	
 	| exp '\n'			{if(flagif) printf("%d\n",$1); exit(0);}
	
	| value					 {if(flagif) $$=$1;}

        ;
%%                     /* C code */
int evaluate(char operator,int a ,int b)
{ switch(operator)
 { case '+' : return(a+b);
   case '*' : return(a*b);
   case '<': if(a<b)
	     return(1);
	     else
	     return (0);
   case 'e' : if(a==b)
	     return(1);
 	     else
	     return(0);
   }
}		
int main (void) {
	/* init symbol table */
	int i;

	return yyparse ( );
}

/* returns the value of a given symbol */
int symbolVal(char symbol[])
{        
	int bucket;
	for(bucket=0;bucket<ccount;bucket++)
	{ if(strcmp(symbols[bucket].name,symbol)==0)
  	  return symbols[bucket].Value;
		
	}
	 
	return -128;
}

/* updates the value of a given symbol */
void updateSymbolVal(char symbol[], int val)
{  int bucket;
	for(bucket=0;bucket<ccount;bucket++)
	{ if(strcmp(symbols[bucket].name,symbol)==0)
  		{symbols[bucket].Value = val;
		
		return ;}
	}
        
	 strcpy(symbols[ccount].name,symbol);
	  symbols[ccount].Value=val;
	  ccount+=1;

	
}




void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 

