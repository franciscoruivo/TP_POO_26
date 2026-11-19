#ifndef COMANDOEXECUTA_H
#define COMANDOEXECUTA_H
#include "Comando.h"

// Executa os comandos de um ficheiro
class ComandoExecuta : public Comando {
    std::string nomeFicheiro;
public:
    ComandoExecuta(const std::string& l);
    bool valida() override;
    void executa(Simulador& s, Interface& ui) override;
    std::string sintaxe() const override;
    std::string ajuda() const override;
};
#endif
