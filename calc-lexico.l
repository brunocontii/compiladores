%{

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "calc-sintaxis.tab.h"

%}

%option noyywrap
%option yylineno

letra [a-zA-Z]
num [0-9]
%%

"int"	{ 
			printf("INT : %s\n",yytext);
			return TOKEN_INT;
		}

"bool" 	{ printf("BOOL : %s\n",yytext); return TOKEN_BOOL; }

"void" 	{ printf("VOID : %s\n",yytext); return TOKEN_VOID;}

"main" 	{ printf("MAIN : %s\n",yytext); return TOKEN_MAIN; }

"return"	{ printf("RETURN : %s\n",yytext); return TOKEN_RETURN; }

{letra}({letra}|{num})*		{ 
								printf("ID : %s\n",yytext);
								yylval.sval = strdup(yytext); // para copiar el valor de yytext
								return TOKEN_ID;
							}

{num}+ 	{ 
			printf("NUM : %s\n",yytext);
			yylval.ival = atoi(yytext); // para convertir yytext en un int
			return TOKEN_NUM;
		}

"-"	{ printf("OP_RES : %s\n",yytext); return TOKEN_OP_RES; }

"+"	{ printf("OP_MAS : %s\n",yytext); return TOKEN_OP_MAS; }

"*"	{ printf("OP_MULT : %s\n",yytext); return TOKEN_OP_MULT; }

"/"	{ printf("OP_DIV : %s\n",yytext); return TOKEN_OP_DIV; }

";"	{ printf("PYC : %s\n",yytext); return TOKEN_PYC; }

"("	{ printf("PAR_A : %s\n",yytext); return TOKEN_PAR_A; }

")"	{ printf("PAR_C : %s\n",yytext); return TOKEN_PAR_C; }

"{"	{ printf("LLA_A : %s\n",yytext); return TOKEN_LLA_A; }

"}"	{ printf("LLA_C : %s\n",yytext); return TOKEN_LLA_C; }

"="	{ printf("IGUAL : %s\n",yytext); return TOKEN_IGUAL; }

[ \t]+						;
.|\n                          ; /* ignore all the rest */


%%

void yyerror(){
	printf("%s%d\n","-> ERROR Sintactico en la linea: ",yylineno);
}

int main(int argc,char *argv[]){
	++argv,--argc;
	if (argc > 0)
		yyin = fopen(argv[0],"r");
	else
		yyin = stdin;

	yyparse();

}
