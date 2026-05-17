%{
    #include "parser.tab.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h> /* Necesario para strdup */
%}

/* Definiciones regulares para mantener el código limpio */
DIGITO [0-9]
LETRA  [a-zA-Z]

%%

    /* 1. PALABRAS RESERVADAS EN ESPAÑOL */
    /* Importante: Deben ir antes de la regla de los identificadores (ID) */
"si"                 { return SI; }
"sino"               { return SINO; }
"mientras"           { return MIENTRAS; }
"para"               { return PARA; }
"imprimir"           { return IMPRIMIR; }
"entero"             { return TIPO_ENTERO; }
"decimal"            { return TIPO_DECIMAL; }

    /* 2. NÚMEROS (Separando enteros de decimales para mayor control) */
{DIGITO}+            { yylval.num_entero = atoi(yytext); return NUM_ENTERO; }
{DIGITO}+"."{DIGITO}+ { yylval.num_decimal = atof(yytext); return NUM_DECIMAL; }


    /* 3. IDENTIFICADORES (Variables, funciones) */
{LETRA}({LETRA}|{DIGITO})* { yylval.cadena = strdup(yytext); return ID; }

    /* 4. OPERADORES ARITMÉTICOS Y DE ASIGNACIÓN */
"+"                  { return MAS; }
"-"                  { return MENOS; }
"*"                  { return MULT; }
"/"                  { return DIV; }
"%"                  { return MOD; }
"="                  { return ASIG; }

    /* 5. OPERADORES RELACIONALES (Nuevos para los ciclos y condicionales) */
"=="                 { return IGUAL_QUE; }
"<"                  { return MENOR_QUE; }
">"                  { return MAYOR_QUE; }
"<="                 { return MENOR_IGUAL; }
">="                 { return MAYOR_IGUAL; }
"!="                 { return DIFERENTE; }

    /* 6. SÍMBOLOS DE AGRUPACIÓN Y CONTROL */
"("                  { return PARI; }
")"                  { return PARD; }
"{"                  { return LLAVEI; }
"}"                  { return LLAVED; }
";"                  { return PCOMA; }

    /* 7. MANEJO DE ESPACIOS Y ERRORES */
[ \t\r]+             { /* Ignorar espacios, tabulaciones y retornos de carro */ }
"\n"                 { return '\n'; /* Útil si quieres que los saltos de línea marquen el fin de una instrucción como en Python */ }
.                    { printf("Error Léxico: Caracter inválido '%s'\n", yytext); }

%%

int yywrap() {
    return 1;
}

//////////////////////////////////////////////

fun calcular()(

)

entero num1;
entero num2;
entero op;
entero res;

imprimir("Introduce numero 1: ");
leer(num1);
imprimir("Introduce numero 2: ");
leer(num2);
imprimir("Que operacion deseas hacer: ");
imprimir("1. +");
imprimir("2. -");
imprimir("3. *");
imprimir("4. /");
leer(op)

calcular(num1, num2, op, res);

imprimir(res);

// impresion de valores dentro un string
// salto de linea en imprimir
