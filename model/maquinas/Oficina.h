#ifndef OFICINA_H
#define OFICINA_H
#include "Maquina.h"

// Só a estrutura (o comportamento fica para a entrega final)
class Oficina : public Maquina {
public:
    Oficina(char d);
    char getSimbolo() const override { return 'O'; }
    std::string getNome() const override { return "Oficina"; }
    bool recebe(Item* i) override;
    void atua(Fabrica& f, Celula& terreno, Maquina* destino) override;
};
#endif
