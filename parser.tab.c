
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
#line 1 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "ast.h" 

    extern FILE *yyin;
    extern int yylineno;
    extern int columna;
    extern char *yytext;
    
    int errores_sintacticos = 0;

    void yyerror(const char *s);
    int yylex();


/* Line 189 of yacc.c  */
#line 91 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
     FUN = 258,
     DEPENDE = 259,
     OTROS = 260,
     RETORNAR = 261,
     LEER = 262,
     SI = 263,
     SINO = 264,
     MIENTRAS = 265,
     PARA = 266,
     IMPRIMIR = 267,
     TIPO_ENTERO = 268,
     TIPO_DECIMAL = 269,
     ID = 270,
     NUM_ENTERO = 271,
     NUM_DECIMAL = 272,
     CADENA = 273,
     MAS = 274,
     MENOS = 275,
     MULT = 276,
     DIV = 277,
     MOD = 278,
     ASIG = 279,
     IGUAL = 280,
     MENOR = 281,
     MAYOR = 282,
     MENOR_IGUAL = 283,
     MAYOR_IGUAL = 284,
     DIFERENTE = 285,
     FLECHA = 286,
     PARI = 287,
     PARD = 288,
     LLAVEI = 289,
     LLAVED = 290,
     PUNTOCOMA = 291,
     COMA = 292,
     DOS_PUNTOS = 293,
     LOWER_THAN_SINO = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 19 "parser.y"

    int num_entero;
    double num_decimal;
    char* cadena; 
    struct NodoAST* nodo; 



/* Line 214 of yacc.c  */
#line 175 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 187 "parser.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   463

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNRULES -- Number of states.  */
#define YYNSTATES  175

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
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    24,    33,
      35,    36,    40,    42,    45,    47,    49,    52,    56,    58,
      60,    64,    67,    68,    71,    76,    82,    88,    92,    94,
      96,    98,   100,   103,   111,   123,   131,   143,   151,   159,
     176,   184,   190,   196,   199,   200,   204,   208,   210,   212,
     214,   218,   220,   222,   224,   228,   232,   236,   240,   244,
     248,   252,   256,   260,   264,   268,   272,   274,   276,   278,
     280,   285,   287,   288,   290
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    -1,    42,    43,    -1,    -1,    53,
      -1,    44,    -1,     3,    15,    32,    45,    33,    31,    48,
      34,    52,    35,    -1,     3,    15,    32,    45,    33,    34,
      52,    35,    -1,    46,    -1,    -1,    46,    37,    47,    -1,
      47,    -1,    48,    15,    -1,    13,    -1,    14,    -1,    48,
      50,    -1,    50,    37,    51,    -1,    51,    -1,    15,    -1,
      15,    24,    63,    -1,    52,    53,    -1,    -1,    49,    36,
      -1,    15,    24,    63,    36,    -1,    12,    32,    61,    33,
      36,    -1,     7,    32,    15,    33,    36,    -1,     6,    63,
      36,    -1,    54,    -1,    55,    -1,    56,    -1,    57,    -1,
       1,    36,    -1,     8,    32,    63,    33,    34,    52,    35,
      -1,     8,    32,    63,    33,    34,    52,    35,     9,    34,
      52,    35,    -1,     8,    32,     1,    33,    34,    52,    35,
      -1,     8,    32,     1,    33,    34,    52,    35,     9,    34,
      52,    35,    -1,    10,    32,    63,    33,    34,    52,    35,
      -1,    10,    32,     1,    33,    34,    52,    35,    -1,    11,
      32,    48,    15,    24,    63,    36,    63,    36,    15,    24,
      63,    33,    34,    52,    35,    -1,    11,    32,     1,    33,
      34,    52,    35,    -1,     4,    63,    34,    58,    35,    -1,
       4,     1,    34,    58,    35,    -1,    58,    59,    -1,    -1,
      60,    38,    52,    -1,     5,    38,    52,    -1,    16,    -1,
      17,    -1,    18,    -1,    61,    37,    62,    -1,    62,    -1,
      18,    -1,    63,    -1,    63,    19,    63,    -1,    63,    20,
      63,    -1,    63,    21,    63,    -1,    63,    22,    63,    -1,
      63,    23,    63,    -1,    63,    27,    63,    -1,    63,    26,
      63,    -1,    63,    29,    63,    -1,    63,    28,    63,    -1,
      63,    25,    63,    -1,    63,    30,    63,    -1,    32,    63,
      33,    -1,    15,    -1,    64,    -1,    16,    -1,    17,    -1,
      15,    32,    65,    33,    -1,    66,    -1,    -1,    63,    -1,
      66,    37,    63,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    66,    66,    80,    81,    85,    86,    91,    93,    98,
      99,   103,   104,   108,   112,   113,   117,   121,   122,   126,
     127,   132,   133,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   151,   153,   155,   156,   160,   162,   166,
     172,   176,   178,   182,   183,   187,   188,   192,   193,   194,
     199,   200,   204,   205,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     229,   233,   234,   238,   239
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUN", "DEPENDE", "OTROS", "RETORNAR",
  "LEER", "SI", "SINO", "MIENTRAS", "PARA", "IMPRIMIR", "TIPO_ENTERO",
  "TIPO_DECIMAL", "ID", "NUM_ENTERO", "NUM_DECIMAL", "CADENA", "MAS",
  "MENOS", "MULT", "DIV", "MOD", "ASIG", "IGUAL", "MENOR", "MAYOR",
  "MENOR_IGUAL", "MAYOR_IGUAL", "DIFERENTE", "FLECHA", "PARI", "PARD",
  "LLAVEI", "LLAVED", "PUNTOCOMA", "COMA", "DOS_PUNTOS", "LOWER_THAN_SINO",
  "$accept", "programa", "lista_elementos", "elemento", "declaracion_fun",
  "parametros", "lista_parametros", "parametro", "tipo", "declaracion_var",
  "lista_ids", "declarador", "bloque_instrucciones", "instruccion",
  "estructura_si", "estructura_mientras", "estructura_para",
  "estructura_depende", "lista_casos", "caso", "valor_constante",
  "lista_impresion", "elemento_impresion", "expresion", "llamada_funcion",
  "argumentos", "lista_argumentos", 0
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
       0,    40,    41,    42,    42,    43,    43,    44,    44,    45,
      45,    46,    46,    47,    48,    48,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    54,    54,    54,    54,    55,    55,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    60,    60,
      61,    61,    62,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      64,    65,    65,    66,    66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,    10,     8,     1,
       0,     3,     1,     2,     1,     1,     2,     3,     1,     1,
       3,     2,     0,     2,     4,     5,     5,     3,     1,     1,
       1,     1,     2,     7,    11,     7,    11,     7,     7,    16,
       7,     5,     5,     2,     0,     3,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       4,     1,     0,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,    15,     0,     3,     6,     0,     0,
       5,    28,    29,    30,    31,    32,     0,     0,    66,    68,
      69,     0,     0,    67,     0,     0,     0,     0,     0,     0,
       0,    19,    16,    18,    23,    10,    44,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,    27,     0,     0,     0,     0,     0,     0,     0,    52,
       0,    51,    53,     0,     0,     0,     0,     9,    12,     0,
       0,    73,     0,    71,    65,    54,    55,    56,    57,    58,
      63,    60,    59,    62,    61,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,    20,    17,     0,
       0,    13,     0,    47,    48,    49,    42,    43,     0,    70,
       0,    41,    26,    22,    22,    22,    22,    22,     0,    25,
      50,     0,    22,    11,    22,    22,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    35,    21,    33,
      38,    37,    40,     0,    22,     8,     0,     0,     0,     0,
      22,    22,     0,     7,     0,     0,     0,    36,    34,     0,
       0,     0,    22,     0,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    16,    17,    76,    77,    78,    18,    19,
      42,    43,   137,   148,    21,    22,    23,    24,    80,   117,
     118,    70,    71,    72,    33,    82,    83
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -71
static const yytype_int16 yypact[] =
{
     -71,    13,   360,   -71,   -32,    11,     5,    77,     0,     1,
       6,     8,    10,   -71,   -71,    39,   -71,   -71,    46,    31,
     -71,   -71,   -71,   -71,   -71,   -71,    53,    62,    66,   -71,
     -71,    77,   357,   -71,   287,    84,    96,   267,    22,    71,
      77,    86,    64,   -71,   -71,    15,   -71,    77,   373,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
     -71,   -71,    82,    83,   388,    88,   403,   105,   102,   -71,
     -30,   -71,   433,   305,    77,    46,   107,    81,   -71,   104,
     270,   433,   108,   106,   -71,    37,    37,   -71,   -71,   -71,
      85,    85,    85,    85,    85,    85,   286,   120,   123,   125,
     136,   141,   145,   148,   150,    71,   -71,   433,   -71,    -7,
      15,   -71,   153,   -71,   -71,   -71,   -71,   -71,   157,   -71,
      77,   -71,   -71,   -71,   -71,   -71,   -71,   -71,    77,   -71,
     -71,    15,   -71,   -71,   -71,   -71,   433,     4,   138,   154,
     170,   186,   317,   168,   202,    65,   119,   179,   -71,   195,
     -71,   -71,   -71,    77,   -71,   -71,   173,   177,   329,   218,
     -71,   -71,   203,   -71,   234,   250,   196,   -71,   -71,    77,
     418,   189,   -71,   266,   -71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   117,   -36,   -71,
     -71,   159,   -70,   237,   -71,   -71,   -71,   -71,   176,   -71,
     -71,   -71,   147,    -6,   -71,   -71,   -71
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -47
static const yytype_int16 yytable[] =
{
      32,    34,    68,   104,    25,     4,    27,   105,     6,    79,
       7,     8,     9,     3,    10,    11,    12,    13,    14,    15,
      28,    29,    30,    67,   131,    48,    26,   132,    13,    14,
      64,    66,    35,    36,    73,    13,    14,    31,    37,   147,
      38,    81,    39,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,   138,   139,   140,   141,    51,    52,
      53,    41,   144,    40,   145,   146,     4,    44,   107,     6,
     -46,     7,     8,     9,    79,    10,    11,    12,    13,    14,
      15,   -46,   -46,   -46,   159,    45,    28,    29,    30,    69,
     164,   165,    28,    29,    30,   143,    46,    63,    47,    62,
     -46,    75,   173,    31,    49,    50,    51,    52,    53,    31,
      74,    28,    29,    30,   136,    97,    98,   103,   110,   111,
       4,   100,   142,     6,   -45,     7,     8,     9,    31,    10,
      11,    12,    13,    14,    15,   -45,   -45,   -45,   102,     4,
     109,   119,     6,   120,     7,     8,     9,   158,    10,    11,
      12,    13,    14,    15,   -45,     4,   122,   123,     6,   124,
       7,     8,     9,   170,    10,    11,    12,    13,    14,    15,
     125,     4,   128,   149,     6,   126,     7,     8,     9,   127,
      10,    11,    12,    13,    14,    15,   129,     4,   156,   150,
       6,   134,     7,     8,     9,   135,    10,    11,    12,    13,
      14,    15,   154,     4,   157,   151,     6,   160,     7,     8,
       9,   161,    10,    11,    12,    13,    14,    15,   166,     4,
     169,   152,     6,   172,     7,     8,     9,   133,    10,    11,
      12,    13,    14,    15,   108,     4,    96,   155,     6,    20,
       7,     8,     9,     0,    10,    11,    12,    13,    14,    15,
       0,     4,   130,   163,     6,     0,     7,     8,     9,     0,
      10,    11,    12,    13,    14,    15,     0,     4,    65,   167,
       6,     0,     7,     8,     9,   112,    10,    11,    12,    13,
      14,    15,    28,    29,    30,   168,   113,   114,   115,     0,
       0,   112,     0,     0,     0,     0,     0,     0,     0,    31,
       0,   174,   113,   114,   115,   116,    49,    50,    51,    52,
      53,     0,    54,    55,    56,    57,    58,    59,     0,     0,
       0,   121,     0,    61,    49,    50,    51,    52,    53,     0,
      54,    55,    56,    57,    58,    59,    49,    50,    51,    52,
      53,   106,    54,    55,    56,    57,    58,    59,    49,    50,
      51,    52,    53,   153,    54,    55,    56,    57,    58,    59,
      -2,     4,     0,     5,     6,   162,     7,     8,     9,     0,
      10,    11,    12,    13,    14,    15,    49,    50,    51,    52,
      53,     0,    54,    55,    56,    57,    58,    59,     0,     0,
       0,    60,    49,    50,    51,    52,    53,     0,    54,    55,
      56,    57,    58,    59,     0,     0,    84,    49,    50,    51,
      52,    53,     0,    54,    55,    56,    57,    58,    59,     0,
       0,    99,    49,    50,    51,    52,    53,     0,    54,    55,
      56,    57,    58,    59,     0,     0,   101,    49,    50,    51,
      52,    53,     0,    54,    55,    56,    57,    58,    59,     0,
       0,   171,    49,    50,    51,    52,    53,     0,    54,    55,
      56,    57,    58,    59
};

static const yytype_int16 yycheck[] =
{
       6,     7,    38,    33,    36,     1,     1,    37,     4,    45,
       6,     7,     8,     0,    10,    11,    12,    13,    14,    15,
      15,    16,    17,     1,    31,    31,    15,    34,    13,    14,
      36,    37,    32,    32,    40,    13,    14,    32,    32,    35,
      32,    47,    32,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,   124,   125,   126,   127,    21,    22,
      23,    15,   132,    24,   134,   135,     1,    36,    74,     4,
       5,     6,     7,     8,   110,    10,    11,    12,    13,    14,
      15,    16,    17,    18,   154,    32,    15,    16,    17,    18,
     160,   161,    15,    16,    17,   131,    34,     1,    32,    15,
      35,    37,   172,    32,    19,    20,    21,    22,    23,    32,
      24,    15,    16,    17,   120,    33,    33,    15,    37,    15,
       1,    33,   128,     4,     5,     6,     7,     8,    32,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    33,     1,
      33,    33,     4,    37,     6,     7,     8,   153,    10,    11,
      12,    13,    14,    15,    35,     1,    36,    34,     4,    34,
       6,     7,     8,   169,    10,    11,    12,    13,    14,    15,
      34,     1,    24,    35,     4,    34,     6,     7,     8,    34,
      10,    11,    12,    13,    14,    15,    36,     1,     9,    35,
       4,    38,     6,     7,     8,    38,    10,    11,    12,    13,
      14,    15,    34,     1,     9,    35,     4,    34,     6,     7,
       8,    34,    10,    11,    12,    13,    14,    15,    15,     1,
      24,    35,     4,    34,     6,     7,     8,   110,    10,    11,
      12,    13,    14,    15,    75,     1,    60,    35,     4,     2,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      -1,     1,   105,    35,     4,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    -1,     1,     1,    35,
       4,    -1,     6,     7,     8,     5,    10,    11,    12,    13,
      14,    15,    15,    16,    17,    35,    16,    17,    18,    -1,
      -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    35,    16,    17,    18,    35,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    35,    -1,    36,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    19,    20,    21,    22,
      23,    36,    25,    26,    27,    28,    29,    30,    19,    20,
      21,    22,    23,    36,    25,    26,    27,    28,    29,    30,
       0,     1,    -1,     3,     4,    36,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    34,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    -1,    -1,    33,    19,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    29,    30,    -1,
      -1,    33,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    -1,    -1,    33,    19,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    29,    30,    -1,
      -1,    33,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    42,     0,     1,     3,     4,     6,     7,     8,
      10,    11,    12,    13,    14,    15,    43,    44,    48,    49,
      53,    54,    55,    56,    57,    36,    15,     1,    15,    16,
      17,    32,    63,    64,    63,    32,    32,    32,    32,    32,
      24,    15,    50,    51,    36,    32,    34,    32,    63,    19,
      20,    21,    22,    23,    25,    26,    27,    28,    29,    30,
      34,    36,    15,     1,    63,     1,    63,     1,    48,    18,
      61,    62,    63,    63,    24,    37,    45,    46,    47,    48,
      58,    63,    65,    66,    33,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    58,    33,    33,    33,
      33,    33,    33,    15,    33,    37,    36,    63,    51,    33,
      37,    15,     5,    16,    17,    18,    35,    59,    60,    33,
      37,    35,    36,    34,    34,    34,    34,    34,    24,    36,
      62,    31,    34,    47,    38,    38,    63,    52,    52,    52,
      52,    52,    63,    48,    52,    52,    52,    35,    53,    35,
      35,    35,    35,    36,    34,    35,     9,     9,    63,    52,
      34,    34,    36,    35,    52,    52,    15,    35,    35,    24,
      63,    33,    34,    52,    35
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
#line 66 "parser.y"
    { 
        (yyval.nodo) = nuevo_nodo_programa((yyvsp[(1) - (1)].nodo)); // Enlace con la raíz global
        if (errores_sintacticos == 0) {
            printf("\nAnálisis sintáctico exitoso. Estructura del AST:\n"); 
            imprimir_ast((yyval.nodo), 0); // Se imprimirá el árbol de forma jerárquica
            liberar_ast((yyval.nodo)); // Se libera la memoria del AST al finalizar
        } else {
            printf("\nAnalisis finalizado con %d error(es) sintactico(s).\n", errores_sintacticos);
            liberar_ast((yyval.nodo));
        }
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 80 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_elements((yyvsp[(1) - (2)].nodo), (yyvsp[(2) - (2)].nodo)); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    { (yyval.nodo) = NULL; ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 85 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 86 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 92 "parser.y"
    { (yyval.nodo) = nuevo_nodo_declaracion_fun((yyvsp[(2) - (10)].cadena), (yyvsp[(7) - (10)].num_entero), (yyvsp[(4) - (10)].nodo), (yyvsp[(9) - (10)].nodo)); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 94 "parser.y"
    { (yyval.nodo) = nuevo_nodo_declaracion_fun((yyvsp[(2) - (8)].cadena), 0, (yyvsp[(4) - (8)].nodo), (yyvsp[(7) - (8)].nodo)); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    { (yyval.nodo) = NULL; ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_parametros((yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_parametros(NULL, (yyvsp[(1) - (1)].nodo)); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    { (yyval.nodo) = nuevo_nodo_parametro((yyvsp[(1) - (2)].num_entero), (yyvsp[(2) - (2)].cadena)); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 112 "parser.y"
    { (yyval.num_entero) = TIPO_ENTERO; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    { (yyval.num_entero) = TIPO_DECIMAL; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    { (yyval.nodo) = nuevo_nodo_declaracion_var((yyvsp[(1) - (2)].num_entero), (yyvsp[(2) - (2)].nodo)); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_ids((yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)->nombre_var); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 122 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_ids(NULL, (yyvsp[(1) - (1)].nodo)->nombre_var); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    { (yyval.nodo) = nuevo_nodo_variable((yyvsp[(1) - (1)].cadena)); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 127 "parser.y"
    { (yyval.nodo) = nuevo_nodo_asignacion((yyvsp[(1) - (3)].cadena), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 132 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_elements((yyvsp[(1) - (2)].nodo), (yyvsp[(2) - (2)].nodo)); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 133 "parser.y"
    { (yyval.nodo) = NULL; ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (2)].nodo); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    { (yyval.nodo) = nuevo_nodo_asignacion((yyvsp[(1) - (4)].cadena), (yyvsp[(3) - (4)].nodo)); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    { (yyval.nodo) = nuevo_nodo_imprimir((yyvsp[(3) - (5)].nodo)); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    { (yyval.nodo) = nuevo_nodo_leer((yyvsp[(3) - (5)].cadena)); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    { (yyval.nodo) = nuevo_nodo_retornar((yyvsp[(2) - (3)].nodo)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    { yyerrok; printf("=> [Panic Mode] Error sintáctico ignorado. Analizador recuperado en el ';'.\n"); (yyval.nodo) = NULL; ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    { (yyval.nodo) = nuevo_nodo_si((yyvsp[(3) - (7)].nodo), (yyvsp[(6) - (7)].nodo), NULL); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    { (yyval.nodo) = nuevo_nodo_si((yyvsp[(3) - (11)].nodo), (yyvsp[(6) - (11)].nodo), (yyvsp[(10) - (11)].nodo)); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    { yyerrok; printf("=> [Panic Mode] Error en condición del SI. Recuperado en ')'.\n"); (yyval.nodo) = NULL; ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    { yyerrok; printf("=> [Panic Mode] Error en condición del SI. Recuperado en ')'.\n"); (yyval.nodo) = NULL; ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    { (yyval.nodo) = nuevo_nodo_mientras((yyvsp[(3) - (7)].nodo), (yyvsp[(6) - (7)].nodo)); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    { yyerrok; printf("=> [Panic Mode] Error en condición del MIENTRAS. Recuperado en ')'.\n"); (yyval.nodo) = NULL; ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    { 
        NodoAST *init = nuevo_nodo_asignacion((yyvsp[(4) - (16)].cadena), (yyvsp[(6) - (16)].nodo));
        NodoAST *paso = nuevo_nodo_asignacion((yyvsp[(10) - (16)].cadena), (yyvsp[(12) - (16)].nodo));
        (yyval.nodo) = nuevo_nodo_para(init, (yyvsp[(8) - (16)].nodo), paso, (yyvsp[(15) - (16)].nodo)); 
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 172 "parser.y"
    { yyerrok; printf("=> [Panic Mode] Error en encabezado del PARA. Recuperado en ')'.\n"); (yyval.nodo) = NULL; ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 177 "parser.y"
    { (yyval.nodo) = nuevo_nodo_depende((yyvsp[(2) - (5)].nodo), (yyvsp[(4) - (5)].nodo)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    { yyerrok; printf("=> [Panic Mode] Error en valor del DEPENDE. Recuperado en '{'.\n"); (yyval.nodo) = NULL; ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_casos((yyvsp[(1) - (2)].nodo), (yyvsp[(2) - (2)].nodo)); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    { (yyval.nodo) = NULL; ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 187 "parser.y"
    { (yyval.nodo) = nuevo_nodo_caso((yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 188 "parser.y"
    { (yyval.nodo) = nuevo_nodo_caso(NULL, (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    { (yyval.nodo) = nuevo_nodo_entero((yyvsp[(1) - (1)].num_entero)); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 193 "parser.y"
    { (yyval.nodo) = nuevo_nodo_decimal((yyvsp[(1) - (1)].num_decimal)); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 194 "parser.y"
    { (yyval.nodo) = nuevo_nodo_cadena((yyvsp[(1) - (1)].cadena)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_argumentos((yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 200 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_argumentos(NULL, (yyvsp[(1) - (1)].nodo)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    { (yyval.nodo) = nuevo_nodo_cadena((yyvsp[(1) - (1)].cadena)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 205 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(MAS, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(MENOS, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(MULT, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 213 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(DIV, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(MOD, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 215 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(MAYOR, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(MENOR, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 217 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(MAYOR_IGUAL, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(MENOR_IGUAL, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(IGUAL, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(DIFERENTE, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 221 "parser.y"
    { (yyval.nodo) = (yyvsp[(2) - (3)].nodo); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    { (yyval.nodo) = nuevo_nodo_variable((yyvsp[(1) - (1)].cadena)); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    { (yyval.nodo) = nuevo_nodo_entero((yyvsp[(1) - (1)].num_entero)); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 225 "parser.y"
    { (yyval.nodo) = nuevo_nodo_decimal((yyvsp[(1) - (1)].num_decimal)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 229 "parser.y"
    { (yyval.nodo) = nuevo_nodo_llamada_funcion((yyvsp[(1) - (4)].cadena), (yyvsp[(3) - (4)].nodo)); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 233 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 234 "parser.y"
    { (yyval.nodo) = NULL; ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 238 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_argumentos(NULL, (yyvsp[(1) - (1)].nodo)); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 239 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_argumentos((yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2111 "parser.tab.c"
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
#line 242 "parser.y"


/* 7. REPORTE DE ERRORES DINÁMICO */
void yyerror(const char *s) {
    errores_sintacticos++;
    int col_exacta = columna - (int)strlen(yytext);
    if (col_exacta < 1) col_exacta = 1;

    fprintf(stderr, "\n¡Ups! Hay un problema sintactico en tu codigo.\n");
    fprintf(stderr, "Linea %d, Columna %d\n", yylineno, col_exacta);
    
    if (yytext[0] == '\0') {
        fprintf(stderr, "Detalle: Llegaste al final del archivo inesperadamente. ¿Te falto cerrar una llave '}' o colocar un ';'?\n");
    } else {
        fprintf(stderr, "Detalle: %s cerca del elemento '%s'\n\n", s, yytext);
    }
}

/* 8. FUNCIÓN PRINCIPAL */
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Error: Falta el archivo de entrada.\nUso: %s <archivo.to>\n", argv[0]);
        return 1;
    }

    FILE *archivo = fopen(argv[1], "r");
    if (!archivo) {
        printf("Error fatal: No se pudo abrir o encontrar el archivo '%s'.\n", argv[1]);
        return 1;
    }

    yyin = archivo;
    yyparse();
    fclose(archivo);
    
    return 0;
}
