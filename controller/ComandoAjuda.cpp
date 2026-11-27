#include "ComandoAjuda.h"
#include "Interface.h"
#include "Simulador.h"
#include "LeitorComandos.h"
using namespace std;

// Mem Din - cria + apaga cmd
// Tbm vai criar e apagar os comandos para buscar a sintaxe e ajuda
ComandoAjuda::ComandoAjuda(const string& l) : Comando(l) {}

bool ComandoAjuda::valida() {
    istringstream in(linha);
    string cmd;
    in >> cmd;
    if (in >> alvo) {
        if (!semMaisParametros(in)) return false;
        LeitorComandos leitor;
        Comando* c = leitor.cria(alvo);
        if (c == nullptr) return erroUso("'" + alvo + "' nao e um comando");
        delete c;
    }
    return true;
}

void ComandoAjuda::executa(Simulador&, Interface& ui) {
    LeitorComandos leitor;
    if (alvo.empty()) {
        string texto = "Comandos disponiveis:\n";
        for (int i = 0; i < LeitorComandos::numComandos; i++) {
            Comando* c = leitor.criaPorIndice(i);
            texto += "  " + c->sintaxe() + "\n";
            delete c;
        }
        ui.mostraTexto(texto);
    } else {
        Comando* c = leitor.cria(alvo);
        ui.mostraTexto(c->ajuda());
        delete c;
    }
}

string ComandoAjuda::sintaxe() const {
    return "ajuda [comando]";
}

string ComandoAjuda::ajuda() const {
    return
        "ajuda [comando]\n"
        "  comando: nome de um comando (opcional)\n"
        "  Sem parametro mostra todos os comandos. Com o nome de um comando mostra a ajuda detalhada.\n"
        "  Falha se o nome indicado nao for um comando.\n"
        "  Exemplo: ajuda compra";
}
