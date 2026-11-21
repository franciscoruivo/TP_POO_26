#ifndef COORDENADA_H
#define COORDENADA_H
#include <string>

// Linha e coluna de uma posição (começam emm 0)
class Coordenada {
    int linha, coluna;
public:
    Coordenada(int l = 0, int c = 0);
    int getLinha() const;
    int getColuna() const;
    std::string obterTexto() const;       // ex: "ce" (linha 2, coluna 4)

    // conversão de texto como "ce" para coordenada; false -> se não for duas letras minúsculas
    static bool converte(const std::string& texto, Coordenada& resultado);
};
#endif
