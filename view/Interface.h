#ifndef INTERFACE_H
#define INTERFACE_H
#include "Simulador.h"
#include "VistaFabrica.h"

// Interface com o utilizador: é a única classe que escreve na consola (através do Ecra).
class Interface {
    Simulador &simulador;
    VistaFabrica vista;

    void mostra(const Simulador &_s) const;

    void consulta(Simulador &_s, const Coordenada &_centro, int _raio) const;

    void mostraResultado(Simulador &_s, bool _criou) const;

    void demonstra();

public:
    Interface(Simulador &_simulador);

    void executa();
};
#endif
