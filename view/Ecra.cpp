#include "Ecra.h"
#include <iostream>
using namespace std;

Ecra::Ecra(int _l, int _c) : linhas(_l), colunas(_c), linhaCursor(0), colunaCursor(0) {
    if (linhas < 0) linhas = 0;
    if (colunas < 0) colunas = 0;
    if (linhas > Settings::ecra_max_linhas) linhas = Settings::ecra_max_linhas;
    if (colunas > Settings::ecra_max_colunas) colunas = Settings::ecra_max_colunas;
    limpa();
}

void Ecra::limpa() {
    for (int l = 0; l < linhas; l++)
        for (int c = 0; c < colunas; c++)
            buffer[l][c] = ' ';
    linhaCursor = 0;
    colunaCursor = 0;
}

void Ecra::posiciona(int _l, int _c) {
    linhaCursor = _l;
    colunaCursor = _c;
}

void Ecra::escreve(char _ch) {
    if (_ch == '\n' || _ch == '\r') return; // não entram no buffer
    if (linhaCursor >= 0 && linhaCursor < linhas && colunaCursor >= 0 && colunaCursor < colunas)
        buffer[linhaCursor][colunaCursor] = _ch; // fora dos limites: ignora
    colunaCursor++;
}

void Ecra::escreve(const string &_s) {
    for (size_t i = 0; i < _s.length(); i++)
        escreve(_s[i]);
}

void Ecra::escreve(int _l, int _c, char _ch) {
    posiciona(_l, _c);
    escreve(_ch);
}

void Ecra::escreve(int _l, int _c, const string &_s) {
    posiciona(_l, _c);
    escreve(_s);
}

void Ecra::moldura(int _l, int _c, int _altura, int _largura) {
    if (_altura < 1 || _largura < 1) return; // moldura impossível
    for (int j = 0; j < _largura; j++) {
        escreve(_l, _c + j, '-');
        escreve(_l + _altura - 1, _c + j, '-');
    }
    for (int i = 0; i < _altura; i++) {
        escreve(_l + i, _c, '|');
        escreve(_l + i, _c + _largura - 1, '|');
    }
    escreve(_l, _c, '+');
    escreve(_l, _c + _largura - 1, '+');
    escreve(_l + _altura - 1, _c, '+');
    escreve(_l + _altura - 1, _c + _largura - 1, '+');
}

void Ecra::mostra() const {
    for (int l = 0; l < linhas; l++) {
        for (int c = 0; c < colunas; c++)
            cout << buffer[l][c];
        cout << '\n';
    }
}
