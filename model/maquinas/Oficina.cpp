#include "Oficina.h"
#include "Settings.h"

Oficina::Oficina(char d) : Maquina(Settings::oficina_custo, d) {}

bool Oficina::recebe(Item*) {
    return false;  // entrega final
}

void Oficina::atua(Fabrica&, Celula&, Maquina*) {
    // entrega final
}

char Oficina::getSimbolo() const {
    return 'O';
}

std::string Oficina::getNome() const {
    return "Oficina";
}
