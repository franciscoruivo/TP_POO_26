#ifndef MAQUINA_H
#define MAQUINA_H
#include <string>
#include "Item.h"

class Fabrica;
class Celula;

// Máquina genérica (abstrata). Cada tipo de máquina é uma classe derivada
class Maquina {
    char direcao;  // direção de saída: c, b, e ou d
    int custo;
protected:
    bool novoItem;  // recebeu ou fez um item neste instante (só o entrega no instante seguinte)

    // tenta passar o item ao destino; se o destino o aceitar, o item deixa de ser desta máquina
    bool entrega(Item*& item, Maquina* destino);
public:
    Maquina(int c, char d);
    virtual ~Maquina();
    Maquina(const Maquina&) = delete;
    Maquina& operator=(const Maquina&) = delete;

    char getDirecao() const;
    void setDirecao(char d);
    int getCusto() const;
    static bool direcaoValida(char d);
    static bool tipoValido(char t);

    virtual char getSimbolo() const = 0;
    virtual std::string getNome() const = 0;
    virtual bool recebe(Item* item) = 0;  // true -> a máquina aceitou o item (passa a ser dela)
    virtual void atua(Fabrica& f, Celula& terreno, Maquina* destino) = 0;  // chamada em cada instante
    virtual void iniciaInstante();
    virtual std::string getAsString() const;
};
#endif
