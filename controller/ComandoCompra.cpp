#include "ComandoCompra.h"
#include "Interface.h"
#include "Simulador.h"
#include "../model/maquinas/Maquina.h"
using namespace std;

ComandoCompra::ComandoCompra(const string& l) : Comando(l), tipo(' '), dir(' ') {}

bool ComandoCompra::valida() {
    istringstream in(linha);
    string cmd;
    in >> cmd;
    string palavra;
    if (!lePalavra(in, palavra)) return false;
    if (palavra.length() != 1 || !Maquina::tipoValido(palavra[0]))
        return erroUso("'" + palavra + "' nao e um tipo de maquina (p, t, r, o, s ou l)");
    tipo = palavra[0];
    return leCoordenada(in, pos) && leDirecao(in, dir) && semMaisParametros(in);
}

void ComandoCompra::executa(Simulador& s, Interface& ui) {
    if (s.compraMaquina(tipo, pos, dir)) ui.mostraFabrica();
    else ui.mostraErro(s.getErro());
}

string ComandoCompra::sintaxe() const {
    return "compra <tipo> <lc> <dir>";
}

string ComandoCompra::ajuda() const {
    return
        "compra <tipo> <lc> <dir>\n"
        "  tipo: p (perfuradora), t (transportador), r (refinaria), o (oficina), s (silo), l (lancador)\n"
        "  lc: posicao da fabrica (linha e coluna, por exemplo ce)\n"
        "  dir: direcao de saida: c (cima), b (baixo), e (esquerda), d (direita)\n"
        "  Compra uma maquina e coloca-a nessa posicao.\n"
        "  Falha se a posicao estiver ocupada, for uma cratera, ficar fora da fabrica ou se nao houver creditos.\n"
        "  Exemplo: compra t ce d";
}
