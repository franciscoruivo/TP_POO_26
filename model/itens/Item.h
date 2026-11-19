#ifndef ITEM_H
#define ITEM_H
#include <string>

// Qualquer coisa que circula pela fábrica. Está sempre dentro de uma máquina.
class Item {
    std::string nome;
    char simbolo;
    int valor;  // em créditos
public:
    Item(const std::string& n, char s, int v) : nome(n), simbolo(s), valor(v) {}
    virtual ~Item() {}
    const std::string& getNome() const { return nome; }
    char getSimbolo() const { return simbolo; }
    int getValor() const { return valor; }
    virtual std::string getAsString() const = 0;  // abstrata: só existem itens concretos
};
#endif
