%{
    #include "parser.tab.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h> /* Necesario para strdup */

    // Variable global para contar la columna actual
    int columna = 1;

    /* Se ejecuta ANTES de procesar cualquier regla.
     * Sumamos el largo del token actual (yyleng) a la columna.
     */
    #define YY_USER_ACTION columna += yyleng;
%}

/* Activar el conteo automático de líneas. ¡Muy útil para reportar errores! */
%option yylineno
%option noyywrap

/* Definiciones regulares para mantener el código limpio */
DIGITO [0-9]
LETRA  [a-zA-Z]

%%

    /* 0. IGNORAR COMENTARIOS (Deben ir primero para que no choquen con la división '/') */
\/\/.* { /* Ignorar comentarios de una línea */ }

    /* 1. PALABRAS RESERVADAS EN ESPAÑOL */
"fun"                { return FUN; }
"depende"            { return DEPENDE; }
"otros"              { return OTROS; }
"retornar"           { return RETORNAR; }
"leer"               { return LEER; }
"si"                 { return SI; }
"sino"               { return SINO; }
"mientras"           { return MIENTRAS; }
"para"               { return PARA; }
"imprimir"           { return IMPRIMIR; }
"entero"             { return TIPO_ENTERO; }
"decimal"            { return TIPO_DECIMAL; }

    /* 2. NÚMEROS */
{DIGITO}+            { yylval.num_entero = atoi(yytext); return NUM_ENTERO; }
{DIGITO}+"."{DIGITO}+ { yylval.num_decimal = atof(yytext); return NUM_DECIMAL; }

    /* 3. CADENAS DE TEXTO (Permite secuencias de escape como \n) */
\"([^\\\"]|\\.)*\"   { yylval.cadena = strdup(yytext); return CADENA; }

    /* 4. IDENTIFICADORES (Variables, funciones) */
{LETRA}({LETRA}|{DIGITO})* { yylval.cadena = strdup(yytext); return ID; }

    /* 5. OPERADORES ARITMÉTICOS Y DE ASIGNACIÓN */
"+"                  { return MAS; }
"-"                  { return MENOS; }
"*"                  { return MULT; }
"/"                  { return DIV; }
"%"                  { return MOD; }
"="                  { return ASIG; }

    /* 6. OPERADORES RELACIONALES Y PUNTEROS */
"=="                 { return IGUAL; }
"<"                  { return MENOR; }
">"                  { return MAYOR; }
"<="                 { return MENOR_IGUAL; }
">="                 { return MAYOR_IGUAL; }
"!="                 { return DIFERENTE; }
"->"                 { return FLECHA; }

    /* 7. SÍMBOLOS DE AGRUPACIÓN Y PUNTUACIÓN */
"("                  { return PARI; }
")"                  { return PARD; }
"{"                  { return LLAVEI; }
"}"                  { return LLAVED; }
";"                  { return PUNTOCOMA; }
","                  { return COMA; }
":"                  { return DOS_PUNTOS; }

    /* 8. MANEJO DE ESPACIOS Y ERRORES */
[ \t\r]+             { /* Ignorar espacios y tabulaciones (YY_USER_ACTION ya sumó las columnas) */ }
\n                   { columna = 1; /* Resetear la columna al cambiar de línea */ }
.                    { printf("Error Léxico en la línea %d, columna %d: Carácter inválido '%s'\n", yylineno, columna - (int)yyleng, yytext); }

%%