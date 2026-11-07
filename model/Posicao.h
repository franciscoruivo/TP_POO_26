#ifndef POSICAO_H
#define POSICAO_H
#include <string>

// Terreno de uma célula: '.' solo, '#' cratera, '%' ferro, '$' silício, '~' gelo
class Posicao {
    char tipo;
    int quantidade;  // só nos depósitos
public:
    Posicao();

    static bool tipoValido(char t);
    static bool tipoDeposito(char t);

    bool setTerreno(char novoTipo, int novaQuantidade = 0);
    char getTipo() const { return tipo; }
    int getQuantidade() const { return quantidade; }
    std::string obterDescricao() const;
};
#endif