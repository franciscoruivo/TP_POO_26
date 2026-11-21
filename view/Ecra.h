#ifndef ECRA_H
#define ECRA_H
#include <string>
#include "Settings.h"

class Ecra {
    char buffer[Settings::ecra_max_linhas][Settings::ecra_max_colunas];
    int linhas, colunas; // tamanho que realmente usa
    int linhaCursor, colunaCursor;
public:
    Ecra(int nl, int nc);
    void limpa();
    void posiciona(int l, int c);
    void escreve(char ch);
    void escreve(const std::string& s);
    void escreve(int l, int c, char ch);
    void escreve(int l, int c, const std::string& s);
    void moldura(int l, int c, int altura, int largura);
    void mostra() const;
};
#endif