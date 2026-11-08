#ifndef INTERFACE_H
#define INTERFACE_H
#include "Simulador.h"
#include "VistaFabrica.h"

// Comunica com o utilizador
class Interface {
    Simulador& simulador;
    VistaFabrica vista;

    void mostraFabrica(const Simulador& s) const;
    void mostraTipoTerreno(Simulador& s, const Coordenada& centro, int raio) const;
    void mostraFabricaETerreno(Simulador& s, bool criou) const;
    void demonstraMeta1();
public:
    Interface(Simulador& sim);
    void executa();
};
#endif