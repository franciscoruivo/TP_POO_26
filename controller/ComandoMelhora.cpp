#include "ComandoMelhora.h"
#include "Interface.h"
#include "Simulador.h"
using namespace std;

ComandoMelhora::ComandoMelhora(const string& l) : Comando(l) {}

bool ComandoMelhora::valida() {
    istringstream in(linha);
    string cmd;
    in >> cmd;
    return leCoordenada(in, pos) && semMaisParametros(in);
}

void ComandoMelhora::executa(Simulador&, Interface& ui) {
    ui.mostraTexto("Comando validado, mas ainda nao disponivel neste checkpoint");
}

string ComandoMelhora::sintaxe() const {
    return "melhora <lc>";
}

string ComandoMelhora::ajuda() const {
    return
        "melhora <lc>\n"
        "  lc: posicao da fabrica (por exemplo hi)\n"
        "  Melhora a maquina que esta nessa posicao, pagando o respetivo custo.\n"
        "  (ainda nao disponivel neste checkpoint)\n"
        "  Exemplo: melhora hi";
}
