#include "Interface.h"
#include <iostream>
#include <string>
#include "Coordenada.h"
#include "Ecra.h"
using namespace std;


// Loop de atualização do display visual -> CK2: recebe comandos

// Valores da demonstração
const int linhasDemo = 12;
const int colunasDemo = 20;
const int centroLinha = 2; // posição "ce"
const int centroColuna = 4;
const int raioDemo = 1;
const int numMapas = 4;
const string mapas[numMapas] = {"mapa1.txt", "erro1.txt", "erro2.txt", "naoexiste.txt"};

Interface::Interface(Simulador& sim) : simulador(sim), vista() {}

void Interface::mostraFabrica(const Simulador& s) const {
    if (!s.temFabrica()) return;
    const Fabrica& f = s.getFabrica();
    Ecra ecra(vista.linhasEcra(f), vista.colunasEcra(f));
    vista.desenha(f, ecra);
    ecra.mostra();
}

void Interface::mostraTipoTerreno(Simulador& s, const Coordenada& centro, int raio) const {
    string texto;
    if (s.consultaPosicao(centro, raio, texto)) cout << texto;
    else cout << s.getErro() << "\n";
}

void Interface::mostraFabricaETerreno(Simulador& s, bool criou) const {
    if (!criou) {
        cout << s.getErro() << "\n";  // a fábrica não foi criada
        return;
    }
    mostraFabrica(s);
    mostraTipoTerreno(s, Coordenada(centroLinha, centroColuna), raioDemo);
}

void Interface::demonstraMeta1() {
    cout << "--- Fabrica aleatoria ---\n";
    mostraFabricaETerreno(simulador, simulador.criaFabrica(linhasDemo, colunasDemo));

    cout << "\n--- Consulta fora da fabrica ---\n";
    mostraTipoTerreno(simulador, Coordenada(30, 30), 0);

    cout << "\n--- Segunda criacao (recusada) ---\n";
    mostraFabricaETerreno(simulador, simulador.criaFabrica(linhasDemo, colunasDemo));

    cout << "\n--- Dimensoes invalidas ---\n";
    Simulador pequeno;
    mostraFabricaETerreno(pequeno, pequeno.criaFabrica(3, 3));

    for (int i = 0; i < numMapas; i++) {
        cout << "\n--- Fabrica carregada de " << mapas[i] << " ---\n";
        Simulador doFicheiro; // cada mapa vai precisar de um simulador novo
        mostraFabricaETerreno(doFicheiro, doFicheiro.carregaFabrica(mapas[i]));
    }
}

void Interface::executa() {
    // Faz a demonstração e pede o fim
    while (!simulador.terminou()) {
        demonstraMeta1();
        cout << "\n--- Fim ---\n";
        simulador.fim();
    }
    cout << "Programa terminado\n";
}