#include "Tarot.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    Tarot tarot;

    while (true) {
        std::cout << "\nTarot - leitura de tarot\n";
        std::cout << "1. Fazer leitura\n";
        std::cout << "2. Ver historico\n";
        std::cout << "0. Sair\n";
        std::cout << "Opcao: ";

        int opcao;
        if (!(std::cin >> opcao)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Opcao invalida.\n";
            continue;
        }
        std::cin.ignore(10000, '\n');

        if (opcao == 0) {
            std::cout << "Ate logo!\n";
            break;
        } else if (opcao == 1) {
            std::cout << "Tema (1-amor 2-carreira 3-familia): ";
            int tema;
            if (!(std::cin >> tema)) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Tema invalido.\n";
                continue;
            }
            std::cin.ignore(10000, '\n');

            std::string pergunta;
            std::cout << "Pergunta: ";
            std::getline(std::cin, pergunta);

            if (!tarot.criarLeitura(tema, pergunta)) {
                if (tema < 1 || tema > 3) {
                    std::cout << "Tema invalido.\n";
                } else {
                    std::cout << "Pergunta vazia. Tente novamente.\n";
                }
                continue;
            }

            const LeituraTarot& ultima = tarot.getHistorico().back();
            const std::vector<Carta>& cartas = ultima.getCartas();
            const char* posicoes[3] = { "Passado", "Presente", "Futuro" };
            for (int i = 0; i < 3; ++i) {
                std::cout << posicoes[i] << ": " << cartas[i].getNome()
                          << " - " << cartas[i].significadoParaTema(ultima.getTema()) << "\n";
            }
        } else if (opcao == 2) {
            if (tarot.historicoVazio()) {
                std::cout << "Nenhuma leitura feita ainda.\n";
                continue;
            }
            for (std::list<LeituraTarot>::const_iterator it = tarot.getHistorico().begin();
                 it != tarot.getHistorico().end(); ++it) {
                std::cout << "[Leitura " << it->getNumero() << "] "
                          << it->getTema() << " - \"" << it->getPergunta() << "\"\n";
                const std::vector<Carta>& cs = it->getCartas();
                std::cout << "  Passado: " << cs[0].getNome()
                          << " | Presente: " << cs[1].getNome()
                          << " | Futuro: " << cs[2].getNome() << "\n";
            }
        } else {
            std::cout << "Opcao invalida.\n";
        }
    }

    return 0;
}
