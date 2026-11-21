#include "Silo.h"
#include <sstream>
#include "Random.h"
#include "Settings.h"
using namespace std;

Silo::Silo(char d)
    : Maquina(Settings::silo_custo, d), itens(nullptr), n(0), itensNovos(0),
      probPerda(Settings::silo_prob_perda) {}

Silo::~Silo() {
    for (int i = 0; i < n; i++)
        delete itens[i];
    delete[] itens;
}

bool Silo::recebe(Item* i) {
    Item** aux = new Item*[n + 1];  // espaço para mais um
    for (int k = 0; k < n; k++)
        aux[k] = itens[k];
    aux[n] = i;  // o novo fica no fim
    delete[] itens;
    itens = aux;
    n++;
    itensNovos++;
    return true;
}

void Silo::tiraMaisAntigo() {
    if (n == 1) {
        delete[] itens;
        itens = nullptr;
        n = 0;
        itensNovos = 0;
        return;
    }
    Item** aux = new Item*[n - 1];  // ajusta o espaço para menos um
    for (int k = 1; k < n; k++)
        aux[k - 1] = itens[k];
    delete[] itens;
    itens = aux;
    n--;
    if (itensNovos > n) itensNovos = n;
}

void Silo::iniciaInstante() {
    Maquina::iniciaInstante();
    itensNovos = 0;
}

void Silo::atua(Fabrica&, Celula&, Maquina* destino) {
    if (n == 0) return;

    // pode perder-se o item guardado há mais tempo
    if (Random::getRandom(1, 100) <= probPerda) {
        delete itens[0];
        itens[0] = nullptr;
        tiraMaisAntigo();
        if (n == 0) return;
    }

    // entrega o mais antigo (se não tiver chegado neste instante)
    if (n > itensNovos) {
        if (entrega(itens[0], destino))
            tiraMaisAntigo();
    }
}

string Silo::getAsString() const {
    ostringstream out;
    out << Maquina::getAsString() << ", " << n << " itens";
    if (n > 0) {
        out << " (";
        for (int i = 0; i < n; i++)
            out << itens[i]->getSimbolo();
        out << ")";
    }
    out << ", probabilidade de perda " << probPerda << "%";
    return out.str();
}

char Silo::getSimbolo() const {
    return 'S';
}

string Silo::getNome() const {
    return "Silo";
}
