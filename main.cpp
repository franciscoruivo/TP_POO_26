#include <iostream>
#include <string>
#include "Coordenada.h"
#include "Simulador.h"
using namespace std;

// Programa de DEMONSTRAÇÃO do checkpoint 1: chama diretamente as funcionalidades
// do Simulador. Não lê nem valida comandos (isso é o checkpoint 2).
// Para demonstrar outros casos, alterar as constantes abaixo.
const int LINHAS = 12;
const int COLUNAS = 20;
const int CENTRO_LINHA = 2; // posição "ce"
const int CENTRO_COLUNA = 4;
const int RAIO = 1;
const int NUM_MAPAS = 4;
const string MAPAS[NUM_MAPAS] = {"mapa1.txt", "erro1.txt", "erro2.txt", "naoexiste.txt"};

void consulta(Simulador &simulador, const Coordenada &centro, int raio) {
    string texto;
    if (simulador.consultaPosicao(centro, raio, texto)) cout << texto;
    else cout << simulador.getErro() << "\n";
}

void mostraResultado(Simulador &simulador, bool criou) {
    if (!criou) {
        cout << simulador.getErro() << "\n"; // a fábrica não foi criada
        return;
    }
    simulador.mostra();
    consulta(simulador, Coordenada(CENTRO_LINHA, CENTRO_COLUNA), RAIO);
}

int main() {
    Simulador simulador;

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
        Simulador doFicheiro;
        mostraResultado(doFicheiro, doFicheiro.carregaFabrica(MAPAS[i]));
    }

    cout << "\n--- Fim ---\n";
    simulador.fim();
    if (simulador.terminou()) cout << "Programa terminado\n";
    return 0;
}
