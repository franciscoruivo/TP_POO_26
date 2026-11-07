#include "Posicao.h"
#include <sstream>
using namespace std;

Posicao::Posicao() : tipo('.'), quantidade(0) {}

bool Posicao::tipoDeposito(char t) {
    return t == '%' || t == '$' || t == '~';
}

bool Posicao::tipoValido(char t) {
    return t == '.' || t == '#' || tipoDeposito(t);
}

bool Posicao::setTerreno(char novoTipo, int novaQuantidade) {
    if (!tipoValido(novoTipo) || novaQuantidade < 0) return false;
    tipo = novoTipo;
    quantidade = tipoDeposito(novoTipo) ? novaQuantidade : 0;
    return true;
}

string Posicao::obterDescricao() const {
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