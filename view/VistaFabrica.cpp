#include "VistaFabrica.h"
#include <sstream>
using namespace std;

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
    ecra.limpa();

    // fábrica: moldura, régua e terreno
    ecra.moldura(0, 0, nl + 3, nc + 3);
    for (int c = 0; c < nc; c++) {
        char letra = 'A' + c;
        ecra.escreve(1, 2 + c, letra); // régua das colunas
    }
    for (int l = 0; l < nl; l++) {
        char letra = 'A' + l;
        ecra.escreve(2 + l, 1, letra);  // régua das linhas
        for (int c = 0; c < nc; c++) {
            char tipo = f.getPosicao(Coordenada(l, c)).getTipo();
            if (tipo == '.') tipo = ' ';  // solo desenha-se vazio
            ecra.escreve(2 + l, 2 + c, tipo);
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
}