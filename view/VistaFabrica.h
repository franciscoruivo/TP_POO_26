// VistaFabrica.h
#ifndef VISTAFABRICA_H
#define VISTAFABRICA_H
#include "Ecra.h"
#include "Fabrica.h"

class VistaFabrica {
public:
    void desenha(const Fabrica& f, Ecra& ecra) const;
};
#endif