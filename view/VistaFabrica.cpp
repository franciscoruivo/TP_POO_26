#include "VistaFabrica.h"
#include <sstream>
using namespace std;

// Envia os dados da fábrica para o ecrã

int VistaFabrica::linhasEcra(const Fabrica& f) const {
    int linhas = f.getLinhas() + 3;
    if (linhas < alturaPainel) linhas = alturaPainel;
    return linhas;
}

int VistaFabrica::colunasEcra(const Fabrica& f) const {
    return f.getColunas() + 4 + larguraPainel;
}

string VistaFabrica::linhaPainel(const string& rotulo, int valor) const {
    ostringstream out;
    out << rotulo << valor;
    return out.str();
}

void VistaFabrica::desenha(const Fabrica& f, Ecra& ecra) const {
    int nl = f.getLinhas();
    int nc = f.getColunas();
    ecra.limpa(); // começar com um ecrã em branco

    // Fábrica: moldura, régua e terreno
    ecra.moldura(0, 0, nl + 3, nc + 3); // moldura
    for (int c = 0; c < nc; c++) { // régua das colunas
        char letra = 'A' + c;
        ecra.escreve(1, 2 + c, letra);
    }
    for (int l = 0; l < nl; l++) { // régua das linhas
        char letra = 'A' + l;
        ecra.escreve(2 + l, 1, letra);
    }
    for (int l = 0; l < nl; l++) { // faz a grelha dentro das réguas
        for (int c = 0; c < nc; c++) {
            ecra.escreve(2 + l, 2 + c, f.getSimboloPosicao(Coordenada(l, c)));  // máquina ou terreno
        }
    }

    // painel de estado
    int col = nc + 4;
    ecra.moldura(0, col, alturaPainel, larguraPainel);
    ecra.escreve(1, col + 2, linhaPainel("Instante: ", f.getInstante()));
    ecra.escreve(2, col + 2, linhaPainel("Creditos: ", f.getCreditos()));
    ecra.escreve(3, col + 2, linhaPainel("Maquinas: ", f.getNumMaquinas()));
    ecra.escreve(4, col + 2, linhaPainel("Engenheiros: ", f.getNumEngenheiros()));
    ecra.escreve(6, col + 2, "No ultimo instante:");
    for (int i = 0; i < f.getNumEventos(); i++)
        ecra.escreve(7 + i, col + 2, f.getEvento(i));
}