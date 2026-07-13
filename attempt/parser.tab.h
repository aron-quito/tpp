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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "parser.y"
{
    int num_entero;
    double num_decimal;
    char* cadena; /* Mapeado con yylval.cadena de tu lexer para ID y CADENA */
    struct NodoAST* nodo; /* Puntero para todos nuestros nodos del AST */
}
/* Line 1529 of yacc.c.  */
#line 134 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

