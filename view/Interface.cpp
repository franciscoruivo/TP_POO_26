#include "Interface.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Comando.h"
#include "Ecra.h"
using namespace std;

Interface::Interface(Simulador& sim) : simulador(sim), vista(), leitor(), aExecutarFicheiro(false) {}

void Interface::mostraFabrica() const {
    if (!simulador.temFabrica()) return;
    const Fabrica& f = simulador.getFabrica();
    Ecra ecra(vista.linhasEcra(f), vista.colunasEcra(f));
    vista.desenha(f, ecra);
    ecra.mostra();
}

void Interface::mostraTexto(const string& texto) const {
    cout << texto;
    if (texto.empty() || texto[texto.length() - 1] != '\n') cout << "\n";
}

void Interface::mostraErro(const string& erro) const {
    cout << "Erro: " << erro << "\n";
}

void Interface::processaLinha(const string& linha) {
    istringstream in(linha);
    string palavra;
    if (!(in >> palavra)) return;  // linha vazia

    Comando* comando = leitor.cria(linha);
    if (comando == nullptr) {
        mostraErro("Comando desconhecido (escreva ajuda para ver os comandos)");
        return;
    }
    if (comando->valida())
        comando->executa(simulador, *this);
    else
        mostraErro(comando->getErro());
    delete comando;
}

bool Interface::executaFicheiro(const string& nome) {
    ifstream ficheiro(nome);
    if (!ficheiro.is_open()) return false;
    if (aExecutarFicheiro) {
        mostraErro("Nao pode usar executa dentro de um ficheiro de comandos");
        return true;
    }

    aExecutarFicheiro = true;
    string linha;
    while (!simulador.terminou() && getline(ficheiro, linha)) {
        cout << "> " << linha << "\n";
        processaLinha(linha);
    }
    aExecutarFicheiro = false;
    return true;
}

void Interface::executa() {
    cout << "Simulador de fabrica em Marte (escreva ajuda para ver os comandos)\n";
    string linha;
    while (!simulador.terminou()) {
        cout << "> ";
        if (!getline(cin, linha)) {  // acabou a entrada
            simulador.fim();
            cout << "\n";
        } else {
            processaLinha(linha);
        }
    }
    cout << "Programa terminado\n";
}
