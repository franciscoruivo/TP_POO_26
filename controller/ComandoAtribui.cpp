#include "ComandoAtribui.h"
#include "Interface.h"
#include "Simulador.h"
using namespace std;

ComandoAtribui::ComandoAtribui(const string& l) : Comando(l), id(0) {}

bool ComandoAtribui::valida() {
    istringstream in(linha);
    string cmd;
    in >> cmd;
    return leInteiro(in, id) && leCoordenada(in, pos) && semMaisParametros(in);
}

void ComandoAtribui::executa(Simulador&, Interface& ui) {
    ui.mostraTexto("Comando validado, mas ainda nao disponivel neste checkpoint");
}

string ComandoAtribui::sintaxe() const {
    return "atribui <id> <lc>";
}

string ComandoAtribui::ajuda() const {
    return
        "atribui <id> <lc>\n"
        "  id: numero do engenheiro\n"
        "  lc: posicao da maquina (por exemplo hr)\n"
        "  Atribui o engenheiro a essa maquina.\n"
        "  (ainda nao disponivel neste checkpoint)\n"
        "  Exemplo: atribui 2 hr";
}
