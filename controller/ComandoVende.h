#ifndef COMANDOVENDE_H
#define COMANDOVENDE_H
#include "Comando.h"

// Vende uma máquina
class ComandoVende : public Comando {
    Coordenada pos;
public:
    ComandoVende(const std::string& l);
    bool valida() override;
    void executa(Simulador& s, Interface& ui) override;
    std::string sintaxe() const override;
    std::string ajuda() const override;
};
#endif
