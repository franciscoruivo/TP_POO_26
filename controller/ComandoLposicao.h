#ifndef COMANDOLPOSICAO_H
#define COMANDOLPOSICAO_H
#include "Comando.h"

// Mostra o que há numa posição
class ComandoLposicao : public Comando {
    Coordenada pos;
    int raio;
public:
    ComandoLposicao(const std::string& l);
    bool valida() override;
    void executa(Simulador& s, Interface& ui) override;
    std::string sintaxe() const override;
    std::string ajuda() const override;
};
#endif
