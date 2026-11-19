#include "Transportador.h"
#include "Settings.h"
using namespace std;

Transportador::Transportador(char d) : Maquina(Settings::transportador_custo, d), item(nullptr) {}

Transportador::~Transportador() {
    delete item;
}

char Transportador::getSimbolo() const {
    if (item != nullptr) return item->getSimbolo();  // mostra o item que transporta
    char d = getDirecao();
    if (d == 'c') return '^';
    if (d == 'b') return 'v';
    if (d == 'e') return '<';
    return '>';
}

bool Transportador::recebe(Item* i) {
    if (item != nullptr) return false;  // só aceita se estiver vazio
    item = i;
    novoItem = true;
    return true;
}

void Transportador::atua(Fabrica&, Celula&, Maquina* destino) {
    if (item != nullptr && !novoItem) entrega(item, destino);
}

string Transportador::getAsString() const {
    if (item == nullptr) return Maquina::getAsString() + ", vazio";
    return Maquina::getAsString() + ", com " + item->getAsString();
}
