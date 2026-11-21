#ifndef LANCADOR_H
#define LANCADOR_H
#include "Maquina.h"

// 	Manda itens para a Terra (dão créditos)
class Lancador : public Maquina {
    Item* item;     // item que falta lançar
    int contador;   // instantes desde o último lançamento
    int probPerda;  // em percentagem
public:
    Lancador(char d);
    ~Lancador() override;
    char getSimbolo() const override;
    std::string getNome() const override;
    bool recebe(Item* i) override;
    void atua(Fabrica& f, Celula& terreno, Maquina* destino) override;
    std::string getAsString() const override;
};
#endif
