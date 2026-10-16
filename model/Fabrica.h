// Fabrica.h
#ifndef FABRICA_H
#define FABRICA_H
#include "Posicao.h"
#include "Settings.h"

class Fabrica {
    Posicao grelha[Settings::fabrica_max_linhas][Settings::fabrica_max_colunas];
    int linhas, colunas;
    int creditos, instante;

    void colocaAleatorios(char tipo, int quantos);
public:
    Fabrica(int l, int c);                       // gera crateras e depósitos aleatórios
    static bool dimensoesValidas(int l, int c);

    int getLinhas() const { return linhas; }
    int getColunas() const { return colunas; }
    int getCreditos() const { return creditos; }
    int getInstante() const { return instante; }
    const Posicao& getPosicao(int l, int c) const { return grelha[l][c]; }
};
#endif