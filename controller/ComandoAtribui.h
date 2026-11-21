#ifndef COMANDOATRIBUI_H
#define COMANDOATRIBUI_H
#include "Comando.h"

// Põe um engenheiro numa máquina
class ComandoAtribui : public Comando {
    int id;
    Coordenada pos;
public:
    ComandoAtribui(const std::string& l);
    bool valida() override;
    void executa(Simulador& s, Interface& ui) override;
    std::string sintaxe() const override;
    std::string ajuda() const override;
};
#endif
