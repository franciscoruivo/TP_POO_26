#include "ComandoExecuta.h"
#include "Interface.h"
#include "Simulador.h"
using namespace std;

ComandoExecuta::ComandoExecuta(const string& l) : Comando(l) {}

bool ComandoExecuta::valida() {
    istringstream in(linha);
    string cmd;
    in >> cmd;
    if (!lePalavra(in, nomeFicheiro) || !semMaisParametros(in)) return false;
    return true;
}

void ComandoExecuta::executa(Simulador&, Interface& ui) {
    if (!ui.executaFicheiro(nomeFicheiro))
        ui.mostraErro("Nao foi possivel abrir o ficheiro " + nomeFicheiro);
}

string ComandoExecuta::sintaxe() const {
    return "executa <nome-do-ficheiro>";
}

string ComandoExecuta::ajuda() const {
    return
        "executa <nome-do-ficheiro>\n"
        "  nome-do-ficheiro: ficheiro de texto com um comando por linha\n"
        "  Executa os comandos do ficheiro, como se fossem escritos no teclado.\n"
        "  Falha se o ficheiro nao existir. Nao pode ser usado dentro de um ficheiro de comandos.\n"
        "  Exemplo: executa teste1.txt";
}
