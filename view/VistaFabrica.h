#ifndef VISTAFABRICA_H
#define VISTAFABRICA_H
#include <string>
#include "Ecra.h"
#include "Fabrica.h"

class VistaFabrica {
    static const int alturaPainel = 12;
    static const int larguraPainel = 34;

    std::string linhaPainel(const std::string& rotulo, int valor) const;
public:
    int linhasEcra(const Fabrica& f) const;  // tamanho de ecrã preciso
    int colunasEcra(const Fabrica& f) const;
    void desenha(const Fabrica& f, Ecra& ecra) const;
};
#endif