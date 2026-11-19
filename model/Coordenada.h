#ifndef COORDENADA_H
#define COORDENADA_H
#include <string>

// Linha e coluna de uma posição (a partir de 0).
class Coordenada {
    int linha, coluna;
public:
    Coordenada(int l = 0, int c = 0);
    int getLinha() const;
    int getColuna() const;
    std::string obterTexto() const;       // por exemplo, "ce" (linha 2, coluna 4)

    // converte texto como "ce" em coordenada; devolve false se não for duas letras minúsculas
    static bool converte(const std::string& texto, Coordenada& resultado);
};
#endif
