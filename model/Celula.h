#ifndef CELULA_H
#define CELULA_H
#include <string>

// Tipos de terreno que uma célula pode ter
enum TipoTerreno { Solo, Cratera, Ferro, Silicio, Gelo };

// Terreno de uma célula (depósito -> quanto ainda tem)
class Celula {
    TipoTerreno tipo;
    int quantidade;  // só para os depósitos
public:
    Celula();

    static bool tipoDeposito(TipoTerreno t);
    // conversão do caractere do mapa ('.', '#', '%', '$' ou '~'); false -> outro
    static bool converteSimbolo(char simbolo, TipoTerreno& resultado);

    bool definirTerreno(TipoTerreno novoTipo, int novaQuantidade = 0);
    TipoTerreno getTipo() const;
    int getQuantidade() const;
    char getSimbolo() const;        // caractere que se desenha no ecrã para este terreno
    char getMateriaPrima() const;   // 'f', 's' ou 'g' se for depósito, senão ' '
    bool retiraUnidade();           // tira 1 unidade ao depósito; se acabar, passa a solo
    std::string obterDescricao() const;
};
#endif
