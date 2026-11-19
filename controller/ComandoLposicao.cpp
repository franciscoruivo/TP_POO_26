#include "ComandoLposicao.h"
#include "Interface.h"
#include "Simulador.h"
using namespace std;

ComandoLposicao::ComandoLposicao(const string& l) : Comando(l), raio(0) {}

bool ComandoLposicao::valida() {
    istringstream in(linha);
    string cmd;
    in >> cmd;
    if (!leCoordenada(in, pos)) return false;
    string palavra;
    if (in >> palavra) {  // o raio é opcional
        if (!converteInteiro(palavra, raio)) return erroUso("'" + palavra + "' nao e um numero inteiro");
        if (raio < 0) return erroUso("O raio nao pode ser negativo");
    }
    return semMaisParametros(in);
}

void ComandoLposicao::executa(Simulador& s, Interface& ui) {
    string texto;
    if (s.consultaPosicao(pos, raio, texto)) ui.mostraTexto(texto);
    else ui.mostraErro(s.getErro());
}

string ComandoLposicao::sintaxe() const {
    return "lposicao <lc> [n]";
}

string ComandoLposicao::ajuda() const {
    return
        "lposicao <lc> [n]\n"
        "  lc: posicao da fabrica (por exemplo df)\n"
        "  n: raio (opcional, inteiro maior ou igual a 0)\n"
        "  Mostra o terreno (e a quantidade, se for um deposito) e a maquina que estiver nessa posicao.\n"
        "  Com n mostra todas as posicoes dentro do quadrado de raio n centrado em lc.\n"
        "  Falha se a posicao estiver fora da fabrica ou se a fabrica ainda nao existir.\n"
        "  Exemplo: lposicao df 2";
}
