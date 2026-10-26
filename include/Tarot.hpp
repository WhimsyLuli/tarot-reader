#ifndef TAROT_HPP
#define TAROT_HPP

#include "Baralho.hpp"
#include "LeituraTarot.hpp"
#include <list>
#include <string>

class Tarot {
public:
    Tarot();

    bool criarLeitura(int tema, const std::string& pergunta);
    const std::list<LeituraTarot>& getHistorico() const;
    bool historicoVazio() const;

private:
    Baralho baralho;
    std::list<LeituraTarot> historico;
    int proximoNumero;
};

#endif
