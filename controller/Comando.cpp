#include "Comando.h"
#include "Maquina.h"
using namespace std;

// Fc auxiliares -> Partilhadas por todos os cmd -> Td têm de as validar
bool Comando::erroUso(const string& motivo) {
    erro = motivo + ". Uso: " + sintaxe();
    return false;
}

bool Comando::converteInteiro(const string& palavra, int& valor) {
    istringstream conv(palavra);
    string sobra;
    return (conv >> valor) && !(conv >> sobra);
}

bool Comando::lePalavra(istringstream& in, string& palavra) {
    if (!(in >> palavra)) return erroUso("Faltam parametros");
    return true;
}

bool Comando::leInteiro(istringstream& in, int& valor) {
    string palavra;
    if (!lePalavra(in, palavra)) return false;
    if (!converteInteiro(palavra, valor)) return erroUso("'" + palavra + "' nao e um numero inteiro");
    return true;
}

bool Comando::leCoordenada(istringstream& in, Coordenada& pos) {
    string palavra;
    if (!lePalavra(in, palavra)) return false;
    if (!Coordenada::converte(palavra, pos))
        return erroUso("'" + palavra + "' nao e uma posicao (duas letras, por exemplo ce)");
    return true;
}

bool Comando::leDirecao(istringstream& in, char& dir) {
    string palavra;
    if (!lePalavra(in, palavra)) return false;
    if (palavra.length() != 1 || !Maquina::direcaoValida(palavra[0]))
        return erroUso("'" + palavra + "' nao e uma direcao (c, b, e ou d)");
    dir = palavra[0];
    return true;
}

bool Comando::semMaisParametros(istringstream& in) {
    string sobra;
    if (in >> sobra) return erroUso("Parametros a mais");
    return true;
}

Comando::Comando(const string& l) : linha(l) {}

Comando::~Comando() {}

const string& Comando::getErro() const {
    return erro;
}
