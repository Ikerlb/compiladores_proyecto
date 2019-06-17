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
	statement* createStatement();
	void print_quads(vector*);
	vector* newQuadsVector();
	condition* createConditionLists();
	void backpatch(vector*,char*);
	vector* merge(vector*,vector*);
	ifthen* createIfThen(condition*);
	ifelse* createIfElse();
	vector* createList();
	ifaux* createIfAux();

#line 246 "parser.tab.c" /* yacc.c:352  */

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
#line 144 "parser.y" /* yacc.c:352  */

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
	ifthen* it;
	ifelse* ie;
	ifaux* nif;

#line 330 "parser.tab.c" /* yacc.c:352  */
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
#define YYLAST   250

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

#define YYUNDEFTOK  2
#define YYMAXUTOK   310

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   207,   207,   210,   211,   215,   216,   217,   218,   219,
     220,   220,   236,   254,   273,   274,   288,   289,   299,   289,
     318,   319,   321,   331,   341,   342,   344,   358,   361,   358,
     367,   370,   373,   385,   388,   389,   390,   391,   392,   394,
     394,   404,   405,   412,   420,   421,   423,   424,   427,   438,
     443,   470,   485,   497,   498,   499,   500,   501,   502,   503,
     505,   516,   523,   551,   552,   553,   554,   555,   556,   559,
     559,   562,   563,   565,   565,   575,   575,   585,   591,   592,
     605,   609,   614,   615,   616,   617,   618,   619
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
  "BREAK", "COLON", "UOPS", "\"then\"", "$accept", "Program",
  "Declarations", "Type", "$@1", "List", "Array", "Functions", "$@2",
  "$@3", "Args", "ListArgs", "Statements", "Statement", "$@4", "$@5", "If",
  "$@6", "Else", "Nif", "Cases", "Default", "LeftPart", "ArrayVar",
  "Expression", "Params", "ListParams", "Condition", "$@7", "$@8",
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
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF -69

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-69)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     224,   -69,   -69,   -69,   -69,   -69,   -69,     2,   -40,   -25,
     -15,   -69,   224,   -69,   -12,   -19,   224,    -8,    13,   -69,
     224,    -6,    26,    42,    71,   -69,   -12,   -69,   -69,   -12,
     -69,   224,   -69,    58,   -69,    40,   -69,    77,   224,    84,
      88,   224,   -69,    37,   105,   147,   167,    37,   107,   111,
      37,     9,   115,   141,    47,   -69,   160,   153,   132,   137,
     -69,   -69,   167,   167,   106,   -69,   -69,   -69,   -69,   132,
      39,   213,   168,   -69,    37,   101,   167,   131,   167,   -69,
     -40,   -69,   -69,   -69,   167,   167,   -69,   -69,   137,   137,
     195,   -10,   -69,   -69,   167,   133,   -69,   167,   167,   167,
     167,   167,   144,   137,   170,   -69,   103,   -69,   200,   -69,
      37,    62,   174,   -69,    -7,   -69,   -69,   -69,   -69,   -69,
     -69,   167,   -69,   -69,   -69,   213,   150,   145,   -69,    86,
      86,   -69,   -69,   -69,   137,    55,   137,   -69,   159,   -69,
     -69,   -69,   -69,   213,   137,   137,    37,   -69,   167,    76,
     -69,   146,   190,   -69,   -69,   -69,   213,   181,    37,    37,
     165,   180,   -69,   -69,   183,   196,   -69,    37,    37,   -69,
     151,   197,   -69,    37,    37
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
       0,    48,     0,     0,     0,    25,    41,     0,    49,     0,
      64,    34,     0,     0,    60,    65,    66,    67,    63,    61,
       0,    38,     0,    27,     0,     0,     0,     0,     0,    37,
      16,    24,    43,    26,     0,     0,    80,    81,     0,     0,
       0,     0,    59,    58,    69,     0,    33,     0,     0,     0,
       0,     0,     0,     0,     0,    35,     0,    50,     0,    19,
       0,     0,     0,    77,     0,    87,    86,    82,    85,    83,
      84,     0,    75,    73,    39,    72,     0,    70,    62,    53,
      54,    55,    56,    57,     0,     0,     0,    51,     0,    42,
      32,    52,    78,    79,     0,     0,     0,    68,     0,     0,
      28,     0,    44,    76,    74,    40,    71,     0,     0,     0,
       0,     0,    30,    29,     0,     0,    36,     0,     0,    31,
      46,     0,    45,     0,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -69,   -69,    -4,    -9,   -69,   -69,    61,   124,   -69,   -69,
     -69,   -69,   -45,   -41,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,   -43,   -37,   -69,   -69,   -68,   -69,   -69,
     -69
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    15,    19,    13,    31,    37,
      34,    35,    54,    55,   103,   158,    56,   146,    83,   110,
     161,   172,    57,    69,    90,   126,   127,    91,   145,   144,
     121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      58,    20,    11,    17,    58,    75,    72,    58,    70,    71,
      12,    58,    22,    81,   122,   123,    25,   122,   123,    14,
     113,   114,    33,    16,    21,    92,    93,   124,    18,    40,
     142,    58,    58,   104,    81,   135,    23,    43,    26,   106,
      44,   108,    45,    46,    47,    48,    49,   111,   112,    76,
      44,    77,    45,    46,    47,    48,    49,   125,    24,    96,
     129,   130,   131,   132,   133,    27,   149,    58,   151,   139,
      97,    98,    99,   100,   101,    50,   153,   154,    28,   122,
     123,    51,   140,    38,   143,    50,    80,    30,    52,    53,
      32,    51,   150,    97,    98,    99,   100,   101,    52,    53,
     122,   123,    36,    58,    44,   155,    45,    46,    47,    48,
      49,   156,    29,   157,    39,    58,    58,   163,   164,    99,
     100,   101,    41,   170,    58,    58,   169,    58,   174,    81,
      58,    58,    42,    81,    97,    98,    99,   100,   101,    50,
     105,    59,    94,    73,   137,    51,    76,    74,    95,    86,
      87,    78,    52,    53,    44,    60,    45,    46,    47,    48,
      49,    79,   171,    88,    82,    60,   159,    61,    62,    63,
     122,   123,    85,    89,    84,   107,   102,   128,    62,    63,
     134,    64,    65,    66,    67,    60,    68,   147,   148,    50,
     136,    64,    65,    66,    67,    51,    68,   152,    62,    63,
     160,   162,    52,    53,   109,    97,    98,    99,   100,   101,
     165,    64,    65,    66,    67,   141,    68,   115,   116,   166,
     167,     0,   117,   118,   119,   120,    97,    98,    99,   100,
     101,    97,    98,    99,   100,   101,     0,   138,     1,     2,
       3,     4,     5,     6,    97,    98,    99,   100,   101,   168,
     173
};

static const yytype_int16 yycheck[] =
{
      43,    20,     0,    12,    47,    50,    47,    50,    45,    46,
      50,    54,    16,    54,    24,    25,    20,    24,    25,    44,
      88,    89,    31,    38,    43,    62,    63,    37,    40,    38,
      37,    74,    75,    74,    75,   103,    44,    41,    44,    76,
       3,    78,     5,     6,     7,     8,     9,    84,    85,    40,
       3,    42,     5,     6,     7,     8,     9,    94,    45,    20,
      97,    98,    99,   100,   101,    39,   134,   110,   136,   110,
      31,    32,    33,    34,    35,    38,   144,   145,    36,    24,
      25,    44,    20,    43,   121,    38,    39,    26,    51,    52,
      29,    44,    37,    31,    32,    33,    34,    35,    51,    52,
      24,    25,    44,   146,     3,   146,     5,     6,     7,     8,
       9,   148,    41,    37,    37,   158,   159,   158,   159,    33,
      34,    35,    38,   168,   167,   168,   167,   170,   173,   170,
     173,   174,    44,   174,    31,    32,    33,    34,    35,    38,
      39,    36,    36,    36,    41,    44,    40,    36,    42,    12,
      13,    36,    51,    52,     3,    18,     5,     6,     7,     8,
       9,    20,    11,    26,     4,    18,    20,    20,    31,    32,
      24,    25,    40,    36,    21,    44,     8,    44,    31,    32,
      36,    44,    45,    46,    47,    18,    49,    37,    43,    38,
      20,    44,    45,    46,    47,    44,    49,    38,    31,    32,
      10,    20,    51,    52,    80,    31,    32,    33,    34,    35,
      45,    44,    45,    46,    47,    41,    49,    22,    23,    39,
      37,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    31,    32,    33,    34,    35,    -1,    37,    14,    15,
      16,    17,    18,    19,    31,    32,    33,    34,    35,    53,
      53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    15,    16,    17,    18,    19,    57,    58,    59,
      60,     0,    50,    63,    44,    61,    38,    59,    40,    62,
      20,    43,    58,    44,    45,    58,    44,    39,    36,    41,
      62,    64,    62,    59,    66,    67,    44,    65,    43,    37,
      59,    38,    44,    58,     3,     5,     6,     7,     8,     9,
      38,    44,    51,    52,    68,    69,    72,    78,    79,    36,
      18,    20,    31,    32,    44,    45,    46,    47,    49,    79,
      80,    80,    69,    36,    36,    68,    40,    42,    36,    20,
      39,    69,     4,    74,    21,    40,    12,    13,    26,    36,
      80,    83,    80,    80,    36,    42,    20,    31,    32,    33,
      34,    35,     8,    70,    69,    39,    80,    44,    80,    63,
      75,    80,    80,    83,    83,    22,    23,    27,    28,    29,
      30,    86,    24,    25,    37,    80,    81,    82,    44,    80,
      80,    80,    80,    80,    36,    83,    20,    41,    37,    69,
      20,    41,    37,    80,    85,    84,    73,    37,    43,    83,
      37,    83,    38,    83,    83,    69,    80,    37,    71,    20,
      10,    76,    20,    69,    69,    45,    39,    37,    53,    69,
      68,    11,    77,    53,    68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    59,    59,
      60,    59,    61,    61,    62,    62,    63,    64,    65,    63,
      66,    66,    67,    67,    68,    68,    69,    70,    71,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    73,
      72,    74,    74,    75,    76,    76,    77,    77,    78,    78,
      78,    79,    79,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    81,
      81,    82,    82,    84,    83,    85,    83,    83,    83,    83,
      83,    83,    86,    86,    86,    86,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     4,     1,     1,     1,     1,     1,
       0,     5,     4,     2,     0,     4,     0,     0,     0,    13,
       0,     1,     4,     2,     2,     1,     2,     0,     0,     7,
       7,     9,     4,     3,     2,     3,     7,     2,     2,     0,
       6,     0,     3,     0,     0,     5,     0,     3,     1,     1,
       3,     4,     4,     3,     3,     3,     3,     3,     2,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     4,     0,
       1,     3,     1,     0,     4,     0,     4,     2,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1
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
#line 215 "parser.y" /* yacc.c:1667  */
    {t=(type*)vector_get(tt,1);}
#line 1563 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 6:
#line 216 "parser.y" /* yacc.c:1667  */
    {t=(type*)vector_get(tt,2);}
#line 1569 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 7:
#line 217 "parser.y" /* yacc.c:1667  */
    {t=(type*)vector_get(tt,3);}
#line 1575 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 8:
#line 218 "parser.y" /* yacc.c:1667  */
    {t=(type*)vector_get(tt,4);}
#line 1581 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 9:
#line 219 "parser.y" /* yacc.c:1667  */
    {t=(type*)vector_get(tt,0);}
#line 1587 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 10:
#line 220 "parser.y" /* yacc.c:1667  */
    {
	  												push(env,(void*)ts);
													push(stack,(void*)offset);

													offset=newOffset();
													ts=newSymbolTable();
												}
#line 1599 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 11:
#line 227 "parser.y" /* yacc.c:1667  */
    {
	  												type nt={"register",NULL,*offset,-1,ts};
	  												ts=(vector*)pop(env);
	  												offset=(unsigned int*)pop(stack);
	  												t=insertType(&nt);
	  											}
#line 1610 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 12:
#line 236 "parser.y" /* yacc.c:1667  */
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
#line 1633 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 13:
#line 254 "parser.y" /* yacc.c:1667  */
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
#line 1655 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 14:
#line 273 "parser.y" /* yacc.c:1667  */
    {(yyval.tipo)=t;}
#line 1661 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 15:
#line 274 "parser.y" /* yacc.c:1667  */
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
#line 1678 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 17:
#line 289 "parser.y" /* yacc.c:1667  */
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
#line 1693 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 18:
#line 299 "parser.y" /* yacc.c:1667  */
    {}
#line 1699 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 19:
#line 300 "parser.y" /* yacc.c:1667  */
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
#line 1719 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 20:
#line 318 "parser.y" /* yacc.c:1667  */
    {(yyval.args)=0;}
#line 1725 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 21:
#line 319 "parser.y" /* yacc.c:1667  */
    {(yyval.args)=(yyvsp[0].args);}
#line 1731 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 22:
#line 321 "parser.y" /* yacc.c:1667  */
    {
											(yyval.args)=(yyvsp[-3].args)+1;
											if(existsSymbol((yyvsp[0].lexval))==-1)
												insertSymbol((yyvsp[0].lexval),t,"arg");
											else{
												char* s="Repeated argument name";
												yyerror(s);
											}
													
										}
#line 1746 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 23:
#line 331 "parser.y" /* yacc.c:1667  */
    {
											(yyval.args)=1;
											if(existsSymbol((yyvsp[0].lexval))==-1)
											insertSymbol((yyvsp[0].lexval),t,"arg");
											else{
												char* s="Repeated argument name";
												yyerror(s);
											}
										}
#line 1760 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 26:
#line 344 "parser.y" /* yacc.c:1667  */
    {
																					//ifthen
																					(yyval.stmt)=createStatement();
																					if((yyvsp[0].ie)==NULL){
																						(yyval.stmt)->nextlist=merge((yyvsp[-1].it)->bfl,(yyvsp[-1].it)->nextlist);
																						//print_quads($$->nextlist);
																					}
																					//ifelse
																					else{
																						backpatch((yyvsp[-1].it)->bfl,(yyvsp[0].ie)->lbl);
																						vector* temp=merge((yyvsp[-1].it)->nextlist,(yyvsp[0].ie)->n);
																						(yyval.stmt)->nextlist=merge(temp,(yyvsp[0].ie)->nextlist);
																					}
																				}
#line 1779 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 27:
#line 358 "parser.y" /* yacc.c:1667  */
    {

																				}
#line 1787 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 28:
#line 361 "parser.y" /* yacc.c:1667  */
    {

			  																	}
#line 1795 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 29:
#line 364 "parser.y" /* yacc.c:1667  */
    {

																				}
#line 1803 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 30:
#line 367 "parser.y" /* yacc.c:1667  */
    {

																				}
#line 1811 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 31:
#line 370 "parser.y" /* yacc.c:1667  */
    {

																				}
#line 1819 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 32:
#line 373 "parser.y" /* yacc.c:1667  */
    {
																					/*CHECK!*/
																					if(strcmp((yyvsp[-3].exp)->tipo->name,(yyvsp[-1].exp)->tipo->name)==0){
																						genQuad("ASSIGN",(yyvsp[-1].exp)->dir,"",(yyvsp[-3].exp)->dir);
																						(yyval.stmt)=createStatement();
																						(yyval.stmt)->nextlist=createList();
																					}
																					else{
																						char* s="Error. Assign of two different types";
																						yyerror(s);
																					}
																				}
#line 1836 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 33:
#line 385 "parser.y" /* yacc.c:1667  */
    {

																				}
#line 1844 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 34:
#line 388 "parser.y" /* yacc.c:1667  */
    {}
#line 1850 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 35:
#line 389 "parser.y" /* yacc.c:1667  */
    {}
#line 1856 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 36:
#line 390 "parser.y" /* yacc.c:1667  */
    {}
#line 1862 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 37:
#line 391 "parser.y" /* yacc.c:1667  */
    {}
#line 1868 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 38:
#line 392 "parser.y" /* yacc.c:1667  */
    {}
#line 1874 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 39:
#line 394 "parser.y" /* yacc.c:1667  */
    {
									char* lbl=newLabel();
									backpatch((yyvsp[-1].cond)->tl,lbl);
									genQuad("LABEL",lbl,"","");
								}
#line 1884 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 40:
#line 399 "parser.y" /* yacc.c:1667  */
    {
									(yyval.it)=createIfThen((yyvsp[-3].cond));
									(yyval.it)->nextlist=(yyvsp[0].stmt)->nextlist;
								}
#line 1893 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 41:
#line 404 "parser.y" /* yacc.c:1667  */
    {(yyval.ie)=NULL;}
#line 1899 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 42:
#line 405 "parser.y" /* yacc.c:1667  */
    {
								(yyval.ie)=createIfElse();
								strcpy((yyval.ie)->lbl,(yyvsp[-1].nif)->lbl);
								(yyval.ie)->n=(yyvsp[-1].nif)->nextlist;
								(yyval.ie)->nextlist=(yyvsp[0].stmt)->nextlist;
							 }
#line 1910 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 43:
#line 412 "parser.y" /* yacc.c:1667  */
    {
		(yyval.nif)=createIfAux();
		vector_add((yyval.nif)->nextlist,genQuad("GOTO","_","",""));
		char* lbl=newLabel();
		genQuad("LABEL",lbl,"","");
		strcpy((yyval.nif)->lbl,lbl);
	  }
#line 1922 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 48:
#line 427 "parser.y" /* yacc.c:1667  */
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
#line 1938 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 49:
#line 438 "parser.y" /* yacc.c:1667  */
    {
							(yyval.exp)=createExpression((yyvsp[0].arr)->tipo);
							sprintf((yyval.exp)->dir,"%s[%s]",(yyvsp[0].arr)->base,(yyvsp[0].arr)->dir);

						}
#line 1948 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 50:
#line 443 "parser.y" /* yacc.c:1667  */
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
#line 1979 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 51:
#line 470 "parser.y" /* yacc.c:1667  */
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
#line 1999 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 52:
#line 485 "parser.y" /* yacc.c:1667  */
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
#line 2014 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 53:
#line 497 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("PLUS",(yyvsp[-2].exp),(yyvsp[0].exp));}
#line 2020 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 54:
#line 498 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("MINUS",(yyvsp[-2].exp),(yyvsp[0].exp));}
#line 2026 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 55:
#line 499 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("PROD",(yyvsp[-2].exp),(yyvsp[0].exp));}
#line 2032 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 56:
#line 500 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("DIV",(yyvsp[-2].exp),(yyvsp[0].exp));}
#line 2038 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 57:
#line 501 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("MODULO",(yyvsp[-2].exp),(yyvsp[0].exp));}
#line 2044 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 58:
#line 502 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("MINUS",zero,(yyvsp[0].exp));}
#line 2050 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 59:
#line 503 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("PLUS",zero,(yyvsp[0].exp));}
#line 2056 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 60:
#line 505 "parser.y" /* yacc.c:1667  */
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
#line 2072 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 61:
#line 516 "parser.y" /* yacc.c:1667  */
    {
												(yyval.exp)=createExpression((yyvsp[0].arr)->tipo);
												sprintf((yyval.exp)->dir,"%s",newTemp());
												char buff[32];
												sprintf(buff,"%s[%s]",(yyvsp[0].arr)->base,(yyvsp[0].arr)->dir);
												genQuad("ASSIGN",buff,"",(yyval.exp)->dir);
											}
#line 2084 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 62:
#line 523 "parser.y" /* yacc.c:1667  */
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
#line 2117 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 63:
#line 551 "parser.y" /* yacc.c:1667  */
    {}
#line 2123 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 64:
#line 552 "parser.y" /* yacc.c:1667  */
    {}
#line 2129 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 65:
#line 553 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=createExpression((type*)vector_get(tt,1));sprintf((yyval.exp)->dir,"%d",(yyvsp[0].numint));}
#line 2135 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 66:
#line 554 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=createExpression((type*)vector_get(tt,2));sprintf((yyval.exp)->dir,"%f",(yyvsp[0].numfloat));}
#line 2141 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 67:
#line 555 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=createExpression((type*)vector_get(tt,3));sprintf((yyval.exp)->dir,"%f",(yyvsp[0].numdouble));}
#line 2147 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 68:
#line 556 "parser.y" /* yacc.c:1667  */
    {}
#line 2153 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 73:
#line 565 "parser.y" /* yacc.c:1667  */
    {
													char* lbl=newLabel();
													backpatch((yyvsp[-1].cond)->fl,lbl);
													genQuad("LABEL",lbl,"","");
												}
#line 2163 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 74:
#line 570 "parser.y" /* yacc.c:1667  */
    {
			  										(yyval.cond)=createConditionLists();
			  										(yyval.cond)->tl=merge((yyvsp[-3].cond)->tl,(yyvsp[0].cond)->tl);
			  										(yyval.cond)->fl=(yyvsp[0].cond)->fl;
												}
#line 2173 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 75:
#line 575 "parser.y" /* yacc.c:1667  */
    {
													char* lbl=newLabel();
													backpatch((yyvsp[-1].cond)->tl,lbl);
													genQuad("LABEL",lbl,"","");
												}
#line 2183 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 76:
#line 580 "parser.y" /* yacc.c:1667  */
    {
			  										(yyval.cond)=createConditionLists();
			  										(yyval.cond)->tl=(yyvsp[0].cond)->tl;
			  										(yyval.cond)->fl=merge((yyvsp[-3].cond)->fl,(yyvsp[0].cond)->fl);
												}
#line 2193 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 77:
#line 585 "parser.y" /* yacc.c:1667  */
    {
													/*use same struct, change fields?*/
													(yyval.cond)=createConditionLists();
													(yyval.cond)->tl=(yyvsp[0].cond)->fl;
													(yyval.cond)->fl=(yyvsp[0].cond)->tl;
												}
#line 2204 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 78:
#line 591 "parser.y" /* yacc.c:1667  */
    {(yyval.cond)=(yyvsp[-1].cond);}
#line 2210 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 79:
#line 592 "parser.y" /* yacc.c:1667  */
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
#line 2228 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 80:
#line 605 "parser.y" /* yacc.c:1667  */
    {
													(yyval.cond)=createConditionLists();
													vector_add((yyval.cond)->tl,genQuad("GOTO","_","",""));
												}
#line 2237 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 81:
#line 609 "parser.y" /* yacc.c:1667  */
    {
													(yyval.cond)=createConditionLists();
													vector_add((yyval.cond)->fl,genQuad("GOTO","_","",""));
												}
#line 2246 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 82:
#line 614 "parser.y" /* yacc.c:1667  */
    {strcpy((yyval.rel),"LTHAN");}
#line 2252 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 83:
#line 615 "parser.y" /* yacc.c:1667  */
    {strcpy((yyval.rel),"GTHAN");}
#line 2258 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 84:
#line 616 "parser.y" /* yacc.c:1667  */
    {strcpy((yyval.rel),"GETHAN");}
#line 2264 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 85:
#line 617 "parser.y" /* yacc.c:1667  */
    {strcpy((yyval.rel),"LETHAN");}
#line 2270 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 86:
#line 618 "parser.y" /* yacc.c:1667  */
    {strcpy((yyval.rel),"NEQUAL");}
#line 2276 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 87:
#line 619 "parser.y" /* yacc.c:1667  */
    {strcpy((yyval.rel),"EQUAL");}
#line 2282 "parser.tab.c" /* yacc.c:1667  */
    break;


#line 2286 "parser.tab.c" /* yacc.c:1667  */
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
#line 623 "parser.y" /* yacc.c:1918  */


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

void print_quads(vector* quads){
	int i;
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
	print_quads(quads);
	print_type_table();
	printf("Main symbol table\n");
	print_symbol_table();
	printf("%d\n",*offset);
}
