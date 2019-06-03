%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
extern void yyerror();

int errcount=0;

/*TODO: for, comma, refactor code, !!BISON!!, yyval correctly*/
/*parser.tab.c enum of tokens*/

char toks[51][11]={"IF","ELSE","RETURN","PRINT",
"DO","WHILE","FOR","CASE","DEFAULT",
"TRUE","FALSE","STRUCT","INTEGER","FLOAT",
"DOUBLE","CHAR","VOID","SC","ASSIGN",
"EQUAL","NEQUAL","AND","OR","NEG","LTHAN",
"LETHAN","GTHAN","GETHAN","PLUS","MINUS",
"PROD","DIV","MODULO","LPAREN","RPAREN",
"LBRACKET","RBRACKET","LSBRACKET","RSBRACKET",
"DOT","COMMA","ID","NUMINT","NUMFLOAT",
"NUMDOUBLE","VALCHAR","VALSTRING","FUNC",
"SWITCH","BREAK","COLON"};
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
<INITIAL>"func"                   return(FUNC);
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
<INITIAL>[a-zA-Z][a-zA-Z0-9]*     {strcpy(yylval.lexval, yytext);return(ID);} /*Cualquier cadena que comience con una letra y le continue cualquier cantidad de caracteres alphanumericos*/
<INITIAL>[-+]?[0-9]+              {yylval.numint=atoi(yytext);return(NUMINT);} /*Cualquier numero entero, sin importar su tamaño*/
<INITIAL>[-+]?[0-9]*[.][0-9]+[Ff] {yylval.numfloat=atof(yytext);return(NUMFLOAT);} /*Cualquier número decimal, sin importar su tamaño pero debe de terminar con F ó f*/
<INITIAL>[-+]?[0-9]*[.][0-9]+     {yylval.numdouble=atof(yytext);return(NUMDOUBLE);} /*Cualquier número decimal, sin importar su tamaño */
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

// 	int rs=yylex();
// 	while(rs){
// 		printf("Token: (%s,%d,%s)\n",toks[rs-258],rs,yytext);
// 		rs=yylex();
// 	}

// 	if(errcount>0){
// 		fprintf(stderr,"Hubo un total de %d errores\n",errcount);
// 	}
// 	else{
// 		printf("Analisis lexico concluido exitosamente\n"); 
// 	}

// 	fclose(yyin);
// }