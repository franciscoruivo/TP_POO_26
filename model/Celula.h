#ifndef CELULA_H
#define CELULA_H
#include <string>

// Tipos de terreno de uma célula
enum TipoTerreno { Solo, Cratera, Ferro, Silicio, Gelo };

// Terreno de uma célula e, nos depósitos, a quantidade que ainda tem
class Celula {
    TipoTerreno tipo;
    int quantidade;  // só nos depósitos
public:
    Celula();

    static bool tipoDeposito(TipoTerreno t);
    // converte o caractere do mapa ('.', '#', '%', '$' ou '~'); devolve false se for outro
    static bool converteSimbolo(char simbolo, TipoTerreno& resultado);

    bool definirTerreno(TipoTerreno novoTipo, int novaQuantidade = 0);
    TipoTerreno getTipo() const;
    int getQuantidade() const;
    char getSimbolo() const;        // caractere usado para desenhar o terreno
    char getMateriaPrima() const;   // 'f', 's' ou 'g' se for depósito, senão ' '
    bool retiraUnidade();           // tira 1 unidade ao depósito; se esgotar passa a solo
    std::string obterDescricao() const;
};
#endif
