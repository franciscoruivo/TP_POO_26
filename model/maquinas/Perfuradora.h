#ifndef PERFURADORA_H
#define PERFURADORA_H
#include "Maquina.h"

// Tira matéria-prima de um depósito e entrega-a à máquina da frente
class Perfuradora : public Maquina {
    Item* item;     // guarda no máximo 1 item por entregar
    int contador;   // instantes desde a última extração
    int probPerda;  // em percentagem
public:
    Perfuradora(char d);
    ~Perfuradora() override;
    char getSimbolo() const override;
    std::string getNome() const override;
    bool recebe(Item* i) override;
    void atua(Fabrica& f, Celula& terreno, Maquina* destino) override;
    std::string getAsString() const override;
};
#endif
