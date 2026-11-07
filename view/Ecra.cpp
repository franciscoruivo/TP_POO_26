#include "Ecra.h"
#include <iostream>
using namespace std;

Ecra::Ecra(int nl, int nc) : linhas(nl), colunas(nc), linhaCursor(0), colunaCursor(0) {
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

void Ecra::posiciona(int l, int c) {
    linhaCursor = l;
    colunaCursor = c;
}

void Ecra::escreve(char ch) {
    if (ch == '\n' || ch == '\r') return;  // não entram no buffer
    if (linhaCursor >= 0 && linhaCursor < linhas && colunaCursor >= 0 && colunaCursor < colunas)
        buffer[linhaCursor][colunaCursor] = ch; // fora dos limites: ignora
    colunaCursor++;
}

void Ecra::escreve(const string& s) {
    for (size_t i = 0; i < s.length(); i++)
        escreve(s[i]);
}

void Ecra::escreve(int l, int c, char ch) {
    posiciona(l, c);
    escreve(ch);
}

void Ecra::escreve(int l, int c, const string& s) {
    posiciona(l, c);
    escreve(s);
}

void Ecra::moldura(int l, int c, int altura, int largura) {
    if (altura < 1 || largura < 1) return;               // moldura impossível
    for (int j = 0; j < largura; j++) {
        escreve(l, c + j, '-');
        escreve(l + altura - 1, c + j, '-');
    }
    for (int i = 0; i < altura; i++) {
        escreve(l + i, c, '|');
        escreve(l + i, c + largura - 1, '|');
    }
    escreve(l, c, '+');
    escreve(l, c + largura - 1, '+');
    escreve(l + altura - 1, c, '+');
    escreve(l + altura - 1, c + largura - 1, '+');
}

void Ecra::mostra() const {
    for (int l = 0; l < linhas; l++) {
        for (int c = 0; c < colunas; c++)
            cout << buffer[l][c];
        cout << '\n';
    }
}