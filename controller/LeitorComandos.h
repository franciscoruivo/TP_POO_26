#ifndef LEITORCOMANDOS_H
#define LEITORCOMANDOS_H
#include <string>

class Comando;

// Cria o comando certo a partir da primeira palavra da frase
class LeitorComandos {
    Comando* criaPorNome(const std::string& nome, const std::string& linha) const;
public:
    static const int numComandos = 17;

    Comando* cria(const std::string& linha) const;  // nullptr se não for um comando
    Comando* criaPorIndice(int i) const;            // para listar os comandos (ajuda)
};
#endif
