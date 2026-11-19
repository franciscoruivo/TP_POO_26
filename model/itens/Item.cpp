#include "Item.h"
using namespace std;

Item::Item(const string& n, char s, int v) : nome(n), simbolo(s), valor(v) {}

Item::~Item() {}

const string& Item::getNome() const {
    return nome;
}

char Item::getSimbolo() const {
    return simbolo;
}

int Item::getValor() const {
    return valor;
}
