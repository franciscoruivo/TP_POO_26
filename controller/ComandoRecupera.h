#ifndef COMANDORECUPERA_H
#define COMANDORECUPERA_H
#include "Comando.h"

// Recupera uma cópia da fábrica
class ComandoRecupera : public Comando {
    std::string nome;
public:
    ComandoRecupera(const std::string& l);
    bool valida() override;
    void executa(Simulador& s, Interface& ui) override;
    std::string sintaxe() const override;
    std::string ajuda() const override;
};
#endif
