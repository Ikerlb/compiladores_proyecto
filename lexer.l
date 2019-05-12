%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
extern void yyerror();

int errcount=0;

/*TODO: for, comma, refactor code, !!BISON!!, yyval correctly*/
/*Nombres asignados en tokens.h, para motivos de depuración*/
char tks[46][15]={"IDENTIFIER","STRUCT",
	     "DOUBLE","FLOAT","INTEGER",
	     "VOID","CHAR","ASSIGN","EQUAL",
	     "NEQUAL","TRUE","FALSE","AND",
	     "OR","NEG","LTHAN","GTHAN","GETHAN",
	     "LETHAN","RPAREN","LPAREN","RBRACKET",
	     "LBRACKET","RSBRACKET","LSBRACKET",
	     "PLUS","MINUS","PROD","DIV","MODULO","DOT",
	     "IF","ELSE","WHILE","DO","RETURN",
	     "SWITCH","BREAK","PRINT","CASE",
	     "DEFAULT","NUMINT","NUMFLOAT","NUMDOUBLE","VALCHAR"
	     ,"VALSTRING"};

/*yyerror, para mostrar los errores léxicos. Estos se manejaran más tarde*/
// void yyerror (int line,char const *s){
//   fprintf (stderr, "Error en caracter %s (Linea %d) --- Se continua con analisis lexico\n",s,line);
// }
%}

%option yylineno
%s COMMENT

%%
<INITIAL>¡\*                      BEGIN(COMMENT);
<COMMENT>\*¿                      BEGIN(INITIAL);
<COMMENT>.						  ;
<COMMENT>[\n]				      ;
<INITIAL>[ \t\n]+                 ;
<INITIAL>"si"                     return(IF);
<INITIAL>"sino"                   return(ELSE);
<INITIAL>"regresa"                return(RETURN);
<INITIAL>"imprime"                return(PRINT);
<INITIAL>"haz"                    return(DO);
<INITIAL>"mientras"               return(WHILE);
<INITIAL>"para"                   return(FOR);
<INITIAL>"rompe"                  return(BREAK);
<INITIAL>"elegir"                 return(SWITCH);
<INITIAL>"caso"                   return(CASE);
<INITIAL>"otro"                   return(DEFAULT);
<INITIAL>"verdadero"              return(TRUE);
<INITIAL>"falso"                  return(FALSE);
<INITIAL>"registro"               return(STRUCT);
<INITIAL>"entero"				  return(INTEGER);
<INITIAL>"flotante"				  return(FLOAT);
<INITIAL>"doble"                  return(DOUBLE);
<INITIAL>"caracter"               return(CHAR);
<INITIAL>"vacio"                  return(VOID);
<INITIAL>";"                      return(SC);
<INITIAL>"="                      return(ASSIGN);
<INITIAL>"=="                     return(EQUAL);
<INITIAL>"!="                     return(NEQUAL);
<INITIAL>"y"                      return(AND);
<INITIAL>"o"					  return(OR);
<INITIAL>"no"					  return(NEG);
<INITIAL>"<"                      return(LTHAN);
<INITIAL>"<="                     return(LETHAN);
<INITIAL>">"                      return(GTHAN);
<INITIAL>">="                     return(GETHAN);
<INITIAL>"+"                      return(PLUS);
<INITIAL>"-"                      return(MINUS);
<INITIAL>"*"                      return(PROD);
<INITIAL>"/"                      return(DIV);
<INITIAL>"%"                      return(MODULO);
<INITIAL>"("                      return(LPAREN);
<INITIAL>")"                      return(RPAREN);
<INITIAL>"{"                      return(LBRACKET);
<INITIAL>"}"                      return(RBRACKET);
<INITIAL>"["                      return(LSBRACKET);
<INITIAL>"]"                      return(RSBRACKET);
<INITIAL>":"                      return(COLON);
<INITIAL>"."                      return(DOT);
<INITIAL>","                      return(COMMA);
<INITIAL>[a-zA-Z][a-zA-Z0-9]*     return(ID); /*Cualquier cadena que comience con una letra y le continue cualquier cantidad de caracteres alphanumericos*/
<INITIAL>[-+]?[0-9]+              return(NUMINT); /*Cualquier numero entero, sin importar su tamaño*/
<INITIAL>[-+]?[0-9]*[.][0-9]+[Ff] return(NUMFLOAT); /*Cualquier número decimal, sin importar su tamaño pero debe de terminar con F ó f*/
<INITIAL>[-+]?[0-9]*[.][0-9]+     return(NUMDOUBLE); /*Cualquier número decimal, sin importar su tamaño */
<INITIAL>\'(\\.|[^"\\])\'         return(VALCHAR); /*Un único caracter de la siguiente forma 'c'*/
<INITIAL>\"(\\.|[^"\\])*\"        return(VALSTRING); /*Sucesión de caracteres. Incluso la sucesición vacia*/
<INITIAL>.                        {errcount+=1;yyerror(yylineno,yytext);} /*No soportado*/
%%

int yywrap(void)
{
    return 1;
}

// int main(int argc, char** argv){
// 	FILE* f;
// 	FILE* o;
// 	if(argc>1){
// 		if((f=fopen(argv[1],"r"))==0)
// 			fprintf(stderr,"Error abriendo archivo");
// 	}
// 	else
// 		fprintf(stderr,"Error el archivo se debe de pasar como un argumento.");

// 	yyin=f;

// 	// int rs=yylex();
// 	// while(rs){
// 	// 	printf("Token: (%s,%s)\n",tks[rs-263],yytext);
// 	// 	rs=yylex();
// 	// }

// 	if(errcount>0){
// 		fprintf(stderr,"Hubo un total de %d errores\n",errcount);
// 	}
// 	else{
// 		printf("Analisis lexico concluido exitosamente\n"); 
// 	}

// 	fclose(yyin);
// }