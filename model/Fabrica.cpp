#include "Fabrica.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Random.h"
using namespace std;

static int quantidadeAleatoria() {
    return Random::getRandom(Settings::deposito_quantidade_min,
                             Settings::deposito_quantidade_max);
}

static void retiraCR(string &_linha) {
    // mapas criados no Windows
    if (!_linha.empty() && _linha.back() == '\r') _linha.pop_back();
}

bool Fabrica::dimensoesValidas(int _linhas, int _colunas) {
    int especiais = Settings::fabrica_num_crateras + Settings::fabrica_num_depositos_ferro
                    + Settings::fabrica_num_depositos_silicio + Settings::fabrica_num_depositos_gelo;
    return _linhas >= 1 && _linhas <= Settings::fabrica_max_linhas
           && _colunas >= 1 && _colunas <= Settings::fabrica_max_colunas
           && _linhas * _colunas > especiais; // tem de sobrar solo livre
}

Fabrica::Fabrica(int _linhas, int _colunas)
    : linhas(dimensoesValidas(_linhas, _colunas) ? _linhas : throw invalid_argument("Dimensoes invalidas")),
      colunas(_colunas),
      creditos(Settings::fabrica_creditos_iniciais), instante(0),
      numMaquinas(0), numEngenheiros(0) {
    colocaAleatorios('#', Settings::fabrica_num_crateras);
    colocaAleatorios('%', Settings::fabrica_num_depositos_ferro);
    colocaAleatorios('$', Settings::fabrica_num_depositos_silicio);
    colocaAleatorios('~', Settings::fabrica_num_depositos_gelo);
}

Fabrica::Fabrica(const string &_nomeFicheiro)
    : linhas(0), colunas(0),
      creditos(Settings::fabrica_creditos_iniciais), instante(0),
      numMaquinas(0), numEngenheiros(0) {
    ifstream ficheiro(_nomeFicheiro);
    if (!ficheiro.is_open()) throw invalid_argument("Ficheiro inexistente");

    string linha;
    if (!getline(ficheiro, linha)) throw invalid_argument("Ficheiro vazio");
    retiraCR(linha);

    int nl = 0, nc = 0;
    string sobra;
    istringstream primeira(linha);
    if (!(primeira >> nl >> nc) || (primeira >> sobra))
        throw invalid_argument("Primeira linha invalida (esperado: linhas colunas)");
    if (nl < 1 || nl > Settings::fabrica_max_linhas || nc < 1 || nc > Settings::fabrica_max_colunas)
        throw invalid_argument("Dimensoes do mapa fora dos limites");

    for (int l = 0; l < nl; l++) {
        if (!getline(ficheiro, linha)) throw invalid_argument("Faltam linhas no mapa");
        retiraCR(linha);
        if (static_cast<int>(linha.length()) != nc) throw invalid_argument("Linha do mapa com tamanho errado");
        for (int c = 0; c < nc; c++) {
            char tipo = linha[c];
            int quantidade = Posicao::tipoDeposito(tipo) ? quantidadeAleatoria() : 0;
            if (!grelha[l][c].setTerreno(tipo, quantidade))
                throw invalid_argument("Caractere invalido no mapa");
        }
    }

    while (getline(ficheiro, linha)) {
        // depois do mapa só linhas vazias
        retiraCR(linha);
        if (!linha.empty()) throw invalid_argument("Linhas a mais no mapa");
    }

    linhas = nl;
    colunas = nc;
}

void Fabrica::colocaAleatorios(char _tipo, int _quantos) {
    int colocados = 0;
    while (colocados < _quantos) {
        int l = Random::getRandom(linhas - 1); // inclui o máximo
        int c = Random::getRandom(colunas - 1);
        if (grelha[l][c].getTipo() == '.') {
            // só em posições ainda vazias
            grelha[l][c].setTerreno(_tipo, Posicao::tipoDeposito(_tipo) ? quantidadeAleatoria() : 0);
            colocados++;
        }
    }
}

bool Fabrica::coordenadaValida(const Coordenada &_c) const {
    return _c.getLinha() >= 0 && _c.getLinha() < linhas
           && _c.getColuna() >= 0 && _c.getColuna() < colunas;
}

const Posicao &Fabrica::getPosicao(const Coordenada &_c) const {
    if (!coordenadaValida(_c)) throw out_of_range("Posicao fora da fabrica");
    return grelha[_c.getLinha()][_c.getColuna()];
}
