#ifndef ITEM_H
#define ITEM_H
#include <string>

// Qualquer coisa que anda pela fábrica. Está sempre dentro de uma máquina
class Item {
    std::string nome;
    char simbolo;
    int valor;  // créditos
public:
    Item(const std::string& n, char s, int v);
    virtual ~Item();
    const std::string& getNome() const;
    char getSimbolo() const;
    int getValor() const;
    virtual std::string getAsString() const = 0;  // abstrata: só se criam itens concretos
};
#endif
