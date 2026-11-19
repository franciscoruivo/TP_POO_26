#include "ComandoVende.h"
#include "Interface.h"
#include "Simulador.h"
using namespace std;

ComandoVende::ComandoVende(const string& l) : Comando(l) {}

bool ComandoVende::valida() {
    istringstream in(linha);
    string cmd;
    in >> cmd;
    return leCoordenada(in, pos) && semMaisParametros(in);
}

void ComandoVende::executa(Simulador& s, Interface& ui) {
    if (s.vendeMaquina(pos)) ui.mostraFabrica();
    else ui.mostraErro(s.getErro());
}

string ComandoVende::sintaxe() const {
    return "vende <lc>";
}

string ComandoVende::ajuda() const {
    return
        "vende <lc>\n"
        "  lc: posicao da fabrica (por exemplo ce)\n"
        "  Vende a maquina que esta nessa posicao e recebe 50% do custo. Os itens que estiverem nela perdem-se.\n"
        "  Falha se a posicao estiver fora da fabrica ou nao tiver nenhuma maquina.\n"
        "  Exemplo: vende ce";
}
