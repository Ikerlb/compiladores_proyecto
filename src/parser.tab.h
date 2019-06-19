/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 42 "parser.y" /* yacc.c:1927  */

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

#line 160 "parser.tab.h" /* yacc.c:1927  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    RETURN = 260,
    PRINT = 261,
    DO = 262,
    WHILE = 263,
    FOR = 264,
    CASE = 265,
    DEFAULT = 266,
    TRUE = 267,
    FALSE = 268,
    STRUCT = 269,
    INTEGER = 270,
    FLOAT = 271,
    DOUBLE = 272,
    CHAR = 273,
    VOID = 274,
    SC = 275,
    ASSIGN = 276,
    EQUAL = 277,
    NEQUAL = 278,
    AND = 279,
    OR = 280,
    NEG = 281,
    LTHAN = 282,
    LETHAN = 283,
    GTHAN = 284,
    GETHAN = 285,
    PLUS = 286,
    MINUS = 287,
    PROD = 288,
    DIV = 289,
    MODULO = 290,
    LPAREN = 291,
    RPAREN = 292,
    LBRACKET = 293,
    RBRACKET = 294,
    LSBRACKET = 295,
    RSBRACKET = 296,
    DOT = 297,
    COMMA = 298,
    ID = 299,
    NUMINT = 300,
    NUMFLOAT = 301,
    NUMDOUBLE = 302,
    VALCHAR = 303,
    VALSTRING = 304,
    FUNC = 305,
    SWITCH = 306,
    BREAK = 307,
    COLON = 308,
    UOPS = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 154 "parser.y" /* yacc.c:1927  */

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

#line 246 "parser.tab.h" /* yacc.c:1927  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
