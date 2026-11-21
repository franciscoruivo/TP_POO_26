#ifndef COMANDOAJUDA_H
#define COMANDOAJUDA_H
#include "Comando.h"

// Mostra todos os comandos ou a ajuda de um só
class ComandoAjuda : public Comando {
    std::string alvo;
public:
    ComandoAjuda(const std::string& l);
    bool valida() override;
    void executa(Simulador& s, Interface& ui) override;
    std::string sintaxe() const override;
    std::string ajuda() const override;
};
#endif
