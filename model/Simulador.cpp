#include "Simulador.h"
#include <stdexcept>
using namespace std;

Simulador::Simulador() : fabrica(), criada(false), terminar(false), erro() {}

bool Simulador::criaFabrica(int nl, int nc) {
    if (criada) {
        erro = "A fabrica ja foi criada";
        return false;
    }
    try {
        fabrica = Fabrica(nl, nc);
    } catch (const invalid_argument& e) {
        erro = e.what();
        return false;
    }
    criada = true;
    return true;
}

bool Simulador::carregaFabrica(const string& ficheiro) {
    if (criada) {
        erro = "A fabrica ja foi criada";
        return false;
    }
    try {
        fabrica = Fabrica(ficheiro);
    } catch (const invalid_argument& e) {
        erro = e.what();
        return false;
    }
    criada = true;
    return true;
}

bool Simulador::consultaPosicao(const Coordenada& centro, int raio, string& texto) {
    if (!criada) {
        erro = "Crie primeiro a fabrica";
        return false;
    }
    if (!fabrica.coordenadaValida(centro)) {
        erro = "Posicao fora da fabrica";
        return false;
    }
    if (raio < 0) {
        erro = "Raio invalido";
        return false;
    }
    texto = fabrica.obterDescricaoTerreno(centro, raio);
    return true;
}

void Simulador::fim() {
    terminar = true;
}