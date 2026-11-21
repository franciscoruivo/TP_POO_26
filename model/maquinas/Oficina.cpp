#include "Oficina.h"
#include "Settings.h"


// Última meta
Oficina::Oficina(char d) : Maquina(Settings::oficina_custo, d) {}

bool Oficina::recebe(Item*) {
    return false;
}

void Oficina::atua(Fabrica&, Celula&, Maquina*) {

}

char Oficina::getSimbolo() const {
    return 'O';
}

std::string Oficina::getNome() const {
    return "Oficina";
}
