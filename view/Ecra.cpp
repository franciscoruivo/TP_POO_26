// Ecra.cpp
#include "Ecra.h"
#include <iostream>
using namespace std;

Ecra::Ecra(int l, int c) : linhas(l), colunas(c), linhaCursor(0), colunaCursor(0) {
    if (linhas > Settings::ecra_max_linhas) linhas = Settings::ecra_max_linhas;
    if (colunas > Settings::ecra_max_colunas) colunas = Settings::ecra_max_colunas;
    limpa();
}

void Ecra::limpa() {
    for (int l = 0; l < linhas; l++)
        for (int c = 0; c < colunas; c++)
            buffer[l][c] = ' ';
    linhaCursor = colunaCursor = 0;
}

void Ecra::posiciona(int l, int c) { linhaCursor = l; colunaCursor = c; }

void Ecra::escreve(char ch) {
    if (linhaCursor >= 0 && linhaCursor < linhas && colunaCursor >= 0 && colunaCursor < colunas)
        buffer[linhaCursor][colunaCursor] = ch;   // fora dos limites: ignora
    colunaCursor++;
}

void Ecra::escreve(const string& s) {
    for (char ch : s) escreve(ch);
}

void Ecra::escreve(int l, int c, char ch) { posiciona(l, c); escreve(ch); }
void Ecra::escreve(int l, int c, const string& s) { posiciona(l, c); escreve(s); }

void Ecra::moldura(int l, int c, int altura, int largura) {
    for (int j = 0; j < largura; j++) {
        escreve(l, c + j, '-');
        escreve(l + altura - 1, c + j, '-');
    }
    for (int i = 0; i < altura; i++) {
        escreve(l + i, c, '|');
        escreve(l + i, c + largura - 1, '|');
    }
    escreve(l, c, '+');                          escreve(l, c + largura - 1, '+');
    escreve(l + altura - 1, c, '+');             escreve(l + altura - 1, c + largura - 1, '+');
}

void Ecra::mostra() const {
    for (int l = 0; l < linhas; l++) {
        for (int c = 0; c < colunas; c++) cout << buffer[l][c];
        cout << '\n';
    }
}