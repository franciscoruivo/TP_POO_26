#include "ComandoDespede.h"
#include "Interface.h"
#include "Simulador.h"
using namespace std;

ComandoDespede::ComandoDespede(const string& l) : Comando(l), id(0) {}

bool ComandoDespede::valida() {
    istringstream in(linha);
    string cmd;
    in >> cmd;
    return leInteiro(in, id) && semMaisParametros(in);
}

void ComandoDespede::executa(Simulador&, Interface& ui) {
    ui.mostraTexto("Comando validado, mas ainda nao disponivel neste checkpoint");
}

string ComandoDespede::sintaxe() const {
    return "despede <id>";
}

string ComandoDespede::ajuda() const {
    return
        "despede <id>\n"
        "  id: numero do engenheiro\n"
        "  Envia o engenheiro para a Terra: deixa de fazer parte da fabrica.\n"
        "  (ainda nao disponivel neste checkpoint)\n"
        "  Exemplo: despede 2";
}
