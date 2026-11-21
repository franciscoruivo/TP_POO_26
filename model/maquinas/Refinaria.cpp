#include "Refinaria.h"
#include "Settings.h"

Refinaria::Refinaria(char d) : Maquina(Settings::refinaria_custo, d) {}


// Última meta
bool Refinaria::recebe(Item*) {
    return false;
}

void Refinaria::atua(Fabrica&, Celula&, Maquina*) {

}

char Refinaria::getSimbolo() const {
    return 'R';
}

std::string Refinaria::getNome() const {
    return "Refinaria";
}
