#ifndef FABRICA_H
#define FABRICA_H
#include <string>
#include "Coordenada.h"
#include "Posicao.h"
#include "Settings.h"

class Fabrica {
    Posicao grelha[Settings::fabrica_max_linhas][Settings::fabrica_max_colunas];
    int linhas, colunas;
    int creditos, instante;
    int numMaquinas, numEngenheiros; // no CP1 são sempre 0

    void colocaAleatorios(char _tipo, int _quantos);

public:
    Fabrica(); // fábrica vazia (ainda não criada)
    Fabrica(int _linhas, int _colunas); // aleatória (comando fabrica)
    Fabrica(const std::string &_nomeFicheiro); // a partir de mapa (comando carrega)

    static bool dimensoesValidas(int _linhas, int _colunas);

    int getLinhas() const { return linhas; }
    int getColunas() const { return colunas; }
    int getCreditos() const { return creditos; }
    int getInstante() const { return instante; }
    int getNumMaquinas() const { return numMaquinas; }
    int getNumEngenheiros() const { return numEngenheiros; }

    bool coordenadaValida(const Coordenada &_c) const;

    const Posicao &getPosicao(const Coordenada &_c) const; // out_of_range se inválida
};
#endif
