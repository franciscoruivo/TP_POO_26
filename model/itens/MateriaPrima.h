#ifndef MATERIAPRIMA_H
#define MATERIAPRIMA_H
#include <string>
#include "Item.h"

// Minério de ferro ('f'), silício bruto ('s') ou gelo ('g')
class MateriaPrima : public Item {
    static std::string nomeDe(char s);
    static int valorDe(char s);
public:
    MateriaPrima(char s);
    std::string getAsString() const override;
};
#endif
