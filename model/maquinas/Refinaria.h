#ifndef REFINARIA_H
#define REFINARIA_H
#include "Maquina.h"

// Última meta: definir o comportamento
// Estrutura
class Refinaria : public Maquina {
public:
    Refinaria(char d);
    char getSimbolo() const override;
    std::string getNome() const override;
    bool recebe(Item* i) override;
    void atua(Fabrica& f, Celula& terreno, Maquina* destino) override;
};
#endif
