#include "Tarot.hpp"

#include <algorithm>
#include <vector>

Tarot::Tarot() : proximoNumero(1) {}

bool Tarot::criarLeitura(int tema, const std::string& pergunta) {
    if (tema < 1 || tema > 3) {
        return false;
    }
    if (pergunta.empty()) {
        return false;
    }

    std::string nomeTema;
    if (tema == 1) {
        nomeTema = "amor";
    } else if (tema == 2) {
        nomeTema = "carreira";
    } else {
        nomeTema = "familia";
    }

    std::vector<Carta> tiragem = baralho.sortear3();
    LeituraTarot leitura(proximoNumero, nomeTema, pergunta, tiragem);
    historico.push_back(leitura);
    proximoNumero++;
    return true;
}

const Carta* Tarot::buscarCarta(const std::string& nome) const {
    const std::vector<Carta>& cartas = baralho.getCartas();
    std::vector<Carta>::const_iterator it = std::find(cartas.begin(), cartas.end(), Carta(0, nome, "", ""));
    if (it == cartas.end()) {
        return 0;
    }
    return &(*it);
}

std::vector<Carta> Tarot::baralhoOrdenado() const {
    std::vector<Carta> copia = baralho.getCartas();
    std::sort(copia.begin(), copia.end());
    return copia;
}

const std::list<LeituraTarot>& Tarot::getHistorico() const {
    return historico;
}

bool Tarot::historicoVazio() const {
    return historico.empty();
}
