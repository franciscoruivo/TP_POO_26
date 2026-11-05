#ifndef SIMULADOR_H
#define SIMULADOR_H
#include <string>
#include "Coordenada.h"
#include "Fabrica.h"

// Dados e funcionalidade da simulação. Não interage com o utilizador:
// quem fala com o utilizador é a Interface. No checkpoint 2, será chamado pelos comandos.
class Simulador {
    Fabrica fabrica;                   // vazia até ser criada
    bool criada;
    bool terminar;                     // condição de saída
    std::string erro;                  // motivo da última falha
public:
    Simulador();

    bool criaFabrica(int _linhas, int _colunas);
    bool carregaFabrica(const std::string& _ficheiro);
    bool consultaPosicao(const Coordenada& _centro, int _raio, std::string& _texto);
    void fim();

    bool terminou() const { return terminar; }
    bool temFabrica() const { return criada; }
    const std::string& getErro() const { return erro; }
    const Fabrica& getFabrica() const { return fabrica; }
};
#endif