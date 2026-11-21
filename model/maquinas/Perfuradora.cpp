#include "Perfuradora.h"
#include <sstream>
#include "Celula.h"
#include "MateriaPrima.h"
#include "Random.h"
#include "Settings.h"
using namespace std;

Perfuradora::Perfuradora(char d)
    : Maquina(Settings::perfuradora_custo, d), item(nullptr), contador(0),
      probPerda(Settings::perfuradora_prob_perda) {}

Perfuradora::~Perfuradora() {
    delete item;
}

bool Perfuradora::recebe(Item*) {
    return false;  // não aceita itens de outras máquinas
}

void Perfuradora::atua(Fabrica&, Celula& terreno, Maquina* destino) {
    if (item != nullptr) {  // tem um item por entregar: não perfura (nem conta o tempo) enquanto o tiver
        if (!novoItem) entrega(item, destino);
        return;
    }
    if (contador < Settings::perfuradora_periodo) contador++;
    if (contador < Settings::perfuradora_periodo) return;
    contador = 0;

    char simbolo = terreno.getMateriaPrima();
    if (simbolo == ' ') return;  // fora de um depósito não extrai nada
    if (!terreno.retiraUnidade()) return;
    if (Random::getRandom(1, 100) <= probPerda) return;  // o item perdeu-se

    item = new MateriaPrima(simbolo);
    novoItem = true;  // só é entregue no instante seguinte
}

string Perfuradora::getAsString() const {
    ostringstream out;
    out << Maquina::getAsString() << ", ";
    if (item == nullptr) out << "vazia";
    else out << "com " << item->getAsString();
    out << ", extracao " << contador << "/" << Settings::perfuradora_periodo
        << ", probabilidade de perda " << probPerda << "%";
    return out.str();
}

char Perfuradora::getSimbolo() const {
    return 'P';
}

string Perfuradora::getNome() const {
    return "Perfuradora";
}
