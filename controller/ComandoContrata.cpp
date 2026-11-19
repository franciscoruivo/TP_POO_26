#include "ComandoContrata.h"
#include "Interface.h"
#include "Simulador.h"
using namespace std;

ComandoContrata::ComandoContrata(const string& l) : Comando(l) {}

bool ComandoContrata::valida() {
    istringstream in(linha);
    string cmd;
    in >> cmd;
    return lePalavra(in, nome) && semMaisParametros(in);
}

void ComandoContrata::executa(Simulador&, Interface& ui) {
    ui.mostraTexto("Comando validado, mas ainda nao disponivel neste checkpoint");
}

string ComandoContrata::sintaxe() const {
    return "contrata <nome>";
}

string ComandoContrata::ajuda() const {
    return
        "contrata <nome>\n"
        "  nome: nome do engenheiro (uma palavra)\n"
        "  Contrata um novo engenheiro, que fica livre.\n"
        "  (ainda nao disponivel neste checkpoint)\n"
        "  Exemplo: contrata joaquim";
}
