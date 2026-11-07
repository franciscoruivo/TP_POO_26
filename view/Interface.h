#ifndef INTERFACE_H
#define INTERFACE_H
#include "Simulador.h"
#include "VistaFabrica.h"

// Comunica com o utilizador
class Interface {
    Simulador& simulador;
    VistaFabrica vista;

    void mostra(const Simulador& s) const;
    void consulta(Simulador& s, const Coordenada& centro, int raio) const;
    void mostraResultado(Simulador& s, bool criou) const;
    void demonstra();
public:
    Interface(Simulador& sim);
    void executa();
};
#endif