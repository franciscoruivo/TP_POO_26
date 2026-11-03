#include <iostream>
#include <sstream>
#include <string>
#include "Simulador.h"
using namespace std;

// Programa de TESTE do checkpoint 1. Só exercita o que o CP1 pede:
// criação da fábrica (aleatória e por ficheiro), apresentação, lposicao (terreno) e fim.
// NÃO interpreta comandos escritos: isso é o CP2 (hierarquia Comando).

static bool lerLinha(const string &pergunta, string &linha) {
    cout << pergunta;
    return static_cast<bool>(getline(cin, linha));
}

static bool lerInteiro(const string &pergunta, int &valor) {
    string linha;
    if (!lerLinha(pergunta, linha)) return false;
    istringstream entrada(linha);
    string sobra;
    return static_cast<bool>(entrada >> valor) && !(entrada >> sobra); // inteiro e mais nada
}

static void mostraMenu() {
    cout << "\n1 - Criar fabrica aleatoria\n"
            << "2 - Carregar fabrica de ficheiro\n"
            << "3 - Listar posicao (lposicao)\n"
            << "0 - Sair (fim)\n";
}

static void criaAleatoria(Simulador &simulador) {
    if (simulador.temFabrica()) {
        cout << "A fabrica ja foi criada\n";
        return;
    }
    int nl = 0, nc = 0;
    if (!lerInteiro("Linhas: ", nl) || !lerInteiro("Colunas: ", nc)) {
        cout << "Valor invalido\n";
        return;
    }
    if (simulador.criaFabrica(nl, nc)) simulador.mostra();
    else cout << simulador.getErro() << "\n";
}

static void carrega(Simulador &simulador) {
    if (simulador.temFabrica()) {
        cout << "A fabrica ja foi criada\n";
        return;
    }
    string ficheiro;
    if (!lerLinha("Ficheiro: ", ficheiro) || ficheiro.empty()) {
        cout << "Nome invalido\n";
        return;
    }
    if (simulador.carregaFabrica(ficheiro)) simulador.mostra();
    else cout << simulador.getErro() << "\n";
}

static void listaPosicao(const Simulador &simulador) {
    if (!simulador.temFabrica()) {
        cout << "Crie primeiro a fabrica\n";
        return;
    }

    string texto;
    Coordenada centro(0, 0);
    if (!lerLinha("Posicao (ex: ce): ", texto) || !Simulador::converteCoordenada(texto, centro)) {
        cout << "Posicao invalida\n";
        return;
    }
    if (!simulador.coordenadaValida(centro)) {
        cout << "Posicao fora da fabrica\n";
        return;
    }

    string linhaRaio;
    if (!lerLinha("Raio (enter para 0): ", linhaRaio)) return;
    int raio = 0;
    if (!linhaRaio.empty()) {
        istringstream entrada(linhaRaio);
        string sobra;
        if (!(entrada >> raio) || (entrada >> sobra) || raio < 0) {
            cout << "Raio invalido\n";
            return;
        }
    }
    cout << simulador.lposicao(centro, raio);
}

int main() {
    Simulador simulador;
    string opcao;

    while (true) {
        mostraMenu();
        if (!lerLinha("Opcao: ", opcao)) break; // fim de entrada
        if (opcao == "1") criaAleatoria(simulador);
        else if (opcao == "2") carrega(simulador);
        else if (opcao == "3") listaPosicao(simulador);
        else if (opcao == "0") break; // fim: o unique_ptr liberta a fábrica
        else cout << "Opcao invalida\n";
    }
    return 0;
}
