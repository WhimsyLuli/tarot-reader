#include "LeituraTarot.hpp"

LeituraTarot::LeituraTarot(int numero, const std::string& tema, const std::string& pergunta,
                           const std::vector<Carta>& cartas)
    : numero(numero), tema(tema), pergunta(pergunta), cartas(cartas) {}

int LeituraTarot::getNumero() const {
    return numero;
}

std::string LeituraTarot::getTema() const {
    return tema;
}

std::string LeituraTarot::getPergunta() const {
    return pergunta;
}

const std::vector<Carta>& LeituraTarot::getCartas() const {
    return cartas;
}
