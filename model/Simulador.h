#ifndef SIMULADOR_H
#define SIMULADOR_H
#include <string>
#include "Coordenada.h"
#include "Fabrica.h"

// Guarda os dados e faz o que os comandos pedem. Nunca escreve na consola
class Simulador {
    Fabrica* fabrica; // nullptr enquanto a fábrica não for criada
    bool terminar; // para saber quando sair
    std::string erro; // motivo da última falha
public:
    Simulador();
    ~Simulador();
    Simulador(const Simulador&) = delete;
    Simulador& operator=(const Simulador&) = delete;

    bool criaFabrica(int nl, int nc);
    bool carregaFabrica(const std::string& ficheiro);
    bool consultaPosicao(const Coordenada& centro, int raio, std::string& texto);
    bool compraMaquina(char tipo, const Coordenada& pos, char dir);
    bool vendeMaquina(const Coordenada& pos);
    bool rodaMaquina(const Coordenada& pos, char dir);
    bool avancaInstante();
    bool obterEstado(std::string& texto);
    void fim();

    bool terminou() const;
    bool temFabrica() const;
    const std::string& getErro() const;
    const Fabrica& getFabrica() const;
};
#endif
