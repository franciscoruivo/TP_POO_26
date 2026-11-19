#include "ComandoRecupera.h"
#include "Interface.h"
#include "Simulador.h"
using namespace std;

ComandoRecupera::ComandoRecupera(const string& l) : Comando(l) {}

bool ComandoRecupera::valida() {
    istringstream in(linha);
    string cmd;
    in >> cmd;
    return lePalavra(in, nome) && semMaisParametros(in);
}

void ComandoRecupera::executa(Simulador&, Interface& ui) {
    ui.mostraTexto("Comando validado, mas ainda nao disponivel neste checkpoint");
}

string ComandoRecupera::sintaxe() const {
    return "recupera <nome>";
}

string ComandoRecupera::ajuda() const {
    return
        "recupera <nome>\n"
        "  nome: nome da copia\n"
        "  Recupera a copia da fabrica com esse nome.\n"
        "  (ainda nao disponivel neste checkpoint)\n"
        "  Exemplo: recupera antes";
}
