# Ejemplos de Código TPP

Este documento contiene los ejemplos de prueba para el lexer/parser.

## Ejemplo 1: Calculadora

```text
// Definición clara con llaves y retorno de valor explícito
fun calcular(entero a, entero b, entero op) -> entero {
    depende op {
        1: retornar a + b;
        2: retornar a - b;
        3: retornar a * b;
        4: retornar a / b;
        otros: 
            imprimir("Operacion no valida\n");
            retornar 0; 
    }
}

// Declaración de variables en una sola línea (opcional pero útil)
entero num1, num2, op, res;

imprimir("Introduce numero 1: ");
leer(num1);

imprimir("Introduce numero 2: ");
leer(num2);

// Cadena multilínea para simplificar el I/O
imprimir("Que operacion deseas hacer:\n1. +\n2. -\n3. *\n4. /\n");
leer(op);

// La llamada a la función es una expresión que se asigna, mucho más intuitivo
res = calcular(num1, num2, op);

// Imprimir el resultado de forma limpia
imprimir("El resultado es: ", res);
```

## Ejemplo 2: Promedio y Condicionales

```text
// Definición de variables con los tipos de tu lexer
decimal nota1;
decimal nota2;
decimal promedio;

imprimir("Ingrese la primera nota: ");
leer(nota1);
imprimir("Ingrese la segunda nota: ");
leer(nota2);

promedio = (nota1 + nota2) / 2.0;

// Uso de SI y SINO
si (promedio >= 10.5) {
    imprimir("¡Felicidades! Has aprobado con: ", promedio);
} sino {
    imprimir("Lo siento, has desaprobado con: ", promedio);
}
```

## Ejemplo 3: Ciclo MIENTRAS

```text
entero cuenta;

imprimir("¿Desde qué número quieres iniciar la cuenta regresiva?: ");
leer(cuenta);

// Uso de MIENTRAS
mientras (cuenta > 0) {
    imprimir("Segundos restantes: ", cuenta, "\n");
    cuenta = cuenta - 1; // Decremento de la variable entero
}

imprimir("¡Tiempo cumplido!");
```

## Ejemplo 4: Ciclo PARA

```text
entero tabla;

imprimir("¿De qué número deseas ver la tabla de multiplicar?: ");
leer(tabla);

imprimir("Tabla del ", tabla, ":\n");

// Uso de PARA con inicialización, condición y paso
para (entero i = 1; i <= 10; i = i + 1) {
    entero resultado;
    resultado = tabla * i;
    imprimir(tabla, " x ", i, " = ", resultado, "\n");
}
```