#include "ComandoFim.h"
#include "Interface.h"
#include "Simulador.h"
using namespace std;

ComandoFim::ComandoFim(const string& l) : Comando(l) {}

bool ComandoFim::valida() {
    istringstream in(linha);
    string cmd;
    in >> cmd;
    return semMaisParametros(in);
}

void ComandoFim::executa(Simulador& s, Interface&) {
    s.fim();
}

string ComandoFim::sintaxe() const {
    return "fim";
}

string ComandoFim::ajuda() const {
    return
        "fim\n"
        "  Termina o programa, libertando todos os recursos.\n"
        "  Exemplo: fim";
}
