#include "Simulador.h"
#include <stdexcept>
using namespace std;

Simulador::Simulador() : fabrica(), criada(false), terminar(false), erro() {}

bool Simulador::criaFabrica(int _linhas, int _colunas) {
    if (criada) {
        erro = "A fabrica ja foi criada";
        return false;
    }
    try {
        fabrica = Fabrica(_linhas, _colunas);
    } catch (const invalid_argument& e) {
        erro = e.what();
        return false;
    }
    criada = true;
    return true;
}

bool Simulador::carregaFabrica(const string& _ficheiro) {
    if (criada) {
        erro = "A fabrica ja foi criada";
        return false;
    }
    try {
        fabrica = Fabrica(_ficheiro);
    } catch (const invalid_argument& e) {
        erro = e.what();
        return false;
    }
    criada = true;
    return true;
}

bool Simulador::consultaPosicao(const Coordenada& _centro, int _raio, string& _texto) {
    if (!criada) {
        erro = "Crie primeiro a fabrica";
        return false;
    }
    if (!fabrica.coordenadaValida(_centro)) {
        erro = "Posicao fora da fabrica";
        return false;
    }
    if (_raio < 0) {
        erro = "Raio invalido";
        return false;
    }
    _texto = fabrica.obterDescricaoTerreno(_centro, _raio);
    return true;
}

void Simulador::fim() {
    terminar = true;
}