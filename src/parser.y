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

int errors=0;

void yyerror(const char*);
void indent(FILE*,int);

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

	typedef struct{
		type* tipo;
		char dir[34];
	} expr;

	typedef struct{
		type* tipo;
		char dir[34];
		char base[34];
	} arrVar;

	typedef struct{
		vector* nextlist;	
	} statement;

	typedef struct{
		vector* tl;
		vector* fl;
	} condition;

	typedef struct{
		vector* btl;
		vector* bfl;
		vector* nextlist;
	} ifthen;

	typedef struct{
		vector* nextlist;
		char lbl[33];
		vector* n;
	} ifelse;

	typedef struct{
		vector* nextlist;
		char lbl[33];
	} ifaux;

	typedef struct{
		vector* args;
		int num;
	} params;

	/*TEMPS I DONT KNOW HOW TO HANDLE YET */
	/*FOR INSTANCE INHERITED ATTRIBUTES*/
	type* t;
	type* currentFnType;
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
	char* newLabel();
	quad* genQuad(char*,char*,char*,char*);
	int isNumeric(type*);
	char* widen(char*,type*,type*);
	type* max(type*,type*);
	expr* expression(char*,expr*,expr*);
	expr* createExpression(type*);
	arrVar* createArrVar(type*);
	int existsSymbolInTable(char*,vector*);
	statement* createStatement();
	void print_quads(FILE*,vector*);
	vector* newQuadsVector();
	condition* createConditionLists();
	void backpatch(vector*,char*);
	vector* merge(vector*,vector*);
	ifthen* createIfThen(condition*);
	ifelse* createIfElse();
	vector* createList();
	ifaux* createIfAux();
	sym* lookupFunction(char*);
	params* createParams();
}

%union{
	type* tipo;
	char lexval[32];
	char rel[32];
	char lbl[33];
	double numdouble;
	float numfloat;
	int numint;
	int args;
	expr* exp;
	arrVar* arr;
	statement* stmt;
	condition* cond;
	ifthen* it;
	ifelse* ie;
	ifaux* nif;
	params* p;
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
%nonassoc "then"
%nonassoc ELSE


%type<args> Args ListArgs
%type<exp> Expression LeftPart
%type<arr> ArrayVar
%type<tipo> Array
%type<stmt> Statement Statements
%type<it> If
%type<ie> Else
%type<nif> Nif
%type<lbl> Mstmt
%type<p> Params ListParams
%type<cond> Condition
%type<rel> Relational
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
/*redo with values!*/
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
								   			
								   			sprintf(buff,"Variable %s has been already declared",$3);
								   			yyerror(buff);
								   			YYABORT;
								   		}
								   	}
								   	else{
								   		sprintf(buff,"Variable %s can't be of type void",$3);
								   		yyerror(buff);
								   		YYABORT;
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
								   			YYABORT;
								   		}
								   	}
								   	else{
								   		sprintf(buff,"Id %s can't be of type void",$1);
								   		yyerror(buff);
								   		YYABORT;
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
													YYABORT;
												}
										    }

/*funciones -> func tipo id(argumentos){declaraciones sentencias} funciones | epsilon*/
Functions : 
			| FUNC	Type ID LPAREN									{
																		if(existsSymbol($3)>-1){
															   				char buff[100];
															   				sprintf(buff,"Id %s has been already declared",$3);
															   				yyerror(buff);
															   				YYABORT;
																		}
																		else{
																			currentFnType=t;
																			push(env,(void*)ts);
																			push(stack,(void*)offset);
																			offset=newOffset();
																			ts=newSymbolTable();
																			genQuad("LABEL",$3,"","");
																		}
																	}
			Args RPAREN LBRACKET Declarations Statements RBRACKET  {
																		//printf("Symbol table for %s\n",$3);
																		//print_symbol_table();
																		vector* prev=ts;
																		ts=(vector*)pop(env);
																		offset=(unsigned int*)pop(stack);
																		insertFunction($3,t,"function",prev,$6);
			 														}
			Functions 												{}


Args :   /*epsilon*/ {$$=0;}
		| ListArgs   {$$=$1;}

ListArgs :    ListArgs COMMA Type ID   {
											$$=$1+1;
											if(existsSymbol($4)==-1)
												insertSymbol($4,t,"arg");
											else{
												char* s="Repeated argument name";
												yyerror(s);
												YYABORT;
											}
													
										}
			| Type ID 					{
											$$=1;
											if(existsSymbol($2)==-1)
											insertSymbol($2,t,"arg");
											else{
												char* s="Repeated argument name";
												yyerror(s);
												YYABORT;
											}
										}

Statements :  Statements Mstmt Statement 	{
												backpatch($1->nextlist,$2);
												$$=$3;
										 	}
			| Statement 					{
												$$=$1;
											}

Statement :   If Else  															{
																					//ifthen
																					$$=createStatement();
																					if($2==NULL)
																						$$->nextlist=merge($1->bfl,$1->nextlist);
																					//ifelse
																					else{
																						backpatch($1->bfl,$2->lbl);
																						vector* temp=merge($1->nextlist,$2->n);
																						$$->nextlist=merge(temp,$2->nextlist);
																					}
																				}
			| WHILE LPAREN Mstmt Condition RPAREN Mstmt Statement  				{
																					$$=createStatement();
																					backpatch($7->nextlist,$3);
																					backpatch($4->tl,$6);
																					$$->nextlist=($4->fl);
																					genQuad("GOTO",$3,"","");																		
																				}
			| DO Mstmt Statement WHILE LPAREN Mstmt Condition RPAREN SC 		{
																					$$=createStatement();
																					backpatch($3->nextlist,$6);
																					backpatch($7->tl,$2);
																					$$->nextlist=($7->fl);
																					//genQuad("GOTO",$6,"","");
																				}
			| FOR LPAREN Statement SC Mstmt Condition SC Mstmt Statement 		{
																					genQuad("GOTO",$5,"","");
																				} 
			RPAREN Mstmt Statement   											{
																					$$=createStatement();
																					backpatch($13->nextlist,$8);
																					backpatch($6->tl,$12);
																					$$->nextlist=$6->fl;
																					genQuad("GOTO",$8,"","");
																				}
			| LeftPart ASSIGN Expression SC 									{
																					/*CHECK!*/
																					if(strcmp($1->tipo->name,$3->tipo->name)==0){
																						genQuad("ASSIGN",$3->dir,"",$1->dir);
																						$$=createStatement();
																						$$->nextlist=createList();
																					}
																					else{
																						char* s="Error. Assign of two different types";
																						yyerror(s);
																						YYABORT;
																					}
																				}
			| RETURN Expression SC 												{
																					char buff[100];
																					if(strcmp(currentFnType->name,($2->tipo)->name)==0)
																						genQuad("RETURN",$2->dir,"","");
																					else{
																						sprintf(buff,"Error: Return type doesn't match function declaration.");
																						yyerror(buff);
																						YYABORT;
																					}
																				}
			| RETURN SC 														{
																					char buff[100];
																					if(strcmp(currentFnType->name,"void")==0)
																						genQuad("RETURN","","","");
																					else{
																						sprintf(buff,"Error: Return type doesn't match function declaration.");
																						yyerror(buff);
																						YYABORT;
																					}
																				}
			| LBRACKET Statements RBRACKET 										{$$=$2;}
			| SWITCH LPAREN Expression RPAREN LBRACKET Cases RBRACKET           {}
			| BREAK SC  														{}
			| PRINT Expression 													{}
			/*added this because otherwise void functions are useless*/
			| ID LPAREN Params RPAREN SC     									{
																					char buff[100];
																					sym* res=lookupFunction($1);
																					if(res!=NULL&&(strcmp(res->var_type,"function")==0)){
																						if(res->args==$3->num){
																							vector* fts=res->lts;
																							int i;
																							for(i=0;i<res->args;i++){
																								sym* ca=(sym*)vector_get(fts,i);
																								expr* exp=(expr*)vector_get($3->args,i);
																								//sanity check, symbol entry should be arg
																								if(strcmp(ca->var_type,"arg")==0){
																									//check if arg[i]'s type corresponds to param[i]'s type'
																									if(strcmp((exp->tipo)->name,(ca->type)->name)==0)
																										genQuad("PUSH",exp->dir,"","");
																									else{
																										sprintf(buff,"Error: Parameter %d differs in type with declared type",i);
																										yyerror(buff);
																										YYABORT;
																									}
																								}
																								else{
																									sprintf(buff,"Error: arg number %d and arg entries differ",i);
																									yyerror(buff);
																									YYABORT;
																								}
																							}
																							$$=createStatement();
																							$$->nextlist=createList();
																							//it can't be void with this grammar!!
																							sprintf(buff,"%d",res->args);
																							genQuad("CALL",$1,buff,"");
																						}
																						else{
																							sprintf(buff,"Error: Function needs %d arguments, %d were given",res->args,$3->num);
																							yyerror(buff);
																							YYABORT;
																						}

																					}
																					else{
																						sprintf(buff,"Error: No function %s declared",$1);
																						yyerror(buff);
																						YYABORT;
																					}
																			    }

//generate labels for statements
Mstmt : {
			strcpy($$,newLabel());
			genQuad("LABEL",$$,"","");
		}

If : IF LPAREN Condition RPAREN {
									char* lbl=newLabel();
									backpatch($3->tl,lbl);
									genQuad("LABEL",lbl,"","");
								} 
	Statement 					{
									$$=createIfThen($3);
									$$->nextlist=$6->nextlist;
								}

Else :	 %prec "then"      	 {$$=NULL;}
		| ELSE Nif Statement {
								$$=createIfElse();
								strcpy($$->lbl,$2->lbl);
								$$->n=$2->nextlist;
								$$->nextlist=$3->nextlist;
							 }

Nif : {
		$$=createIfAux();
		vector_add($$->nextlist,genQuad("GOTO","_","",""));
		char* lbl=newLabel();
		genQuad("LABEL",lbl,"","");
		strcpy($$->lbl,lbl);
	  }

Cases : 
		| CASE NUMINT COLON Statements Default

Default : 
			| DEFAULT COLON Statements


LeftPart :    ID 		{
							sym* res=lookupSymbol($1);
							char buff[100];
							if(res!=NULL){
								$$=createExpression(res->type);
								sprintf($$->dir,"%s",res->id);
							}
							else{
								sprintf(buff,"Error: %s has not been previously declared",$1);
								yyerror(buff);
								YYABORT;
							}
						}
			| ArrayVar  {
							$$=createExpression($1->tipo);
							sprintf($$->dir,"%s[%s]",$1->base,$1->dir);

						}
			| ID DOT ID {
							sym* res=lookupSymbol($1);
							char buff[100];
							if(res!=NULL){
								if(strcmp((res->type)->name,"register")==0){
									int exists=existsSymbolInTable($3,(res->type)->ts);
									if(exists>=0){
										sym* res2=(sym*)vector_get((res->type)->ts,exists);
										$$=createExpression(res2->type);
										sprintf($$->dir,"%s.%s",$1,$3);
									}
									else{
										sprintf(buff,"Error: Register type %s does not contain field %s",$1,$3);
										yyerror(buff);
										YYABORT;
									}
								}
								else{
									sprintf(buff,"Error: Symbol %s is not of type register",$1);
									yyerror(buff);
									YYABORT;
								}
							}
							else{
								sprintf(buff,"Symbol %s not found",$1);
								yyerror(buff);
								YYABORT;
							}
						}

ArrayVar :    ID LSBRACKET Expression RSBRACKET 		{
															sym* res=lookupSymbol($1);
															char buff[100];
															if(res!=NULL){
																$$=createArrVar((res->type)->base);
																sprintf($$->base,"%s",res->id);
																sprintf($$->dir,"%s",newTemp());
																char buff[32];
																sprintf(buff,"%d",($$->tipo)->width);
																genQuad("PROD",$3->dir,buff,$$->dir);
															}
															else{
																sprintf(buff,"Error: Id %s has not been declared.",$1);
																yyerror(buff);
																YYABORT;
															}
														}
			| ArrayVar LSBRACKET Expression RSBRACKET   {
															$$=createArrVar(($1->tipo)->base);
															strcpy($$->base,$1->base);
															char* temp=newTemp();
															sprintf($$->dir,"%s",newTemp());
															char buff[32];
															sprintf(buff,"%d",($$->tipo)->width);
															genQuad("PROD",$3->dir,buff,temp);
															genQuad("PLUS",$1->dir,temp,$$->dir);
														}

/*Expresiones MISSING ID, ID.ID and ARRAY??*/
Expression :  Expression PLUS Expression   {$$=expression("PLUS",$1,$3);}
			| Expression MINUS Expression  {$$=expression("MINUS",$1,$3);}
			| Expression PROD Expression   {$$=expression("PROD",$1,$3);}
			| Expression DIV Expression    {$$=expression("DIV",$1,$3);}
			| Expression MODULO Expression {$$=expression("MODULO",$1,$3);}
			| MINUS Expression %prec UOPS  {$$=expression("MINUS",zero,$2);}
			| PLUS Expression %prec UOPS   {$$=expression("PLUS",zero,$2);}
			/*??*/
			| ID					   	   {
												char buff[100];
												sym* res=lookupSymbol($1);
												if(res!=NULL){
													$$=createExpression(res->type);
													sprintf($$->dir,"%s",res->id);
												}
												else{
													sprintf(buff,"Error: Id %s has not been declared.",$1);
													yyerror(buff);
													YYABORT;
												}	
										   }
			| ArrayVar 					   {
												$$=createExpression($1->tipo);
												sprintf($$->dir,"%s",newTemp());
												char buff[32];
												sprintf(buff,"%s[%s]",$1->base,$1->dir);
												genQuad("ASSIGN",buff,"",$$->dir);
											}
			| ID DOT ID 					{
												sym* res=lookupSymbol($1);
												char buff[100];
												if(res!=NULL){
													if(strcmp((res->type)->name,"register")==0){
														int exists=existsSymbolInTable($3,(res->type)->ts);
														if(exists>=0){
															sym* res2=(sym*)vector_get((res->type)->ts,exists);
															$$=createExpression(res2->type);
															sprintf($$->dir,"%s",newTemp());
															genQuad(".",$1,$3,$$->dir);
														}
														else{
															sprintf(buff,"Error: Register type %s does not contain field %s",$1,$3);
															yyerror(buff);
															YYABORT;
														}

													}
													else{
														sprintf(buff,"Error: variable %s is not of type register",$1);
														yyerror(buff);
														YYABORT;
													}
												}
												else{
													sprintf(buff,"Variable %s not found",$1);
													yyerror(buff);
													YYABORT;
												}
										    }
			| VALSTRING                    {}
			| CHAR                         {}
			| NUMINT                       {$$=createExpression((type*)vector_get(tt,1));sprintf($$->dir,"%d",$1);} //1
			| NUMFLOAT                     {$$=createExpression((type*)vector_get(tt,2));sprintf($$->dir,"%f",$1);} //2
			| NUMDOUBLE                    {$$=createExpression((type*)vector_get(tt,3));sprintf($$->dir,"%f",$1);} //3
			| ID LPAREN Params RPAREN      {
												char buff[100];
												sym* res=lookupFunction($1);
												if(res!=NULL&&(strcmp(res->var_type,"function")==0)){
													if(res->args==$3->num){
														vector* fts=res->lts;
														int i;
														for(i=0;i<res->args;i++){
															sym* ca=(sym*)vector_get(fts,i);
															expr* exp=(expr*)vector_get($3->args,i);
															//sanity check, symbol entry should be arg
															if(strcmp(ca->var_type,"arg")==0){
																//check if arg[i]'s type corresponds to param[i]'s type'
																if(strcmp((exp->tipo)->name,(ca->type)->name)==0)
																	genQuad("PUSH",exp->dir,"","");

																else{
																	sprintf(buff,"Error: Parameter %d differs in type with declared type",i);
																	yyerror(buff);
																	YYABORT;
																}
															}
															else{
																sprintf(buff,"Error: arg number %d and arg entries differ",i);
																yyerror(buff);
																YYABORT;
															}
														}
														$$=createExpression(res->type);
														//it can't be void with this grammar!!
														sprintf(buff,"%d",res->args);
														char* t=newTemp();
														genQuad("CALL",$1,buff,t);
														strcpy($$->dir,t);
													}
													else{
														sprintf(buff,"Error: Function needs %d arguments, %d were given",res->args,$3->num);
														yyerror(buff);
														YYABORT;
													}

												}
												else{
													sprintf(buff,"Error: No function %s declared",$1);
													yyerror(buff);
													YYABORT;
												}
										   }

/*Params -> lista_parametros | Epsilon*/
Params :   /*epsilon*/	{createParams();}
		 | ListParams 	{$$=$1;}

/*Lista_parametros -> lista_parametros, expresion | expresion*/
ListParams :  ListParams COMMA Expression   {
												char buff[100];
												$$=$1;
												if(strcmp(($3->tipo)->name,"void")!=0){
													vector_add($1->args,$3);
													$$->num++;
												}
												else{
													sprintf(buff,"Error: Parameter %d is of type void.",$$->num);
													yyerror(buff);
													YYABORT;
												}
											}
			| Expression 					{
												/*should be the first param*/
												char buff[100];
												$$=createParams();
												if(strcmp(($1->tipo)->name,"void")!=0){
													vector_add($$->args,$1);
													$$->num++;
												}
												else{
													sprintf(buff,"Error: Parameter %d is of type void.",$$->num);
													yyerror(buff);
													YYABORT;
												}

											}

/*improve using Mstmt, change Mstmt name, etc.*/
Condition :   Condition OR 						{
													char* lbl=newLabel();
													backpatch($1->fl,lbl);
													genQuad("LABEL",lbl,"","");
												}
			  Condition 			            {
			  										$$=createConditionLists();
			  										$$->tl=merge($1->tl,$4->tl);
			  										$$->fl=$4->fl;
												}
			| Condition AND 					{
													char* lbl=newLabel();
													backpatch($1->tl,lbl);
													genQuad("LABEL",lbl,"","");
												}
			  Condition 						{
			  										$$=createConditionLists();
			  										$$->tl=$4->tl;
			  										$$->fl=merge($1->fl,$4->fl);
												}
			| NEG Condition 					{
													/*use same struct, change fields?*/
													$$=createConditionLists();
													$$->tl=$2->fl;
													$$->fl=$2->tl;
												}
			| LPAREN Condition RPAREN			{$$=$2;}
			| Expression Relational Expression 	{	
													/*CHECK EXPRESSIONS TYPE! or do implicit cast!*/
													if(strcmp($1->tipo->name,$3->tipo->name)==0){
														$$=createConditionLists();
														vector_add($$->tl,genQuad($2,$1->dir,$3->dir,"GOTO _"));
														vector_add($$->fl,genQuad("GOTO","_","",""));
													}
													else{
														char buff[100];
														sprintf(buff,"Expressions %s and %s have different types.",$1->dir,$3->dir);
														yyerror(buff);
														YYABORT;
													}
												}
			| TRUE 								{
													$$=createConditionLists();
													vector_add($$->tl,genQuad("GOTO","_","",""));
												}
			| FALSE 							{
													$$=createConditionLists();
													vector_add($$->fl,genQuad("GOTO","_","",""));
												}

Relational :  LTHAN 	{strcpy($$,"LTHAN");}
			| GTHAN 	{strcpy($$,"GTHAN");}
			| GETHAN 	{strcpy($$,"GETHAN");}
			| LETHAN 	{strcpy($$,"LETHAN");}
			| NEQUAL 	{strcpy($$,"NEQUAL");}
			| EQUAL		{strcpy($$,"EQUAL");}



%%

void yyerror(const char* s){
	errors++;
	printf("Error found on line: %d\nArround word '%s'\n%s\n" , yylineno, yytext,s);
}

//look if yyerror halts or not
expr* expression(char* op,expr* e1, expr* e2){
	char buff[100];
	if((!isNumeric(e1->tipo))&&(!isNumeric(e2->tipo))){
		sprintf(buff,"Error: Expressions differ in type.");
		yyerror(buff);
	}
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

void backpatch(vector* lst,char* lbl){
	int i;
	char buff[100];
	for (i = 0;i<vector_total(lst); i++){
		quad* q=(quad*)vector_get(lst,i);
		if(strcmp(q->arg1,"_")==0)
			strcpy(q->arg1,lbl);
		else{
			sprintf(buff,"GOTO %s",lbl);
			strcpy(q->res,buff);			
		}
	}
}

/*changed to void, check if it still works, it should though*/
vector* merge(vector* v1,vector* v2){
	int i;
	for (i = 0;i<vector_total(v2); i++){
		void* q=vector_get(v2,i);
		vector_add(v1,q);
	}
	return v1;
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
	/*'L'+32 possible digits*/
	char* ptr=(char*)malloc(33);
	sprintf(ptr,"L%d",label++);
	return ptr;
}

arrVar* createArrVar(type* t){
	arrVar av={.tipo=t,.dir="",.base=""};
	arrVar* ptr=(arrVar*)malloc(sizeof(arrVar));
	*ptr=av;
	return ptr;
}

expr* createExpression(type* t){
	expr e={.tipo=t,.dir=""};
	expr* ptr=(expr*)malloc(sizeof(expr));
	*ptr=e;
	return ptr;
}

/*????*/
statement* createStatement(){
	statement st={};
	statement* ptr=(statement*)malloc(sizeof(statement));
	*ptr=st;
	return ptr;
}

ifthen* createIfThen(condition* c){
	ifthen it={.btl=c->tl,.bfl=c->fl,.nextlist=NULL};
	ifthen* ptr=(ifthen*)malloc(sizeof(ifthen));
	*ptr=it;
	return ptr;
}

ifelse* createIfElse(){
	ifelse ie={};
	ifelse* ptr=(ifelse*)malloc(sizeof(ifelse));
	*ptr=ie;
	return ptr;
}

ifaux* createIfAux(){
	ifaux ia={.nextlist=createList(),.lbl=""};
	ifaux* ptr=(ifaux*)malloc(sizeof(ifaux));
	*ptr=ia;
	return ptr;
}

params* createParams(){
	params p={.num=0,.args=createList()};
	params* ptr=(params*)malloc(sizeof(params));
	*ptr=p;
	return ptr;	
}

condition* createConditionLists(){
	vector* tl=createList();
	vector* fl=createList();
	condition c={.tl=tl,.fl=fl};
	condition* ptr=(condition*)malloc(sizeof(condition));
	*ptr=c;
	return ptr;
}

vector* createList(){
	vector* ptr=(vector*)malloc(sizeof(vector));
	vector_init(ptr);
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

/*IMPORTANT: It works because there are no function calls outside a function scope.*/
/*Env must have global sym table!*/
sym* lookupFunction(char* id){
	vector* ts=(vector*)vector_get(env,0);
	int res=existsSymbolInTable(id,ts);
	if(res>-1){
		sym* psym=(sym*)vector_get(ts,res);
		return psym;
	}
	return NULL;
}

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

vector* newQuadsVector(){
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

/*TODO: Pretty print*/
void print_quads(FILE* f,vector* quads){
	int i;
	int lvl=1;
	for (i = 0; i < vector_total(quads); i++){
		quad* q=((quad*)vector_get(quads,i));
		if(strcmp(q->op,"LTHAN")==0){
			indent(f,lvl);
			fprintf(f,"%s %s %s %s\n",q->op,q->arg1,q->arg2,q->res);
		}
		else if(strcmp(q->op,"GTHAN")==0){
			indent(f,lvl);
			fprintf(f,"%s %s %s %s\n",q->op,q->arg1,q->arg2,q->res);
		}
		else if(strcmp(q->op,"LETHAN")==0){
			indent(f,lvl);
			fprintf(f,"%s %s %s %s\n",q->op,q->arg1,q->arg2,q->res);
		}
		else if(strcmp(q->op,"GETHAN")==0){
			indent(f,lvl);
			fprintf(f,"%s %s %s %s\n",q->op,q->arg1,q->arg2,q->res);
		}
		else if(strcmp(q->op,"EQUAL")==0){
			indent(f,lvl);
			fprintf(f,"%s %s %s %s\n",q->op,q->arg1,q->arg2,q->res);
		}
		else if(strcmp(q->op,"NEQUAL")==0){
			indent(f,lvl);
			fprintf(f,"%s %s %s %s\n",q->op,q->arg1,q->arg2,q->res);
		}
		else if(strcmp(q->op,"GOTO")==0){
			indent(f,lvl);
			fprintf(f,"%s %s\n",q->op,q->arg1);
		}
		else if(strcmp(q->op,"LABEL")==0){
			if((q->arg1)[0]=='L'){
				indent(f,1);
				if(lvl==1)
					lvl++;
				fprintf(f,"%s %s\n",q->op,q->arg1);
			}
			else{
				if(lvl>1)
					lvl--;
				fprintf(f,"%s %s\n",q->op,q->arg1);
			}
		}
		else if(strcmp(q->op,"PUSH")==0){
			indent(f,lvl);
			fprintf(f,"%s %s\n",q->op,q->arg1);
		}
		else if(strcmp(q->op,"CALL")==0){
			if(strcmp(q->res,"")==0){
				indent(f,lvl);
				fprintf(f,"%s %s %s\n",q->op,q->arg1,q->arg2);
			}
			else{
				indent(f,lvl);
				fprintf(f,"%s := %s %s %s\n",q->res,q->op,q->arg1,q->arg2);
			}
		}
		else if(strcmp(q->op,"RETURN")==0){
			indent(f,lvl);
			fprintf(f,"%s %s\n",q->op,q->arg1);
		}
		else{
			indent(f,lvl);
			fprintf(f,"%s := %s %s %s\n",q->res,q->arg1,q->op,q->arg2);
		}
	}
}

void indent(FILE* f,int n){
    for (int i = 0; i < n; i++)
       fprintf(f,"\t");
}

void print_symbol_table(){
	int i;
	for (i = 0; i < vector_total(ts); i++){
		sym* sp=((sym*)vector_get(ts,i));
		printf("(id: %s, varType: %s, type: %s, dir: %d)\n",sp->id,sp->var_type,(sp->type)->name,sp->dir);
	}
}

int main(int argc, char** argv){
	char outputf[100];
	char routputf[100];
	FILE* f;
	FILE* o;
	if(argc==5){
		int i;
		/*First we find the -i flag*/
		for (i=0;i<argc;i++){
			if(strcmp(argv[i],"-i")==0){
				/*input file should be i+1*/
				if(i<=(argc-2)){
					/*check if i+1 is a file*/
					if((f=fopen(argv[i+1],"r"))==0){
						fprintf(stderr,"Error opening input file.\nUsage is ./c-- -i cminusprog.txt -o 3ac.txt\n");
						return 0;
					}
				}
				break;
			}
		}
		/*Then we find the -o flag*/
		for (i=0;i<argc;i++){
			if(strcmp(argv[i],"-o")==0){
				/*output file should be i+1*/
				if(i<=(argc-2)){
					/*check if i+1 is a file*/
					strcpy(outputf,argv[i+1]);
					if((o=fopen(outputf,"w"))==0){
						fprintf(stderr,"Error opening output file.\nUsage is ./c-- -i cminusprog.txt -o 3ac.txt\n");
						return 0;
					}
				}
			break;
			}
		}
	}
	else{
		fprintf(stderr,"Error. Usage is ./c-- -i cminusprog.txt -o 3ac.txt\n");
		return 0;
	}

	yyin=f;

	init();
	yyparse();

	int mf=existsSymbol("main");
	char buff[100];
	if(errors==0){
		if(mf==-1){
			sprintf(buff,"Error: No main function declared.");
			yyerror(buff);
		}
		else if(vector_total(ts)-1!=mf){
			sprintf(buff,"Error: Main function should be the last declared function");
			yyerror(buff);
		}
		else{
			// print_symbol_table();
			// print_type_table();
			realpath(outputf,routputf);
			printf("Compilation front-end completed succesfully. Three address code written in %s.\n",routputf);
			print_quads(o,quads);
		}
	}
}