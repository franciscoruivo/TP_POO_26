#include "Fabrica.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Random.h"
using namespace std;

int quantidadeAleatoria() {
    return Random::getRandom(Settings::deposito_quantidade_min,
                             Settings::deposito_quantidade_max);
}

bool Fabrica::dimensoesValidas(int nl, int nc) {
    int especiais = Settings::fabrica_num_crateras + Settings::fabrica_num_depositos_ferro
                  + Settings::fabrica_num_depositos_silicio + Settings::fabrica_num_depositos_gelo;
    return nl >= 1 && nl <= Settings::fabrica_max_linhas
        && nc >= 1 && nc <= Settings::fabrica_max_colunas
        && nl * nc > especiais;  // porque tem de sobrar solo livre
}

Fabrica::Fabrica()
    : linhas(0), colunas(0), creditos(0), instante(0), numMaquinas(0), numEngenheiros(0) {}

Fabrica::Fabrica(int nl, int nc)
    : linhas(nl), colunas(nc),
      creditos(Settings::fabrica_creditos_iniciais), instante(0),
      numMaquinas(0), numEngenheiros(0) {
    if (!dimensoesValidas(nl, nc)) throw invalid_argument("Dimensoes invalidas");
    colocaAleatorios('#', Settings::fabrica_num_crateras);
    colocaAleatorios('%', Settings::fabrica_num_depositos_ferro);
    colocaAleatorios('$', Settings::fabrica_num_depositos_silicio);
    colocaAleatorios('~', Settings::fabrica_num_depositos_gelo);
}

Fabrica::Fabrica(const string& nomeFicheiro)
    : linhas(0), colunas(0),
      creditos(Settings::fabrica_creditos_iniciais), instante(0),
      numMaquinas(0), numEngenheiros(0) {
    ifstream ficheiro(nomeFicheiro);
    if (!ficheiro.is_open()) throw invalid_argument("Ficheiro inexistente");

    string linha;
    if (!getline(ficheiro, linha)) throw invalid_argument("Ficheiro vazio");

    int nl = 0, nc = 0;
    string sobra;
    istringstream primeira(linha);
    if (!(primeira >> nl >> nc) || (primeira >> sobra))
        throw invalid_argument("Primeira linha invalida (esperado: linhas colunas)");
    if (nl < 1 || nl > Settings::fabrica_max_linhas || nc < 1 || nc > Settings::fabrica_max_colunas)
        throw invalid_argument("Dimensoes do mapa fora dos limites");

    for (int l = 0; l < nl; l++) {
        if (!getline(ficheiro, linha)) throw invalid_argument("Faltam linhas no mapa");
        int tamanho = linha.length();
        if (tamanho != nc) throw invalid_argument("Linha do mapa com tamanho errado");
        for (int c = 0; c < nc; c++) {
            char tipo = linha[c];
            int quantidade = 0;
            if (Posicao::tipoDeposito(tipo)) quantidade = quantidadeAleatoria();
            if (!grelha[l][c].setTerreno(tipo, quantidade))
                throw invalid_argument("Caractere invalido no mapa");
        }
    }

    while (getline(ficheiro, linha)) {  // depois do mapa, só linhas vazias
        if (!linha.empty()) throw invalid_argument("Linhas a mais no mapa");
    }

    linhas = nl;
    colunas = nc;
}

void Fabrica::colocaAleatorios(char tipo, int quantos) {
    int colocados = 0;
    while (colocados < quantos) {
        int l = Random::getRandom(linhas - 1);  // inclui o máximo
        int c = Random::getRandom(colunas - 1);
        if (grelha[l][c].getTipo() == '.') {  // só se ainda for solo
            int quantidade = 0;
            if (Posicao::tipoDeposito(tipo)) quantidade = quantidadeAleatoria();
            grelha[l][c].setTerreno(tipo, quantidade);
            colocados++;
        }
    }
}

bool Fabrica::coordenadaValida(const Coordenada& c) const {
    return c.getLinha() >= 0 && c.getLinha() < linhas
        && c.getColuna() >= 0 && c.getColuna() < colunas;
}

const Posicao& Fabrica::getPosicao(const Coordenada& c) const {
    if (!coordenadaValida(c)) throw out_of_range("Posicao fora da fabrica");
    return grelha[c.getLinha()][c.getColuna()];
}

string Fabrica::obterDescricaoTerreno(const Coordenada& centro, int raio) const {
    ostringstream out;
    int maximo = linhas;
    if (colunas > maximo) maximo = colunas;
    if (raio < 0) raio = 0;
    if (raio > maximo) raio = maximo; // mais do que isto, já "apanha" tudo

    for (int l = centro.getLinha() - raio; l <= centro.getLinha() + raio; l++) {
        for (int c = centro.getColuna() - raio; c <= centro.getColuna() + raio; c++) {
            Coordenada atual(l, c);
            if (coordenadaValida(atual))  // o que sai da fábrica é cortado
                out << atual.obterTexto() << ": " << getPosicao(atual).obterDescricao() << "\n";
        }
    }
    return out.str();
}