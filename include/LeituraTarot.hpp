#ifndef LEITURATAROT_HPP
#define LEITURATAROT_HPP

#include "Carta.hpp"
#include <string>
#include <vector>

class LeituraTarot {
public:
    LeituraTarot(int numero, const std::string& tema, const std::string& pergunta,
                 const std::vector<Carta>& cartas);

    int getNumero() const;
    std::string getTema() const;
    std::string getPergunta() const;
    const std::vector<Carta>& getCartas() const;

private:
    int numero;
    std::string tema;
    std::string pergunta;
    std::vector<Carta> cartas;
};

#endif
