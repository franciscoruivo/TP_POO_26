#include "ComandoGrava.h"
#include "Interface.h"
#include "Simulador.h"
using namespace std;

ComandoGrava::ComandoGrava(const string& l) : Comando(l) {}

bool ComandoGrava::valida() {
    istringstream in(linha);
    string cmd;
    in >> cmd;
    return lePalavra(in, nome) && semMaisParametros(in);
}

void ComandoGrava::executa(Simulador&, Interface& ui) {
    ui.mostraTexto("Comando validado, mas ainda nao disponivel neste checkpoint");
}

string ComandoGrava::sintaxe() const {
    return "grava <nome>";
}

string ComandoGrava::ajuda() const {
    return
        "grava <nome>\n"
        "  nome: nome da copia\n"
        "  Guarda em memoria uma copia da fabrica.\n"
        "  (ainda nao disponivel neste checkpoint)\n"
        "  Exemplo: grava antes";
}
