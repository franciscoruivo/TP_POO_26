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
    int numMaquinas, numEngenheiros;

    void colocaAleatorios(char tipo, int quantos);
public:
    Fabrica();  // vazia (ainda não criada)
    Fabrica(int nl, int nc); // aleatória
    Fabrica(const std::string& nomeFicheiro);  // a partir de um mapa

    static bool dimensoesValidas(int nl, int nc);

    int getLinhas() const { return linhas; }
    int getColunas() const { return colunas; }
    int getCreditos() const { return creditos; }
    int getInstante() const { return instante; }
    int getNumMaquinas() const { return numMaquinas; }
    int getNumEngenheiros() const { return numEngenheiros; }

    bool coordenadaValida(const Coordenada& c) const;
    const Posicao& getPosicao(const Coordenada& c) const;   // "out_of_range" se inválida

    // descrição do terreno do centro e das posições à volta
    std::string obterDescricaoTerreno(const Coordenada& centro, int raio) const;
};
#endif