#ifndef FABRICA_H
#define FABRICA_H
#include <string>
#include "Coordenada.h"
#include "Celula.h"
#include "itens/Item.h"
#include "maquinas/Maquina.h"
#include "Settings.h"

class Fabrica {
    static const int maxEventos = 4;  // linhas do "no último instante" no painel

    Celula grelha[Settings::fabrica_max_linhas][Settings::fabrica_max_colunas];
    Maquina* maquinas[Settings::fabrica_max_linhas][Settings::fabrica_max_colunas];  // nullptr = sem máquina
    int linhas, colunas;
    int creditos, instante;
    int numMaquinas, numEngenheiros;
    std::string eventos[maxEventos];
    int numEventos;
    int enviados[3];  // itens enviados para a Terra: ferro, silício, gelo

    void inicia();
    void colocaAleatorios(char tipo, int quantos);
    Maquina* criaMaquina(char tipo, char dir) const;
    Maquina* vizinha(int l, int c, char dir) const;  // máquina vizinha nessa direção (ou nullptr)
public:
    Fabrica(int nl, int nc); // aleatória
    Fabrica(const std::string& nomeFicheiro);  // a partir de um mapa
    ~Fabrica();
    Fabrica(const Fabrica&) = delete;
    Fabrica& operator=(const Fabrica&) = delete;

    static bool dimensoesValidas(int nl, int nc);

    int getLinhas() const { return linhas; }
    int getColunas() const { return colunas; }
    int getCreditos() const { return creditos; }
    int getInstante() const { return instante; }
    int getNumMaquinas() const { return numMaquinas; }
    int getNumEngenheiros() const { return numEngenheiros; }
    int getNumEventos() const { return numEventos; }
    const std::string& getEvento(int i) const { return eventos[i]; }

    bool coordenadaValida(const Coordenada& c) const;
    const Celula& getPosicao(const Coordenada& c) const;   // "out_of_range" se inválida
    char getSimboloPosicao(const Coordenada& c) const;     // a máquina, ou então o terreno

    // máquinas (devolvem false e preenchem erro quando não é possível)
    bool compraMaquina(char tipo, const Coordenada& pos, char dir, std::string& erro);
    bool vendeMaquina(const Coordenada& pos, std::string& erro);
    bool rodaMaquina(const Coordenada& pos, char dir, std::string& erro);

    void avancaInstante();

    // usadas pelas máquinas
    void registaEvento(const std::string& texto);
    void registaEnvio(const Item& item);  // soma os créditos do item

    std::string obterEstado() const;
    // descrição do terreno (e da máquina) do centro e das posições à volta
    std::string obterDescricaoPosicao(const Coordenada& centro, int raio) const;
};
#endif
