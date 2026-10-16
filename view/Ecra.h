// Ecra.h
#ifndef ECRA_H
#define ECRA_H
#include <string>
#include "Settings.h"

class Ecra {
    char buffer[Settings::ecra_max_linhas][Settings::ecra_max_colunas];
    int linhas, colunas;                    // dimensão realmente usada
    int linhaCursor, colunaCursor;
public:
    Ecra(int l, int c);
    void limpa();
    void posiciona(int l, int c);
    void escreve(char ch);                  // escreve no cursor
    void escreve(const std::string& s);     // escreve no cursor
    void escreve(int l, int c, char ch);
    void escreve(int l, int c, const std::string& s);
    void moldura(int l, int c, int altura, int largura);
    void mostra() const;
};
#endif