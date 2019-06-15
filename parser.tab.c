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

	typedef struct {
		type* tipo;
		char dir[34];
	} expr;

	typedef struct{
		type* tipo;
		char dir[34];
		char base[34];
	} arrVar;

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
	arrVar* createArrVar(type*);
	int existsSymbolInTable(char*,vector*);

#line 209 "parser.tab.c" /* yacc.c:352  */

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
#line 107 "parser.y" /* yacc.c:352  */

	type* tipo;
	char lexval[32];
	double numdouble;
	float numfloat;
	int numint;
	int args;
	expr* exp;
	arrVar* arr;

#line 287 "parser.tab.c" /* yacc.c:352  */
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
#define YYLAST   248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

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
       0,   157,   157,   160,   161,   165,   166,   167,   168,   169,
     170,   170,   186,   204,   223,   224,   238,   239,   249,   239,
     268,   269,   271,   281,   291,   292,   294,   295,   296,   297,
     298,   299,   309,   310,   311,   312,   313,   314,   316,   317,
     319,   320,   323,   334,   341,   357,   372,   377,   378,   379,
     380,   381,   382,   383,   385,   396,   403,   419,   420,   421,
     422,   423,   424,   427,   427,   430,   431,   433,   434,   435,
     436,   437,   438,   439,   441,   442,   443,   444,   445,   446
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
  "Expression", "Params", "ListParams", "Condition", "Relational", YY_NULLPTR
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

#define YYPACT_NINF -50

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-50)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     222,   -50,   -50,   -50,   -50,   -50,   -50,    10,   -35,   -17,
      -9,   -50,   222,   -50,    -6,    -8,   222,    -3,    -2,   -50,
     222,     2,     9,    15,    32,   -50,    -6,   -50,   -50,    -6,
     -50,   222,   -50,     8,   -50,    44,   -50,    19,   222,    64,
      45,   222,   -50,   128,    56,    54,   160,   128,    68,    73,
     128,   -39,    77,    94,    11,   -50,   107,    98,   139,   -50,
     -50,   160,   160,    42,   -50,   -50,   -50,   -50,    98,    33,
     211,   140,   139,   128,    88,   160,   106,   160,   -50,   -35,
     -50,   160,   160,   -50,   -50,   139,   139,   188,    87,   -50,
     -50,   160,   109,   -50,   160,   160,   160,   160,   160,   120,
     105,   148,   -50,   162,   -50,   198,   -50,   167,   193,   -50,
     130,   -50,   -50,   -50,   -50,   -50,   -50,   160,   139,   139,
     128,   211,   121,   116,   -50,   129,   129,   -50,   -50,   -50,
     139,   128,   139,   -50,   131,   -50,   -50,   -50,   211,   -50,
     -50,   170,   -50,   160,   136,   -50,    51,   171,   128,   211,
     157,   128,   163,   173,   -50,   -50,   176,   161,   -50,   128,
     128,   -50,   138,   194,   -50,   128,   128
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
      24,     0,     0,    72,    73,     0,     0,     0,     0,    53,
      52,    63,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,    44,     0,    19,     0,     0,    69,
       0,    79,    78,    74,    77,    75,    76,     0,     0,     0,
       0,    66,     0,    64,    56,    47,    48,    49,    50,    51,
       0,     0,     0,    45,     0,    31,    46,    70,    71,    68,
      67,    26,    62,     0,     0,    28,     0,    38,     0,    65,
       0,     0,     0,     0,    27,    29,     0,     0,    35,     0,
       0,    30,    40,     0,    39,     0,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -50,   -50,     6,   -10,   -50,   -50,    13,   169,   -50,   -50,
     -50,   -50,   -45,   -41,   -50,   -50,   -50,   -43,   -37,   -50,
     -50,   -49,   -50
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    15,    19,    13,    31,    37,
      34,    35,    54,    55,   153,   164,    56,    68,    87,   122,
     123,    88,   117
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    75,    17,    76,    57,    74,    71,    57,    69,    70,
      11,    57,    20,    80,    44,    12,    45,    46,    47,    48,
      49,    33,    22,   100,    89,    90,    25,    14,    40,    16,
      57,    57,   101,    80,    18,    21,   109,   110,   103,    30,
     105,    23,    32,    24,   107,   108,    26,    43,    27,    50,
      79,    28,    36,    93,   121,    51,    39,   125,   126,   127,
     128,   129,    52,    53,    94,    95,    96,    97,    98,   139,
     140,   151,    59,    29,    60,   118,   119,    57,    91,   141,
     138,   144,    75,   146,    92,    61,    62,    38,    57,    42,
     145,    44,    58,    45,    46,    47,    48,    49,    63,    64,
      65,    66,    41,    67,    72,    57,   149,   154,    57,    73,
     156,   118,   119,    77,    78,   162,    57,    57,   161,    57,
     166,    80,    57,    57,   120,    80,    50,   102,    81,   118,
     119,    44,    51,    45,    46,    47,    48,    49,    82,    52,
      53,    44,   131,    45,    46,    47,    48,    49,    99,   163,
     104,    83,    84,   124,   118,   119,   130,    59,   142,   143,
     118,   119,    96,    97,    98,    85,    50,   137,   132,   147,
      61,    62,    51,   150,   148,    86,    50,   155,    59,    52,
      53,   152,    51,    63,    64,    65,    66,   135,    67,    52,
      53,    61,    62,    94,    95,    96,    97,    98,    94,    95,
      96,    97,    98,   133,    63,    64,    65,    66,   157,    67,
     111,   112,   158,   159,   160,   113,   114,   115,   116,    94,
      95,    96,    97,    98,    94,    95,    96,    97,    98,    94,
      95,    96,    97,    98,   136,   134,     1,     2,     3,     4,
       5,     6,    94,    95,    96,    97,    98,   165,   106
};

static const yytype_uint8 yycheck[] =
{
      43,    40,    12,    42,    47,    50,    47,    50,    45,    46,
       0,    54,    20,    54,     3,    50,     5,     6,     7,     8,
       9,    31,    16,    72,    61,    62,    20,    44,    38,    38,
      73,    74,    73,    74,    40,    43,    85,    86,    75,    26,
      77,    44,    29,    45,    81,    82,    44,    41,    39,    38,
      39,    36,    44,    20,    91,    44,    37,    94,    95,    96,
      97,    98,    51,    52,    31,    32,    33,    34,    35,   118,
     119,    20,    18,    41,    20,    24,    25,   120,    36,   120,
     117,   130,    40,   132,    42,    31,    32,    43,   131,    44,
     131,     3,    36,     5,     6,     7,     8,     9,    44,    45,
      46,    47,    38,    49,    36,   148,   143,   148,   151,    36,
     151,    24,    25,    36,    20,   160,   159,   160,   159,   162,
     165,   162,   165,   166,    37,   166,    38,    39,    21,    24,
      25,     3,    44,     5,     6,     7,     8,     9,    40,    51,
      52,     3,    37,     5,     6,     7,     8,     9,     8,    11,
      44,    12,    13,    44,    24,    25,    36,    18,    37,    43,
      24,    25,    33,    34,    35,    26,    38,    37,    20,    38,
      31,    32,    44,    37,     4,    36,    38,    20,    18,    51,
      52,    10,    44,    44,    45,    46,    47,    20,    49,    51,
      52,    31,    32,    31,    32,    33,    34,    35,    31,    32,
      33,    34,    35,    41,    44,    45,    46,    47,    45,    49,
      22,    23,    39,    37,    53,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    31,    32,    33,    34,    35,    31,
      32,    33,    34,    35,    41,    37,    14,    15,    16,    17,
      18,    19,    31,    32,    33,    34,    35,    53,    79
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
      76,    22,    23,    27,    28,    29,    30,    77,    24,    25,
      37,    73,    74,    75,    44,    73,    73,    73,    73,    73,
      36,    37,    20,    41,    37,    20,    41,    37,    73,    76,
      76,    68,    37,    43,    76,    68,    76,    38,     4,    73,
      37,    20,    10,    69,    68,    20,    68,    45,    39,    37,
      53,    68,    67,    11,    70,    53,    67
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
      73,    73,    73,    74,    74,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    77,    77,    77,    77,    77,    77
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
       1,     1,     4,     0,     1,     3,     1,     3,     3,     2,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 165 "parser.y" /* yacc.c:1667  */
    {t=(type*)vector_get(tt,1);}
#line 1507 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 6:
#line 166 "parser.y" /* yacc.c:1667  */
    {t=(type*)vector_get(tt,2);}
#line 1513 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 7:
#line 167 "parser.y" /* yacc.c:1667  */
    {t=(type*)vector_get(tt,3);}
#line 1519 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 8:
#line 168 "parser.y" /* yacc.c:1667  */
    {t=(type*)vector_get(tt,4);}
#line 1525 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 9:
#line 169 "parser.y" /* yacc.c:1667  */
    {t=(type*)vector_get(tt,0);}
#line 1531 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 10:
#line 170 "parser.y" /* yacc.c:1667  */
    {
	  												push(env,(void*)ts);
													push(stack,(void*)offset);

													offset=newOffset();
													ts=newSymbolTable();
												}
#line 1543 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 11:
#line 177 "parser.y" /* yacc.c:1667  */
    {
	  												type nt={"register",NULL,*offset,-1,ts};
	  												ts=(vector*)pop(env);
	  												offset=(unsigned int*)pop(stack);
	  												t=insertType(&nt);
	  											}
#line 1554 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 12:
#line 186 "parser.y" /* yacc.c:1667  */
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
#line 1577 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 13:
#line 204 "parser.y" /* yacc.c:1667  */
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
#line 1599 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 14:
#line 223 "parser.y" /* yacc.c:1667  */
    {(yyval.tipo)=t;}
#line 1605 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 15:
#line 224 "parser.y" /* yacc.c:1667  */
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
#line 1622 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 17:
#line 239 "parser.y" /* yacc.c:1667  */
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
#line 1637 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 18:
#line 249 "parser.y" /* yacc.c:1667  */
    {}
#line 1643 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 19:
#line 250 "parser.y" /* yacc.c:1667  */
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
#line 1663 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 20:
#line 268 "parser.y" /* yacc.c:1667  */
    {(yyval.args)=0;}
#line 1669 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 21:
#line 269 "parser.y" /* yacc.c:1667  */
    {(yyval.args)=(yyvsp[0].args);}
#line 1675 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 22:
#line 271 "parser.y" /* yacc.c:1667  */
    {
											(yyval.args)=(yyvsp[-3].args)+1;
											if(existsSymbol((yyvsp[0].lexval))==-1)
												insertSymbol((yyvsp[0].lexval),t,"arg");
											else{
												char* s="Repeated argument name";
												yyerror(s);
											}
													
										}
#line 1690 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 23:
#line 281 "parser.y" /* yacc.c:1667  */
    {
											(yyval.args)=1;
											if(existsSymbol((yyvsp[0].lexval))==-1)
											insertSymbol((yyvsp[0].lexval),t,"arg");
											else{
												char* s="Repeated argument name";
												yyerror(s);
											}
										}
#line 1704 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 31:
#line 299 "parser.y" /* yacc.c:1667  */
    {
																					printf("%s\n",(yyvsp[-3].exp)->tipo->name);
																					printf("%s\n",(yyvsp[-1].exp)->tipo->name);
																					if(strcmp((yyvsp[-3].exp)->tipo->name,(yyvsp[-1].exp)->tipo->name)==0)
																						genQuad("ASSIGN",(yyvsp[-1].exp)->dir,"",(yyvsp[-3].exp)->dir);
																					else{
																						char* s="Error. Assign of two different types";
																						yyerror(s);
																					}
																				}
#line 1719 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 42:
#line 323 "parser.y" /* yacc.c:1667  */
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
#line 1735 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 43:
#line 334 "parser.y" /* yacc.c:1667  */
    {
							/*CHECK!*/
							//printf("%s\n",$1->tipo->name);
							(yyval.exp)=createExpression((yyvsp[0].arr)->tipo);
							sprintf((yyval.exp)->dir,"%s[%s]",(yyvsp[0].arr)->base,(yyvsp[0].arr)->dir);

						}
#line 1747 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 44:
#line 341 "parser.y" /* yacc.c:1667  */
    {
							sym* res=lookupSymbol((yyvsp[-2].lexval));
							if(res!=NULL){
								if(strcmp((res->type)->name,"register")==0){
									//$$=createExpression($3->tipo);
									//sprintf(&&->dir,"%s.%s",$1,$3);
									int exists=existsSymbolInTable((yyvsp[0].lexval),(res->type)->ts);
									if(exists>=0){
										sym* res2=(sym*)vector_get((res->type)->ts,exists);
										(yyval.exp)=createExpression(res2->type);
										sprintf((yyval.exp)->dir,"%s.%s",(yyvsp[-2].lexval),(yyvsp[0].lexval));
									}
								}
							}
						}
#line 1767 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 45:
#line 357 "parser.y" /* yacc.c:1667  */
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
#line 1787 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 46:
#line 372 "parser.y" /* yacc.c:1667  */
    {

														}
#line 1795 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 47:
#line 377 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("PLUS",(yyvsp[-2].exp),(yyvsp[0].exp));}
#line 1801 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 48:
#line 378 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("MINUS",(yyvsp[-2].exp),(yyvsp[0].exp));}
#line 1807 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 49:
#line 379 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("PROD",(yyvsp[-2].exp),(yyvsp[0].exp));}
#line 1813 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 50:
#line 380 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("DIV",(yyvsp[-2].exp),(yyvsp[0].exp));}
#line 1819 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 51:
#line 381 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("MODULO",(yyvsp[-2].exp),(yyvsp[0].exp));}
#line 1825 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 52:
#line 382 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("MINUS",zero,(yyvsp[0].exp));}
#line 1831 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 53:
#line 383 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=expression("PLUS",zero,(yyvsp[0].exp));}
#line 1837 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 54:
#line 385 "parser.y" /* yacc.c:1667  */
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
#line 1853 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 55:
#line 396 "parser.y" /* yacc.c:1667  */
    {
												(yyval.exp)=createExpression((yyvsp[0].arr)->tipo);
												sprintf((yyval.exp)->dir,"%s",newTemp());
												char buff[32];
												sprintf(buff,"%s[%s]",(yyvsp[0].arr)->base,(yyvsp[0].arr)->dir);
												genQuad("ASSIGN",buff,"",(yyval.exp)->dir);
											}
#line 1865 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 56:
#line 403 "parser.y" /* yacc.c:1667  */
    {
												sym* res=lookupSymbol((yyvsp[-2].lexval));
												if(res!=NULL){
													if(strcmp((res->type)->name,"register")==0){
														//$$=createExpression($3->tipo);
														//sprintf(&&->dir,"%s.%s",$1,$3);
														int exists=existsSymbolInTable((yyvsp[0].lexval),(res->type)->ts);
														if(exists>=0){
															sym* res2=(sym*)vector_get((res->type)->ts,exists);
															(yyval.exp)=createExpression(res2->type);
															sprintf((yyval.exp)->dir,"%s",newTemp());
															genQuad(".",(yyvsp[-2].lexval),(yyvsp[0].lexval),(yyval.exp)->dir);
														}
													}
												}
										    }
#line 1886 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 57:
#line 419 "parser.y" /* yacc.c:1667  */
    {}
#line 1892 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 58:
#line 420 "parser.y" /* yacc.c:1667  */
    {}
#line 1898 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 59:
#line 421 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=createExpression((type*)vector_get(tt,1));sprintf((yyval.exp)->dir,"%d",(yyvsp[0].numint));}
#line 1904 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 60:
#line 422 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=createExpression((type*)vector_get(tt,2));sprintf((yyval.exp)->dir,"%f",(yyvsp[0].numfloat));}
#line 1910 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 61:
#line 423 "parser.y" /* yacc.c:1667  */
    {(yyval.exp)=createExpression((type*)vector_get(tt,3));sprintf((yyval.exp)->dir,"%f",(yyvsp[0].numdouble));}
#line 1916 "parser.tab.c" /* yacc.c:1667  */
    break;

  case 62:
#line 424 "parser.y" /* yacc.c:1667  */
    {}
#line 1922 "parser.tab.c" /* yacc.c:1667  */
    break;


#line 1926 "parser.tab.c" /* yacc.c:1667  */
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
#line 450 "parser.y" /* yacc.c:1918  */


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
