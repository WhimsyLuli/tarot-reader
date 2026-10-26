#ifndef BARALHO_HPP
#define BARALHO_HPP

#include "Carta.hpp"
#include <vector>
#include <string>

class Baralho {
public:
    Baralho();

    const std::vector<Carta>& getCartas() const;
    std::size_t tamanho() const;

private:
    std::vector<Carta> cartas;

    void adicionarCarta(const std::string& nome, const std::string& categoria,
                        const std::string& significadoGeral);
};

#endif
