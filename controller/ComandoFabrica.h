#ifndef COMANDOFABRICA_H
#define COMANDOFABRICA_H
#include "Comando.h"

// Cria a fábrica com o tamanho indicado
class ComandoFabrica : public Comando {
    int nl;
    int nc;
public:
    ComandoFabrica(const std::string& l);
    bool valida() override;
    void executa(Simulador& s, Interface& ui) override;
    std::string sintaxe() const override;
    std::string ajuda() const override;
};
#endif
