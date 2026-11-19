#include "ComandoEstado.h"
#include "Interface.h"
#include "Simulador.h"
using namespace std;

ComandoEstado::ComandoEstado(const string& l) : Comando(l) {}

bool ComandoEstado::valida() {
    istringstream in(linha);
    string cmd;
    in >> cmd;
    return semMaisParametros(in);
}

void ComandoEstado::executa(Simulador& s, Interface& ui) {
    string texto;
    if (s.obterEstado(texto)) ui.mostraTexto(texto);
    else ui.mostraErro(s.getErro());
}

string ComandoEstado::sintaxe() const {
    return "estado";
}

string ComandoEstado::ajuda() const {
    return
        "estado\n"
        "  Mostra o instante, os creditos, as maquinas (tipo, posicao, direcao e conteudo), os engenheiros\n"
        "  e o total de itens enviados para a Terra.\n"
        "  Falha se a fabrica ainda nao existir.\n"
        "  Exemplo: estado";
}
