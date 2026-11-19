#ifndef COMANDORODA_H
#define COMANDORODA_H
#include "Comando.h"

// Muda a direção de uma máquina
class ComandoRoda : public Comando {
    Coordenada pos;
    char dir;
public:
    ComandoRoda(const std::string& l);
    bool valida() override;
    void executa(Simulador& s, Interface& ui) override;
    std::string sintaxe() const override;
    std::string ajuda() const override;
};
#endif
