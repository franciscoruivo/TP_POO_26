#ifndef COMANDOMELHORA_H
#define COMANDOMELHORA_H
#include "Comando.h"

// Melhora uma máquina
class ComandoMelhora : public Comando {
    Coordenada pos;
public:
    ComandoMelhora(const std::string& l);
    bool valida() override;
    void executa(Simulador& s, Interface& ui) override;
    std::string sintaxe() const override;
    std::string ajuda() const override;
};
#endif
