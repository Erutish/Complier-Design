
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "23241131.y"


#include "symbol_table.h"

#include <cstring>

#define YYSTYPE symbol_info*

extern FILE *yyin;
int yyparse(void);
int yylex(void);
extern YYSTYPE yylval;

// symbol table here.
symbol_table *table;

// global variables 
string current_type;
string current_func_name;
string current_func_return_type;
vector<pair<string, string> > current_func_params;
vector<pair<string, string> > multiple_func_params;
//helper functions
bool is_function_definition = false;
bool error_found = false;

//Logging variables
int lines = 1;
ofstream outlog;
ofstream errlog;
int error_count = 0;

void yyerror(const char *s)
{
    outlog << "Error at line " << lines << ": " << s << endl << endl;
    error_found = true;
}

// check for function declaration 
bool is_function_declared(string name) {
    symbol_info* temp = new symbol_info(name, "ID");
    symbol_info* found = table->lookup(temp);
    delete temp;
    return found != NULL && found->get_is_function();
}

// check for variable in current scope
bool is_variable_declared_current_scope(string name) {
    symbol_info* temp = new symbol_info(name, "ID");
    symbol_info* found = table->lookup_current_scope(temp);
    delete temp;
    return found != NULL;
}
// check for variable 
symbol_info* get_info(string name) {
	symbol_info* temp = new symbol_info(name, "ID");
	symbol_info* found = table->lookup(temp);
	delete temp;
	return found;
}



/* Line 189 of yacc.c  */
#line 137 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     ELSE = 259,
     FOR = 260,
     WHILE = 261,
     DO = 262,
     BREAK = 263,
     INT = 264,
     CHAR = 265,
     FLOAT = 266,
     DOUBLE = 267,
     VOID = 268,
     RETURN = 269,
     SWITCH = 270,
     CASE = 271,
     DEFAULT = 272,
     CONTINUE = 273,
     PRINTLN = 274,
     ADDOP = 275,
     MULOP = 276,
     INCOP = 277,
     DECOP = 278,
     RELOP = 279,
     ASSIGNOP = 280,
     LOGICOP = 281,
     NOT = 282,
     LPAREN = 283,
     RPAREN = 284,
     LCURL = 285,
     RCURL = 286,
     LTHIRD = 287,
     RTHIRD = 288,
     COMMA = 289,
     SEMICOLON = 290,
     CONST_INT = 291,
     CONST_FLOAT = 292,
     ID = 293,
     LOWER_THAN_ELSE = 294
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define BREAK 263
#define INT 264
#define CHAR 265
#define FLOAT 266
#define DOUBLE 267
#define VOID 268
#define RETURN 269
#define SWITCH 270
#define CASE 271
#define DEFAULT 272
#define CONTINUE 273
#define PRINTLN 274
#define ADDOP 275
#define MULOP 276
#define INCOP 277
#define DECOP 278
#define RELOP 279
#define ASSIGNOP 280
#define LOGICOP 281
#define NOT 282
#define LPAREN 283
#define RPAREN 284
#define LCURL 285
#define RCURL 286
#define LTHIRD 287
#define RTHIRD 288
#define COMMA 289
#define SEMICOLON 290
#define CONST_INT 291
#define CONST_FLOAT 292
#define ID 293
#define LOWER_THAN_ELSE 294




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 257 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   140

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  118

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    15,    23,
      24,    31,    36,    40,    43,    45,    46,    51,    52,    56,
      60,    62,    64,    66,    70,    77,    79,    84,    86,    89,
      91,    93,    95,    97,   105,   111,   119,   125,   131,   135,
     137,   140,   142,   147,   149,   153,   155,   159,   161,   165,
     167,   171,   173,   177,   180,   183,   185,   187,   192,   196,
     198,   200,   203,   206,   208,   209,   213
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    -1,    42,    43,    -1,    43,    -1,
      51,    -1,    44,    -1,    -1,    52,    38,    28,    47,    29,
      45,    48,    -1,    -1,    52,    38,    28,    29,    46,    48,
      -1,    47,    34,    52,    38,    -1,    47,    34,    52,    -1,
      52,    38,    -1,    52,    -1,    -1,    30,    49,    54,    31,
      -1,    -1,    30,    50,    31,    -1,    52,    53,    35,    -1,
       9,    -1,    11,    -1,    13,    -1,    53,    34,    38,    -1,
      53,    34,    38,    32,    36,    33,    -1,    38,    -1,    38,
      32,    36,    33,    -1,    55,    -1,    54,    55,    -1,    51,
      -1,    44,    -1,    56,    -1,    48,    -1,     5,    28,    56,
      56,    58,    29,    55,    -1,     3,    28,    58,    29,    55,
      -1,     3,    28,    58,    29,    55,     4,    55,    -1,     6,
      28,    58,    29,    55,    -1,    19,    28,    38,    29,    35,
      -1,    14,    58,    35,    -1,    35,    -1,    58,    35,    -1,
      38,    -1,    38,    32,    58,    33,    -1,    59,    -1,    57,
      25,    59,    -1,    60,    -1,    60,    26,    60,    -1,    61,
      -1,    61,    24,    61,    -1,    62,    -1,    61,    20,    62,
      -1,    63,    -1,    62,    21,    63,    -1,    20,    63,    -1,
      27,    63,    -1,    64,    -1,    57,    -1,    38,    28,    65,
      29,    -1,    28,    58,    29,    -1,    36,    -1,    37,    -1,
      57,    22,    -1,    57,    23,    -1,    66,    -1,    -1,    66,
      34,    59,    -1,    59,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    78,    84,    92,    98,   106,   106,   156,
     156,   185,   203,   215,   228,   241,   241,   267,   267,   285,
     302,   311,   320,   331,   351,   372,   392,   416,   423,   432,
     439,   447,   454,   461,   468,   475,   483,   490,   504,   515,
     522,   531,   560,   589,   597,   632,   653,   671,   690,   707,
     726,   747,   763,   815,   829,   842,   861,   869,   918,   925,
     933,   940,   947,   956,   964,   972,   982
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "DO",
  "BREAK", "INT", "CHAR", "FLOAT", "DOUBLE", "VOID", "RETURN", "SWITCH",
  "CASE", "DEFAULT", "CONTINUE", "PRINTLN", "ADDOP", "MULOP", "INCOP",
  "DECOP", "RELOP", "ASSIGNOP", "LOGICOP", "NOT", "LPAREN", "RPAREN",
  "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA", "SEMICOLON", "CONST_INT",
  "CONST_FLOAT", "ID", "LOWER_THAN_ELSE", "$accept", "start", "program",
  "unit", "func_definition", "$@1", "$@2", "parameter_list",
  "compound_statement", "$@3", "$@4", "var_declaration", "type_specifier",
  "declaration_list", "statements", "statement", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor",
  "argument_list", "arguments", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    45,    44,    46,
      44,    47,    47,    47,    47,    49,    48,    50,    48,    51,
      52,    52,    52,    53,    53,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    66,    66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     0,     7,     0,
       6,     4,     3,     2,     1,     0,     4,     0,     3,     3,
       1,     1,     1,     3,     6,     1,     4,     1,     2,     1,
       1,     1,     1,     7,     5,     7,     5,     5,     3,     1,
       2,     1,     4,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     2,     2,     1,     1,     4,     3,     1,
       1,     2,     2,     1,     0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    20,    21,    22,     0,     2,     4,     6,     5,     0,
       1,     3,    25,     0,     0,     0,     0,    19,     9,     0,
      14,     0,    23,     0,     7,     0,    13,    26,     0,    15,
      10,     0,    12,     0,     0,     0,     8,    11,    24,     0,
       0,     0,     0,     0,     0,     0,     0,    39,    59,    60,
      41,    30,    32,    29,     0,    27,    31,    56,     0,    43,
      45,    47,    49,    51,    55,    18,     0,     0,     0,     0,
       0,    56,    53,    54,     0,    64,     0,    16,    28,    61,
      62,     0,    40,     0,     0,     0,     0,     0,     0,     0,
      38,     0,    58,    66,     0,    63,     0,    44,    46,    50,
      48,    52,     0,     0,     0,     0,    57,     0,    42,    34,
       0,    36,    37,    65,     0,     0,    35,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    51,    31,    23,    19,    52,    34,
      35,    53,     9,    13,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    94,    95
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -65
static const yytype_int8 yypact[] =
{
      36,   -65,   -65,   -65,     9,    36,   -65,   -65,   -65,   -16,
     -65,   -65,    -5,     0,     3,    12,    -2,   -65,   -65,   -19,
      13,    27,    29,    32,   -65,    36,   -65,   -65,    23,    33,
     -65,    32,    31,    39,   101,    44,   -65,   -65,   -65,    49,
      54,    55,    89,    58,    89,    89,    89,   -65,   -65,   -65,
       1,   -65,   -65,   -65,    65,   -65,   -65,    30,    52,   -65,
      68,    26,    76,   -65,   -65,   -65,    89,    53,    89,    63,
      61,    35,   -65,   -65,    79,    89,    89,   -65,   -65,   -65,
     -65,    89,   -65,    89,    89,    89,    89,    82,    53,    84,
     -65,    90,   -65,   -65,    93,    71,    85,   -65,   -65,    76,
     103,   -65,   101,    89,   101,    95,   -65,    89,   -65,   120,
     104,   -65,   -65,   -65,   101,   101,   -65,   -65
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -65,   127,    19,   -65,   -65,   -65,   -10,   -65,
     -65,    20,    -7,   -65,   -65,   -48,   -62,   -44,   -38,   -64,
      51,    50,    56,   -42,   -65,   -65,   -65
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -18
static const yytype_int8 yytable[] =
{
      71,    71,    72,    73,    69,    88,    78,    20,    74,    10,
      24,    93,     1,    30,     2,    25,     3,    97,    32,     7,
       8,    36,    12,    14,     7,     8,   103,    15,    87,    75,
      89,    71,    18,    76,    16,    17,    22,    71,    96,    71,
      71,    71,    71,   113,   101,     1,    84,     2,    21,     3,
      85,    26,    79,    80,   109,    81,   111,    79,    80,    33,
      27,    28,    29,    71,   -17,   110,   116,   117,    39,    37,
      40,    41,    38,    44,     1,    65,     2,    66,     3,    42,
      45,    46,    67,    68,    43,    44,    70,    82,    47,    48,
      49,    50,    45,    46,    83,    29,    77,    86,    90,    91,
      47,    48,    49,    50,    39,   107,    40,    41,    92,    44,
       1,   102,     2,   104,     3,    42,    45,    46,   108,   105,
      43,    44,   106,    84,   114,    48,    49,    50,    45,    46,
     112,    29,    11,   115,    98,   100,    47,    48,    49,    50,
      99
};

static const yytype_uint8 yycheck[] =
{
      44,    45,    44,    45,    42,    67,    54,    14,    46,     0,
      29,    75,     9,    23,    11,    34,    13,    81,    25,     0,
       0,    31,    38,    28,     5,     5,    88,    32,    66,    28,
      68,    75,    29,    32,    34,    35,    38,    81,    76,    83,
      84,    85,    86,   107,    86,     9,    20,    11,    36,    13,
      24,    38,    22,    23,   102,    25,   104,    22,    23,    36,
      33,    32,    30,   107,    31,   103,   114,   115,     3,    38,
       5,     6,    33,    20,     9,    31,    11,    28,    13,    14,
      27,    28,    28,    28,    19,    20,    28,    35,    35,    36,
      37,    38,    27,    28,    26,    30,    31,    21,    35,    38,
      35,    36,    37,    38,     3,    34,     5,     6,    29,    20,
       9,    29,    11,    29,    13,    14,    27,    28,    33,    29,
      19,    20,    29,    20,     4,    36,    37,    38,    27,    28,
      35,    30,     5,    29,    83,    85,    35,    36,    37,    38,
      84
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    11,    13,    41,    42,    43,    44,    51,    52,
       0,    43,    38,    53,    28,    32,    34,    35,    29,    47,
      52,    36,    38,    46,    29,    34,    38,    33,    32,    30,
      48,    45,    52,    36,    49,    50,    48,    38,    33,     3,
       5,     6,    14,    19,    20,    27,    28,    35,    36,    37,
      38,    44,    48,    51,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    31,    28,    28,    28,    58,
      28,    57,    63,    63,    58,    28,    32,    31,    55,    22,
      23,    25,    35,    26,    20,    24,    21,    58,    56,    58,
      35,    38,    29,    59,    65,    66,    58,    59,    60,    62,
      61,    63,    29,    56,    29,    29,    29,    34,    33,    55,
      58,    55,    35,    59,     4,    29,    55,    55
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
	    /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 72 "23241131.y"
    {
		outlog << "At line no: " << lines << " start : program " << endl << endl;
		table->print_all_scopes(outlog);
	}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 79 "23241131.y"
    {
		outlog << "At line no: " << lines << " program : program unit " << endl << endl;
		outlog << (yyvsp[(1) - (2)])->getname() + "\n" + (yyvsp[(2) - (2)])->getname() << endl << endl;
		(yyval) = new symbol_info((yyvsp[(1) - (2)])->getname() + "\n" + (yyvsp[(2) - (2)])->getname(), "program");
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 85 "23241131.y"
    {
		outlog << "At line no: " << lines << " program : unit " << endl << endl;
		outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
		(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "program");
	}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 93 "23241131.y"
    {
		outlog << "At line no: " << lines << " unit : var_declaration " << endl << endl;
		outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
		(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "unit");
	 }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 99 "23241131.y"
    {
		outlog << "At line no: " << lines << " unit : func_definition " << endl << endl;
		outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
		(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "unit");
	 }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 106 "23241131.y"
    {
			// Create and insert function symbol before compound statement
			if(!is_function_declared((yyvsp[(2) - (5)])->getname()) && !is_variable_declared_current_scope((yyvsp[(2) - (5)])->getname())) {

				vector<pair<string, string> > params = current_func_params;
				current_func_name= (yyvsp[(2) - (5)])->getname();
				symbol_info* func = new symbol_info((yyvsp[(2) - (5)])->getname(), "ID", (yyvsp[(1) - (5)])->getname());
				func->set_as_function((yyvsp[(1) - (5)])->getname(), params);
				table->insert(func);
				if (multiple_func_params.size() > 0) {
					for (auto param : multiple_func_params) {

						outlog << "At line no: " << lines << ": Multiple declaration of parameter " << param.second << " in a parameter of " << current_func_name << endl << endl;
						errlog << "At line no: " << lines << ": Multiple declaration of parameter " << param.second << " in a parameter of " << current_func_name << endl << endl;
						error_count++;
					}
					multiple_func_params.clear();
				}		
			} else{
				outlog << "At line no: " << lines << ": Multiple declaration of function " << (yyvsp[(2) - (5)])->getname() << endl << endl;
				errlog << "At line no: " << lines << ": Multiple declaration of function " << (yyvsp[(2) - (5)])->getname() << endl << endl;
				error_count++;
			}
		    // The function definition is complete.
            // You can now insert necessary information about the function into the symbol table
           	// However, note that the scope of the function and the scope of the compound statement are different.

		}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 134 "23241131.y"
    {	
			outlog << "At line no: " << lines << " func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement " << endl << endl;
			outlog << (yyvsp[(1) - (7)])->getname() << " " << (yyvsp[(2) - (7)])->getname() << "(" + (yyvsp[(4) - (7)])->getname() + ")\n" << (yyvsp[(7) - (7)])->getname() << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (7)])->getname() + " " + (yyvsp[(2) - (7)])->getname() + "(" + (yyvsp[(4) - (7)])->getname() + ")\n" + (yyvsp[(7) - (7)])->getname(), "func_def");
			
			//Instructed by SZD sir to check return type of function here


			// if ($1->get_data_type()!=current_func_return_type && current_func_return_type!="" && is_function_definition==true){ 
			// 	outlog << "At line no: " << lines << ": Function return type mismatch "<< $1->getname() << endl << endl;
			// 	errlog << "At line no: " << lines << ": Function return type mismatch "<< $1->getname()<<" "<<current_func_return_type << endl << endl;
			// 	error_count++;
			// 	is_function_definition = false;
			// }


			// Clear function parameters for next function
			current_func_params.clear();
			current_func_return_type = "";
			
		}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 156 "23241131.y"
    {
			// Create and insert function symbol before compound statement
			if(!is_function_declared((yyvsp[(2) - (4)])->getname())) {
				vector<pair<string, string> > params;
				symbol_info* func = new symbol_info((yyvsp[(2) - (4)])->getname(), "ID", (yyvsp[(1) - (4)])->getname());
				func->set_as_function((yyvsp[(1) - (4)])->getname(), params);
				table->insert(func);
			}
			
		}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 166 "23241131.y"
    {
			outlog << "At line no: " << lines << " func_definition : type_specifier ID LPAREN RPAREN compound_statement " << endl << endl;
			outlog << (yyvsp[(1) - (6)])->getname() << " " << (yyvsp[(2) - (6)])->getname() << "()\n" << (yyvsp[(6) - (6)])->getname() << endl << endl;

			//Instructed by SZD sir to check return type of function here

			// if ($1->get_data_type()!=current_func_return_type && current_func_return_type!="" && is_function_definition==true){ 
			// 	outlog << "At line no: " << lines << ": Function return type mismatch "<< $1->getname() << endl << endl;
			// 	errlog << "At line no: " << lines << ": Function return type mismatch "<< $1->get_data_type()<<" "<<current_func_return_type << endl << endl;
			// 	error_count++;
			// 	is_function_definition = false;
			// }	


			(yyval) = new symbol_info((yyvsp[(1) - (6)])->getname() + " " + (yyvsp[(2) - (6)])->getname() + "()\n" + (yyvsp[(6) - (6)])->getname(), "func_def");	
			current_func_return_type = "";
		}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 186 "23241131.y"
    {
			outlog << "At line no: " << lines << " parameter_list : parameter_list COMMA type_specifier ID " << endl << endl;
			outlog << (yyvsp[(1) - (4)])->getname() << "," << (yyvsp[(3) - (4)])->getname() << " " << (yyvsp[(4) - (4)])->getname() << endl << endl;
					
			(yyval) = new symbol_info((yyvsp[(1) - (4)])->getname() + "," + (yyvsp[(3) - (4)])->getname() + " " + (yyvsp[(4) - (4)])->getname(), "param_list");
			
			// Store parameter info
			pair<string, string> param((yyvsp[(3) - (4)])->getname(), (yyvsp[(4) - (4)])->getname());
			if(!current_func_params.empty()) {
				for(auto param : current_func_params) {
					if(param.second==(yyvsp[(4) - (4)])->getname()) {
						multiple_func_params.push_back(param);
					}
				}
			}
			current_func_params.push_back(param);
		}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 204 "23241131.y"
    {
			outlog << "At line no: " << lines << " parameter_list : parameter_list COMMA type_specifier " << endl << endl;
			outlog << (yyvsp[(1) - (3)])->getname() << "," << (yyvsp[(3) - (3)])->getname() << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (3)])->getname() + "," + (yyvsp[(3) - (3)])->getname(), "param_list");
			
			//storing  the necessary information about the function parameters
			// They will be needed when you want to enter the function into the symbol table
			pair<string, string> param((yyvsp[(3) - (3)])->getname(), "");
			current_func_params.push_back(param);
		}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 216 "23241131.y"
    {
			outlog << "At line no: " << lines << " parameter_list : type_specifier ID " << endl << endl;
			outlog << (yyvsp[(1) - (2)])->getname() << " " << (yyvsp[(2) - (2)])->getname() << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (2)])->getname() + " " + (yyvsp[(2) - (2)])->getname(), "param_list");
			
			//storing  the necessary information about the function parameters
			// They will be needed when you want to enter the function into the symbol table

			pair<string, string> param((yyvsp[(1) - (2)])->getname(), (yyvsp[(2) - (2)])->getname());
			current_func_params.push_back(param);
		}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 229 "23241131.y"
    {
			outlog << "At line no: " << lines << " parameter_list : type_specifier " << endl << endl;
			outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "param_list");
			
			// Store parameter info without name
			pair<string, string> param((yyvsp[(1) - (1)])->getname(), "");
			current_func_params.push_back(param);
		}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 241 "23241131.y"
    {
		// Enter a new scope
		table->enter_scope();
		
		// If we're in a function definition, add parameters to current scope
		if(!current_func_params.empty()) {
			for(auto param : current_func_params) {
				if(!param.second.empty()) {
					symbol_info* param_symbol = new symbol_info(param.second, "ID", param.first);
					table->insert(param_symbol);
				}
			}
		}
	}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 255 "23241131.y"
    { 
		outlog << "At line no: " << lines << " compound_statement : LCURL statements RCURL " << endl << endl;
		outlog << "{\n" + (yyvsp[(3) - (4)])->getname() + "\n}" << endl << endl;
		
		// Print current scope before exiting
		table->print_current_scope();
		
		// Exit the current scope
		table->exit_scope();
		
		(yyval) = new symbol_info("{\n" + (yyvsp[(3) - (4)])->getname() + "\n}", "comp_stmnt");
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 267 "23241131.y"
    {
		// Enter a new scope
		table->enter_scope();
	}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 271 "23241131.y"
    { 
		outlog << "At line no: " << lines << " compound_statement : LCURL RCURL " << endl << endl;
		outlog << "{\n}" << endl << endl;
		
		// Print current scope before exiting
		table->print_current_scope();
		
		// Exit the current scope
		table->exit_scope();
		
		(yyval) = new symbol_info("{\n}", "comp_stmnt");
	}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 286 "23241131.y"
    {
			outlog << "At line no: " << lines << " var_declaration : type_specifier declaration_list SEMICOLON " << endl << endl;
			outlog << (yyvsp[(1) - (3)])->getname() << " " << (yyvsp[(2) - (3)])->getname() << ";" << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (3)])->getname() + " " + (yyvsp[(2) - (3)])->getname() + ";", "var_dec");
			
			// Store the current type for use in declaration_list
			if ((yyvsp[(1) - (3)])->getname() == "void") {
				outlog << "At line no: " << lines << " variable type cannot be void" << endl << endl;
				errlog << "At line no: " << lines << " variable type cannot be void" << endl << endl;
				error_count++;
			}
			
		 }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 303 "23241131.y"
    {
			outlog << "At line no: " << lines << " type_specifier : INT " << endl << endl;
			outlog << "int" << endl << endl;
			
			(yyval) = new symbol_info("int", "type");
			(yyval)->set_data_type("int");
			current_type = "int";
	    }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 312 "23241131.y"
    {
			outlog << "At line no: " << lines << " type_specifier : FLOAT " << endl << endl;
			outlog << "float" << endl << endl;
			
			(yyval) = new symbol_info("float", "type");
			(yyval)->set_data_type("float");
			current_type = "float";
	    }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 321 "23241131.y"
    {
			outlog << "At line no: " << lines << " type_specifier : VOID " << endl << endl;
			outlog << "void" << endl << endl;
			
			(yyval) = new symbol_info("void", "type");
			(yyval)->set_data_type("void");
			current_type = "void";
	    }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 332 "23241131.y"
    {
 		  	outlog << "At line no: " << lines << " declaration_list : declaration_list COMMA ID " << endl << endl;
 		  	outlog << (yyvsp[(1) - (3)])->getname() + "," << (yyvsp[(3) - (3)])->getname() << endl << endl;
			(yyval) = new symbol_info((yyvsp[(1) - (3)])->getname() + "," + (yyvsp[(3) - (3)])->getname(), "decl_list");

            // check if variable already declared in current scope
            if(is_variable_declared_current_scope((yyvsp[(3) - (3)])->getname())) {
                (yyval) = new symbol_info((yyvsp[(1) - (3)])->getname() + "," + (yyvsp[(3) - (3)])->getname(), "decl_list");
				outlog << "At line no: " << lines << ": Multiple declaration of variable " << (yyvsp[(3) - (3)])->getname() << endl << endl;
				errlog << "At line no: " << lines << ": Multiple declaration of variable " << (yyvsp[(3) - (3)])->getname() << endl << endl;
				error_count++;
				
            } else {
                // Create and insert new variable
                symbol_info* new_var = new symbol_info((yyvsp[(3) - (3)])->getname(), "ID", current_type);
                table->insert(new_var);
                (yyval) = new symbol_info((yyvsp[(1) - (3)])->getname() + "," + (yyvsp[(3) - (3)])->getname(), "decl_list");
            }
 		  }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 352 "23241131.y"
    {
 		  	outlog << "At line no: " << lines << " declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD " << endl << endl;
 		  	outlog << (yyvsp[(1) - (6)])->getname() + "," << (yyvsp[(3) - (6)])->getname() << "[" << (yyvsp[(5) - (6)])->getname() << "]" << endl << endl;
			(yyval) = new symbol_info((yyvsp[(1) - (6)])->getname() + "," + (yyvsp[(3) - (6)])->getname() + "[" + (yyvsp[(5) - (6)])->getname() + "]", "decl_list");

            // Check if array already declared in current scope
            if(is_variable_declared_current_scope((yyvsp[(3) - (6)])->getname())) {
                // Silently ignore multiple declarations
				outlog << "At line no: " << lines << ": Multiple declaration of variable " << (yyvsp[(3) - (6)])->getname() << endl << endl;
				errlog << "At line no: " << lines << ": Multiple declaration of variable " << (yyvsp[(3) - (6)])->getname() << endl << endl;
				error_count++;
                (yyval) = new symbol_info((yyvsp[(1) - (6)])->getname() + "," + (yyvsp[(3) - (6)])->getname() + "[" + (yyvsp[(5) - (6)])->getname() + "]", "decl_list");
            } else {
                // Create and insert new array
                int size = stoi((yyvsp[(5) - (6)])->getname());
                symbol_info* new_array = new symbol_info((yyvsp[(3) - (6)])->getname(), "ID", current_type, size);
                table->insert(new_array);
                (yyval) = new symbol_info((yyvsp[(1) - (6)])->getname() + "," + (yyvsp[(3) - (6)])->getname() + "[" + (yyvsp[(5) - (6)])->getname() + "]", "decl_list");
            }
 		  }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 373 "23241131.y"
    {
 		  	outlog << "At line no: " << lines << " declaration_list : ID " << endl << endl;
			outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
			(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "decl_list");

            // Check if variable already declared in current scope
            if(is_variable_declared_current_scope((yyvsp[(1) - (1)])->getname())) {
                // Silently ignore multiple declarations
				outlog << "At line no: " << lines << ": Multiple declaration of variable " << (yyvsp[(1) - (1)])->getname() << endl << endl;
				errlog << "At line no: " << lines << ": Multiple declaration of variable " << (yyvsp[(1) - (1)])->getname() << endl << endl;
				error_count++;
                (yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "decl_list");
            } else {
                // Create and insert new variable
                symbol_info* new_var = new symbol_info((yyvsp[(1) - (1)])->getname(), "ID", current_type);
                table->insert(new_var);
                (yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "decl_list");
            }
 		  }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 393 "23241131.y"
    {
 		  	outlog << "At line no: " << lines << " declaration_list : ID LTHIRD CONST_INT RTHIRD " << endl << endl;
			outlog << (yyvsp[(1) - (4)])->getname() << "[" << (yyvsp[(3) - (4)])->getname() << "]" << endl << endl;
			(yyval) = new symbol_info((yyvsp[(1) - (4)])->getname() + "[" + (yyvsp[(3) - (4)])->getname() + "]", "decl_list");

            // Check if array already declared in current scope
            if(is_variable_declared_current_scope((yyvsp[(1) - (4)])->getname())) {
                // Silently ignore multiple declarations
				outlog << "At line no: " << lines << ": Multiple declaration of variable " << (yyvsp[(1) - (4)])->getname() << endl << endl;
				errlog << "At line no: " << lines << ": Multiple declaration of variable " << (yyvsp[(1) - (4)])->getname() << endl << endl;
				error_count++;
                (yyval) = new symbol_info((yyvsp[(1) - (4)])->getname() + "[" + (yyvsp[(3) - (4)])->getname() + "]", "decl_list");
            } else {
                // Create and insert new array
                int size = stoi((yyvsp[(3) - (4)])->getname());
                symbol_info* new_array = new symbol_info((yyvsp[(1) - (4)])->getname(), "ID", current_type, size);
                table->insert(new_array);
                (yyval) = new symbol_info((yyvsp[(1) - (4)])->getname() + "[" + (yyvsp[(3) - (4)])->getname() + "]", "decl_list");
            }
 		  }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 417 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " statements : statement " << endl << endl;
			outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "stmnts");
	   }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 424 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " statements : statements statement " << endl << endl;
			outlog << (yyvsp[(1) - (2)])->getname() << "\n" << (yyvsp[(2) - (2)])->getname() << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (2)])->getname() + "\n" + (yyvsp[(2) - (2)])->getname(), "stmnts");
	   }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 433 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " statement : var_declaration " << endl << endl;
			outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "stmnt");
	  }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 440 "23241131.y"
    {
	  		outlog << "At line no: " << lines << " statement : func_definition " << endl << endl;
            outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;

            (yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "stmnt");
	  		
	  }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 448 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " statement : expression_statement " << endl << endl;
			outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "stmnt");
	  }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 455 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " statement : compound_statement " << endl << endl;
			outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "stmnt");
	  }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 462 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement " << endl << endl;
			outlog << "for(" << (yyvsp[(3) - (7)])->getname() << (yyvsp[(4) - (7)])->getname() << (yyvsp[(5) - (7)])->getname() << ")\n" << (yyvsp[(7) - (7)])->getname() << endl << endl;
			
			(yyval) = new symbol_info("for(" + (yyvsp[(3) - (7)])->getname() + (yyvsp[(4) - (7)])->getname() + (yyvsp[(5) - (7)])->getname() + ")\n" + (yyvsp[(7) - (7)])->getname(), "stmnt");
	  }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 469 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " statement : IF LPAREN expression RPAREN statement " << endl << endl;
			outlog << "if(" << (yyvsp[(3) - (5)])->getname() << ")\n" << (yyvsp[(5) - (5)])->getname() << endl << endl;
			
			(yyval) = new symbol_info("if(" + (yyvsp[(3) - (5)])->getname() + ")\n" + (yyvsp[(5) - (5)])->getname(), "stmnt");
	  }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 476 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " statement : IF LPAREN expression RPAREN statement ELSE statement " << endl << endl;
			outlog << "if(" << (yyvsp[(3) - (7)])->getname() << ")\n" << (yyvsp[(5) - (7)])->getname() << "\nelse\n" << (yyvsp[(7) - (7)])->getname() << endl << endl;

			
			(yyval) = new symbol_info("if(" + (yyvsp[(3) - (7)])->getname() + ")\n" + (yyvsp[(5) - (7)])->getname() + "\nelse\n" + (yyvsp[(7) - (7)])->getname(), "stmnt");
	  }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 484 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " statement : WHILE LPAREN expression RPAREN statement " << endl << endl;
			outlog << "while(" << (yyvsp[(3) - (5)])->getname() << ")\n" << (yyvsp[(5) - (5)])->getname() << endl << endl;
			
			(yyval) = new symbol_info("while(" + (yyvsp[(3) - (5)])->getname() + ")\n" + (yyvsp[(5) - (5)])->getname(), "stmnt");
	  }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 491 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " statement : PRINTLN LPAREN ID RPAREN SEMICOLON " << endl << endl;
			outlog << "printf(" << (yyvsp[(3) - (5)])->getname() << ");" << endl << endl; 

			symbol_info * var_info = get_info((yyvsp[(3) - (5)])->getname());
			if (var_info==NULL){
				outlog << "At line no: " << lines << " Undeclared variable " << (yyvsp[(3) - (5)])->getname() << endl << endl;
				errlog << "At line no: " << lines << " Undeclared variable " << (yyvsp[(3) - (5)])->getname() << endl << endl;
				error_count++;
			}
			
			(yyval) = new symbol_info("printf(" + (yyvsp[(3) - (5)])->getname() + ");", "stmnt");
	  }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 505 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " statement : RETURN expression SEMICOLON " << endl << endl;
			outlog << "return " << (yyvsp[(2) - (3)])->getname() << ";" << endl << endl;

			(yyval) = new symbol_info("return " + (yyvsp[(2) - (3)])->getname() + ";", "stmnt");
			current_func_return_type = (yyvsp[(2) - (3)])->get_data_type();
			is_function_definition = true;
	  }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 516 "23241131.y"
    {
				outlog << "At line no: " << lines << " expression_statement : SEMICOLON " << endl << endl;
				outlog << ";" << endl << endl;
				
				(yyval) = new symbol_info(";", "expr_stmt");
	        }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 523 "23241131.y"
    {
				outlog << "At line no: " << lines << " expression_statement : expression SEMICOLON " << endl << endl;
				outlog << (yyvsp[(1) - (2)])->getname() << ";" << endl << endl;
				
				(yyval) = new symbol_info((yyvsp[(1) - (2)])->getname() + ";", "expr_stmt");
	        }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 532 "23241131.y"
    {
	    outlog << "At line no: " << lines << " variable : ID " << endl << endl;
		outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
		symbol_info* var_info = get_info((yyvsp[(1) - (1)])->getname());
		

		if (var_info==NULL){
			outlog << "At line no: " << lines << " Undeclared variable " << (yyvsp[(1) - (1)])->getname() << endl << endl;
			errlog << "At line no: " << lines << " Undeclared variable " << (yyvsp[(1) - (1)])->getname() << endl << endl;
			error_count++;
			(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "Not_declared_var");
			(yyval)->set_is_undefined_function();
		}
		else{
			(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "varbl");
			(yyval)->set_data_type(var_info->get_data_type()); // Set float flag if var_info is float
		}

		if (var_info!=NULL && var_info->get_is_array()){
			outlog << "At line no: " << lines << " Variable is of array type: " << (yyvsp[(1) - (1)])->getname()<< endl << endl;
			errlog << "At line no: " << lines << " Variable is of array type: " << (yyvsp[(1) - (1)])->getname()<< endl << endl;
			error_count++;
		}
	  
		
		
		
	 }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 561 "23241131.y"
    {
	 	outlog << "At line no: " << lines << " variable : ID LTHIRD expression RTHIRD " << endl << endl;
		outlog << (yyvsp[(1) - (4)])->getname() << "[" << (yyvsp[(3) - (4)])->getname() << "]" << endl << endl;
		symbol_info* var_info = get_info((yyvsp[(1) - (4)])->getname());
		(yyval) = new symbol_info((yyvsp[(1) - (4)])->getname() + "[" + (yyvsp[(3) - (4)])->getname() + "]", "varbl");
		(yyval)->set_is_array(var_info->get_is_array());
		(yyval)->set_data_type(var_info->get_data_type());  // Set data type of the array

		if (var_info==NULL){
			outlog << "At line no: " << lines << " Undeclared variable " << (yyvsp[(1) - (4)])->getname() << endl << endl;
			errlog << "At line no: " << lines << " Undeclared variable " << (yyvsp[(1) - (4)])->getname() << endl << endl;
			error_count++;
		}
		else{
			if (!var_info->get_is_array()){
				outlog << "At line no: " << lines << " variable is not of array type : " << (yyvsp[(1) - (4)])->getname()<< endl << endl;
				errlog << "At line no: " << lines << " variable is not of array type : " << (yyvsp[(1) - (4)])->getname()<< endl << endl;
				error_count++;
			}
			if ((yyvsp[(3) - (4)])->get_data_type()!="int"){
				outlog << "At line no: " << lines << " array index is not of integer type:" << (yyvsp[(1) - (4)])->getname() << endl << endl;
				errlog << "At line no: " << lines << " array index is not of integer type:" << (yyvsp[(1) - (4)])->getname() << endl << endl;
				error_count++;
			}
		}
	 }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 590 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " expression : logic_expression " << endl << endl;
			outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "expr");
			(yyval)->set_data_type((yyvsp[(1) - (1)])->get_data_type());  // Set float flag if logic_expression is float
	   }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 598 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " expression : variable ASSIGNOP logic_expression " << endl << endl;
			outlog << (yyvsp[(1) - (3)])->getname() << "=" << (yyvsp[(3) - (3)])->getname() << endl << endl;
			if (!is_variable_declared_current_scope((yyvsp[(3) - (3)])->getname())) {

				if((yyvsp[(3) - (3)])->get_is_operation()){
					//pass
				}
				else if ((yyvsp[(3) - (3)])->get_is_relational()){
					
					if ((yyvsp[(3) - (3)])->get_data_type()!="int"){
						outlog << "At line no: " << lines << " RELOP/LOGICOP result is of non integer type " << endl << endl;
						errlog << "At line no: " << lines << " RELOP/LOGICOP result is of non integer type "<< endl << endl;
						error_count++;
					}					

				}else if((yyvsp[(3) - (3)])->get_is_function()){
					if ((yyvsp[(1) - (3)])->get_data_type()!=(yyvsp[(3) - (3)])->get_return_type()){

						outlog << "At line no: " << lines << " operation on void type " << endl << endl;
						errlog << "At line no: " << lines << " operation on void type " << endl << endl;
						error_count++;
					}
				}else if ((yyvsp[(1) - (3)])->get_data_type()!=(yyvsp[(3) - (3)])->get_data_type() && (yyvsp[(3) - (3)])->get_is_undefined_function()==false && (yyvsp[(1) - (3)])->get_is_undefined_function()==false){
					outlog << "At line no: " << lines << " Warning: Assignment of " << (yyvsp[(3) - (3)])->get_data_type()<<" value into variable of "<<(yyvsp[(1) - (3)])->get_data_type()<<" type" << endl << endl;
					errlog << "At line no: " << lines << " Warning: Assignment of " << (yyvsp[(3) - (3)])->get_data_type()<<" value into variable of "<<(yyvsp[(1) - (3)])->get_data_type()<<" type" << endl << endl;
					error_count++;
				}
			}

			(yyval) = new symbol_info((yyvsp[(1) - (3)])->getname() + "=" + (yyvsp[(3) - (3)])->getname(), "expr");
	   }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 633 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " logic_expression : rel_expression " << endl << endl;
			outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "lgc_expr");
			(yyval)->set_data_type((yyvsp[(1) - (1)])->get_data_type());  // Set float flag if rel_expression is float
			if ((yyvsp[(1) - (1)])->get_is_function()){
				(yyval)->set_as_function((yyvsp[(1) - (1)])->get_return_type(),(yyvsp[(1) - (1)])->get_parameters());
			}
			if ((yyvsp[(1) - (1)])->get_is_operation()){
				(yyval)->set_is_operation();
			}
			if ((yyvsp[(1) - (1)])->get_is_undefined_function()){
				(yyval)->set_is_undefined_function();
			}
			if ((yyvsp[(1) - (1)])->get_is_relational()){
				(yyval)->set_is_relational();
			}

	     }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 654 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " logic_expression : rel_expression LOGICOP rel_expression " << endl << endl;
			outlog << (yyvsp[(1) - (3)])->getname() << (yyvsp[(2) - (3)])->getname() << (yyvsp[(3) - (3)])->getname() << endl << endl;
			(yyval) = new symbol_info((yyvsp[(1) - (3)])->getname() + (yyvsp[(2) - (3)])->getname() + (yyvsp[(3) - (3)])->getname(), "lgc_expr");
			(yyval)->set_is_relational();

			if ((yyvsp[(1) - (3)])->get_data_type()== "void" || (yyvsp[(3) - (3)])->get_data_type()=="void"){
				outlog << "At line no: " << lines << " Relational operator on void type" << endl << endl;
				errlog << "At line no: " << lines << " Relational operator on void type" << endl << endl;
				error_count++;
			}else{
			(yyval)->set_data_type("int");
			}
			
	     }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 672 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " rel_expression : simple_expression " << endl << endl;
			outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "rel_expr");
			(yyval)->set_data_type((yyvsp[(1) - (1)])->get_data_type());  // Set float flag if simple_expression is float
			if ((yyvsp[(1) - (1)])->get_is_function()){
				(yyval)->set_as_function((yyvsp[(1) - (1)])->get_return_type(),(yyvsp[(1) - (1)])->get_parameters());
			}
			
			if ((yyvsp[(1) - (1)])->get_is_operation()){
				(yyval)->set_is_operation();
			}
			if ((yyvsp[(1) - (1)])->get_is_undefined_function()){
				(yyval)->set_is_undefined_function();
			}

	    }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 691 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " rel_expression : simple_expression RELOP simple_expression " << endl << endl;
			outlog << (yyvsp[(1) - (3)])->getname() << (yyvsp[(2) - (3)])->getname() << (yyvsp[(3) - (3)])->getname() << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (3)])->getname() + (yyvsp[(2) - (3)])->getname() + (yyvsp[(3) - (3)])->getname(), "rel_expr");
			(yyval)->set_is_relational();
			if ((yyvsp[(1) - (3)])->get_data_type()== "void" || (yyvsp[(3) - (3)])->get_data_type()=="void"){
				outlog << "At line no: " << lines << " Logical operator on void type" << endl << endl;
				errlog << "At line no: " << lines << " Logical operator on void type" << endl << endl;
				error_count++;
			}else{
				(yyval)->set_data_type("int");
			}
	    }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 708 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " simple_expression : term " << endl << endl;
			outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "simp_expr");
			(yyval)->set_data_type((yyvsp[(1) - (1)])->get_data_type());  // Set data type of term
			if ((yyvsp[(1) - (1)])->get_is_function()){
				(yyval)->set_as_function((yyvsp[(1) - (1)])->get_return_type(),(yyvsp[(1) - (1)])->get_parameters());
			}

			if ((yyvsp[(1) - (1)])->get_is_operation()){
				(yyval)->set_is_operation();
			}
			if ((yyvsp[(1) - (1)])->get_is_undefined_function()){
				(yyval)->set_is_undefined_function();
			}
			
	      	}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 727 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " simple_expression : simple_expression ADDOP term " << endl << endl;
			outlog << (yyvsp[(1) - (3)])->getname() << (yyvsp[(2) - (3)])->getname() << (yyvsp[(3) - (3)])->getname() << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (3)])->getname() + (yyvsp[(2) - (3)])->getname() + (yyvsp[(3) - (3)])->getname(), "simp_expr");
			(yyval)->set_is_operation();

			if ((yyvsp[(1) - (3)])->get_data_type()== "void" || (yyvsp[(3) - (3)])->get_data_type()=="void"){
				outlog << "At line no: " << lines << " operation on void type" << endl << endl;
				errlog << "At line no: " << lines << " operation on void type" << endl << endl;
				error_count++;
			}else if ((yyvsp[(1) - (3)])->get_data_type()== "float" || (yyvsp[(3) - (3)])->get_data_type()=="float"){
				(yyval)->set_data_type("float");}
			else{
				(yyval)->set_data_type("int");
			}

	      }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 748 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " term : unary_expression " << endl << endl;
			outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "term");
			(yyval)->set_data_type((yyvsp[(1) - (1)])->get_data_type());  // Set float flag if unary_expression is float
			if ((yyvsp[(1) - (1)])->get_is_function()){
				(yyval)->set_as_function((yyvsp[(1) - (1)])->get_return_type(),(yyvsp[(1) - (1)])->get_parameters());
			}
			if ((yyvsp[(1) - (1)])->get_is_undefined_function()){
				(yyval)->set_is_undefined_function();
			}

			
	 }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 764 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " term : term MULOP unary_expression " << endl << endl;
			outlog << (yyvsp[(1) - (3)])->getname() << (yyvsp[(2) - (3)])->getname() << (yyvsp[(3) - (3)])->getname() << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (3)])->getname() + (yyvsp[(2) - (3)])->getname() + (yyvsp[(3) - (3)])->getname(), "operation");
			(yyval)->set_is_operation();
			if ((yyvsp[(1) - (3)])->get_data_type()== "void" || (yyvsp[(3) - (3)])->get_data_type()=="void"){
				outlog << "At line no: " << lines << " operation on void type" << endl << endl;
				errlog << "At line no: " << lines << " operation on void type" << endl << endl;
				error_count++;}
			else{
				if ((yyvsp[(2) - (3)])->getname() == "/" || (yyvsp[(2) - (3)])->getname() == "%"){


					if ((yyvsp[(3) - (3)])->getname()=="0" && (yyvsp[(2) - (3)])->getname()=="/" ){
						outlog << "At line no: " << lines << " Division by 0" << endl << endl;
						errlog << "At line no: " << lines << " Division by 0 " << endl << endl;
						error_count++;
					}
					else if ((yyvsp[(3) - (3)])->getname()=="0" && (yyvsp[(2) - (3)])->getname()=="%" ){
						outlog << "At line no: " << lines << " Modulus by 0" << endl << endl;
						errlog << "At line no: " << lines << " Modulus by 0 " << endl << endl;
						error_count++;
					}


					if ((yyvsp[(2) - (3)])->getname() == "%" ){
						if ((yyvsp[(1) - (3)])->get_data_type()!="int" || (yyvsp[(3) - (3)])->get_data_type()!="int" ){
							outlog << "At line no: " << lines << " Modulus operator on non integer type" << endl << endl;
							errlog << "At line no: " << lines << " Modulus operator on non integer type" << endl << endl;
							error_count++;
						}
					}
				}

				if ((yyvsp[(3) - (3)])->get_is_function() && (yyvsp[(3) - (3)])->get_return_type()=="void"){
					outlog << "At line no: " << lines << " operation on "<< (yyvsp[(3) - (3)])->get_return_type()<<" type" << endl << endl;
					errlog << "At line no: " << lines << " operation on "<< (yyvsp[(3) - (3)])->get_return_type()<<" type" << endl << endl;
					error_count++;
				}

			}
			//setting data type of the operation cause float*int=float
			if ((yyvsp[(1) - (3)])->get_data_type()== "float" || (yyvsp[(3) - (3)])->get_data_type()=="float"){
				(yyval)->set_data_type("float");}
			else{
				(yyval)->set_data_type("int");
			}
	 }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 816 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " unary_expression : ADDOP unary_expression " << endl << endl;
			outlog << (yyvsp[(1) - (2)])->getname() << (yyvsp[(2) - (2)])->getname() << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (2)])->getname() + (yyvsp[(2) - (2)])->getname(), "operation");
			(yyval)->set_is_operation();

			if ((yyvsp[(2) - (2)])->get_is_function() && (yyvsp[(2) - (2)])->get_return_type()=="void"){
				outlog << "At line no: " << lines << " operation on "<< (yyvsp[(2) - (2)])->get_return_type()<<" type" << endl << endl;
				errlog << "At line no: " << lines << " operation on "<< (yyvsp[(2) - (2)])->get_return_type()<<" type" << endl << endl;
				error_count++;
			}
	     }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 830 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " unary_expression : NOT unary_expression " << endl << endl;
			outlog << "!" << (yyvsp[(2) - (2)])->getname() << endl << endl;

			if ((yyvsp[(2) - (2)])->get_data_type()== "void"){
				outlog << "At line no: " << lines << " Logical operator on void type" << endl << endl;
				errlog << "At line no: " << lines << " Logical operator on void type" << endl << endl;
				error_count++;
			}
			
			(yyval) = new symbol_info("!" + (yyvsp[(2) - (2)])->getname(), "un_expr");
	     }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 843 "23241131.y"
    {
	    	outlog << "At line no: " << lines << " unary_expression : factor " << endl << endl;
			outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
			
			(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "un_expr");
			(yyval)->set_data_type((yyvsp[(1) - (1)])->get_data_type()); // Set float flag if factor is float

			if ((yyvsp[(1) - (1)])->get_is_function()){
				(yyval)->set_as_function((yyvsp[(1) - (1)])->get_return_type(),(yyvsp[(1) - (1)])->get_parameters());
	     	}
			if ((yyvsp[(1) - (1)])->get_is_undefined_function()){
				(yyval)->set_is_undefined_function();
			}

		 }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 862 "23241131.y"
    {
	    outlog << "At line no: " << lines << " factor : variable " << endl << endl;
		outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
			
		(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "fctr");
		(yyval)->set_data_type((yyvsp[(1) - (1)])->get_data_type()); 
	}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 870 "23241131.y"
    {
	    outlog << "At line no: " << lines << " factor : ID LPAREN argument_list RPAREN " << endl << endl;
		outlog << (yyvsp[(1) - (4)])->getname() << "(" << (yyvsp[(3) - (4)])->getname() << ")" << endl << endl;

		symbol_info* var_info = get_info((yyvsp[(1) - (4)])->getname());



		(yyval) = new symbol_info((yyvsp[(1) - (4)])->getname() + "(" + (yyvsp[(3) - (4)])->getname() + ")", "fctr");

		if (var_info==NULL){ 
			outlog << "At line no: " << lines << " Undeclared function " << (yyvsp[(1) - (4)])->getname() << endl << endl;
			errlog << "At line no: " << lines << " Undeclared function " << (yyvsp[(1) - (4)])->getname() << endl << endl;
			(yyval)->set_is_undefined_function();
			error_count++;
		}else if (var_info!=NULL){
			(yyval)->set_as_function(var_info->get_return_type(),var_info->get_parameters());
			if (current_func_params.size()!=var_info->get_parameters().size()){
				outlog << "At line no: " << lines << " Inconsistencies in number of arguments in function call : " <<  (yyvsp[(1) - (4)])->getname() << endl << endl;
				errlog << "At line no: " << lines << " Inconsistencies in number of arguments in function call : " <<  (yyvsp[(1) - (4)])->getname() << endl << endl;
				error_count++;
			}
			else if(current_func_params.size()==var_info->get_parameters().size()){
				for (int i=0; i<current_func_params.size(); i++){
					symbol_info* v_info = get_info(current_func_params[i].first);

					if (v_info!= NULL && v_info->get_is_array()==false ){

						if (current_func_params[i].second!=var_info->get_parameters()[i].first){
							outlog << "At line no: " << lines << " argument "<< i+1 << " type mismatch in function call : " <<  (yyvsp[(1) - (4)])->getname() << endl << endl;
							errlog << "At line no: " << lines << " argument "<< i+1 << " type mismatch in function call : " <<  (yyvsp[(1) - (4)])->getname() << endl << endl;
							error_count++;
						}
					}else if (v_info==NULL){

						if (current_func_params[i].second!=var_info->get_parameters()[i].first ){
							outlog << "At line no: " << lines << " argument "<< i+1 << " type mismatch in function call : " <<  (yyvsp[(1) - (4)])->getname() << endl << endl;
							errlog << "At line no: " << lines << " argument "<< i+1 << " type mismatch in function call : " <<  (yyvsp[(1) - (4)])->getname() << endl << endl;
							error_count++;
						}
					}
				}
			}	
		}
			
		current_func_params.clear(); // Clear the current function parameters after use

	}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 919 "23241131.y"
    {
	   	outlog << "At line no: " << lines << " factor : LPAREN expression RPAREN " << endl << endl;
		outlog << "(" << (yyvsp[(2) - (3)])->getname() << ")" << endl << endl;
		
		(yyval) = new symbol_info("(" + (yyvsp[(2) - (3)])->getname() + ")", "fctr");
	}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 926 "23241131.y"
    {
	    outlog << "At line no: " << lines << " factor : CONST_INT " << endl << endl;
		outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
			
		(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "fctr");
		(yyval)->set_data_type("int");
	}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 934 "23241131.y"
    {
	    outlog << "At line no: " << lines << " factor : CONST_FLOAT " << endl << endl;
		outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
		(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "fctr");
		(yyval)->set_data_type("float"); // Set float flag
	}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 941 "23241131.y"
    {
	    outlog << "At line no: " << lines << " factor : variable INCOP " << endl << endl;
		outlog << (yyvsp[(1) - (2)])->getname() << "++" << endl << endl;
			
		(yyval) = new symbol_info((yyvsp[(1) - (2)])->getname() + "++", "fctr");
	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 948 "23241131.y"
    {
	    outlog << "At line no: " << lines << " factor : variable DECOP " << endl << endl;
		outlog << (yyvsp[(1) - (2)])->getname() << "--" << endl << endl;
			
		(yyval) = new symbol_info((yyvsp[(1) - (2)])->getname() + "--", "fctr");
	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 957 "23241131.y"
    {
					outlog << "At line no: " << lines << " argument_list : arguments " << endl << endl;
					outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
						
					(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "arg_list");
			  }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 964 "23241131.y"
    {
					outlog << "At line no: " << lines << " argument_list :  " << endl << endl;
					outlog << "" << endl << endl;
						
					(yyval) = new symbol_info("", "arg_list");
			  }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 973 "23241131.y"
    {
				outlog << "At line no: " << lines << " arguments : arguments COMMA logic_expression " << endl << endl;
				outlog << (yyvsp[(1) - (3)])->getname() << "," << (yyvsp[(3) - (3)])->getname() << endl << endl;
				pair<string, string> param((yyvsp[(3) - (3)])->getname(), (yyvsp[(3) - (3)])->get_data_type());
				current_func_params.push_back(param);
						
						
				(yyval) = new symbol_info((yyvsp[(1) - (3)])->getname() + "," + (yyvsp[(3) - (3)])->getname(), "arg");
		  }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 983 "23241131.y"
    {
				outlog << "At line no: " << lines << " arguments : logic_expression " << endl << endl;
				outlog << (yyvsp[(1) - (1)])->getname() << endl << endl;
				pair<string, string> param((yyvsp[(1) - (1)])->getname(), (yyvsp[(1) - (1)])->get_data_type());
				current_func_params.push_back(param);
						
				(yyval) = new symbol_info((yyvsp[(1) - (1)])->getname(), "arg");
		  }
    break;



/* Line 1455 of yacc.c  */
#line 2770 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 994 "23241131.y"


int main(int argc, char *argv[])
{
	if(argc != 2) 
	{
		cout << "Please input file name" << endl;
		return 0;
	}
	yyin = fopen(argv[1], "r");
	outlog.open("23241131_log.txt", ios::trunc);
	errlog.open("23241131_error.txt", ios::trunc);

	if(yyin == NULL)
	{
		cout << "Couldn't open file" << endl;
		return 0;
	}

	table = new symbol_table(10);  
	
	yyparse();
	
	delete table;
	
	outlog << endl << "Total lines: " << lines << endl;
	outlog << "Total errors: " << error_count << endl;
	errlog << "Total errors: " << error_count << endl;
	outlog.close();
	fclose(yyin);
	
	return 0;
}
