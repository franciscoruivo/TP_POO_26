#ifndef INTERFACE_H
#define INTERFACE_H
#include <string>
#include "Simulador.h"
#include "VistaFabrica.h"
#include "LeitorComandos.h"

// Comunica com o utilizador: lê as frases, mostra a fábrica e os textos
class Interface {
    Simulador& simulador;
    VistaFabrica vista;
    LeitorComandos leitor;
    bool aExecutarFicheiro;  // para não aceitar executa dentro de um ficheiro de comandos
public:
    Interface(Simulador& sim);

    void executa();  // ciclo principal: lê comandos do teclado até ao fim
    void processaLinha(const std::string& linha);  // igual para o teclado e para os ficheiros
    bool executaFicheiro(const std::string& nome);  // false se não conseguir abrir o ficheiro

    void mostraFabrica() const;
    void mostraTexto(const std::string& texto) const;
    void mostraErro(const std::string& erro) const;
};
#endif
