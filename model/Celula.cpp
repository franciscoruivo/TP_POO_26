#include "Celula.h"
#include <sstream>
using namespace std;

Celula::Celula() : tipo('.'), quantidade(0) {} // 1º solo -> Depois define o tipo de terreno

bool Celula::tipoDeposito(char t) {
    return t == '%' || t == '$' || t == '~';
}

bool Celula::tipoValido(char t) {
    return t == '.' || t == '#' || tipoDeposito(t);
}

bool Celula::definirTerreno(char novoTipo, int novaQuantidade) {
    if (!tipoValido(novoTipo) || novaQuantidade < 0) return false;
    tipo = novoTipo;
    quantidade = tipoDeposito(novoTipo) ? novaQuantidade : 0;
    return true;
}

char Celula::getMateriaPrima() const {
    if (tipo == '%') return 'f';
    if (tipo == '$') return 's';
    if (tipo == '~') return 'g';
    return ' ';
}

bool Celula::retiraUnidade() {
    if (!tipoDeposito(tipo) || quantidade <= 0) return false;
    quantidade--;
    if (quantidade == 0) tipo = '.';  // esgotou: passa a solo
    return true;
}

string Celula::obterDescricao() const {
    ostringstream out;
    switch (tipo) {
        case '#': out << "cratera"; break;
        case '%': out << "deposito de ferro com " << quantidade << " unidades"; break;
        case '$': out << "deposito de silicio com " << quantidade << " unidades"; break;
        case '~': out << "deposito de gelo com " << quantidade << " unidades"; break;
        default:  out << "solo"; break;
    }
    return out.str();
}