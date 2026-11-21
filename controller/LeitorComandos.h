#ifndef LEITORCOMANDOS_H
#define LEITORCOMANDOS_H
#include <string>

class Comando;

// Vê a primeira palavra da frase e cria o comando que lhe corresponde
class LeitorComandos {
    Comando* criaPorNome(const std::string& nome, const std::string& linha) const;
public:
    static const int numComandos = 17;

    Comando* cria(const std::string& linha) const;  // nullptr se a palavra não for nenhum comando
    Comando* criaPorIndice(int i) const;            // serve para a ajuda listar os comandos
};
#endif
