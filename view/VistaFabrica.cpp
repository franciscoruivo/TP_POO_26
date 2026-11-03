#include "VistaFabrica.h"
#include <sstream>
using namespace std;

int VistaFabrica::linhasEcra(const Fabrica &_f) const {
    int linhas = _f.getLinhas() + 3; // moldura + régua + moldura
    if (linhas < ALTURA_PAINEL) linhas = ALTURA_PAINEL;
    return linhas;
}

int VistaFabrica::colunasEcra(const Fabrica &_f) const {
    return _f.getColunas() + 4 + LARGURA_PAINEL;
}

string VistaFabrica::linhaPainel(const string &_rotulo, int _valor) const {
    ostringstream out;
    out << _rotulo << _valor;
    return out.str();
}

void VistaFabrica::desenha(const Fabrica &_f, Ecra &_ecra) const {
    int nl = _f.getLinhas();
    int nc = _f.getColunas();
    _ecra.limpa();

    // fábrica: moldura, régua e terreno
    _ecra.moldura(0, 0, nl + 3, nc + 3);
    for (int c = 0; c < nc; c++) {
        char letra = 'A' + c;
        _ecra.escreve(1, 2 + c, letra); // régua das colunas
    }
    for (int l = 0; l < nl; l++) {
        char letra = 'A' + l;
        _ecra.escreve(2 + l, 1, letra); // régua das linhas
        for (int c = 0; c < nc; c++) {
            char tipo = _f.getPosicao(Coordenada(l, c)).getTipo();
            if (tipo == '.') tipo = ' '; // solo desenha-se vazio
            _ecra.escreve(2 + l, 2 + c, tipo);
        }
    }

    // painel de estado
    int col = nc + 4;
    _ecra.moldura(0, col, ALTURA_PAINEL, LARGURA_PAINEL);
    _ecra.escreve(1, col + 2, linhaPainel("Instante: ", _f.getInstante()));
    _ecra.escreve(2, col + 2, linhaPainel("Creditos: ", _f.getCreditos()));
    _ecra.escreve(3, col + 2, linhaPainel("Maquinas: ", _f.getNumMaquinas()));
    _ecra.escreve(4, col + 2, linhaPainel("Engenheiros: ", _f.getNumEngenheiros()));
    _ecra.escreve(6, col + 2, "No ultimo instante:");
}
