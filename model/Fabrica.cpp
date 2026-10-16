// Fabrica.cpp
#include "Fabrica.h"
#include <cstdlib>

Fabrica::Fabrica(int l, int c)
    : linhas(l), colunas(c), creditos(Settings::fabrica_creditos_iniciais), instante(0) {
    colocaAleatorios('#', Settings::fabrica_num_crateras);
    colocaAleatorios('%', Settings::fabrica_num_depositos_ferro);
    colocaAleatorios('$', Settings::fabrica_num_depositos_silicio);
    colocaAleatorios('~', Settings::fabrica_num_depositos_gelo);
}

bool Fabrica::dimensoesValidas(int l, int c) {
    int especiais = Settings::fabrica_num_crateras + Settings::fabrica_num_depositos_ferro
                  + Settings::fabrica_num_depositos_silicio + Settings::fabrica_num_depositos_gelo;
    return l >= 1 && l <= Settings::fabrica_max_linhas
        && c >= 1 && c <= Settings::fabrica_max_colunas
        && l * c > especiais;                    // tem de sobrar solo livre
}

void Fabrica::colocaAleatorios(char tipo, int quantos) {
    int colocados = 0;
    while (colocados < quantos) {
        int l = rand() % linhas;
        int c = rand() % colunas;
        if (grelha[l][c].getTipo() == '.') {     // só em posições ainda vazias
            int q = 0;
            if (tipo != '#')
                q = Settings::deposito_quantidade_min
                  + rand() % (Settings::deposito_quantidade_max - Settings::deposito_quantidade_min + 1);
            grelha[l][c].setTerreno(tipo, q);
            colocados++;
        }
    }
}