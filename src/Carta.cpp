#include "Carta.hpp"

Carta::Carta(int numero, const std::string& nome, const std::string& categoria,
             const std::string& significadoGeral)
    : numero(numero), nome(nome), categoria(categoria), significadoGeral(significadoGeral) {}

void Carta::adicionarSignificado(const std::string& tema, const std::string& significado) {
    significadosPorTema[tema] = significado;
}

int Carta::getNumero() const {
    return numero;
}

std::string Carta::getNome() const {
    return nome;
}

std::string Carta::getCategoria() const {
    return categoria;
}

std::string Carta::getSignificadoGeral() const {
    return significadoGeral;
}

std::string Carta::significadoParaTema(const std::string& tema) const {
    std::map<std::string, std::string>::const_iterator it = significadosPorTema.find(tema);
    if (it == significadosPorTema.end()) {
        return "";
    }
    return it->second;
}

bool Carta::operator<(const Carta& outra) const {
    return numero < outra.numero;
}

bool Carta::operator==(const Carta& outra) const {
    return nome == outra.nome;
}
