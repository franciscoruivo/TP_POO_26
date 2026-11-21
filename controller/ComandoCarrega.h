#ifndef COMANDOCARREGA_H
#define COMANDOCARREGA_H
#include "Comando.h"

// Cria a fábrica a partir de um mapa que está num ficheiro
class ComandoCarrega : public Comando {
    std::string nomeFicheiro;
public:
    ComandoCarrega(const std::string& l);
    bool valida() override;
    void executa(Simulador& s, Interface& ui) override;
    std::string sintaxe() const override;
    std::string ajuda() const override;
};
#endif
