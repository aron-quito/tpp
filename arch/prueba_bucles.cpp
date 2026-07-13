#include <iostream>
#include <string>

int main() {
    int cuenta;
    std::cout << "¿Desde que numero quieres iniciar la cuenta regresiva?: ";
    std::cin >> cuenta;
    while ((cuenta > 0)) {
        std::cout << "Segundos restantes: " << cuenta << "\n";
        cuenta = (cuenta - 1);
    }
    std::cout << "¡Tiempo cumplido!\n";
    int tabla;
    std::cout << "¿De que numero deseas ver la tabla de multiplicar?: ";
    std::cin >> tabla;
    for (int i = 1; (i <= 10); i = (i + 1)) {
        int resultado;
        resultado = (tabla * i);
        std::cout << tabla << " x " << i << " = " << resultado << "\n";
    }
    return 0;
}
