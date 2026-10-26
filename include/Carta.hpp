#ifndef CARTA_HPP
#define CARTA_HPP

#include <string>
#include <map>

class Carta {
public:
    Carta(int numero, const std::string& nome, const std::string& categoria,
          const std::string& significadoGeral);

    void adicionarSignificado(const std::string& tema, const std::string& significado);

    int getNumero() const;
    std::string getNome() const;
    std::string getCategoria() const;
    std::string getSignificadoGeral() const;
    std::string significadoParaTema(const std::string& tema) const;

    bool operator<(const Carta& outra) const;
    bool operator==(const Carta& outra) const;

private:
    int numero;
    std::string nome;
    std::string categoria;
    std::string significadoGeral;
    std::map<std::string, std::string> significadosPorTema;
};

#endif
