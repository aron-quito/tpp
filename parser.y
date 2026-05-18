%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    extern FILE *yyin;
    extern int yylineno;
    extern int columna;
    extern char *yytext;
    
    void yyerror(const char *s);
    int yylex();
%}

/* DEFINICIÓN DE LA UNIÓN: Tipos de datos para el AST o valores semánticos */
%union {
    int num_entero;
    double num_decimal;
    char* cadena; /* Mapeado con yylval.cadena de tu lexer para ID y CADENA */
}

/* Tokens de palabras reservadas */
%token FUN DEPENDE OTROS RETORNAR LEER SI SINO MIENTRAS PARA IMPRIMIR TIPO_ENTERO TIPO_DECIMAL

/* Tokens con valor semántico asociado */
%token <cadena> ID
%token <num_entero> NUM_ENTERO
%token <num_decimal> NUM_DECIMAL
%token <cadena> CADENA



/* Operadores Aritméticos y de Asignación */
%token MAS MENOS MULT DIV MOD ASIG

/* Operadores Relacionales y Punteros */
%token IGUAL MENOR MAYOR MENOR_IGUAL MAYOR_IGUAL DIFERENTE FLECHA

/* Símbolos de agrupación y puntuación */
%token PARI PARD LLAVEI LLAVED PUNTOCOMA COMA DOS_PUNTOS

/* Precedencia y asociatividad de operadores para resolver ambigüedades matemáticas y lógicas */
%left IGUAL DIFERENTE MENOR MAYOR MENOR_IGUAL MAYOR_IGUAL
%left MAS MENOS
%left MULT DIV MOD

/* Configuración para resolver el dilema del "sino" huérfano (Dangling Else) */
%nonassoc LOWER_THAN_SINO
%nonassoc SINO

%%

/* 1. PUNTO DE ENTRADA DE LA GRAMÁTICA */
programa:
    lista_elementos { printf("Análisis sintáctico exitoso. El código es válido.\n"); }
    ;

lista_elementos:
    lista_elementos elemento
    | /* vacío */
    ;

elemento:
    instruccion
    | declaracion_fun
    ;

/* 2. DEFINICIÓN DE FUNCIONES Y PARÁMETROS */
declaracion_fun:
    FUN ID PARI parametros PARD FLECHA tipo LLAVEI bloque_instrucciones LLAVED
    | FUN ID PARI parametros PARD LLAVEI bloque_instrucciones LLAVED
    ;

parametros:
    lista_parametros
    | /* vacío (sin parámetros) */
    ;

lista_parametros:
    lista_parametros COMA parametro
    | parametro
    ;

parametro:
    tipo ID
    ;

tipo:
    TIPO_ENTERO
    | TIPO_DECIMAL
    ;

declaracion_var:
    tipo lista_ids
    ;

lista_ids:
    lista_ids COMA ID
    | ID
    ;

/* 3. BLOQUES DE CÓDIGO E INSTRUCCIONES ATÓMICAS */
bloque_instrucciones:
    bloque_instrucciones instruccion
    | /* vacío */
    ;

instruccion:
    declaracion_var PUNTOCOMA
    | ID ASIG expresion PUNTOCOMA
    | IMPRIMIR PARI lista_impresion PARD PUNTOCOMA
    | LEER PARI ID PARD PUNTOCOMA
    | RETORNAR expresion PUNTOCOMA
    | estructura_si
    | estructura_mientras
    | estructura_para
    | estructura_depende
    ;

/* 4. ESTRUCTURAS DE CONTROL DE FLUJO */
estructura_si:
    SI PARI expresion PARD LLAVEI bloque_instrucciones LLAVED %prec LOWER_THAN_SINO
    | SI PARI expresion PARD LLAVEI bloque_instrucciones LLAVED SINO LLAVEI bloque_instrucciones LLAVED
    ;

estructura_mientras:
    MIENTRAS PARI expresion PARD LLAVEI bloque_instrucciones LLAVED
    ;

estructura_para:
    PARA PARI tipo ID ASIG expresion PUNTOCOMA expresion PUNTOCOMA ID ASIG expresion PARD LLAVEI bloque_instrucciones LLAVED
    ;

estructura_depende:
    DEPENDE expresion LLAVEI lista_casos LLAVED
    ;

lista_casos:
    lista_casos caso
    | /* vacío */
    ;

/* Redefinimos 'caso' para que exija un valor constante en lugar de una expresión abierta */
caso:
    valor_constante DOS_PUNTOS bloque_instrucciones
    | OTROS DOS_PUNTOS bloque_instrucciones
    ;

/* Creamos una nueva regla exclusiva para literales puros */
valor_constante:
    NUM_ENTERO
    | NUM_DECIMAL
    | CADENA
    ;

/* 5. OPERACIONES DE ENTRADA / SALIDA */
lista_impresion:
    lista_impresion COMA elemento_impresion
    | elemento_impresion
    ;

elemento_impresion:
    CADENA
    | expresion
    ;

/* 6. EXPRESIONES (Matemáticas, Lógicas y Llamadas a Funciones) */
expresion:
    expresion MAS expresion
    | expresion MENOS expresion
    | expresion MULT expresion
    | expresion DIV expresion
    | expresion MOD expresion
    | expresion MAYOR expresion
    | expresion MENOR expresion
    | expresion MAYOR_IGUAL expresion
    | expresion MENOR_IGUAL expresion
    | expresion IGUAL expresion
    | expresion DIFERENTE expresion
    | PARI expresion PARD
    | ID
    | llamada_funcion
    | NUM_ENTERO
    | NUM_DECIMAL
    ;

llamada_funcion:
    ID PARI argumentos PARD
    ;

argumentos:
    lista_argumentos
    | /* vacío */
    ;

lista_argumentos:
    expresion
    | lista_argumentos COMA expresion
    ;

%%

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