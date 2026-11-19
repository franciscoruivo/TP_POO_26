#ifndef COMANDOGRAVA_H
#define COMANDOGRAVA_H
#include "Comando.h"

// Guarda uma cópia da fábrica
class ComandoGrava : public Comando {
    std::string nome;
public:
    ComandoGrava(const std::string& l);
    bool valida() override;
    void executa(Simulador& s, Interface& ui) override;
    std::string sintaxe() const override;
    std::string ajuda() const override;
};
#endif
