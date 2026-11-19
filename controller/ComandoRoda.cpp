#include "ComandoRoda.h"
#include "Interface.h"
#include "Simulador.h"
using namespace std;

ComandoRoda::ComandoRoda(const string& l) : Comando(l), dir(' ') {}

bool ComandoRoda::valida() {
    istringstream in(linha);
    string cmd;
    in >> cmd;
    return leCoordenada(in, pos) && leDirecao(in, dir) && semMaisParametros(in);
}

void ComandoRoda::executa(Simulador& s, Interface& ui) {
    if (s.rodaMaquina(pos, dir)) ui.mostraFabrica();
    else ui.mostraErro(s.getErro());
}

string ComandoRoda::sintaxe() const {
    return "roda <lc> <dir>";
}

string ComandoRoda::ajuda() const {
    return
        "roda <lc> <dir>\n"
        "  lc: posicao da fabrica (por exemplo ce)\n"
        "  dir: nova direcao de saida: c (cima), b (baixo), e (esquerda), d (direita)\n"
        "  Muda a direcao de saida da maquina que esta nessa posicao.\n"
        "  Falha se a posicao estiver fora da fabrica ou nao tiver nenhuma maquina.\n"
        "  Exemplo: roda ce b";
}
