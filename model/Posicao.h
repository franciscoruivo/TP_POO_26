// Posicao.h
#ifndef POSICAO_H
#define POSICAO_H

class Posicao {
    char tipo;
    int quantidade;      // só faz sentido nos depósitos
public:
    Posicao() : tipo('.'), quantidade(0) {}
    void setTerreno(char t, int q = 0) { tipo = t; quantidade = q; }
    char getTipo() const { return tipo; }
    int getQuantidade() const { return quantidade; }
};
#endif