#ifndef POSICAO_H
#define POSICAO_H
#include <string>

// Terreno de uma célula: '.' solo, '#' cratera, '%' ferro, '$' silício, '~' gelo
class Posicao {
    char tipo;
    int quantidade; // só nos depósitos
public:
    Posicao();

    static bool tipoValido(char _tipo);

    static bool tipoDeposito(char _tipo);

    bool setTerreno(char _tipo, int _quantidade = 0);

    char getTipo() const { return tipo; }
    int getQuantidade() const { return quantidade; }

    std::string obterDescricao() const;
};
#endif
