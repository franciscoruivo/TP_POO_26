#include "Interface.h"
#include "Simulador.h"

int main() {
    Simulador simulador;
    Interface ui(simulador);
    ui.executa();
    return 0;
}
