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

bool Coordenada::converte(const string& texto, Coordenada& resultado) {
    if (texto.length() != 2) return false;
    char l = texto[0];
    char c = texto[1];
    if (l < 'a' || l > 'z' || c < 'a' || c > 'z') return false;
    resultado = Coordenada(l - 'a', c - 'a');
    return true;
}
