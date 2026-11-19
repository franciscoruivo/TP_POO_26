#include "ComandoCarrega.h"
#include "Interface.h"
#include "Simulador.h"
using namespace std;

ComandoCarrega::ComandoCarrega(const string& l) : Comando(l) {}

bool ComandoCarrega::valida() {
    istringstream in(linha);
    string cmd;
    in >> cmd;
    if (!lePalavra(in, nomeFicheiro) || !semMaisParametros(in)) return false;
    return true;
}

void ComandoCarrega::executa(Simulador& s, Interface& ui) {
    if (s.carregaFabrica(nomeFicheiro)) ui.mostraFabrica();
    else ui.mostraErro(s.getErro());
}

string ComandoCarrega::sintaxe() const {
    return "carrega <nome-do-ficheiro>";
}

string ComandoCarrega::ajuda() const {
    return
        "carrega <nome-do-ficheiro>\n"
        "  nome-do-ficheiro: ficheiro de texto com o mapa da fabrica\n"
        "  Cria a fabrica a partir do mapa descrito no ficheiro.\n"
        "  Falha se a fabrica ja existir, se o ficheiro nao existir ou se nao respeitar o formato.\n"
        "  Exemplo: carrega mapa1.txt";
}
