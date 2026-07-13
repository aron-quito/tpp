%{
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
%}

/* DEFINICIÓN DE LA UNIÓN: Tipos de datos para el AST o valores semánticos */
%union {
    int num_entero;
    double num_decimal;
    char* cadena; 
    struct NodoAST* nodo; 
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

/* Mapeamos qué reglas de la gramática devolverán un nodo del AST */
%type <nodo> programa lista_elementos elemento declaracion_fun
%type <nodo> parametros lista_parametros parametro
%type <nodo> declaracion_var lista_ids declarador bloque_instrucciones instruccion
%type <nodo> estructura_si estructura_mientras estructura_para estructura_depende
%type <nodo> lista_casos caso valor_constante lista_impresion elemento_impresion
%type <nodo> expresion llamada_funcion argumentos lista_argumentos
%type <num_entero> tipo 

/* Precedencia y asociatividad de operadores */
%left IGUAL DIFERENTE MENOR MAYOR MENOR_IGUAL MAYOR_IGUAL
%left MAS MENOS
%left MULT DIV MOD

/* Configuración para resolver el dilema del "sino" huérfano */
%nonassoc LOWER_THAN_SINO
%nonassoc SINO

%%

/* 1. PUNTO DE ENTRADA DE LA GRAMÁTICA */
programa:
    lista_elementos { 
        $$ = nuevo_nodo_programa($1); // Enlace con la raíz global
        if (errores_sintacticos == 0) {
            printf("\nAnálisis sintáctico exitoso. Estructura del AST:\n"); 
            imprimir_ast($$, 0); // Se imprimirá el árbol de forma jerárquica
            liberar_ast($$); // Se libera la memoria del AST al finalizar
        } else {
            printf("\nAnalisis finalizado con %d error(es) sintactico(s).\n", errores_sintacticos);
            liberar_ast($$);
        }
    }
    ;

lista_elementos:
    lista_elementos elemento { $$ = nuevo_nodo_lista_elements($1, $2); }
    | /* vacío */            { $$ = NULL; }
    ;

elemento:
    instruccion       { $$ = $1; }
    | declaracion_fun { $$ = $1; }
    ;

/* 2. DEFINICIÓN DE FUNCIONES Y PARÁMETROS */
declaracion_fun:
    FUN ID PARI parametros PARD FLECHA tipo LLAVEI bloque_instrucciones LLAVED
    { $$ = nuevo_nodo_declaracion_fun($2, $7, $4, $9); }
    | FUN ID PARI parametros PARD LLAVEI bloque_instrucciones LLAVED
    { $$ = nuevo_nodo_declaracion_fun($2, 0, $4, $7); } /* 0 o vacío si no define retorno */
    ;

parametros:
    lista_parametros { $$ = $1; }
    | /* vacío */    { $$ = NULL; }
    ;

lista_parametros:
    lista_parametros COMA parametro { $$ = nuevo_nodo_lista_parametros($1, $3); }
    | parametro                    { $$ = nuevo_nodo_lista_parametros(NULL, $1); }
    ;

parametro:
    tipo ID { $$ = nuevo_nodo_parametro($1, $2); }
    ;

tipo:
    TIPO_ENTERO   { $$ = TIPO_ENTERO; }
    | TIPO_DECIMAL { $$ = TIPO_DECIMAL; }
    ;

declaracion_var:
    tipo lista_ids { $$ = nuevo_nodo_declaracion_var($1, $2); }
    ;

lista_ids:
    lista_ids COMA declarador { $$ = nuevo_nodo_lista_ids($1, $3->nombre_var); } 
    | declarador              { $$ = nuevo_nodo_lista_ids(NULL, $1->nombre_var); }
    ;

declarador:
    ID                 { $$ = nuevo_nodo_variable($1); }
    | ID ASIG expresion { $$ = nuevo_nodo_asignacion($1, $3); }
    ;

/* 3. BLOQUES DE CÓDIGO E INSTRUCCIONES ATÓMICAS */
bloque_instrucciones:
    bloque_instrucciones instruccion { $$ = nuevo_nodo_lista_elements($1, $2); }
    | /* vacío */                   { $$ = NULL; }
    ;

instruccion:
    declaracion_var PUNTOCOMA                 { $$ = $1; }
    | ID ASIG expresion PUNTOCOMA              { $$ = nuevo_nodo_asignacion($1, $3); }
    | IMPRIMIR PARI lista_impresion PARD PUNTOCOMA { $$ = nuevo_nodo_imprimir($3); }
    | LEER PARI ID PARD PUNTOCOMA              { $$ = nuevo_nodo_leer($3); }
    | RETORNAR expresion PUNTOCOMA             { $$ = nuevo_nodo_retornar($2); }
    | estructura_si                            { $$ = $1; }
    | estructura_mientras                      { $$ = $1; }
    | estructura_para                          { $$ = $1; }
    | estructura_depende                       { $$ = $1; }
    | error PUNTOCOMA { yyerrok; printf("=> [Panic Mode] Error sintáctico ignorado. Analizador recuperado en el ';'.\n"); $$ = NULL; }
    ;

/* 4. ESTRUCTURAS DE CONTROL DE FLUJO */
estructura_si:
    SI PARI expresion PARD LLAVEI bloque_instrucciones LLAVED %prec LOWER_THAN_SINO
    { $$ = nuevo_nodo_si($3, $6, NULL); }
    | SI PARI expresion PARD LLAVEI bloque_instrucciones LLAVED SINO LLAVEI bloque_instrucciones LLAVED
    { $$ = nuevo_nodo_si($3, $6, $10); }
    | SI PARI error PARD LLAVEI bloque_instrucciones LLAVED %prec LOWER_THAN_SINO { yyerrok; printf("=> [Panic Mode] Error en condición del SI. Recuperado en ')'.\n"); $$ = NULL; }
    | SI PARI error PARD LLAVEI bloque_instrucciones LLAVED SINO LLAVEI bloque_instrucciones LLAVED { yyerrok; printf("=> [Panic Mode] Error en condición del SI. Recuperado en ')'.\n"); $$ = NULL; }
    ;

estructura_mientras:
    MIENTRAS PARI expresion PARD LLAVEI bloque_instrucciones LLAVED
    { $$ = nuevo_nodo_mientras($3, $6); }
    | MIENTRAS PARI error PARD LLAVEI bloque_instrucciones LLAVED { yyerrok; printf("=> [Panic Mode] Error en condición del MIENTRAS. Recuperado en ')'.\n"); $$ = NULL; }
    ;

estructura_para:
    PARA PARI tipo ID ASIG expresion PUNTOCOMA expresion PUNTOCOMA ID ASIG expresion PARD LLAVEI bloque_instrucciones LLAVED
    { 
        NodoAST *init = nuevo_nodo_asignacion($4, $6);
        NodoAST *paso = nuevo_nodo_asignacion($10, $12);
        $$ = nuevo_nodo_para(init, $8, paso, $15); 
    }
    | PARA PARI error PARD LLAVEI bloque_instrucciones LLAVED { yyerrok; printf("=> [Panic Mode] Error en encabezado del PARA. Recuperado en ')'.\n"); $$ = NULL; }
    ;

estructura_depende:
    DEPENDE expresion LLAVEI lista_casos LLAVED
    { $$ = nuevo_nodo_depende($2, $4); }
    | DEPENDE error LLAVEI lista_casos LLAVED { yyerrok; printf("=> [Panic Mode] Error en valor del DEPENDE. Recuperado en '{'.\n"); $$ = NULL; }
    ;

lista_casos:
    lista_casos caso { $$ = nuevo_nodo_lista_casos($1, $2); }
    | /* vacío */    { $$ = NULL; }
    ;

caso:
    valor_constante DOS_PUNTOS bloque_instrucciones { $$ = nuevo_nodo_caso($1, $3); }
    | OTROS DOS_PUNTOS bloque_instrucciones         { $$ = nuevo_nodo_caso(NULL, $3); }
    ;

valor_constante:
    NUM_ENTERO    { $$ = nuevo_nodo_entero($1); }
    | NUM_DECIMAL { $$ = nuevo_nodo_decimal($1); }
    | CADENA      { $$ = nuevo_nodo_cadena($1); }
    ;

/* 5. OPERACIONES DE ENTRADA / SALIDA */
lista_impresion:
    lista_impresion COMA elemento_impresion { $$ = nuevo_nodo_lista_argumentos($1, $3); }
    | elemento_impresion                    { $$ = nuevo_nodo_lista_argumentos(NULL, $1); }
    ;

elemento_impresion:
    CADENA      { $$ = nuevo_nodo_cadena($1); }
    | expresion { $$ = $1; }
    ;

/* 6. EXPRESIONES (Matemáticas, Lógicas y Llamadas a Funciones) */
expresion:
    expresion MAS expresion         { $$ = nuevo_nodo_operacion(MAS, $1, $3); }
    | expresion MENOS expresion     { $$ = nuevo_nodo_operacion(MENOS, $1, $3); }
    | expresion MULT expresion      { $$ = nuevo_nodo_operacion(MULT, $1, $3); }
    | expresion DIV expresion       { $$ = nuevo_nodo_operacion(DIV, $1, $3); }
    | expresion MOD expresion       { $$ = nuevo_nodo_operacion(MOD, $1, $3); }
    | expresion MAYOR expresion     { $$ = nuevo_nodo_operacion(MAYOR, $1, $3); }
    | expresion MENOR expresion     { $$ = nuevo_nodo_operacion(MENOR, $1, $3); }
    | expresion MAYOR_IGUAL expresion { $$ = nuevo_nodo_operacion(MAYOR_IGUAL, $1, $3); }
    | expresion MENOR_IGUAL expresion { $$ = nuevo_nodo_operacion(MENOR_IGUAL, $1, $3); }
    | expresion IGUAL expresion     { $$ = nuevo_nodo_operacion(IGUAL, $1, $3); }
    | expresion DIFERENTE expresion { $$ = nuevo_nodo_operacion(DIFERENTE, $1, $3); }
    | PARI expresion PARD           { $$ = $2; }
    | ID                            { $$ = nuevo_nodo_variable($1); }
    | llamada_funcion               { $$ = $1; }
    | NUM_ENTERO                    { $$ = nuevo_nodo_entero($1); }
    | NUM_DECIMAL                   { $$ = nuevo_nodo_decimal($1); }
    ;

llamada_funcion:
    ID PARI argumentos PARD { $$ = nuevo_nodo_llamada_funcion($1, $3); }
    ;

argumentos:
    lista_argumentos { $$ = $1; }
    | /* vacío */    { $$ = NULL; }
    ;

lista_argumentos:
    expresion                      { $$ = nuevo_nodo_lista_argumentos(NULL, $1); }
    | lista_argumentos COMA expresion { $$ = nuevo_nodo_lista_argumentos($1, $3); }
    ;

%%

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