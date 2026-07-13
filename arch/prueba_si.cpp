#include <iostream>
#include <string>

int main() {
    double nota1;
    double nota2;
    double promedio;
    std::cout << "Ingrese la primera nota: ";
    std::cin >> nota1;
    std::cout << "Ingrese la segunda nota: ";
    std::cin >> nota2;
    promedio = ((nota1 + nota2) / 2.000000);
    if ((promedio >= 10.500000)) {
        std::cout << "¡Felicidades! Has aprobado con: " << promedio;
    }
    else {
        std::cout << "Lo siento, has desaprobado con: " << promedio;
    }
    return 0;
}
