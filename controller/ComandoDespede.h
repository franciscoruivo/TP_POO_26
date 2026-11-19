#ifndef COMANDODESPEDE_H
#define COMANDODESPEDE_H
#include "Comando.h"

// Despede um engenheiro
class ComandoDespede : public Comando {
    int id;
public:
    ComandoDespede(const std::string& l);
    bool valida() override;
    void executa(Simulador& s, Interface& ui) override;
    std::string sintaxe() const override;
    std::string ajuda() const override;
};
#endif
