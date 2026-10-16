// VistaFabrica.cpp
#include "VistaFabrica.h"
#include <string>
using namespace std;

void VistaFabrica::desenha(const Fabrica& f, Ecra& ecra) const {
    int nl = f.getLinhas(), nc = f.getColunas();
    ecra.limpa();

    ecra.moldura(0, 0, nl + 3, nc + 3);
    for (int c = 0; c < nc; c++)
        ecra.escreve(1, 2 + c, (char)('A' + c));           // régua das colunas
    for (int l = 0; l < nl; l++) {
        ecra.escreve(2 + l, 1, (char)('A' + l));           // régua das linhas
        for (int c = 0; c < nc; c++) {
            char t = f.getPosicao(l, c).getTipo();
            if (t == '.') t = ' ';                          // solo desenha-se vazio
            ecra.escreve(2 + l, 2 + c, t);
        }
    }

    int col = nc + 4;                                       // painel de estado
    ecra.moldura(0, col, 8, 34);
    ecra.escreve(1, col + 2, "Instante: " + to_string(f.getInstante()));
    ecra.escreve(2, col + 2, "Creditos: " + to_string(f.getCreditos()));
    ecra.escreve(3, col + 2, "Maquinas: 0");
    ecra.escreve(4, col + 2, "Engenheiros: 0");
    ecra.escreve(6, col + 2, "No ultimo instante:");
}