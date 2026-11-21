#ifndef COMANDOESTADO_H
#define COMANDOESTADO_H
#include "Comando.h"

// Mostra como está a fábrica
class ComandoEstado : public Comando {
public:
    ComandoEstado(const std::string& l);
    bool valida() override;
    void executa(Simulador& s, Interface& ui) override;
    std::string sintaxe() const override;
    std::string ajuda() const override;
};
#endif
