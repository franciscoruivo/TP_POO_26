#ifndef COMANDOFIM_H
#define COMANDOFIM_H
#include "Comando.h"

// Termina o programa
class ComandoFim : public Comando {
public:
    ComandoFim(const std::string& l);
    bool valida() override;
    void executa(Simulador& s, Interface& ui) override;
    std::string sintaxe() const override;
    std::string ajuda() const override;
};
#endif
