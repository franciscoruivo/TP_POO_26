#include "Lancador.h"
#include <sstream>
#include "Fabrica.h"
#include "Random.h"
#include "Settings.h"
using namespace std;

Lancador::Lancador(char d)
    : Maquina(Settings::lancador_custo, d), item(nullptr),
      contador(Settings::lancador_recarga),  // começa já carregado, pronto a lançar
      probPerda(Settings::lancador_prob_perda) {}

Lancador::~Lancador() {
    delete item;
}

bool Lancador::recebe(Item* i) {
    if (item != nullptr) return false;  // se ainda tem um item por lançar, não aceita outro
    item = i;
    novoItem = true;
    return true;
}

void Lancador::atua(Fabrica& f, Celula&, Maquina*) {
    if (contador < Settings::lancador_recarga) contador++;
    if (item == nullptr || novoItem) return;
    if (contador < Settings::lancador_recarga) return;  // ainda está a recarregar

    contador = 0;
    if (Random::getRandom(1, 100) <= probPerda)
        f.registaEvento("item perdido no lancamento");
    else
        f.registaEnvio(*item);
    delete item;
    item = nullptr;
}

string Lancador::getAsString() const {
    ostringstream out;
    out << Maquina::getAsString() << ", ";
    if (item == nullptr) out << "vazio";
    else out << "com " << item->getAsString();
    out << ", recarga " << contador << "/" << Settings::lancador_recarga
        << ", probabilidade de perda " << probPerda << "%";
    return out.str();
}

char Lancador::getSimbolo() const {
    return 'L';
}

string Lancador::getNome() const {
    return "Lancador";
}
