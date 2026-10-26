#include "Baralho.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    Baralho baralho;
    std::vector<Carta> tiragem = baralho.sortear3();

    std::cout << "Sorteio de 3 cartas\n";
    const char* posicoes[3] = { "Passado", "Presente", "Futuro" };
    for (int i = 0; i < 3; ++i) {
        std::cout << posicoes[i] << ": " << tiragem[i].getNome() << "\n";
    }

    return 0;
}
