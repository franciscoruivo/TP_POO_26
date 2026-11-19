#include "Simulador.h"
#include <stdexcept>
using namespace std;

Simulador::Simulador() : fabrica(nullptr), terminar(false), erro() {}

Simulador::~Simulador() {
    delete fabrica;
}

bool Simulador::criaFabrica(int nl, int nc) {
    if (fabrica != nullptr) {
        erro = "A fabrica ja foi criada";
        return false;
    }
    try {
        fabrica = new Fabrica(nl, nc);
    } catch (const invalid_argument& e) {
        erro = e.what();
        return false;
    }
    return true;
}

bool Simulador::carregaFabrica(const string& ficheiro) {
    if (fabrica != nullptr) {
        erro = "A fabrica ja foi criada";
        return false;
    }
    try {
        fabrica = new Fabrica(ficheiro);
    } catch (const invalid_argument& e) {
        erro = e.what();
        return false;
    }
    return true;
}

bool Simulador::consultaPosicao(const Coordenada& centro, int raio, string& texto) {
    if (fabrica == nullptr) {
        erro = "Crie primeiro a fabrica";
        return false;
    }
    if (!fabrica->coordenadaValida(centro)) {
        erro = "Posicao fora da fabrica";
        return false;
    }
    if (raio < 0) {
        erro = "Raio invalido";
        return false;
    }
    texto = fabrica->obterDescricaoPosicao(centro, raio);
    return true;
}

bool Simulador::compraMaquina(char tipo, const Coordenada& pos, char dir) {
    if (fabrica == nullptr) {
        erro = "Crie primeiro a fabrica";
        return false;
    }
    return fabrica->compraMaquina(tipo, pos, dir, erro);
}

bool Simulador::vendeMaquina(const Coordenada& pos) {
    if (fabrica == nullptr) {
        erro = "Crie primeiro a fabrica";
        return false;
    }
    return fabrica->vendeMaquina(pos, erro);
}

bool Simulador::rodaMaquina(const Coordenada& pos, char dir) {
    if (fabrica == nullptr) {
        erro = "Crie primeiro a fabrica";
        return false;
    }
    return fabrica->rodaMaquina(pos, dir, erro);
}

bool Simulador::avancaInstante() {
    if (fabrica == nullptr) {
        erro = "Crie primeiro a fabrica";
        return false;
    }
    fabrica->avancaInstante();
    return true;
}

bool Simulador::obterEstado(string& texto) {
    if (fabrica == nullptr) {
        erro = "Crie primeiro a fabrica";
        return false;
    }
    texto = fabrica->obterEstado();
    return true;
}

void Simulador::fim() {
    terminar = true;
}

bool Simulador::terminou() const {
    return terminar;
}

bool Simulador::temFabrica() const {
    return fabrica != nullptr;
}

const string& Simulador::getErro() const {
    return erro;
}

const Fabrica& Simulador::getFabrica() const {
    return *fabrica;
}
