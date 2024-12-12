#include <iostream>
#include <vector>
#include <tuple>
#include <functional>
#include <iomanip>
#include <map>

int main() {
    const int A1 = 2023;
    const int A2 = 2024;
    const int A3 = 2025;
    const int MODULO = 10000;

    std::vector<int> secuencia = { A1 % MODULO, A2 % MODULO, A3 % MODULO };

    
    std::map<std::tuple<int, int, int>, int> mapa;

    mapa[{secuencia[0], secuencia[1], secuencia[2]}] = 3;

    int comienzo = 0;
    int duracion = 0;

    while (true) {
        int proximo = (secuencia[secuencia.size() - 1] + secuencia[secuencia.size() - 2] + secuencia[secuencia.size() - 3]) % MODULO;
        secuencia.push_back(proximo);

        std::tuple<int, int, int> estadoActual = { secuencia[secuencia.size() - 3], secuencia[secuencia.size() - 2], secuencia[secuencia.size() - 1] };

        if (mapa.find(estadoActual) != mapa.end()) {
            comienzo = mapa[estadoActual];
            duracion = secuencia.size() - comienzo;
            break;
        }

        mapa[estadoActual] = secuencia.size();
    }
    long long objetivo = 2023202320232023;
    int ri = (objetivo - 1) % duracion + comienzo;
    int resultado = secuencia[ri - 1];
    std::cout << "chan chan chan (música de suspenso\n";
    system("pause");
    std::cout << "Los ultimos 4 digitos son: " << std::setfill('0') << std::setw(4) << resultado << "\n";

    return 0;
}