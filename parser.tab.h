/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
     COLON = 308
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define RETURN 260
#define PRINT 261
#define DO 262
#define WHILE 263
#define FOR 264
#define CASE 265
#define DEFAULT 266
#define TRUE 267
#define FALSE 268
#define STRUCT 269
#define INTEGER 270
#define FLOAT 271
#define DOUBLE 272
#define CHAR 273
#define VOID 274
#define SC 275
#define ASSIGN 276
#define EQUAL 277
#define NEQUAL 278
#define AND 279
#define OR 280
#define NEG 281
#define LTHAN 282
#define LETHAN 283
#define GTHAN 284
#define GETHAN 285
#define PLUS 286
#define MINUS 287
#define PROD 288
#define DIV 289
#define MODULO 290
#define LPAREN 291
#define RPAREN 292
#define LBRACKET 293
#define RBRACKET 294
#define LSBRACKET 295
#define RSBRACKET 296
#define DOT 297
#define COMMA 298
#define ID 299
#define NUMINT 300
#define NUMFLOAT 301
#define NUMDOUBLE 302
#define VALCHAR 303
#define VALSTRING 304
#define FUNC 305
#define SWITCH 306
#define BREAK 307
#define COLON 308




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

