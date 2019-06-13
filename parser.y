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

vector* quads;

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

	typedef struct{
		char op[10];
		char arg1[34];
		char arg2[34];
		char res[34];
	} quad;

	typedef struct {
		type* tipo;
		char dir[34];
	} expr;

	/*TEMPS I DONT KNOW HOW TO HANDLE YET */
	/*FOR INSTANCE INHERITED ATTRIBUTES*/
	type* t;
	int functionAlreadyUsed;
	expr* zero;

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
	char* newTemp();
	quad* genQuad(char*,char*,char*,char*);
	int isNumeric(type*);
	char* widen(char*,type*,type*);
	type* max(type*,type*);
	expr* expression(char*,expr*,expr*);
	expr* createExpression(type*);
}

%union{
	type* tipo;
	char lexval[32];
	double numdouble;
	float numfloat;
	int numint;
	int args;
	expr* exp;
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

%left AND OR
%left PLUS MINUS
%left PROD DIV MODULO
%right UOPS
%right NEG
%left LPAREN RPAREN
%left IF
%left ELSE

%type<args> Args ListArgs
%type<exp> Expression LeftPart
%type<tipo> Array
%type<lexval> ID
%type<numint> NUMINT
%type<numfloat> NUMFLOAT
%type<numdouble> NUMDOUBLE
%define parse.error verbose

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
													char* s="Arrays can't be negative size";
													yyerror(s);
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
												char* s="Repeated argument name";
												yyerror(s);
													
										}
			| Type ID 					{
											$$=1;
											if(existsSymbol($2)==-1)
											insertSymbol($2,t,"arg");
											else{
												char* s="Repeated argument name";
												yyerror(s);
											}
										}

Statements :  Statements Statement 
			| Statement

Statement :   IF LPAREN Condition RPAREN Statement
			| IF LPAREN Condition RPAREN Statement ELSE Statement
			| WHILE LPAREN Condition RPAREN Statement
			| DO Statement WHILE LPAREN Condition RPAREN SC
			| FOR LPAREN Statement SC Condition SC Statement RPAREN Statement
			| LeftPart ASSIGN Expression SC 									{
																					if(strcmp($1->tipo->name,$3->tipo->name)==0)
																						genQuad($3->dir,"","ASSIGN",$1->dir);
																					else
																						yyerror("Error. Assign of two different types");
																				}
			| RETURN Expression SC
			| RETURN SC 
			| LBRACKET Statements RBRACKET
			| SWITCH LPAREN Expression RPAREN LBRACKET Cases RBRACKET 
			| BREAK SC 
			| PRINT Expression

Cases : 
		| CASE NUMINT COLON Statements Default

Default : 
			| DEFAULT COLON Statements


LeftPart :    ID 		{
							sym* res=lookupSymbol($1);
							if(res!=NULL){
								$$=createExpression(res->type);
								sprintf($$->dir,"%s",res->id);
							}
							else
								yyerror("Symbol not found.");
						}
			| ArrayVar  {

						}
			| ID DOT ID {

						}

ArrayVar :    ID LSBRACKET Expression RSBRACKET 
			| ArrayVar LSBRACKET Expression RSBRACKET

/*Expresiones MISSING ID, ID.ID and ARRAY??*/
Expression :  Expression PLUS Expression   {$$=expression("PLUS",$1,$3);}
			| Expression MINUS Expression  {$$=expression("MINUS",$1,$3);}
			| Expression PROD Expression   {$$=expression("PROD",$1,$3);}
			| Expression DIV Expression    {$$=expression("DIV",$1,$3);}
			| Expression MODULO Expression {$$=expression("MODULO",$1,$3);}
			| MINUS Expression %prec UOPS  {$$=expression("MINUS",zero,$2);}
			| PLUS Expression %prec UOPS   {$$=expression("PLUS",zero,$2);}
			| VALSTRING                    {}
			| CHAR                         {}
			| NUMINT                       {$$=createExpression((type*)vector_get(tt,1));sprintf($$->dir,"%d",$1);} //1
			| NUMDOUBLE                    {$$=createExpression((type*)vector_get(tt,2));sprintf($$->dir,"%f",$1);} //2
			| NUMFLOAT                     {$$=createExpression((type*)vector_get(tt,3));sprintf($$->dir,"%f",$1);} //3
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
	printf("Error found on line: %d\nArround word '%s'\n%s\n" , yylineno, yytext,s);
}

//look if yyerror halts or not
expr* expression(char* op,expr* e1, expr* e2){
	if((!isNumeric(e1->tipo))&&(!isNumeric(e2->tipo)))
		yyerror("Type error.");
	expr e={.tipo=NULL,.dir=""};
	e.tipo=max(e1->tipo,e2->tipo);
	strcpy(e.dir,newTemp());
	expr* ptr=(expr*)malloc(sizeof(expr));
	*ptr=e;
	char* d1=widen(e1->dir,e1->tipo,ptr->tipo);
	char* d2=widen(e2->dir,e2->tipo,ptr->tipo);
	//printf("prueba\n");
	genQuad(op,d1,d2,e.dir);
	return ptr;
}

/*might use later*/
int isNumeric(type* t1){
	if(strcmp(t1->name,"double")==0)
		return 1;
	if(strcmp(t1->name,"float")==0)
		return 1;
	if(strcmp(t1->name,"int")==0)
		return 1;
	return 0;
}

//check types earlier?
type* max(type* t1,type* t2){
	if(strcmp(t1->name,"double")==0)
		return t1;
	if(strcmp(t2->name,"double")==0)
		return t2;
	if(strcmp(t1->name,"float")==0)
		return t1;
	if(strcmp(t2->name,"float")==0)
		return t2;
	return t1;
}



//t2 will be max type of binary expression
char* widen(char* dir, type* t1, type* t2){
	//should be exact same mem address. but do name check instead
	if(strcmp(t1->name,t2->name)==0)
		return dir;
	//if the maximum is a double, cast other expression to double
	if(strcmp(t2->name,"double")){
		char* t=newTemp();
		//do double (t=(double)d) cast in quads
		genQuad("CAST","(double)",dir,t);
		return t;
	}
	//otherwise it is a float (if max is int, the other expression MUST be int)
	char* t=newTemp();
	//do float (t=(float)d) cast in quads
	genQuad("CAST","(float)",dir,t);
	return t;	
}

char* newTemp(){
	/*'_t'+32 possible digits*/
	char* ptr=(char*)malloc(34);
	sprintf(ptr,"_t%d",temp++);
	return ptr;
}

char* newLabel(){
	/*'_t'+32 possible digits*/
	char* ptr=(char*)malloc(34);
	sprintf(ptr,"_t%d",label++);
	return ptr;
}

expr* createExpression(type* t){
	expr e={.tipo=t,.dir=""};
	expr* ptr=(expr*)malloc(sizeof(expr));
	*ptr=e;
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

/*generalization of existsSymbol*/
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
/*look for ts as well*/
sym* lookupSymbol(char* id){
	sym* psym;
	int res=existsSymbol(id);
	if(res>-1){
		psym=(sym*)vector_get(ts,res);
		return psym;
	}
	else
		for(int lvl=vector_total(env)-1;lvl>-1;lvl--){
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

quad* genQuad(char* op,char* arg1,char* arg2,char* res){
	quad q={.op="",.arg1="",.arg2="",.res=""};
	strcpy(q.op,op);
	strcpy(q.arg1,arg1);
	strcpy(q.arg2,arg2);
	strcpy(q.res,res);
	quad* ptr=(quad*)malloc(sizeof(quad));
	*ptr=q;
	vector_add(quads,ptr);
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

	quads=(vector*)malloc(sizeof(vector));

	vector_init(stack);
	vector_init(env);

	vector_init(quads);

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

	zero=createExpression((type*)vector_get(tt,1));
	sprintf(zero->dir,"%d",0);

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

void print_quads(){
	int i;
	printf("Quads:\n");
	for (i = 0; i < vector_total(quads); i++){
		quad* q=((quad*)vector_get(quads,i));
		printf("%s := %s %s %s\n",q->res,q->arg1,q->op,q->arg2);
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
	print_quads();
}