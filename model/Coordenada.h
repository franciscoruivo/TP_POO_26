#ifndef COORDENADA_H
#define COORDENADA_H
#include <string>

// Linha e coluna de uma posição (a partir de 0).
class Coordenada {
    int linha, coluna;
public:
    Coordenada(int l, int c);
    int getLinha() const { return linha; }
    int getColuna() const { return coluna; }
    std::string obterTexto() const;       // por exemplo, "ce" (linha 2, coluna 4)
};
#endif