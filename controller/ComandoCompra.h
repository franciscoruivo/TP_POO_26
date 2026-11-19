#ifndef COMANDOCOMPRA_H
#define COMANDOCOMPRA_H
#include "Comando.h"

// Compra uma máquina
class ComandoCompra : public Comando {
    char tipo;
    Coordenada pos;
    char dir;
public:
    ComandoCompra(const std::string& l);
    bool valida() override;
    void executa(Simulador& s, Interface& ui) override;
    std::string sintaxe() const override;
    std::string ajuda() const override;
};
#endif
