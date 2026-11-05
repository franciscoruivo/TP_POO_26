#include "Coordenada.h"
using namespace std;

Coordenada::Coordenada(int _linha, int _coluna) : linha(_linha), coluna(_coluna) {}

string Coordenada::obterTexto() const {
    string texto;
    char l = 'a' + linha;
    char c = 'a' + coluna;
    texto += l;
    texto += c;
    return texto;
}