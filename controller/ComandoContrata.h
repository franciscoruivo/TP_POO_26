#ifndef COMANDOCONTRATA_H
#define COMANDOCONTRATA_H
#include "Comando.h"

// Contrata um engenheiro
class ComandoContrata : public Comando {
    std::string nome;
public:
    ComandoContrata(const std::string& l);
    bool valida() override;
    void executa(Simulador& s, Interface& ui) override;
    std::string sintaxe() const override;
    std::string ajuda() const override;
};
#endif
