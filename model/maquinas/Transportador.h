#ifndef TRANSPORTADOR_H
#define TRANSPORTADOR_H
#include "Maquina.h"

// Transporta 1 item de cada vez
class Transportador : public Maquina {
    Item* item;
public:
    Transportador(char d);
    ~Transportador() override;
    char getSimbolo() const override;
    std::string getNome() const override { return "Transportador"; }
    bool recebe(Item* i) override;
    void atua(Fabrica& f, Celula& terreno, Maquina* destino) override;
    std::string getAsString() const override;
};
#endif
