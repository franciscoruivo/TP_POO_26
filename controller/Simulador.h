#ifndef SIMULADOR_H
#define SIMULADOR_H
#include <memory>
#include <string>
#include "Coordenada.h"
#include "Fabrica.h"

class Simulador {
    std::unique_ptr<Fabrica> fabrica; // só existe depois de fabrica/carrega
    std::string erro;

public:
    bool temFabrica() const { return fabrica != nullptr; }
    const std::string &getErro() const { return erro; }

    bool criaFabrica(int _linhas, int _colunas);

    bool carregaFabrica(const std::string &_ficheiro);

    void mostra() const;

    bool coordenadaValida(const Coordenada &_c) const;

    std::string lposicao(const Coordenada &_centro, int _raio) const;

    static bool converteCoordenada(const std::string &_texto, Coordenada &_resultado);

    static std::string textoCoordenada(const Coordenada &_c);
};
#endif
