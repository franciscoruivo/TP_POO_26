#include "Refinaria.h"
#include "Settings.h"

Refinaria::Refinaria(char d) : Maquina(Settings::refinaria_custo, d) {}

bool Refinaria::recebe(Item*) {
    return false;  // entrega final
}

void Refinaria::atua(Fabrica&, Celula&, Maquina*) {
    // entrega final
}

char Refinaria::getSimbolo() const {
    return 'R';
}

std::string Refinaria::getNome() const {
    return "Refinaria";
}
