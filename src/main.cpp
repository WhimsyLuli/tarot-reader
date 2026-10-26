#include "Baralho.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    Baralho baralho;

    std::vector<Carta> cartas = baralho.getCartas();
    std::sort(cartas.begin(), cartas.end());

    std::cout << "Baralho de tarot - " << cartas.size() << " cartas\n";
    for (std::size_t i = 0; i < cartas.size(); ++i) {
        std::cout << i + 1 << ". " << cartas[i].getNome() << "\n";
    }

    return 0;
}
