#include "Posicao.h"
#include <sstream>
using namespace std;

Posicao::Posicao() : tipo('.'), quantidade(0) {
}

bool Posicao::tipoDeposito(char _tipo) {
    return _tipo == '%' || _tipo == '$' || _tipo == '~';
}

bool Posicao::tipoValido(char _tipo) {
    return _tipo == '.' || _tipo == '#' || tipoDeposito(_tipo);
}

bool Posicao::setTerreno(char _tipo, int _quantidade) {
    if (!tipoValido(_tipo) || _quantidade < 0) return false;
    tipo = _tipo;
    quantidade = tipoDeposito(_tipo) ? _quantidade : 0;
    return true;
}

string Posicao::obterDescricao() const {
    ostringstream out;
    switch (tipo) {
        case '#': out << "cratera";
            break;
        case '%': out << "deposito de ferro com " << quantidade << " unidades";
            break;
        case '$': out << "deposito de silicio com " << quantidade << " unidades";
            break;
        case '~': out << "deposito de gelo com " << quantidade << " unidades";
            break;
        default: out << "solo";
            break;
    }
    return out.str();
}
