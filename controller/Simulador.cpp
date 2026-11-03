#include "Simulador.h"
#include <sstream>
#include <stdexcept>
#include "Ecra.h"
#include "VistaFabrica.h"
using namespace std;

Simulador::Simulador() : fabrica(), criada(false), erro() {
}

bool Simulador::criaFabrica(int _linhas, int _colunas) {
    if (criada) {
        erro = "A fabrica ja foi criada";
        return false;
    }
    try {
        fabrica = Fabrica(_linhas, _colunas);
    } catch (const invalid_argument &e) {
        erro = e.what();
        return false;
    }
    criada = true;
    return true;
}

bool Simulador::carregaFabrica(const string &_ficheiro) {
    if (criada) {
        erro = "A fabrica ja foi criada";
        return false;
    }
    try {
        fabrica = Fabrica(_ficheiro);
    } catch (const invalid_argument &e) {
        erro = e.what();
        return false;
    }
    criada = true;
    return true;
}

void Simulador::mostra() const {
    if (!criada) return;
    VistaFabrica vista;
    Ecra ecra(vista.linhasEcra(fabrica), vista.colunasEcra(fabrica));
    vista.desenha(fabrica, ecra);
    ecra.mostra();
}

bool Simulador::coordenadaValida(const Coordenada &_c) const {
    return criada && fabrica.coordenadaValida(_c);
}

string Simulador::lposicao(const Coordenada &_centro, int _raio) const {
    ostringstream out;
    if (!criada) return out.str();

    int maximo = fabrica.getLinhas();
    if (fabrica.getColunas() > maximo) maximo = fabrica.getColunas();
    if (_raio > maximo) _raio = maximo; // mais do que isto já cobre tudo

    for (int l = _centro.getLinha() - _raio; l <= _centro.getLinha() + _raio; l++) {
        for (int c = _centro.getColuna() - _raio; c <= _centro.getColuna() + _raio; c++) {
            Coordenada atual(l, c);
            if (fabrica.coordenadaValida(atual)) // o que sai da fábrica é cortado
                out << textoCoordenada(atual) << ": "
                        << fabrica.getPosicao(atual).obterDescricao() << "\n";
        }
    }
    return out.str();
}

bool Simulador::converteCoordenada(const string &_texto, Coordenada &_resultado) {
    if (_texto.length() != 2) return false;
    char l = _texto[0];
    char c = _texto[1];
    if (l < 'a' || l > 'z' || c < 'a' || c > 'z') return false;
    _resultado = Coordenada(l - 'a', c - 'a');
    return true;
}

string Simulador::textoCoordenada(const Coordenada &_c) {
    string texto;
    char l = 'a' + _c.getLinha();
    char c = 'a' + _c.getColuna();
    texto += l;
    texto += c;
    return texto;
}
