#ifndef CELULA_H
#define CELULA_H
#include <string>

// Terreno de uma célula: '.' solo, '#' cratera, '%' ferro, '$' silício, '~' gelo
class Celula {
    char tipo;
    int quantidade;  // só nos depósitos
public:
    Celula();

    static bool tipoValido(char t);
    static bool tipoDeposito(char t);

    bool definirTerreno(char novoTipo, int novaQuantidade = 0);
    char getTipo() const { return tipo; }
    int getQuantidade() const { return quantidade; }
    char getMateriaPrima() const;   // 'f', 's' ou 'g' se for depósito, senão ' '
    bool retiraUnidade();           // tira 1 unidade ao depósito; se esgotar passa a solo
    std::string obterDescricao() const;
};
#endif