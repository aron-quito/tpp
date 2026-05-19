/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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
/* Tokens.  */
#define FUN 258
#define DEPENDE 259
#define OTROS 260
#define RETORNAR 261
#define LEER 262
#define SI 263
#define SINO 264
#define MIENTRAS 265
#define PARA 266
#define IMPRIMIR 267
#define TIPO_ENTERO 268
#define TIPO_DECIMAL 269
#define ID 270
#define NUM_ENTERO 271
#define NUM_DECIMAL 272
#define CADENA 273
#define MAS 274
#define MENOS 275
#define MULT 276
#define DIV 277
#define MOD 278
#define ASIG 279
#define IGUAL 280
#define MENOR 281
#define MAYOR 282
#define MENOR_IGUAL 283
#define MAYOR_IGUAL 284
#define DIFERENTE 285
#define FLECHA 286
#define PARI 287
#define PARD 288
#define LLAVEI 289
#define LLAVED 290
#define PUNTOCOMA 291
#define COMA 292
#define DOS_PUNTOS 293
#define LOWER_THAN_SINO 294




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "ast.h"
    #include "semantic.h"
    #include "codegen.h"
    
    char nombre_base[256];

    extern FILE *yyin;
    extern int yylineno;
    extern int columna;
    extern char *yytext;
    
    void yyerror(const char *s);
    int yylex();


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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "parser.y"
{
    int num_entero;
    double num_decimal;
    char* cadena; /* Mapeado con yylval.cadena de tu lexer para ID y CADENA */
    struct NodoAST* nodo; /* Puntero para todos nuestros nodos del AST */
}
/* Line 193 of yacc.c.  */
#line 200 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 213 "parser.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   327

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  147

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
       0,     0,     3,     5,     8,     9,    11,    13,    24,    33,
      35,    36,    40,    42,    45,    47,    49,    52,    56,    58,
      61,    62,    65,    70,    76,    82,    86,    88,    90,    92,
      94,   102,   114,   122,   139,   145,   148,   149,   153,   157,
     159,   161,   163,   167,   169,   171,   173,   177,   181,   185,
     189,   193,   197,   201,   205,   209,   213,   217,   221,   223,
     225,   227,   229,   234,   236,   237,   239
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    -1,    42,    43,    -1,    -1,    52,
      -1,    44,    -1,     3,    15,    32,    45,    33,    31,    48,
      34,    51,    35,    -1,     3,    15,    32,    45,    33,    34,
      51,    35,    -1,    46,    -1,    -1,    46,    37,    47,    -1,
      47,    -1,    48,    15,    -1,    13,    -1,    14,    -1,    48,
      50,    -1,    50,    37,    15,    -1,    15,    -1,    51,    52,
      -1,    -1,    49,    36,    -1,    15,    24,    62,    36,    -1,
      12,    32,    60,    33,    36,    -1,     7,    32,    15,    33,
      36,    -1,     6,    62,    36,    -1,    53,    -1,    54,    -1,
      55,    -1,    56,    -1,     8,    32,    62,    33,    34,    51,
      35,    -1,     8,    32,    62,    33,    34,    51,    35,     9,
      34,    51,    35,    -1,    10,    32,    62,    33,    34,    51,
      35,    -1,    11,    32,    48,    15,    24,    62,    36,    62,
      36,    15,    24,    62,    33,    34,    51,    35,    -1,     4,
      62,    34,    57,    35,    -1,    57,    58,    -1,    -1,    59,
      38,    51,    -1,     5,    38,    51,    -1,    16,    -1,    17,
      -1,    18,    -1,    60,    37,    61,    -1,    61,    -1,    18,
      -1,    62,    -1,    62,    19,    62,    -1,    62,    20,    62,
      -1,    62,    21,    62,    -1,    62,    22,    62,    -1,    62,
      23,    62,    -1,    62,    27,    62,    -1,    62,    26,    62,
      -1,    62,    29,    62,    -1,    62,    28,    62,    -1,    62,
      25,    62,    -1,    62,    30,    62,    -1,    32,    62,    33,
      -1,    15,    -1,    63,    -1,    16,    -1,    17,    -1,    15,
      32,    64,    33,    -1,    65,    -1,    -1,    62,    -1,    65,
      37,    62,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    63,    63,    82,    83,    87,    88,    93,    97,   104,
     105,   109,   110,   114,   118,   119,   123,   127,   128,   133,
     134,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     151,   154,   160,   166,   176,   182,   183,   187,   190,   196,
     197,   198,   203,   204,   208,   209,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   233,   237,   238,   242,   243
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
  "lista_ids", "bloque_instrucciones", "instruccion", "estructura_si",
  "estructura_mientras", "estructura_para", "estructura_depende",
  "lista_casos", "caso", "valor_constante", "lista_impresion",
  "elemento_impresion", "expresion", "llamada_funcion", "argumentos",
  "lista_argumentos", 0
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
      51,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      53,    53,    54,    55,    56,    57,    57,    58,    58,    59,
      59,    59,    60,    60,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    63,    64,    64,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,    10,     8,     1,
       0,     3,     1,     2,     1,     1,     2,     3,     1,     2,
       0,     2,     4,     5,     5,     3,     1,     1,     1,     1,
       7,    11,     7,    16,     5,     2,     0,     3,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     4,     1,     0,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     3,     6,     0,     0,     5,
      26,    27,    28,    29,     0,    58,    60,    61,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,    18,    16,
      21,    10,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    25,     0,     0,     0,
       0,    44,     0,    43,    45,     0,     0,     0,     9,    12,
       0,    65,     0,    63,    57,    46,    47,    48,    49,    50,
      55,    52,    51,    54,    53,    56,     0,     0,     0,     0,
       0,     0,     0,    22,    17,     0,     0,    13,    62,     0,
       0,    39,    40,    41,    34,    35,     0,    24,    20,    20,
       0,    23,    42,     0,    20,    11,    66,    20,    20,     0,
       0,     0,     0,     0,    38,    37,    30,    19,    32,     0,
      20,     8,     0,     0,     0,    20,     0,     7,     0,     0,
      31,     0,     0,     0,    20,     0,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    15,    16,    67,    68,    69,    17,    18,
      39,   119,   127,    20,    21,    22,    23,    86,   105,   106,
      62,    63,    64,    30,    72,    73
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -60
static const yytype_int16 yypact[] =
{
     -60,     4,   159,   -60,     0,    45,    45,   -11,    -2,     3,
       6,    19,   -60,   -60,     7,   -60,   -60,    21,    16,   -60,
     -60,   -60,   -60,   -60,    22,    24,   -60,   -60,    45,   204,
     -60,   156,    42,    45,    45,    13,     1,    45,   -60,    33,
     -60,    13,    45,   220,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,   -60,   -60,    39,   235,   250,
      58,   -60,   -13,   -60,   280,   168,    59,    49,    38,   -60,
      63,   280,    51,    44,   -60,    46,    46,   -60,   -60,   -60,
     304,   304,   304,   304,   304,   304,    48,    43,    52,    53,
      64,    54,     1,   -60,   -60,    -9,    13,   -60,   -60,    45,
      65,   -60,   -60,   -60,   -60,   -60,    71,   -60,   -60,   -60,
      45,   -60,   -60,    13,   -60,   -60,   280,   -60,   -60,    -1,
      85,   180,    67,   100,   307,   307,    93,   -60,   -60,    45,
     -60,   -60,    82,   192,   115,   -60,   102,   -60,   133,    94,
     -60,    45,   265,    97,   -60,   145,   -60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -60,   -60,   -60,   -60,   -60,   -60,   -60,    36,   -33,   -60,
     -60,   -59,   131,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,    50,    -5,   -60,   -60,   -60
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      29,    31,    60,     5,     3,     6,     7,     8,    70,     9,
      10,    11,    12,    13,    14,    24,    25,    26,    27,    61,
      91,    32,   113,    43,    92,   114,    12,    13,    58,    59,
      33,    37,    65,    28,   126,    34,    38,    71,    35,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
     120,    36,    40,   100,    41,   123,    42,    57,   124,   125,
      25,    26,    27,    70,   101,   102,   103,    46,    47,    48,
      66,   134,    87,    90,    94,    96,   138,    28,    97,   107,
     122,    99,    95,   104,    98,   145,   108,   109,   110,     5,
     111,     6,     7,     8,   116,     9,    10,    11,    12,    13,
      14,   130,   132,   117,     5,   121,     6,     7,     8,   118,
       9,    10,    11,    12,    13,    14,   135,   139,   141,     5,
     128,     6,     7,     8,   133,     9,    10,    11,    12,    13,
      14,   144,   115,    19,     0,   131,   142,     5,     0,     6,
       7,     8,   112,     9,    10,    11,    12,    13,    14,     5,
     137,     6,     7,     8,     0,     9,    10,    11,    12,    13,
      14,     0,     4,     5,     0,     6,     7,     8,   140,     9,
      10,    11,    12,    13,    14,    44,    45,    46,    47,    48,
     146,    49,    50,    51,    52,    53,    54,    44,    45,    46,
      47,    48,    56,    49,    50,    51,    52,    53,    54,    44,
      45,    46,    47,    48,    93,    49,    50,    51,    52,    53,
      54,    44,    45,    46,    47,    48,   129,    49,    50,    51,
      52,    53,    54,    44,    45,    46,    47,    48,   136,    49,
      50,    51,    52,    53,    54,     0,     0,     0,    55,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,    53,
      54,     0,     0,    74,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,    53,    54,     0,     0,    88,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,    53,
      54,     0,     0,    89,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,    53,    54,     0,     0,   143,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,    53,
      54,     5,     0,     6,     7,     8,     0,     9,    10,    11,
      12,    13,    14,    44,    45,    46,    47,    48
};

static const yytype_int16 yycheck[] =
{
       5,     6,    35,     4,     0,     6,     7,     8,    41,    10,
      11,    12,    13,    14,    15,    15,    15,    16,    17,    18,
      33,    32,    31,    28,    37,    34,    13,    14,    33,    34,
      32,    24,    37,    32,    35,    32,    15,    42,    32,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
     109,    32,    36,     5,    32,   114,    32,    15,   117,   118,
      15,    16,    17,    96,    16,    17,    18,    21,    22,    23,
      37,   130,    33,    15,    15,    37,   135,    32,    15,    36,
     113,    37,    33,    35,    33,   144,    34,    34,    24,     4,
      36,     6,     7,     8,    99,    10,    11,    12,    13,    14,
      15,    34,     9,    38,     4,   110,     6,     7,     8,    38,
      10,    11,    12,    13,    14,    15,    34,    15,    24,     4,
      35,     6,     7,     8,   129,    10,    11,    12,    13,    14,
      15,    34,    96,     2,    -1,    35,   141,     4,    -1,     6,
       7,     8,    92,    10,    11,    12,    13,    14,    15,     4,
      35,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    -1,     3,     4,    -1,     6,     7,     8,    35,    10,
      11,    12,    13,    14,    15,    19,    20,    21,    22,    23,
      35,    25,    26,    27,    28,    29,    30,    19,    20,    21,
      22,    23,    36,    25,    26,    27,    28,    29,    30,    19,
      20,    21,    22,    23,    36,    25,    26,    27,    28,    29,
      30,    19,    20,    21,    22,    23,    36,    25,    26,    27,
      28,    29,    30,    19,    20,    21,    22,    23,    36,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    34,    19,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    29,
      30,    -1,    -1,    33,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    -1,    -1,    33,    19,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    29,
      30,    -1,    -1,    33,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    -1,    -1,    33,    19,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    29,
      30,     4,    -1,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    19,    20,    21,    22,    23
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    42,     0,     3,     4,     6,     7,     8,    10,
      11,    12,    13,    14,    15,    43,    44,    48,    49,    52,
      53,    54,    55,    56,    15,    15,    16,    17,    32,    62,
      63,    62,    32,    32,    32,    32,    32,    24,    15,    50,
      36,    32,    32,    62,    19,    20,    21,    22,    23,    25,
      26,    27,    28,    29,    30,    34,    36,    15,    62,    62,
      48,    18,    60,    61,    62,    62,    37,    45,    46,    47,
      48,    62,    64,    65,    33,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    57,    33,    33,    33,
      15,    33,    37,    36,    15,    33,    37,    15,    33,    37,
       5,    16,    17,    18,    35,    58,    59,    36,    34,    34,
      24,    36,    61,    31,    34,    47,    62,    38,    38,    51,
      51,    62,    48,    51,    51,    51,    35,    52,    35,    36,
      34,    35,     9,    62,    51,    34,    36,    35,    51,    15,
      35,    24,    62,    33,    34,    51,    35
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 63 "parser.y"
    { 
        NodoAST* raiz = nuevo_nodo_programa((yyvsp[(1) - (1)].nodo));
        printf("\n¡Análisis sintáctico exitoso! El código es válido.\n\n"); 
        printf("======================= ÁRBOL SINTÁCTICO ABSTRACTO (AST) =======================\n");
        imprimir_ast(raiz, 0);
        printf("================================================================================\n\n");
        
        if (analizar_semantica(raiz)) {
            char archivo_cpp[256];
            snprintf(archivo_cpp, sizeof(archivo_cpp), "%s.cpp", nombre_base);
            generar_codigo_c(raiz, archivo_cpp, nombre_base);
        }
        
        liberar_ast(raiz);
        (yyval.nodo) = NULL;
    ;}
    break;

  case 3:
#line 82 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_elementos((yyvsp[(1) - (2)].nodo), (yyvsp[(2) - (2)].nodo)); ;}
    break;

  case 4:
#line 83 "parser.y"
    { (yyval.nodo) = NULL; ;}
    break;

  case 5:
#line 87 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 6:
#line 88 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 7:
#line 93 "parser.y"
    {
        (yyval.nodo) = nuevo_nodo_declaracion_fun((yyvsp[(2) - (10)].cadena), (yyvsp[(7) - (10)].num_entero), (yyvsp[(4) - (10)].nodo), (yyvsp[(9) - (10)].nodo));
        free((yyvsp[(2) - (10)].cadena));
    ;}
    break;

  case 8:
#line 97 "parser.y"
    {
        (yyval.nodo) = nuevo_nodo_declaracion_fun((yyvsp[(2) - (8)].cadena), 0, (yyvsp[(4) - (8)].nodo), (yyvsp[(7) - (8)].nodo));
        free((yyvsp[(2) - (8)].cadena));
    ;}
    break;

  case 9:
#line 104 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 10:
#line 105 "parser.y"
    { (yyval.nodo) = NULL; ;}
    break;

  case 11:
#line 109 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_parametros((yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 12:
#line 110 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 13:
#line 114 "parser.y"
    { (yyval.nodo) = nuevo_nodo_parametro((yyvsp[(1) - (2)].num_entero), (yyvsp[(2) - (2)].cadena)); free((yyvsp[(2) - (2)].cadena)); ;}
    break;

  case 14:
#line 118 "parser.y"
    { (yyval.num_entero) = TIPO_ENTERO; ;}
    break;

  case 15:
#line 119 "parser.y"
    { (yyval.num_entero) = TIPO_DECIMAL; ;}
    break;

  case 16:
#line 123 "parser.y"
    { (yyval.nodo) = nuevo_nodo_declaracion_var((yyvsp[(1) - (2)].num_entero), (yyvsp[(2) - (2)].nodo)); ;}
    break;

  case 17:
#line 127 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_ids((yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].cadena)); free((yyvsp[(3) - (3)].cadena)); ;}
    break;

  case 18:
#line 128 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_ids(NULL, (yyvsp[(1) - (1)].cadena)); free((yyvsp[(1) - (1)].cadena)); ;}
    break;

  case 19:
#line 133 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_elementos((yyvsp[(1) - (2)].nodo), (yyvsp[(2) - (2)].nodo)); ;}
    break;

  case 20:
#line 134 "parser.y"
    { (yyval.nodo) = NULL; ;}
    break;

  case 21:
#line 138 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (2)].nodo); ;}
    break;

  case 22:
#line 139 "parser.y"
    { (yyval.nodo) = nuevo_nodo_asignacion((yyvsp[(1) - (4)].cadena), (yyvsp[(3) - (4)].nodo)); free((yyvsp[(1) - (4)].cadena)); ;}
    break;

  case 23:
#line 140 "parser.y"
    { (yyval.nodo) = nuevo_nodo_imprimir((yyvsp[(3) - (5)].nodo)); ;}
    break;

  case 24:
#line 141 "parser.y"
    { (yyval.nodo) = nuevo_nodo_leer((yyvsp[(3) - (5)].cadena)); free((yyvsp[(3) - (5)].cadena)); ;}
    break;

  case 25:
#line 142 "parser.y"
    { (yyval.nodo) = nuevo_nodo_retornar((yyvsp[(2) - (3)].nodo)); ;}
    break;

  case 26:
#line 143 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 27:
#line 144 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 28:
#line 145 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 29:
#line 146 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 30:
#line 151 "parser.y"
    {
        (yyval.nodo) = nuevo_nodo_si((yyvsp[(3) - (7)].nodo), (yyvsp[(6) - (7)].nodo), NULL);
    ;}
    break;

  case 31:
#line 154 "parser.y"
    {
        (yyval.nodo) = nuevo_nodo_si((yyvsp[(3) - (11)].nodo), (yyvsp[(6) - (11)].nodo), (yyvsp[(10) - (11)].nodo));
    ;}
    break;

  case 32:
#line 160 "parser.y"
    {
        (yyval.nodo) = nuevo_nodo_mientras((yyvsp[(3) - (7)].nodo), (yyvsp[(6) - (7)].nodo));
    ;}
    break;

  case 33:
#line 166 "parser.y"
    {
        NodoAST* init = nuevo_nodo_declaracion_var((yyvsp[(3) - (16)].num_entero), nuevo_nodo_asignacion((yyvsp[(4) - (16)].cadena), (yyvsp[(6) - (16)].nodo)));
        NodoAST* paso = nuevo_nodo_asignacion((yyvsp[(10) - (16)].cadena), (yyvsp[(12) - (16)].nodo));
        (yyval.nodo) = nuevo_nodo_para(init, (yyvsp[(8) - (16)].nodo), paso, (yyvsp[(15) - (16)].nodo));
        free((yyvsp[(4) - (16)].cadena));
        free((yyvsp[(10) - (16)].cadena));
    ;}
    break;

  case 34:
#line 176 "parser.y"
    {
        (yyval.nodo) = nuevo_nodo_depende((yyvsp[(2) - (5)].nodo), (yyvsp[(4) - (5)].nodo));
    ;}
    break;

  case 35:
#line 182 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_casos((yyvsp[(1) - (2)].nodo), (yyvsp[(2) - (2)].nodo)); ;}
    break;

  case 36:
#line 183 "parser.y"
    { (yyval.nodo) = NULL; ;}
    break;

  case 37:
#line 187 "parser.y"
    {
        (yyval.nodo) = nuevo_nodo_caso((yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo));
    ;}
    break;

  case 38:
#line 190 "parser.y"
    {
        (yyval.nodo) = nuevo_nodo_caso(NULL, (yyvsp[(3) - (3)].nodo));
    ;}
    break;

  case 39:
#line 196 "parser.y"
    { (yyval.nodo) = nuevo_nodo_entero((yyvsp[(1) - (1)].num_entero)); ;}
    break;

  case 40:
#line 197 "parser.y"
    { (yyval.nodo) = nuevo_nodo_decimal((yyvsp[(1) - (1)].num_decimal)); ;}
    break;

  case 41:
#line 198 "parser.y"
    { (yyval.nodo) = nuevo_nodo_cadena((yyvsp[(1) - (1)].cadena)); free((yyvsp[(1) - (1)].cadena)); ;}
    break;

  case 42:
#line 203 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_argumentos((yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 43:
#line 204 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 44:
#line 208 "parser.y"
    { (yyval.nodo) = nuevo_nodo_cadena((yyvsp[(1) - (1)].cadena)); free((yyvsp[(1) - (1)].cadena)); ;}
    break;

  case 45:
#line 209 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 46:
#line 214 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(MAS, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 47:
#line 215 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(MENOS, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 48:
#line 216 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(MULT, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 49:
#line 217 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(DIV, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 50:
#line 218 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(MOD, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 51:
#line 219 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(MAYOR, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 52:
#line 220 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(MENOR, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 53:
#line 221 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(MAYOR_IGUAL, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 54:
#line 222 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(MENOR_IGUAL, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 55:
#line 223 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(IGUAL, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 56:
#line 224 "parser.y"
    { (yyval.nodo) = nuevo_nodo_operacion(DIFERENTE, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 57:
#line 225 "parser.y"
    { (yyval.nodo) = (yyvsp[(2) - (3)].nodo); ;}
    break;

  case 58:
#line 226 "parser.y"
    { (yyval.nodo) = nuevo_nodo_variable((yyvsp[(1) - (1)].cadena)); free((yyvsp[(1) - (1)].cadena)); ;}
    break;

  case 59:
#line 227 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 60:
#line 228 "parser.y"
    { (yyval.nodo) = nuevo_nodo_entero((yyvsp[(1) - (1)].num_entero)); ;}
    break;

  case 61:
#line 229 "parser.y"
    { (yyval.nodo) = nuevo_nodo_decimal((yyvsp[(1) - (1)].num_decimal)); ;}
    break;

  case 62:
#line 233 "parser.y"
    { (yyval.nodo) = nuevo_nodo_llamada_funcion((yyvsp[(1) - (4)].cadena), (yyvsp[(3) - (4)].nodo)); free((yyvsp[(1) - (4)].cadena)); ;}
    break;

  case 63:
#line 237 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 64:
#line 238 "parser.y"
    { (yyval.nodo) = NULL; ;}
    break;

  case 65:
#line 242 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_argumentos(NULL, (yyvsp[(1) - (1)].nodo)); ;}
    break;

  case 66:
#line 243 "parser.y"
    { (yyval.nodo) = nuevo_nodo_lista_argumentos((yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1932 "parser.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 246 "parser.y"


/* 7. REPORTE DE ERRORES DINÁMICO */
void yyerror(const char *s) {
    int col_exacta = columna - (int)strlen(yytext);
    if (col_exacta < 1) col_exacta = 1;

    fprintf(stderr, "\n¡Ups! Hay un problema sintáctico en tu código.\n");
    fprintf(stderr, "Linea %d, Columna %d\n", yylineno, col_exacta);
    
    if (yytext[0] == '\0') {
        fprintf(stderr, "Detalle: Llegaste al final del archivo inesperadamente. ¿Te faltó cerrar una llave '}' o colocar un ';'?\n");
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

    // Extraer el nombre base sin extensión
    strncpy(nombre_base, argv[1], sizeof(nombre_base) - 1);
    nombre_base[sizeof(nombre_base) - 1] = '\0';
    char *dot = strrchr(nombre_base, '.');
    if (dot) {
        *dot = '\0';
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
