%{
#define DEBUG_MODE 1

#include "vector.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


extern char* yytext;
extern int yylex();
extern int yylineno;
extern FILE *yyin;
extern int errcount;

/*TODO: get rid of ts, maintain only stack*/
/*ts -> Table de simbolos actual*/
vector* ts;
/*env -> Stack de TS*/
vector* env;

vector* tt;

/*Offset -> dirección relativa*/
unsigned int* offset;
/*Stack -> Stack de offset*/
vector* stack;


unsigned int temp=0;
unsigned int label=0;

void yyerror(char*);



%}

%code requires {
	/*eww get rid of this*/
	#include "vector.h"
	typedef struct type{
	    char name[32];
	    struct type* base;
	    int width;
	    int elem_num;
	    /*struct sym table*/
	    vector* ts;
	} type;

	typedef struct{
    	char id[32];
    	char var_type[32];
    	type* type;
    	int dir;
    	int args;
    	vector* lts;
	} sym;

	/*TEMPS I DONT KNOW HOW TO HANDLE YET */
	/*FOR INSTANCE INHERITED ATTRIBUTES*/
	type* t;
	int functionAlreadyUsed;

	/*functions used withing semantic actions*/
	type* insertType(type*);
	sym* insertSymbol(char*,type*,char*);
	sym* insertFunction(char*,type*,char*,vector*,int);
	sym* lookupSymbol(char*);
	int existsSymbol(char*);
	void push(vector*,void*);
	vector* newSymbolTable();
	void print_symbol_table();
	void* pop(vector*);
	void* top(vector*);
	unsigned int* newOffset();
}

%union{
	type* tipo;
	char lexval[32];
	double numdouble;
	float numfloat;
	int numint;
	int args;
	struct {
		type* tipo;
		char dir[32];
	} exp;
}

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
%left LPAREN RPAREN
%left IF
%left ELSE

%type<args> Args ListArgs
%type<exp> Expression
%type<tipo> Array
%type<lexval> ID
%type<numint> NUMINT
%type<numfloat> NUMFLOAT
%type<numdouble> NUMDOUBLE
//%define parse.error verbose

%%

/*programa -> Declaraciones Funciones*/
Program : Declarations Functions 

/*declaraciones -> Tipo Lista; Declaraciones | epsilon */
Declarations : 
				| Type List SC  Declarations

/*type not necessary!! just testing!!*/
/*tipo -> int | float | double | char | void */
Type :    INTEGER 								{t=(type*)vector_get(tt,1);}
		| FLOAT   								{t=(type*)vector_get(tt,2);}
	  	| DOUBLE  								{t=(type*)vector_get(tt,3);}
	  	| CHAR    								{t=(type*)vector_get(tt,4);}
	  	| VOID    								{t=(type*)vector_get(tt,0);}
	  	| STRUCT 								{
	  												push(env,(void*)ts);
													push(stack,(void*)offset);

													offset=newOffset();
													ts=newSymbolTable();
												}
	  	LBRACKET Declarations RBRACKET 			{
	  												type nt={"register",NULL,*offset,-1,ts};
	  												ts=(vector*)pop(env);
	  												offset=(unsigned int*)pop(stack);
	  												t=insertType(&nt);
	  											}

/*lista -> lista, id arreglo| id arreglo*/
	  							/*This declarations are global!!*/
List :    List COMMA ID Array  {
									char buff[100];
									if(strcmp(t->name,"void")!=0){

								   		if(existsSymbol($3)==-1){
								   			insertSymbol($3,$4,"var");
								   		}
								   		else{
								   			
								   			sprintf(buff,"Id %s has been already declared",$3);
								   			yyerror(buff);
								   		}
								   	}
								   	else{
								   		sprintf(buff,"Id %s can't be of type void",$3);
								   		yyerror(buff);
								   	}
							   }
 		| ID Array             {
 									char buff[100];
 									if(strcmp(t->name,"void")!=0){
								   		if(existsSymbol($1)==-1){
								   			insertSymbol($1,$2,"var");
								   		}
								   		else{
								   			char buff[100];
								   			sprintf(buff,"Id %s has been already declared",$1);
								   			yyerror(buff);
								   		}
								   	}
								   	else{
								   		sprintf(buff,"Id %s can't be of type void",$1);
								   		yyerror(buff);
								   	}
 							   }

/*arreglo -> [numero] arreglo | epsilon*/
Array :   /*epsilon*/                       {$$=t;}
		| LSBRACKET NUMINT RSBRACKET Array  {
												if($2>=0){
													int nw=$2*($4->width);
													type nt={"array",$4,nw,$2,NULL};
													/*TODO: Duplicates! eg i[3] and j[3] have same type!*/
													$$=insertType(&nt);
												}
												else{
													yyerror("Arrays can't be negative size");
												}
										    }

/*funciones -> func tipo id(argumentos){declaraciones sentencias} funciones | epsilon*/
Functions : 
			| FUNC	Type ID LPAREN									{
																			if(existsSymbol($3)>-1)
																				functionAlreadyUsed=1;
																			else{
																				push(env,(void*)ts);
																				push(stack,(void*)offset);
																				offset=newOffset();
																				ts=newSymbolTable();
																			}
																		}
			Args 														{}
			RPAREN LBRACKET Declarations Statements RBRACKET Functions {
																			printf("Symbol table for %s\n",$3);
																			print_symbol_table();
																			if(functionAlreadyUsed==0){
																				vector* prev=ts;
																				ts=(vector*)pop(env);
																				offset=(unsigned int*)pop(stack);
																				insertFunction($3,t,"function",prev,$6);
																			}
																			else{
																	   			char buff[100];
																	   			sprintf(buff,"Id %s has been already declared",$3);
																	   			yyerror(buff);
																	   		}
			 															}
			
			

Args :   /*epsilon*/ {$$=0;}
		| ListArgs   {$$=$1;}

ListArgs :    ListArgs COMMA Type ID   {
											$$=$1+1;
											if(existsSymbol($4)==-1)
												insertSymbol($4,t,"arg");
											else
												yyerror("Repeated argument name");
													
										}
			| Type ID 					{
											$$=1;
											if(existsSymbol($2)==-1)
											insertSymbol($2,t,"arg");
											else
												yyerror("Repeated argument name");
										}

Statements :  Statements Statement 
			| Statement

Statement :   IF LPAREN Condition RPAREN Statement
			| IF LPAREN Condition RPAREN Statement ELSE Statement
			| WHILE LPAREN Condition RPAREN Statement
			| DO Statement WHILE LPAREN Condition RPAREN SC
			| FOR LPAREN Statement SC Condition SC Statement RPAREN Statement
			| LeftPart ASSIGN Expression SC | RETURN Expression SC
			| RETURN SC | LBRACKET Statements RBRACKET
			| SWITCH LPAREN Expression RPAREN LBRACKET Cases RBRACKET 
			| BREAK SC | PRINT Expression

Cases : 
		| CASE NUMINT COLON Statements Default

Default : 
			| DEFAULT COLON Statements

LeftPart :    ID 
			| ArrayVar 
			| ID DOT ID

ArrayVar :    ID LSBRACKET Expression RSBRACKET 
			| ArrayVar LSBRACKET Expression RSBRACKET

/*Expresiones MISSING ID?*/
Expression :  Expression PLUS Expression   {}
			| Expression MINUS Expression  {}
			| Expression PROD Expression   {}
			| Expression DIV Expression    {}
			| Expression MODULO Expression {}
			| VALSTRING                    {}
			| CHAR                         {}
			| NUMINT                       {$$.tipo=(type*)vector_get(tt,1);}
			| NUMDOUBLE                    {$$.tipo=(type*)vector_get(tt,3);}
			| NUMFLOAT                     {$$.tipo=(type*)vector_get(tt,2);}
			| ID LPAREN Params RPAREN      {}

/*Params -> lista_parametros | Epsilon*/
Params : | ListParams

/*Lista_parametros -> lista_parametros, expresion | expresion*/
ListParams :  ListParams COMMA Expression 
			| Expression

Condition :   Condition OR Condition 
			| Condition AND Condition 
			| NEG Condition 
			| LPAREN Condition RPAREN
			| Expression Relational Expression 
			| TRUE 
			| FALSE

Relational :  LTHAN 
			| GTHAN 
			| GETHAN 
			| LETHAN 
			| NEQUAL 
			| EQUAL



%%

void yyerror(char* s){
	printf("Syntax Error on line: %d\nArround word '%s'\n%s\n" , yylineno, yytext,s);
}



char* newTemp(){
	/*'_t'+32 possible digits*/
	char* ptr=(char*)malloc(34);
	sprintf(ptr,"t%d",temp++);
	return ptr;
}

char* newLabel(){
	/*'_t'+32 possible digits*/
	char* ptr=(char*)malloc(34);
	sprintf(ptr,"_t%d",label++);
	return ptr;
}

/*linear search, improve*/
/*works for current scope*/
int existsSymbol(char* id){
	int i;
	for (i = 0; i < vector_total(ts); i++){
		char* cs=((sym*)vector_get(ts,i))->id;
		if(strcmp(id,cs)==0)
			return i;
	}
	return -1;
}

int existsSymbolInTable(char* id,vector* ts){
	int i;
	for (i = 0; i < vector_total(ts); i++){
		char* cs=((sym*)vector_get(ts,i))->id;
		if(strcmp(id,cs)==0)
			return i;
	}
	return -1;
}

/*look for current scope, move up in heirarchy*/
sym* lookupSymbol(char* id){
	sym* psym;
	int res;
	for(int lvl=vector_total(env)-1;lvl>-1;){
		vector* ts=(vector*)vector_get(env,lvl);
		res=existsSymbolInTable(id,ts);
		if(res>-1){
			psym=(sym*)vector_get(ts,res);
			return psym;
		}
	}
	return NULL;
}

/*	typedef struct{
    	char id[32];
    	char var_type[32];
    	type* type;
    	int dir;
    	type* args[32];
    	int arg_num;
	} sym;*/
sym* insertSymbol(char* id,type* tp,char* var_type){
	sym ns={.id="",.var_type="",.type=tp,.dir=*offset,.args=-1,.lts=NULL};
	strcpy(ns.id,id);
	strcpy(ns.var_type,var_type);
	sym* ptr=(sym*)malloc(sizeof(sym));
	*ptr=ns; 
	*offset+=tp->width;
	vector_add(ts,ptr);
	return ptr;
}


sym* insertFunction(char* id,type* tp,char* var_type,vector* lts,int args){
	sym ns={.id="",.var_type="",.type=tp,.dir=-1,.args=args,.lts=lts};
	strcpy(ns.id,id);
	strcpy(ns.var_type,var_type);
	sym* ptr=(sym*)malloc(sizeof(sym));
	*ptr=ns;
	vector_add(ts,ptr);
	return ptr;
}

type* insertType(type* t){
	type* ptr=(type*)malloc(sizeof(type));
	*ptr=(*t);
	vector_add(tt,ptr);
	return ptr;
}

void* top(vector* s){
	int tm1=(s->total)-1;
	return vector_get(s,tm1);
}

void push(vector* s,void* e){
	vector_add(s,e);
}

void* pop(vector* s){
	int tm1=(s->total)-1;
	void* r=vector_get(s,tm1);
	vector_delete(s,tm1);
	return r;
}

void init(){
	functionAlreadyUsed=0;

	ts=(vector*)malloc(sizeof(vector));
	tt=(vector*)malloc(sizeof(vector));
	vector_init(ts);
	vector_init(tt);

	offset=(unsigned int*)malloc(sizeof(unsigned int));
	*offset=0;

	stack=(vector*)malloc(sizeof(vector));
	env=(vector*)malloc(sizeof(vector));

	vector_init(stack);
	vector_init(env);

	type void_type={"void",NULL,0,-1,NULL}; //0
	insertType(&void_type);
	type int_type={"int",NULL,4,-1,NULL}; //1
	insertType(&int_type);
	type float_type={"float",NULL,4,-1,NULL}; //2
	insertType(&float_type);
	type double_type={"double",NULL,8,-1,NULL}; //3
	insertType(&double_type);
	type char_type={"char",NULL,1,-1,NULL}; //4
	insertType(&char_type);
}

vector* newSymbolTable(){
	vector* np=(vector*)malloc(sizeof(vector));
	vector_init(np);
	return np;
}

unsigned int* newOffset(){
	unsigned int* np=(unsigned int*)malloc(sizeof(unsigned int));
	*np=0;
	return np;
}

void print_type_table(){
	int i;
	printf("Type Table\n");
	for (i = 0; i < vector_total(tt); i++){
		type* tp=((type*)vector_get(tt,i));
		char* base=tp->base?((tp->base)->name):("-1");
		printf("(type: %s, base: %s, width: %d, elems: %d)\n",(tp->name),base,(tp->width),(tp->elem_num));
	}
}

void print_symbol_table(){
	int i;
	for (i = 0; i < vector_total(ts); i++){
		sym* sp=((sym*)vector_get(ts,i));
		printf("(id: %s, varType: %s, type: %s, dir: %d)\n",sp->id,sp->var_type,(sp->type)->name,sp->dir);
	}
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

	init();
	yyparse();
	print_type_table();
	printf("Main symbol table\n");
	print_symbol_table();
	printf("%d\n",*offset);
}