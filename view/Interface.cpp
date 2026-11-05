#include "Interface.h"
#include <iostream>
#include <string>
#include "Coordenada.h"
#include "Ecra.h"
using namespace std;

// Valores da demonstração do checkpoint 1 (alterar para demonstrar outros casos)
const int LINHAS = 12;
const int COLUNAS = 20;
const int CENTRO_LINHA = 2; // posição "ce"
const int CENTRO_COLUNA = 4;
const int RAIO = 1;
const int NUM_MAPAS = 4;
const string MAPAS[NUM_MAPAS] = {"mapa1.txt", "erro1.txt", "erro2.txt", "naoexiste.txt"};

Interface::Interface(Simulador &_simulador) : simulador(_simulador), vista() {
}

void Interface::mostra(const Simulador &_s) const {
    if (!_s.temFabrica()) return;
    const Fabrica &f = _s.getFabrica();
    Ecra ecra(vista.linhasEcra(f), vista.colunasEcra(f));
    vista.desenha(f, ecra);
    ecra.mostra();
}

void Interface::consulta(Simulador &_s, const Coordenada &_centro, int _raio) const {
    string texto;
    if (_s.consultaPosicao(_centro, _raio, texto)) cout << texto;
    else cout << _s.getErro() << "\n";
}

void Interface::mostraResultado(Simulador &_s, bool _criou) const {
    if (!_criou) {
        cout << _s.getErro() << "\n"; // a fábrica não foi criada
        return;
    }
    mostra(_s);
    consulta(_s, Coordenada(CENTRO_LINHA, CENTRO_COLUNA), RAIO);
}

void Interface::demonstra() {
    cout << "--- Fabrica aleatoria ---\n";
    mostraResultado(simulador, simulador.criaFabrica(LINHAS, COLUNAS));

    cout << "\n--- Consulta fora da fabrica ---\n";
    consulta(simulador, Coordenada(30, 30), 0);

    cout << "\n--- Segunda criacao (recusada) ---\n";
    mostraResultado(simulador, simulador.criaFabrica(LINHAS, COLUNAS));

    cout << "\n--- Dimensoes invalidas ---\n";
    Simulador pequeno;
    mostraResultado(pequeno, pequeno.criaFabrica(3, 3));

    for (int i = 0; i < NUM_MAPAS; i++) {
        cout << "\n--- Fabrica carregada de " << MAPAS[i] << " ---\n";
        Simulador doFicheiro; // cada mapa precisa de um simulador novo
        mostraResultado(doFicheiro, doFicheiro.carregaFabrica(MAPAS[i]));
    }
}

void Interface::executa() {
    // No checkpoint 2, o corpo do ciclo passa a ler e executar comandos.
    // No checkpoint 1 faz uma passagem pelas funcionalidades e pede o fim.
    while (!simulador.terminou()) {
        demonstra();
        cout << "\n--- Fim ---\n";
        simulador.fim();
    }
    cout << "Programa terminado\n";
}
