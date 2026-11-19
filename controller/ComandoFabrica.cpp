#include "ComandoFabrica.h"
#include "Interface.h"
#include "Simulador.h"
#include "Settings.h"
using namespace std;

ComandoFabrica::ComandoFabrica(const string& l) : Comando(l), nl(0), nc(0) {}

bool ComandoFabrica::valida() {
    istringstream in(linha);
    string cmd;
    in >> cmd;
    if (!leInteiro(in, nl) || !leInteiro(in, nc) || !semMaisParametros(in)) return false;
    if (nl < 1 || nl > Settings::fabrica_max_linhas || nc < 1 || nc > Settings::fabrica_max_colunas)
        return erroUso("Dimensoes fora dos limites");
    return true;
}

void ComandoFabrica::executa(Simulador& s, Interface& ui) {
    if (s.criaFabrica(nl, nc)) ui.mostraFabrica();
    else ui.mostraErro(s.getErro());
}

string ComandoFabrica::sintaxe() const {
    return "fabrica <nl> <nc>";
}

string ComandoFabrica::ajuda() const {
    return
        "fabrica <nl> <nc>\n"
        "  nl, nc: numero de linhas e de colunas da fabrica (maximo 26 cada)\n"
        "  Cria a fabrica com crateras e depositos em posicoes aleatorias.\n"
        "  Falha se a fabrica ja existir ou se as dimensoes nao comportarem as crateras e os depositos.\n"
        "  Exemplo: fabrica 12 20";
}
