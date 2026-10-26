#include "Tarot.hpp"

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

const std::list<LeituraTarot>& Tarot::getHistorico() const {
    return historico;
}

bool Tarot::historicoVazio() const {
    return historico.empty();
}
