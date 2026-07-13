#include <iostream>
#include <string>

int calcular(int a, int b, int op) {
    switch (op) {
        case 1:
            return (a + b);
            break;
        case 2:
            return (a - b);
            break;
        case 3:
            return (a * b);
            break;
        case 4:
            return (a / b);
            break;
        default:
            std::cout << "Operacion no valida\n";
            return 0;
            break;
    }
}

int main() {
    int res, op, num2, num1;
    std::cout << "Introduce numero 1: ";
    std::cin >> num1;
    std::cout << "Introduce numero 2: ";
    std::cin >> num2;
    std::cout << "Que operacion deseas hacer:\n1. +\n2. -\n3. *\n4. /\n";
    std::cin >> op;
    res = calcular(num1, num2, op);
    std::cout << "El resultado es: " << res;
    return 0;
}
