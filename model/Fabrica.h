#ifndef FABRICA_H
#define FABRICA_H
#include <string>
#include "Coordenada.h"
#include "Celula.h"
#include "Item.h"
#include "Maquina.h"
#include "Settings.h"

class Fabrica {
    static const int maxEventos = 4;  // quantas linhas de eventos cabem no painel ("no último instante")

    Celula grelha[Settings::fabrica_max_linhas][Settings::fabrica_max_colunas];
    Maquina* maquinas[Settings::fabrica_max_linhas][Settings::fabrica_max_colunas];  // nullptr = nã há máquina
    int linhas, colunas;
    int creditos, instante;
    int numMaquinas, numEngenheiros;
    std::string eventos[maxEventos];
    int numEventos;
    int enviados[3];  // itens enviados para a Terra: ferro, silício, gelo

    void inicia();
    void colocaAleatorios(TipoTerreno tipo, int quantos);
    Maquina* criaMaquina(char tipo, char dir) const;
    Maquina* vizinha(int l, int c, char dir) const;  // máquina vizinha nessa direção (ou nullptr)
public:
    Fabrica(int nl, int nc); // fábrica aleatória
    Fabrica(const std::string& nomeFicheiro);  // fábrica feita a partir de um mapa (ficheiro)
    ~Fabrica();
    Fabrica(const Fabrica&) = delete;
    Fabrica& operator=(const Fabrica&) = delete;

    static bool dimensoesValidas(int nl, int nc);

    int getLinhas() const;
    int getColunas() const;
    int getCreditos() const;
    int getInstante() const;
    int getNumMaquinas() const;
    int getNumEngenheiros() const;
    int getNumEventos() const;
    const std::string& getEvento(int i) const;

    bool coordenadaValida(const Coordenada& c) const;
    const Celula& getPosicao(const Coordenada& c) const;   // "out_of_range" -> posição inválida
    char getSimboloPosicao(const Coordenada& c) const;     // símbolo da máquina, ou então do terreno

    // operações com máquinas (dão false e preenchem o erro se não der)
    bool compraMaquina(char tipo, const Coordenada& pos, char dir, std::string& erro);
    bool vendeMaquina(const Coordenada& pos, std::string& erro);
    bool rodaMaquina(const Coordenada& pos, char dir, std::string& erro);

    void avancaInstante();

    // funções que as máquinas usam
    void registaEvento(const std::string& texto);
    void registaEnvio(const Item& item);  // soma os créditos do item

    std::string obterEstado() const;
    // descrição do terreno (e da máquina) do centro e das posições à volta
    std::string obterDescricaoPosicao(const Coordenada& centro, int raio) const;
};
#endif
