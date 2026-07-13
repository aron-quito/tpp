#include <iostream>
#include <string>

void sexito(int veces, int meses) {
    int total;
    total = (veces * meses);
    std::cout << "sexitos totales: " << total;
}

int main() {
    int meses, veces;
    std::cin >> veces;
    std::cin >> meses;
    sexito(veces, meses);
    return 0;
}
