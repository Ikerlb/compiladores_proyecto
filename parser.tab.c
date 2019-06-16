/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y" /* yacc.c:337  */

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


#line 108 "parser.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
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
#line 39 "parser.y" /* yacc.c:352  */

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
		vector* code;	
	} statement;

	typedef struct{
		vector* tl;
		vector* fl;
	} condition;

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
	char* newLabel();
	quad* genQuad(char*,char*,char*,char*);
	int isNumeric(type*);
	char* widen(char*,type*,type*);
	type* max(type*,type*);
	expr* expression(char*,expr*,expr*);
	expr* createExpression(type*);
	arrVar* createArrVar(type*);
	int existsSymbolInTable(char*,vector*);
	statement* createStatement(vector*);
	void print_quads();
	vector* newQuadsVector();
	condition* createConditionLists();
	void backpatch(vector*,char*);
	vector* merge(vector*,vector*);

#line 225 "parser.tab.c" /* yacc.c:352  */

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
#line 123 "parser.y" /* yacc.c:352  */

	type* tipo;
	char lexval[32];
	char rel[32];
	double numdouble;
	float numfloat;
	int numint;
	int args;
	expr* exp;
	arrVar* arr;
	statement* stmt;
	condition* cond;

#line 306 "parser.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   249

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

#define YYUNDEFTOK  2
#define YYMAXUTOK   309

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   179,   179,   182,   183,   187,   188,   189,   190,   191,
     192,   192,   208,   226,   245,   246,   260,   261,   271,   261,
     290,   291,   293,   303,   313,   314,   316,   317,   318,   319,
     320,   321,   336,   337,   338,   339,   340,   341,   343,   344,
     346,   347,   350,   361,   366,   393,   408,   420,   421,   422,
     423,   424,   425,   426,   428,   439,   446,   474,   475,   476,
     477,   478,   479,   482,   482,   485,   486,   488,   488,   498,
     498,   508,   514,   515,   528,   532,   537,   538,   539,   540,
     541,   542
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "RETURN", "PRINT", "DO",
  "WHILE", "FOR", "CASE", "DEFAULT", "TRUE", "FALSE", "STRUCT", "INTEGER",
  "FLOAT", "DOUBLE", "CHAR", "VOID", "SC", "ASSIGN", "EQUAL", "NEQUAL",
  "AND", "OR", "NEG", "LTHAN", "LETHAN", "GTHAN", "GETHAN", "PLUS",
  "MINUS", "PROD", "DIV", "MODULO", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "LSBRACKET", "RSBRACKET", "DOT", "COMMA", "ID", "NUMINT",
  "NUMFLOAT", "NUMDOUBLE", "VALCHAR", "VALSTRING", "FUNC", "SWITCH",
  "BREAK", "COLON", "UOPS", "$accept", "Program", "Declarations", "Type",
  "$@1", "List", "Array", "Functions", "$@2", "$@3", "Args", "ListArgs",
  "Statements", "Statement", "Cases", "Default", "LeftPart", "ArrayVar",
  "Expression", "Params", "ListParams", "Condition", "$@4", "$@5",
  "Relational", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF -59

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-59)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     219,   -59,   -59,   -59,   -59,   -59,   -59,     1,   -48,   -34,
     -12,   -59,   219,   -59,     8,     3,   219,    -8,     4,   -59,
     219,    27,    23,    48,    44,   -59,     8,   -59,   -59,     8,
     -59,   219,   -59,    50,   -59,    62,   -59,    71,   219,    73,
      72,   219,   -59,   130,    79,    21,   162,   130,    94,   104,
     130,    36,   114,   132,    12,   -59,   137,   125,   141,   -59,
     -59,   162,   162,    33,   -59,   -59,   -59,   -59,   125,    69,
     208,   158,   141,   130,    90,   162,   127,   162,   -59,   -48,
     -59,   162,   162,   -59,   -59,   141,   141,   190,    10,   -59,
     -59,   162,   131,   -59,   162,   162,   162,   162,   162,   133,
      18,   156,   -59,   129,   -59,   195,   -59,   169,   164,   -59,
      89,   -59,   -59,   -59,   -59,   -59,   -59,   162,   -59,   -59,
     130,   208,   142,   167,   -59,   122,   122,   -59,   -59,   -59,
     141,   130,   141,   -59,   145,   -59,   -59,   -59,   208,   141,
     141,   210,   -59,   162,   107,   -59,    67,   205,   -59,   -59,
     130,   208,   196,   130,   186,   206,   -59,   -59,   207,   193,
     -59,   130,   130,   -59,   140,   194,   -59,   130,   130
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    10,     5,     6,     7,     8,     9,     0,    16,     0,
       0,     1,     0,     2,    14,     0,     3,     0,     0,    13,
       3,     0,     0,     0,     0,     4,    14,    11,    17,    14,
      12,    20,    15,     0,    18,    21,    23,     0,     0,     0,
       0,     3,    22,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,    25,     0,    43,     0,    58,
      33,     0,     0,    54,    59,    60,    61,    57,    55,     0,
      37,     0,     0,     0,     0,     0,     0,     0,    36,    16,
      24,     0,     0,    74,    75,     0,     0,     0,     0,    53,
      52,    63,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,    44,     0,    19,     0,     0,    71,
       0,    81,    80,    76,    79,    77,    78,     0,    69,    67,
       0,    66,     0,    64,    56,    47,    48,    49,    50,    51,
       0,     0,     0,    45,     0,    31,    46,    72,    73,     0,
       0,    26,    62,     0,     0,    28,     0,    38,    70,    68,
       0,    65,     0,     0,     0,     0,    27,    29,     0,     0,
      35,     0,     0,    30,    40,     0,    39,     0,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -59,    -4,    -9,   -59,   -59,    57,   170,   -59,   -59,
     -59,   -59,   -45,   -41,   -59,   -59,   -59,   -43,   -37,   -59,
     -59,   -58,   -59,   -59,   -59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    15,    19,    13,    31,    37,
      34,    35,    54,    55,   155,   166,    56,    68,    87,   122,
     123,    88,   140,   139,   117
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    11,    12,    17,    57,    74,    71,    57,    69,    70,
      14,    57,    22,    80,   100,    44,    25,    45,    46,    47,
      48,    49,    33,    20,    89,    90,    16,   109,   110,    40,
      57,    57,   101,    80,   118,   119,    23,    43,   103,    59,
     105,    60,   118,   119,   107,   108,    21,   120,    18,    24,
      50,    79,    61,    62,   121,   131,    51,   125,   126,   127,
     128,   129,    27,    52,    53,    63,    64,    65,    66,    91,
      67,    26,   144,    75,   146,    92,    75,    57,    76,   141,
     138,   148,   149,    30,    28,    29,    32,   153,    57,    93,
     145,   118,   119,    44,    36,    45,    46,    47,    48,    49,
      94,    95,    96,    97,    98,    38,   151,    57,    39,   156,
      57,    41,   158,   118,   119,    58,    42,   164,    57,    57,
     163,    57,   168,    80,    57,    57,   137,    80,    50,   102,
      72,   118,   119,    44,    51,    45,    46,    47,    48,    49,
      73,    52,    53,    44,   152,    45,    46,    47,    48,    49,
      77,   165,    78,    83,    84,    96,    97,    98,    81,    59,
      94,    95,    96,    97,    98,    82,    99,    85,    50,   130,
     133,   104,    61,    62,    51,   124,   132,    86,    50,   142,
      59,    52,    53,   147,    51,    63,    64,    65,    66,   135,
      67,    52,    53,    61,    62,    94,    95,    96,    97,    98,
      94,    95,    96,    97,    98,   136,    63,    64,    65,    66,
     143,    67,   111,   112,   150,   154,   157,   113,   114,   115,
     116,    94,    95,    96,    97,    98,    94,    95,    96,    97,
      98,   159,   134,     1,     2,     3,     4,     5,     6,    94,
      95,    96,    97,    98,   161,   160,   162,   167,     0,   106
};

static const yytype_int16 yycheck[] =
{
      43,     0,    50,    12,    47,    50,    47,    50,    45,    46,
      44,    54,    16,    54,    72,     3,    20,     5,     6,     7,
       8,     9,    31,    20,    61,    62,    38,    85,    86,    38,
      73,    74,    73,    74,    24,    25,    44,    41,    75,    18,
      77,    20,    24,    25,    81,    82,    43,    37,    40,    45,
      38,    39,    31,    32,    91,    37,    44,    94,    95,    96,
      97,    98,    39,    51,    52,    44,    45,    46,    47,    36,
      49,    44,   130,    40,   132,    42,    40,   120,    42,   120,
     117,   139,   140,    26,    36,    41,    29,    20,   131,    20,
     131,    24,    25,     3,    44,     5,     6,     7,     8,     9,
      31,    32,    33,    34,    35,    43,   143,   150,    37,   150,
     153,    38,   153,    24,    25,    36,    44,   162,   161,   162,
     161,   164,   167,   164,   167,   168,    37,   168,    38,    39,
      36,    24,    25,     3,    44,     5,     6,     7,     8,     9,
      36,    51,    52,     3,    37,     5,     6,     7,     8,     9,
      36,    11,    20,    12,    13,    33,    34,    35,    21,    18,
      31,    32,    33,    34,    35,    40,     8,    26,    38,    36,
      41,    44,    31,    32,    44,    44,    20,    36,    38,    37,
      18,    51,    52,    38,    44,    44,    45,    46,    47,    20,
      49,    51,    52,    31,    32,    31,    32,    33,    34,    35,
      31,    32,    33,    34,    35,    41,    44,    45,    46,    47,
      43,    49,    22,    23,     4,    10,    20,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    31,    32,    33,    34,
      35,    45,    37,    14,    15,    16,    17,    18,    19,    31,
      32,    33,    34,    35,    37,    39,    53,    53,    -1,    79
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    15,    16,    17,    18,    19,    56,    57,    58,
      59,     0,    50,    62,    44,    60,    38,    58,    40,    61,
      20,    43,    57,    44,    45,    57,    44,    39,    36,    41,
      61,    63,    61,    58,    65,    66,    44,    64,    43,    37,
      58,    38,    44,    57,     3,     5,     6,     7,     8,     9,
      38,    44,    51,    52,    67,    68,    71,    72,    36,    18,
      20,    31,    32,    44,    45,    46,    47,    49,    72,    73,
      73,    68,    36,    36,    67,    40,    42,    36,    20,    39,
      68,    21,    40,    12,    13,    26,    36,    73,    76,    73,
      73,    36,    42,    20,    31,    32,    33,    34,    35,     8,
      76,    68,    39,    73,    44,    73,    62,    73,    73,    76,
      76,    22,    23,    27,    28,    29,    30,    79,    24,    25,
      37,    73,    74,    75,    44,    73,    73,    73,    73,    73,
      36,    37,    20,    41,    37,    20,    41,    37,    73,    78,
      77,    68,    37,    43,    76,    68,    76,    38,    76,    76,
       4,    73,    37,    20,    10,    69,    68,    20,    68,    45,
      39,    37,    53,    68,    67,    11,    70,    53,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    58,    58,
      59,    58,    60,    60,    61,    61,    62,    63,    64,    62,
      65,    65,    66,    66,    67,    67,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    69,    69,
      70,    70,    71,    71,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    74,    74,    75,    75,    77,    76,    78,
      76,    76,    76,    76,    76,    76,    79,    79,    79,    79,
      79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     4,     1,     1,     1,     1,     1,
       0,     5,     4,     2,     0,     4,     0,     0,     0,    13,
       0,     1,     4,     2,     2,     1,     5,     7,     5,     7,
       9,     4,     3,     2,     3,     7,     2,     2,     0,     5,
       0,     3,     1,     1,     3,     4,     4,     3,     3,     3,
       3,     3,     2,     2,     1,     1,     3,     1,     1,     1,
       1,     1,     4,     0,     1,     3,     1,     0,     4,     0,
       4,     2,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 187 "parser.y" /* yacc.c:1667  */
    {t=(type*)vector_get(tt,1);}
#line 1530 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 6:
#line 188 "parser.y" /* yacc.c:1667  */
    {t=(type*)vector_get(tt,2);}
#line 1536 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 7:
#line 189 "parser.y" /* yacc.c:1667  */
    {t=(type*)vector_get(tt,3);}
#line 1542 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 8:
#line 190 "parser.y" /* yacc.c:1667  */
    {t=(type*)vector_get(tt,4);}
#line 1548 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 9:
#line 191 "parser.y" /* yacc.c:1667  */
    {t=(type*)vector_get(tt,0);}
#line 1554 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 10:
#line 192 "parser.y" /* yacc.c:1667  */
    {
	  												push(env,(void*)ts);
													push(stack,(void*)offset);

													offset=newOffset();
													ts=newSymbolTable();
												}
#line 1566 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 11:
#line 199 "parser.y" /* yacc.c:1667  */
    {
	  												type nt={"register",NULL,*offset,-1,ts};
	  												ts=(vector*)pop(env);
	  												offset=(unsigned int*)pop(stack);
	  												t=insertType(&nt);
	  											}
#line 1577 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 12:
#line 208 "parser.y" /* yacc.c:1667  */
    {
									char buff[100];
									if(strcmp(t->name,"void")!=0){

								   		if(existsSymbol((yyvsp[-1].lexval))==-1){
								   			insertSymbol((yyvsp[-1].lexval),(yyvsp[0].tipo),"var");
								   		}
								   		else{
								   			
								   			sprintf(buff,"Id %s has been already declared",(yyvsp[-1].lexval));
								   			yyerror(buff);
								   		}
								   	}
								   	else{
								   		sprintf(buff,"Id %s can't be of type void",(yyvsp[-1].lexval));
								   		yyerror(buff);
								   	}
							   }
#line 1600 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 13:
#line 226 "parser.y" /* yacc.c:1667  */
    {
 									char buff[100];
 									if(strcmp(t->name,"void")!=0){
								   		if(existsSymbol((yyvsp[-1].lexval))==-1){
								   			insertSymbol((yyvsp[-1].lexval),(yyvsp[0].tipo),"var");
								   		}
								   		else{
								   			char buff[100];
								   			sprintf(buff,"Id %s has been already declared",(yyvsp[-1].lexval));
								   			yyerror(buff);
								   		}
								   	}
								   	else{
								   		sprintf(buff,"Id %s can't be of type void",(yyvsp[-1].lexval));
								   		yyerror(buff);
								   	}
 							   }
#line 1622 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 14:
#line 245 "parser.y" /* yacc.c:1667  */
    {(yyval.tipo)=t;}
#line 1628 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 15:
#line 246 "parser.y" /* yacc.c:1667  */
    {
												if((yyvsp[-2].numint)>=0){
													int nw=(yyvsp[-2].numint)*((yyvsp[0].tipo)->width);
													type nt={"array",(yyvsp[0].tipo),nw,(yyvsp[-2].numint),NULL};
													/*TODO: Duplicates! eg i[3] and j[3] have same type!*/
													(yyval.tipo)=insertType(&nt);
												}
												else{
													char* s="Arrays can't be negative size";
													yyerror(s);
												}
										    }
#line 1645 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 17:
#line 261 "parser.y" /* yacc.c:1667  */
    {
																			if(existsSymbol((yyvsp[-1].lexval))>-1)
																				functionAlreadyUsed=1;
																			else{
																				push(env,(void*)ts);
																				push(stack,(void*)offset);
																				offset=newOffset();
																				ts=newSymbolTable();
																			}
																		}
#line 1660 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 18:
#line 271 "parser.y" /* yacc.c:1667  */
    {}
#line 1666 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 19:
#line 272 "parser.y" /* yacc.c:1667  */
    {
																			printf("Symbol table for %s\n",(yyvsp[-10].lexval));
																			print_symbol_table();
																			if(functionAlreadyUsed==0){
																				vector* prev=ts;
																				ts=(vector*)pop(env);
																				offset=(unsigned int*)pop(stack);
																				insertFunction((yyvsp[-10].lexval),t,"function",prev,(yyvsp[-7].args));
																			}
																			else{
																	   			char buff[100];
																	   			sprintf(buff,"Id %s has been already declared",(yyvsp[-10].lexval));
																	   			yyerror(buff);
																	   		}
			 															}
#line 1686 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 20:
#line 290 "parser.y" /* yacc.c:1667  */
    {(yyval.args)=0;}
#line 1692 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 21:
#line 291 "parser.y" /* yacc.c:1667  */
    {(yyval.args)=(yyvsp[0].args);}
#line 1698 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 22:
#line 293 "parser.y" /* yacc.c:1667  */
    {
											(yyval.args)=(yyvsp[-3].args)+1;
											if(existsSymbol((yyvsp[0].lexval))==-1)
												insertSymbol((yyvsp[0].lexval),t,"arg");
											else{
												char* s="Repeated argument name";
												yyerror(s);
											}
													
										}
#line 1713 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 23:
#line 303 "parser.y" /* yacc.c:1667  */
    {
											(yyval.args)=1;
											if(existsSymbol((yyvsp[0].lexval))==-1)
											insertSymbol((yyvsp[0].lexval),t,"arg");
											else{
												char* s="Repeated argument name";
												yyerror(s);
											}
										}
#line 1727 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 26:
#line 316 "parser.y" /* yacc.c:1667  */
    {print_quads();}
#line 1733 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 27:
#line 317 "parser.y" /* yacc.c:1667  */
    {}
#line 1739 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 28:
#line 318 "parser.y" /* yacc.c:1667  */
    {}
#line 1745 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 29:
#line 319 "parser.y" /* yacc.c:1667  */
    {}
#line 1751 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 30:
#line 320 "parser.y" /* yacc.c:1667  */
    {}
#line 1757 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 31:
#line 321 "parser.y" /* yacc.c:1667  */
    {
																					/*CHECK!*/
																					if(strcmp((yyvsp[-3].exp)->tipo->name,(yyvsp[-1].exp)->tipo->name)==0){
																						genQuad("ASSIGN",(yyvsp[-1].exp)->dir,"",(yyvsp[-3].exp)->dir);
																						(yyval.stmt)=createStatement(quads);
																						printf("Statement: assignation.\n");
																						print_quads();
																						quads=newQuadsVector();

																					}
																					else{
																						char* s="Error. Assign of two different types";
																						yyerror(s);
																					}
																				}
#line 1777 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 32:
#line 336 "parser.y" /* yacc.c:1667  */
    {}
#line 1783 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 33:
#line 337 "parser.y" /* yacc.c:1667  */
    {}
#line 1789 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 34:
#line 338 "parser.y" /* yacc.c:1667  */
    {}
#line 1795 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 35:
#line 339 "parser.y" /* yacc.c:1667  */
    {}
#line 1801 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 36:
#line 340 "parser.y" /* yacc.c:1667  */
    {}
#line 1807 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 37:
#line 341 "parser.y" /* yacc.c:1667  */
    {}
#line 1813 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 42:
#line 350 "parser.y" /* yacc.c:1667  */
    {
							sym* res=lookupSymbol((yyvsp[0].lexval));
							if(res!=NULL){
								(yyval.exp)=createExpression(res->type);
								sprintf((yyval.exp)->dir,"%s",res->id);
							}
							else{
								char* s="Symbol not found.";
								yyerror(s);
							}
						}
#line 1829 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 43:
#line 361 "parser.y" /* yacc.c:1667  */
    {
							(yyval.exp)=createExpression((yyvsp[0].arr)->tipo);
							sprintf((yyval.exp)->dir,"%s[%s]",(yyvsp[0].arr)->base,(yyvsp[0].arr)->dir);

						}
#line 1839 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 44:
#line 366 "parser.y" /* yacc.c:1667  */
    {
							sym* res=lookupSymbol((yyvsp[-2].lexval));
							char buff[100];
							if(res!=NULL){
								if(strcmp((res->type)->name,"register")==0){
									int exists=existsSymbolInTable((yyvsp[0].lexval),(res->type)->ts);
									if(exists>=0){
										sym* res2=(sym*)vector_get((res->type)->ts,exists);
										(yyval.exp)=createExpression(res2->type);
										sprintf((yyval.exp)->dir,"%s.%s",(yyvsp[-2].lexval),(yyvsp[0].lexval));
									}
									else{
										sprintf(buff,"Register type %s does not contain field %s",(yyvsp[-2].lexval),(yyvsp[0].lexval));
										yyerror(buff);
									}
								}
								else{
									sprintf(buff,"Symbol %s is not of type register",(yyvsp[-2].lexval));
									yyerror(buff);
								}
							}
							else{
								sprintf(buff,"Symbol %s not found",(yyvsp[-2].lexval));
								yyerror(buff);
							}
						}
#line 1870 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 45:
#line 393 "parser.y" /* yacc.c:1667  */
    {
															sym* res=lookupSymbol((yyvsp[-3].lexval));
															if(res!=NULL){
																(yyval.arr)=createArrVar((res->type)->base);
																sprintf((yyval.arr)->base,"%s",res->id);
																sprintf((yyval.arr)->dir,"%s",newTemp());
																char buff[32];
																sprintf(buff,"%d",((yyval.arr)->tipo)->width);
																genQuad("PROD",(yyvsp[-1].exp)->dir,buff,(yyval.arr)->dir);
															}
															else{
																char* s="Symbol not found";
																yyerror(s);
															}
														}
#line 1890 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 46:
#line 408 "parser.y" /* yacc.c:1667  */
    {
															(yyval.arr)=createArrVar(((yyvsp[-3].arr)->tipo)->base);
															strcpy((yyval.arr)->base,(yyvsp[-3].arr)->base);
															char* temp=newTemp();
															sprintf((yyval.arr)->dir,"%s",newTemp());
															char buff[32];
															sprintf(buff,"%d",((yyval.arr)->tipo)->width);
															genQuad("PROD",(yyvsp[-1].exp)->dir,buff,temp);
															genQuad("PLUS",(yyvsp[-3].arr)->dir,temp,(yyval.arr)->dir);
														}
#line 1905 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 47:
#line 420 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("PLUS",(yyvsp[-2].exp),(yyvsp[0].exp));}
#line 1911 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 48:
#line 421 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("MINUS",(yyvsp[-2].exp),(yyvsp[0].exp));}
#line 1917 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 49:
#line 422 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("PROD",(yyvsp[-2].exp),(yyvsp[0].exp));}
#line 1923 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 50:
#line 423 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("DIV",(yyvsp[-2].exp),(yyvsp[0].exp));}
#line 1929 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 51:
#line 424 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("MODULO",(yyvsp[-2].exp),(yyvsp[0].exp));}
#line 1935 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 52:
#line 425 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("MINUS",zero,(yyvsp[0].exp));}
#line 1941 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 53:
#line 426 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("PLUS",zero,(yyvsp[0].exp));}
#line 1947 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 54:
#line 428 "parser.y" /* yacc.c:1667  */
    {
												sym* res=lookupSymbol((yyvsp[0].lexval));
												if(res!=NULL){
													(yyval.exp)=createExpression(res->type);
													sprintf((yyval.exp)->dir,"%s",res->id);
												}
												else{
													char* s="Symbol not found.";
													yyerror(s);
												}	
										   }
#line 1963 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 55:
#line 439 "parser.y" /* yacc.c:1667  */
    {
												(yyval.exp)=createExpression((yyvsp[0].arr)->tipo);
												sprintf((yyval.exp)->dir,"%s",newTemp());
												char buff[32];
												sprintf(buff,"%s[%s]",(yyvsp[0].arr)->base,(yyvsp[0].arr)->dir);
												genQuad("ASSIGN",buff,"",(yyval.exp)->dir);
											}
#line 1975 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 56:
#line 446 "parser.y" /* yacc.c:1667  */
    {
												sym* res=lookupSymbol((yyvsp[-2].lexval));
												char buff[100];
												if(res!=NULL){
													if(strcmp((res->type)->name,"register")==0){
														int exists=existsSymbolInTable((yyvsp[0].lexval),(res->type)->ts);
														if(exists>=0){
															sym* res2=(sym*)vector_get((res->type)->ts,exists);
															(yyval.exp)=createExpression(res2->type);
															sprintf((yyval.exp)->dir,"%s",newTemp());
															genQuad(".",(yyvsp[-2].lexval),(yyvsp[0].lexval),(yyval.exp)->dir);
														}
														else{
															sprintf(buff,"Register type %s does not contain field %s",(yyvsp[-2].lexval),(yyvsp[0].lexval));
															yyerror(buff);
														}

													}
													else{
														sprintf(buff,"Symbol %s is not of type register",(yyvsp[-2].lexval));
														yyerror(buff);
													}
												}
												else{
													sprintf(buff,"Symbol %s not found",(yyvsp[-2].lexval));
													yyerror(buff);
												}
										    }
#line 2008 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 57:
#line 474 "parser.y" /* yacc.c:1667  */
    {}
#line 2014 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 58:
#line 475 "parser.y" /* yacc.c:1667  */
    {}
#line 2020 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 59:
#line 476 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=createExpression((type*)vector_get(tt,1));sprintf((yyval.exp)->dir,"%d",(yyvsp[0].numint));}
#line 2026 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 60:
#line 477 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=createExpression((type*)vector_get(tt,2));sprintf((yyval.exp)->dir,"%f",(yyvsp[0].numfloat));}
#line 2032 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 61:
#line 478 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=createExpression((type*)vector_get(tt,3));sprintf((yyval.exp)->dir,"%f",(yyvsp[0].numdouble));}
#line 2038 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 62:
#line 479 "parser.y" /* yacc.c:1667  */
    {}
#line 2044 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 67:
#line 488 "parser.y" /* yacc.c:1667  */
    {
													char* lbl=newLabel();
													backpatch((yyvsp[-1].cond)->fl,lbl);
													genQuad("LABEL",lbl,"","");
												}
#line 2054 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 68:
#line 493 "parser.y" /* yacc.c:1667  */
    {
			  										(yyval.cond)=createConditionLists();
			  										(yyval.cond)->tl=merge((yyvsp[-3].cond)->tl,(yyvsp[0].cond)->tl);
			  										(yyval.cond)->fl=(yyvsp[0].cond)->fl;
												}
#line 2064 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 69:
#line 498 "parser.y" /* yacc.c:1667  */
    {
													char* lbl=newLabel();
													backpatch((yyvsp[-1].cond)->tl,lbl);
													genQuad("LABEL",lbl,"","");
												}
#line 2074 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 70:
#line 503 "parser.y" /* yacc.c:1667  */
    {
			  										(yyval.cond)=createConditionLists();
			  										(yyval.cond)->tl=(yyvsp[0].cond)->tl;
			  										(yyval.cond)->fl=merge((yyvsp[-3].cond)->fl,(yyvsp[0].cond)->fl);
												}
#line 2084 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 71:
#line 508 "parser.y" /* yacc.c:1667  */
    {
													/*use same struct, change fields?*/
													(yyval.cond)=createConditionLists();
													(yyval.cond)->tl=(yyvsp[0].cond)->fl;
													(yyval.cond)->fl=(yyvsp[0].cond)->tl;
												}
#line 2095 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 72:
#line 514 "parser.y" /* yacc.c:1667  */
    {(yyval.cond)=(yyvsp[-1].cond);}
#line 2101 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 73:
#line 515 "parser.y" /* yacc.c:1667  */
    {	
													/*CHECK EXPRESSIONS TYPE! or do implicit cast!*/
													if(strcmp((yyvsp[-2].exp)->tipo->name,(yyvsp[0].exp)->tipo->name)==0){
														(yyval.cond)=createConditionLists();
														vector_add((yyval.cond)->tl,genQuad((yyvsp[-1].rel),(yyvsp[-2].exp)->dir,(yyvsp[0].exp)->dir,"GOTO _"));
														vector_add((yyval.cond)->fl,genQuad("GOTO","_","",""));
													}
													else{
														char buff[100];
														sprintf(buff,"Expressions %s and %s have different types.",(yyvsp[-2].exp)->dir,(yyvsp[0].exp)->dir);
														yyerror(buff);
													}
												}
#line 2119 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 74:
#line 528 "parser.y" /* yacc.c:1667  */
    {
													(yyval.cond)=createConditionLists();
													vector_add((yyval.cond)->tl,genQuad("GOTO","_","",""));
												}
#line 2128 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 75:
#line 532 "parser.y" /* yacc.c:1667  */
    {
													(yyval.cond)=createConditionLists();
													vector_add((yyval.cond)->fl,genQuad("GOTO","_","",""));
												}
#line 2137 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 76:
#line 537 "parser.y" /* yacc.c:1667  */
    {strcpy((yyval.rel),"LTHAN");}
#line 2143 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 77:
#line 538 "parser.y" /* yacc.c:1667  */
    {strcpy((yyval.rel),"GTHAN");}
#line 2149 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 78:
#line 539 "parser.y" /* yacc.c:1667  */
    {strcpy((yyval.rel),"GETHAN");}
#line 2155 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 79:
#line 540 "parser.y" /* yacc.c:1667  */
    {strcpy((yyval.rel),"LETHAN");}
#line 2161 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 80:
#line 541 "parser.y" /* yacc.c:1667  */
    {strcpy((yyval.rel),"NEQUAL");}
#line 2167 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 81:
#line 542 "parser.y" /* yacc.c:1667  */
    {strcpy((yyval.rel),"EQUAL");}
#line 2173 "parser.tab.c" /* yacc.c:1667  */
    break;


#line 2177 "parser.tab.c" /* yacc.c:1667  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 546 "parser.y" /* yacc.c:1918  */


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

void backpatch(vector* lst,char* lbl){
	int i;
	for (i = 0;i<vector_total(lst); i++){
		quad* q=(quad*)vector_get(lst,i);
		if(strcmp(q->arg1,"_")==0)
			strcpy(q->arg1,lbl);
		else
			strcpy(q->res,lbl);			
	}
}

vector* merge(vector* v1,vector* v2){
	int i;
	for (i = 0;i<vector_total(v2); i++){
		quad* q=(quad*)vector_get(v2,i);
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
	/*'_t'+32 possible digits*/
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
statement* createStatement(vector* code){
	statement st={.code=code};
	statement* ptr=(statement*)malloc(sizeof(statement));
	*ptr=st;
	return ptr;
}

condition* createConditionLists(){
	vector* tl=(vector*)malloc(sizeof(vector));
	vector_init(tl);
	vector* fl=(vector*)malloc(sizeof(vector));
	vector_init(fl);
	condition c={.tl=tl,.fl=fl};
	condition* ptr=(condition*)malloc(sizeof(condition));
	*ptr=c;
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

void print_quads(){
	int i;
	printf("Quads:\n");
	for (i = 0; i < vector_total(quads); i++){
		quad* q=((quad*)vector_get(quads,i));
		if(strcmp(q->op,"LTHAN")==0)
			printf("%s %s %s %s\n",q->op,q->arg1,q->arg2,q->res);
		else if(strcmp(q->op,"GTHAN")==0)
			printf("%s %s %s %s\n",q->op,q->arg1,q->arg2,q->res);
		else if(strcmp(q->op,"LETHAN")==0)
			printf("%s %s %s %s\n",q->op,q->arg1,q->arg2,q->res);
		else if(strcmp(q->op,"GETHAN")==0)
			printf("%s %s %s %s\n",q->op,q->arg1,q->arg2,q->res);
		else if(strcmp(q->op,"EQUAL")==0)
			printf("%s %s %s %s\n",q->op,q->arg1,q->arg2,q->res);
		else if(strcmp(q->op,"NEQUAL")==0)
			printf("%s %s %s %s\n",q->op,q->arg1,q->arg2,q->res);
		else if(strcmp(q->op,"GOTO")==0)
			printf("%s %s\n",q->op,q->arg1);
		else if(strcmp(q->op,"LABEL")==0)
			printf("%s %s\n",q->op,q->arg1);
		else	
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
}
