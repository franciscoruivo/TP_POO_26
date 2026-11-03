#ifndef ECRA_H
#define ECRA_H
#include <string>
#include "Settings.h"

class Ecra {
    char buffer[Settings::ecra_max_linhas][Settings::ecra_max_colunas];
    int linhas, colunas; // dimensão realmente usada
    int linhaCursor, colunaCursor;

public:
    Ecra(int _l, int _c);

    void limpa();

    void posiciona(int _l, int _c);

    void escreve(char _ch); // escreve no cursor
    void escreve(const std::string &_s); // escreve no cursor
    void escreve(int _l, int _c, char _ch);

    void escreve(int _l, int _c, const std::string &_s);

    void moldura(int _l, int _c, int _altura, int _largura);

    void mostra() const;
};
#endif
