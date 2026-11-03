#ifndef VISTAFABRICA_H
#define VISTAFABRICA_H
#include <string>
#include "Ecra.h"
#include "Fabrica.h"

class VistaFabrica {
    static const int ALTURA_PAINEL = 8;
    static const int LARGURA_PAINEL = 34;

    std::string linhaPainel(const std::string &_rotulo, int _valor) const;

public:
    int linhasEcra(const Fabrica &_f) const; // tamanho de ecrã necessário
    int colunasEcra(const Fabrica &_f) const;

    void desenha(const Fabrica &_f, Ecra &_ecra) const;
};
#endif
