#ifndef COMANDOAVANCA_H
#define COMANDOAVANCA_H
#include "Comando.h"

// Faz passar o tempo (avança instantes)
class ComandoAvanca : public Comando {
    int n;
public:
    ComandoAvanca(const std::string& l);
    bool valida() override;
    void executa(Simulador& s, Interface& ui) override;
    std::string sintaxe() const override;
    std::string ajuda() const override;
};
#endif
