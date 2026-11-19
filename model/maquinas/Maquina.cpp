#include "Maquina.h"
using namespace std;

Maquina::Maquina(int c, char d) : direcao(d), custo(c), novoItem(false) {}

bool Maquina::direcaoValida(char d) {
    return d == 'c' || d == 'b' || d == 'e' || d == 'd';
}

bool Maquina::tipoValido(char t) {
    return t == 'p' || t == 't' || t == 'r' || t == 'o' || t == 's' || t == 'l';
}

bool Maquina::entrega(Item*& item, Maquina* destino) {
    if (item == nullptr || destino == nullptr) return false;
    if (!destino->recebe(item)) return false;
    item = nullptr;  // passou a ser do destino
    return true;
}

void Maquina::iniciaInstante() {
    novoItem = false;
}

string Maquina::getAsString() const {
    return getNome() + ", direcao " + string(1, direcao);
}
