#ifndef LANCADOR_H
#define LANCADOR_H
#include "Maquina.h"

// Envia itens para a Terra (rendem créditos)
class Lancador : public Maquina {
    Item* item;     // item por lançar
    int contador;   // instantes desde o último lançamento
    int probPerda;  // em percentagem
public:
    Lancador(char d);
    ~Lancador() override;
    char getSimbolo() const override { return 'L'; }
    std::string getNome() const override { return "Lancador"; }
    bool recebe(Item* i) override;
    void atua(Fabrica& f, Celula& terreno, Maquina* destino) override;
    std::string getAsString() const override;
};
#endif
