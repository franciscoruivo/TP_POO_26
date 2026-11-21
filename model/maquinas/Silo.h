#ifndef SILO_H
#define SILO_H
#include "Maquina.h"

// Guarda itens de qualquer tipo, sem limite. Entrega primeiro o que está guardado há mais tempo
class Silo : public Maquina {
    Item** itens;    // array dinâmico de ponteiros, com n elementos (o 0 é o mais antigo)
    int n;
    int itensNovos;  // quantos itens chegaram neste instante (são os últimos do array)
    int probPerda;   // em percentagem

    void tiraMaisAntigo();  // tira o primeiro do array (não destrói o item)
public:
    Silo(char d);
    ~Silo() override;
    char getSimbolo() const override;
    std::string getNome() const override;
    bool recebe(Item* i) override;
    void atua(Fabrica& f, Celula& terreno, Maquina* destino) override;
    void iniciaInstante() override;
    std::string getAsString() const override;
};
#endif
