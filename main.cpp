#include <cstdlib>
#include <ctime>
#include "Fabrica.h"
#include "VistaFabrica.h"

int main() {
    srand((unsigned)time(nullptr));
    if (!Fabrica::dimensoesValidas(12, 20)) return 1;
    Fabrica f(12, 20);
    int linhasEcra = (f.getLinhas() + 3 > 8) ? f.getLinhas() + 3 : 8;
    Ecra ecra(linhasEcra, f.getColunas() + 4 + 34);
    VistaFabrica vista;
    vista.desenha(f, ecra);
    ecra.mostra();
}