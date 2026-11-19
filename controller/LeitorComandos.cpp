#include "LeitorComandos.h"
#include <sstream>
#include "ComandoAjuda.h"
#include "ComandoFabrica.h"
#include "ComandoCarrega.h"
#include "ComandoExecuta.h"
#include "ComandoAvanca.h"
#include "ComandoCompra.h"
#include "ComandoVende.h"
#include "ComandoRoda.h"
#include "ComandoMelhora.h"
#include "ComandoContrata.h"
#include "ComandoAtribui.h"
#include "ComandoDespede.h"
#include "ComandoEstado.h"
#include "ComandoLposicao.h"
#include "ComandoGrava.h"
#include "ComandoRecupera.h"
#include "ComandoFim.h"
using namespace std;

const string nomesComandos[LeitorComandos::numComandos] = {
    "ajuda", "fabrica", "carrega", "executa", "avanca", "compra", "vende", "roda", "melhora", "contrata", "atribui", "despede", "estado", "lposicao", "grava", "recupera", "fim"
};

Comando* LeitorComandos::criaPorNome(const string& nome, const string& linha) const {
    if (nome == "ajuda") return new ComandoAjuda(linha);
    if (nome == "fabrica") return new ComandoFabrica(linha);
    if (nome == "carrega") return new ComandoCarrega(linha);
    if (nome == "executa") return new ComandoExecuta(linha);
    if (nome == "avanca") return new ComandoAvanca(linha);
    if (nome == "compra") return new ComandoCompra(linha);
    if (nome == "vende") return new ComandoVende(linha);
    if (nome == "roda") return new ComandoRoda(linha);
    if (nome == "melhora") return new ComandoMelhora(linha);
    if (nome == "contrata") return new ComandoContrata(linha);
    if (nome == "atribui") return new ComandoAtribui(linha);
    if (nome == "despede") return new ComandoDespede(linha);
    if (nome == "estado") return new ComandoEstado(linha);
    if (nome == "lposicao") return new ComandoLposicao(linha);
    if (nome == "grava") return new ComandoGrava(linha);
    if (nome == "recupera") return new ComandoRecupera(linha);
    if (nome == "fim") return new ComandoFim(linha);
    return nullptr;
}

Comando* LeitorComandos::cria(const string& linha) const {
    istringstream in(linha);
    string nome;
    in >> nome;
    return criaPorNome(nome, linha);
}

Comando* LeitorComandos::criaPorIndice(int i) const {
    if (i < 0 || i >= numComandos) return nullptr;
    return criaPorNome(nomesComandos[i], nomesComandos[i]);
}
