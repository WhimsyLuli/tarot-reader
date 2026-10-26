#include "Baralho.hpp"

Baralho::Baralho() {
    adicionarCarta("O Louco", "Arcano Maior", "");
    adicionarCarta("O Mago", "Arcano Maior", "");
    adicionarCarta("A Sacerdotisa", "Arcano Maior", "");
    adicionarCarta("A Imperatriz", "Arcano Maior", "");
    adicionarCarta("O Imperador", "Arcano Maior", "");
    adicionarCarta("O Hierofante", "Arcano Maior", "");
    adicionarCarta("Os Enamorados", "Arcano Maior", "");
    adicionarCarta("O Carro", "Arcano Maior", "");
    adicionarCarta("A Forca", "Arcano Maior", "");
    adicionarCarta("O Eremita", "Arcano Maior", "");
    adicionarCarta("A Roda da Fortuna", "Arcano Maior", "");
    adicionarCarta("A Justica", "Arcano Maior", "");
    adicionarCarta("O Enforcado", "Arcano Maior", "");
    adicionarCarta("A Morte", "Arcano Maior", "");
    adicionarCarta("A Temperanca", "Arcano Maior", "");
    adicionarCarta("O Diabo", "Arcano Maior", "");
    adicionarCarta("A Torre", "Arcano Maior", "");
    adicionarCarta("A Estrela", "Arcano Maior", "");
    adicionarCarta("A Lua", "Arcano Maior", "");
    adicionarCarta("O Sol", "Arcano Maior", "");
    adicionarCarta("O Julgamento", "Arcano Maior", "");
    adicionarCarta("O Mundo", "Arcano Maior", "");
}

const std::vector<Carta>& Baralho::getCartas() const {
    return cartas;
}

std::size_t Baralho::tamanho() const {
    return cartas.size();
}

void Baralho::adicionarCarta(const std::string& nome, const std::string& categoria,
                             const std::string& significadoGeral) {
    cartas.push_back(Carta(nome, categoria, significadoGeral));
}
