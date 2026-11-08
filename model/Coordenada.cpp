#include "Coordenada.h"
using namespace std;

Coordenada::Coordenada(int l, int c) : linha(l), coluna(c) {}

string Coordenada::obterTexto() const {
    string texto;
    char l = 'a' + linha; // a + 2 = c
    char c = 'a' + coluna;
    texto += l;
    texto += c;
    return texto;
}