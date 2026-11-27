#ifndef COMANDO_H
#define COMANDO_H
#include <sstream>
#include <string>
#include "Coordenada.h"

class Simulador;
class Interface;

// Classe base de todos os comandos. Cada comando valida os seus parâmetros,
// executa-se e sabe escrever a sua própria ajuda
class Comando {
protected:
    std::string linha;  // o que o utilizador escreveu
    std::string erro;   // mensagem de erro, preenchida pelo valida() quando falha

    // funções para ler parâmetros (se falharem, guardam o erro e devolvem false)
    bool erroUso(const std::string& motivo);
    bool converteInteiro(const std::string& palavra, int& valor);
    bool lePalavra(std::istringstream& in, std::string& palavra);
    bool leInteiro(std::istringstream& in, int& valor);
    bool leCoordenada(std::istringstream& in, Coordenada& pos);
    bool leDirecao(std::istringstream& in, char& dir);
    bool semMaisParametros(std::istringstream& in);
public:
    Comando(const std::string& l);
    virtual ~Comando();

    virtual bool valida() = 0;  // Virtual Pura -> cd cmd verifica sintaxe e parâmetros
    virtual void executa(Simulador& s, Interface& ui) = 0;
    virtual std::string sintaxe() const = 0;  // sintaxe resumida
    virtual std::string ajuda() const = 0;    // ajuda completa do comando

    const std::string& getErro() const;
};
#endif
