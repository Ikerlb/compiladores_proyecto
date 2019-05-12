%{
#include "vector.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*symbol table register*/
typedef struct{
    char id[20];
    int type;
    int dir;
} symreg;

/*type table register*/
typedef struct{
    char type[20];
    int base_type;
    int size;
    int elem_num;
} typereg;

/*vector that will contain symregs*/
vector symtable;
/*vector that will contain typeregs*/
vector typetable;

extern FILE *yyin;
extern int errcount;

void yyerror(char *s){
	fprintf(stderr, "error: %s\n", s);
}

%}

%token IF ELSE RETURN 
%token PRINT DO WHILE 
%token FOR CASE DEFAULT 
%token TRUE FALSE STRUCT
%token INTEGER FLOAT 
%token DOUBLE CHAR VOID
%token SC ASSIGN EQUAL
%token NEQUAL AND OR
%token NEG LTHAN LETHAN
%token GTHAN GETHAN PLUS
%token MINUS PROD DIV MODULO
%token LPAREN RPAREN LBRACKET
%token RBRACKET LSBRACKET RSBRACKET
%token DOT COMMA ID NUMINT NUMFLOAT
%token NUMDOUBLE VALCHAR VALSTRING
%token FUNC SWITCH BREAK COLON

%left PLUS MINUS AND OR
%left PROD DIV MODULO
%right NEG

%%

/*programa -> Declaraciones Funciones*/
/*INCOMPLETE! MISSING FUNCTIONS*/
Program : Declarations Functions

/*declaraciones -> Tipo Lista; | epsilon */
Declarations : | Type List SC

/*tipo -> int | float | double | char | void */
Type : INTEGER | FLOAT | DOUBLE | CHAR | VOID

/*lista -> lista, id arreglo| id arreglo*/
List : List COMMA ID Array | ID Array

/*arreglo -> [numero] arreglo | epsilon*/
Array : LSBRACKET NUMINT RSBRACKET Array | 

/*funciones -> func tipo id(argumentos){declaraciones sentencias} funciones | epsilon*/
Functions : | FUNC Type ID LPAREN Args RPAREN LBRACKET Declarations Statements RBRACKET Functions

Args : | ListArgs

ListArgs : ListArgs COMMA Type ID ArrayPart | Type ID ArrayPart

ArrayPart : | LSBRACKET RSBRACKET ArrayPart

/*NOTE SWITCH IS ILL DEFINED! Report it*/
Statements : IF LPAREN Condition RPAREN Statements 
			| IF LPAREN Condition RPAREN Statements ELSE Statements
			| WHILE LPAREN Condition RPAREN Statements 
			| DO Statements WHILE LPAREN Condition RPAREN SC
			| FOR LPAREN Statements SC Condition SC Statements RPAREN Statements
			| LeftPart ASSIGN Expression SC | RETURN Expression SC
			| RETURN SC | LBRACKET Statements RBRACKET
			| SWITCH LPAREN Expression RPAREN LBRACKET Cases RBRACKET 
			| BREAK SC | PRINT Expression

Cases : | CASE NUMINT COLON Statements Default

Default : | DEFAULT COLON Statements

LeftPart : ID | ArrayVar | ID DOT ID

ArrayVar : ID LSBRACKET Expression RSBRACKET | ArrayVar LSBRACKET Expression RSBRACKET

/*Expresiones*/
Expression : Expression PLUS Expression | Expression MINUS Expression 
			 | Expression PROD Expression | Expression DIV Expression
			 | Expression MODULO Expression | VALSTRING | CHAR | NUMINT 
			 | NUMDOUBLE | NUMFLOAT | ID LPAREN Params RPAREN

/*Params -> lista_parametros | Epsilon*/
Params : | ListParams

/*Lista_parametros -> lista_parametros, expresion | expresion*/
ListParams : ListParams COMMA Expression | Expression

Condition : Condition OR Condition | Condition AND Condition 
			| NEG Condition | LPAREN Condition RPAREN
			| Expression Relational Expression | TRUE | FALSE

Relational : LTHAN | GTHAN | GETHAN | LETHAN | NEQUAL | EQUAL



%%

/*push a typereg struct to the typetable*/
void typetable_push(typereg* tr){
	typereg* ptr=(typereg*)malloc(sizeof(typereg));
	*ptr=(*tr);
	vector_add(&typetable,ptr);
}

/*initially only int float double and char values*/
void typetable_init(){
	vector_init(&typetable);
	typereg int_type={"int",-1,4,-1};
	typetable_push(&int_type);
	typereg float_type={"float",-1,4,-1};
	typetable_push(&float_type);
	typereg double_type={"double",-1,8,-1};
	typetable_push(&double_type);
	typereg char_type={"char",-1,1,-1};
	typetable_push(&char_type);
}

/*free memory allocated by typeregs and vector*/
void typetable_free(){
	int i;
	for (i = 0; i < vector_total(&typetable); i++)
        free((typereg*)vector_get(&typetable,i));
    vector_free(&typetable);
}

/*push a symreg into the symbol table*/
void symtable_push(symreg* sr){
	symreg* psr=(symreg*)malloc(sizeof(typereg));
	*psr=(*sr);
	vector_add(&symtable,psr);
}

/*create a new symreg. it depends on symtable last entry*/
symreg symreg_new(char* id,int type){
	int ts,nd,vt;
	vt=vector_total(&symtable)-1;
	if(vt==-1)
		nd=0;
	else{
		symreg* le=(symreg*)vector_get(&symtable,vt);
		ts=((typereg*)vector_get(&typetable,le->type))->size;
		nd=(le->dir)+ts;
	}
	//works?
	symreg nsr={"",type,nd};
	strcpy(nsr.id,id);
	return nsr;
}

/*linear search, improve!*/
/*reports index of id if it exists on symtable*/
int symtable_exists(char* id){
	int i;
	for (i = 0; i < vector_total(&symtable); i++){
		char* cs=((symreg*)vector_get(&symtable,i))->id;
		if(strcmp(id,cs)==0)
			return i;
	}
	return -1;
}

/*free allocated symregs and vector*/
void symtable_free(){
	int i;
	for (i = 0; i < vector_total(&symtable); i++)
        free((symreg*)vector_get(&symtable,i));
    vector_free(&symtable);
}

int main(int argc, char** argv){
	FILE* f;
	FILE* o;
	if(argc>1){
		if((f=fopen(argv[1],"r"))==0)
			fprintf(stderr,"Error abriendo archivo\n");
	}
	else{
		fprintf(stderr,"Error el archivo se debe de pasar como un argumento.\n");
		return 0;
	}

	yyin=f;

	vector_init(&symtable);
	typetable_init();

	//test
	// symreg sr1=symreg_new("abcdefghijk",0);
	// symtable_push(&sr1);
	// printf("%s\n",sr1.id);

	yyparse();

	symtable_free();
	typetable_free();


	if(errcount>0)
		fprintf(stderr,"Hubo un total de %d errores\n",errcount);
	else
		printf("Analisis lexico concluido exitosamente\n"); 

	fclose(yyin);
}