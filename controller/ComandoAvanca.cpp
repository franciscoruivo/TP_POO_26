#include "ComandoAvanca.h"
#include "Interface.h"
#include "Simulador.h"
using namespace std;

ComandoAvanca::ComandoAvanca(const string& l) : Comando(l), n(1) {}

bool ComandoAvanca::valida() {
    istringstream in(linha);
    string cmd;
    in >> cmd;
    string palavra;
    if (in >> palavra) {  // o número é opcional
        if (!converteInteiro(palavra, n)) return erroUso("'" + palavra + "' nao e um numero inteiro");
        if (n <= 0) return erroUso("O numero de instantes tem de ser positivo");
    }
    return semMaisParametros(in);
}

void ComandoAvanca::executa(Simulador& s, Interface& ui) {
    for (int i = 0; i < n; i++) {
        if (!s.avancaInstante()) {
            ui.mostraErro(s.getErro());
            return;
        }
        ui.mostraFabrica();
    }
}

string ComandoAvanca::sintaxe() const {
    return "avanca [n]";
}

string ComandoAvanca::ajuda() const {
    return
        "avanca [n]\n"
        "  n: numero de instantes a avancar (inteiro positivo; se faltar assume 1)\n"
        "  Avanca n instantes, um de cada vez. Em cada instante as maquinas atuam e o ecra e mostrado.\n"
        "  Falha se a fabrica ainda nao existir ou se n nao for um inteiro positivo.\n"
        "  Exemplo: avanca 10";
}
