#include "Celula.h"
#include <sstream>
using namespace std;

Celula::Celula() : tipo(Solo), quantidade(0) {} // 1º solo -> Depois define o tipo de terreno

bool Celula::tipoDeposito(TipoTerreno t) {
    return t == Ferro || t == Silicio || t == Gelo;
}

bool Celula::converteSimbolo(char simbolo, TipoTerreno& resultado) {
    switch (simbolo) {
        case '.': resultado = Solo; return true;
        case '#': resultado = Cratera; return true;
        case '%': resultado = Ferro; return true;
        case '$': resultado = Silicio; return true;
        case '~': resultado = Gelo; return true;
    }
    return false;
}

bool Celula::definirTerreno(TipoTerreno novoTipo, int novaQuantidade) {
    if (novaQuantidade < 0) return false;
    tipo = novoTipo;
    quantidade = tipoDeposito(novoTipo) ? novaQuantidade : 0;
    return true;
}

TipoTerreno Celula::getTipo() const {
    return tipo;
}

int Celula::getQuantidade() const {
    return quantidade;
}

char Celula::getSimbolo() const {
    switch (tipo) {
        case Cratera: return '#';
        case Ferro: return '%';
        case Silicio: return '$';
        case Gelo: return '~';
        default: return '.';
    }
}

char Celula::getMateriaPrima() const {
    switch (tipo) {
        case Ferro: return 'f';
        case Silicio: return 's';
        case Gelo: return 'g';
        default: return ' ';
    }
}

bool Celula::retiraUnidade() {
    if (!tipoDeposito(tipo) || quantidade <= 0) return false;
    quantidade--;
    if (quantidade == 0) tipo = Solo;  // esgotou: passa a solo
    return true;
}

string Celula::obterDescricao() const {
    ostringstream out;
    switch (tipo) {
        case Cratera: out << "cratera"; break;
        case Ferro: out << "deposito de ferro com " << quantidade << " unidades"; break;
        case Silicio: out << "deposito de silicio com " << quantidade << " unidades"; break;
        case Gelo: out << "deposito de gelo com " << quantidade << " unidades"; break;
        default: out << "solo"; break;
    }
    return out.str();
}
