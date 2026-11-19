#ifndef COMANDO_H
#define COMANDO_H
#include <sstream>
#include <string>
#include "Coordenada.h"

class Simulador;
class Interface;

// Classe base de todos os comandos. Cada comando valida os seus parâmetros,
// executa-se e gera a sua própria ajuda.
class Comando {
protected:
    std::string linha;  // a frase escrita pelo utilizador
    std::string erro;   // preenchido por valida() quando falha

    // funções para ler parâmetros (preenchem o erro e devolvem false se falharem)
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

    virtual bool valida() = 0;  // sintaxe e parâmetros
    virtual void executa(Simulador& s, Interface& ui) = 0;
    virtual std::string sintaxe() const = 0;  // sintaxe resumida
    virtual std::string ajuda() const = 0;    // ajuda detalhada

    const std::string& getErro() const;
};
#endif
