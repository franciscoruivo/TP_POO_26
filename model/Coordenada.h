#ifndef COORDENADA_H
#define COORDENADA_H

// Um endereço na grelha (linha e coluna, a partir de 0).
// Não valida limites: quem sabe o tamanho da fábrica é a Fabrica.
class Coordenada {
    int linha, coluna;

public:
    Coordenada(int _linha, int _coluna);

    int getLinha() const { return linha; }
    int getColuna() const { return coluna; }
};
#endif
