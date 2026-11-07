#ifndef SIMULADOR_H
#define SIMULADOR_H
#include <string>
#include "Coordenada.h"
#include "Fabrica.h"

// Guarda os dados
class Simulador {
    Fabrica fabrica; // vazia até ser criada
    bool criada;
    bool terminar; // condição de saída
    std::string erro; // descrição da última falha
public:
    Simulador();

    bool criaFabrica(int nl, int nc);
    bool carregaFabrica(const std::string& ficheiro);
    bool consultaPosicao(const Coordenada& centro, int raio, std::string& texto);
    void fim();

    bool terminou() const { return terminar; }
    bool temFabrica() const { return criada; }
    const std::string& getErro() const { return erro; }
    const Fabrica& getFabrica() const { return fabrica; }
};
#endif