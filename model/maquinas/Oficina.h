#ifndef OFICINA_H
#define OFICINA_H
#include "Maquina.h"

// Última meta: definir o comportamento
// Só a estrutura
class Oficina : public Maquina {
public:
    Oficina(char d);
    char getSimbolo() const override;
    std::string getNome() const override;
    bool recebe(Item* i) override;
    void atua(Fabrica& f, Celula& terreno, Maquina* destino) override;
};
#endif
