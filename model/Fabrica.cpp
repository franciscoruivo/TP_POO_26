#include "Fabrica.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Random.h"
#include "maquinas/Perfuradora.h"
#include "maquinas/Transportador.h"
#include "maquinas/Refinaria.h"
#include "maquinas/Oficina.h"
#include "maquinas/Silo.h"
#include "maquinas/Lancador.h"
using namespace std;

int quantidadeAleatoria() {
    return Random::getRandom(Settings::deposito_quantidade_min,
                             Settings::deposito_quantidade_max);
}

// ficheiros escritos no Windows podem terminar as linhas com \r\n
void tiraRetorno(string& linha) {
    if (!linha.empty() && linha[linha.length() - 1] == '\r')
        linha = linha.substr(0, linha.length() - 1);
}

bool Fabrica::dimensoesValidas(int nl, int nc) {
    int especiais = Settings::fabrica_num_crateras + Settings::fabrica_num_depositos_ferro
                  + Settings::fabrica_num_depositos_silicio + Settings::fabrica_num_depositos_gelo;
    return nl >= 1 && nl <= Settings::fabrica_max_linhas
        && nc >= 1 && nc <= Settings::fabrica_max_colunas
        && nl * nc > especiais;  // porque tem de sobrar solo livre, assim o sorteio termina
}

Fabrica::Fabrica(int nl, int nc)
    : linhas(nl), colunas(nc),
      creditos(Settings::fabrica_creditos_iniciais), instante(0),
      numMaquinas(0), numEngenheiros(0), numEventos(0) {
    if (!dimensoesValidas(nl, nc)) throw invalid_argument("Dimensoes invalidas");  // construtor não devolve valor -> usa execução
    inicia();
    colocaAleatorios('#', Settings::fabrica_num_crateras);
    colocaAleatorios('%', Settings::fabrica_num_depositos_ferro);
    colocaAleatorios('$', Settings::fabrica_num_depositos_silicio);
    colocaAleatorios('~', Settings::fabrica_num_depositos_gelo);
}

Fabrica::Fabrica(const string& nomeFicheiro)
    : linhas(0), colunas(0),
      creditos(Settings::fabrica_creditos_iniciais), instante(0),
      numMaquinas(0), numEngenheiros(0), numEventos(0) {
    inicia();
    ifstream ficheiro(nomeFicheiro);
    if (!ficheiro.is_open()) throw invalid_argument("Ficheiro inexistente");

    string linha;
    if (!getline(ficheiro, linha)) throw invalid_argument("Ficheiro vazio");

    int nl = 0, nc = 0;
    string sobra;
    istringstream primeira(linha);
    if (!(primeira >> nl >> nc) || (primeira >> sobra))
        throw invalid_argument("Primeira linha invalida (esperado: linhas colunas)");
    if (nl < 1 || nl > Settings::fabrica_max_linhas || nc < 1 || nc > Settings::fabrica_max_colunas)
        throw invalid_argument("Dimensoes do mapa fora dos limites");

    for (int l = 0; l < nl; l++) {
        if (!getline(ficheiro, linha)) throw invalid_argument("Faltam linhas no mapa");
        tiraRetorno(linha);
        int tamanho = linha.length();
        if (tamanho != nc) throw invalid_argument("Linha do mapa com tamanho errado");
        for (int c = 0; c < nc; c++) {
            char tipo = linha[c];
            int quantidade = 0;
            if (Celula::tipoDeposito(tipo)) quantidade = quantidadeAleatoria();
            if (!grelha[l][c].definirTerreno(tipo, quantidade))
                throw invalid_argument("Caractere invalido no mapa");
        }
    }

    while (getline(ficheiro, linha)) {  // depois do mapa, só linhas vazias
        tiraRetorno(linha);
        if (!linha.empty()) throw invalid_argument("Linhas a mais no mapa");
    }

    // Depois de validar -> Guarda as dimensões
    linhas = nl;
    colunas = nc;
}

void Fabrica::inicia() {
    for (int l = 0; l < Settings::fabrica_max_linhas; l++)
        for (int c = 0; c < Settings::fabrica_max_colunas; c++)
            maquinas[l][c] = nullptr;
    for (int i = 0; i < 3; i++)
        enviados[i] = 0;
}

Fabrica::~Fabrica() {
    for (int l = 0; l < Settings::fabrica_max_linhas; l++)
        for (int c = 0; c < Settings::fabrica_max_colunas; c++)
            delete maquinas[l][c];
}

void Fabrica::colocaAleatorios(char tipo, int quantos) {
    int colocados = 0;
    while (colocados < quantos) {
        int l = Random::getRandom(linhas - 1);  // inclui o máximo
        int c = Random::getRandom(colunas - 1);
        if (grelha[l][c].getTipo() == '.') {  // só se ainda for solo
            int quantidade = 0;
            if (Celula::tipoDeposito(tipo)) {
                quantidade = quantidadeAleatoria();
            }
            grelha[l][c].definirTerreno(tipo, quantidade);
            colocados++;
        }
    }
}

bool Fabrica::coordenadaValida(const Coordenada& c) const {
    return c.getLinha() >= 0 && c.getLinha() < linhas
        && c.getColuna() >= 0 && c.getColuna() < colunas;
}

const Celula& Fabrica::getPosicao(const Coordenada& c) const {
    if (!coordenadaValida(c)) throw out_of_range("Celula fora da fabrica"); // Simulador valida antes -> protege contra erros
    return grelha[c.getLinha()][c.getColuna()];
}

char Fabrica::getSimboloPosicao(const Coordenada& c) const {
    Maquina* m = maquinas[c.getLinha()][c.getColuna()];
    if (m != nullptr) return m->getSimbolo();
    char tipo = getPosicao(c).getTipo();
    if (tipo == '.') return ' ';  // solo desenha-se vazio
    return tipo;
}

Maquina* Fabrica::criaMaquina(char tipo, char dir) const {
    if (tipo == 'p') return new Perfuradora(dir);
    if (tipo == 't') return new Transportador(dir);
    if (tipo == 'r') return new Refinaria(dir);
    if (tipo == 'o') return new Oficina(dir);
    if (tipo == 's') return new Silo(dir);
    if (tipo == 'l') return new Lancador(dir);
    return nullptr;
}

bool Fabrica::compraMaquina(char tipo, const Coordenada& pos, char dir, string& erro) {
    if (!coordenadaValida(pos)) {
        erro = "Posicao fora da fabrica";
        return false;
    }
    if (getPosicao(pos).getTipo() == '#') {
        erro = "Nao se pode colocar uma maquina numa cratera";
        return false;
    }
    if (maquinas[pos.getLinha()][pos.getColuna()] != nullptr) {
        erro = "Ja existe uma maquina nessa posicao";
        return false;
    }
    Maquina* m = criaMaquina(tipo, dir);
    if (m == nullptr) {
        erro = "Tipo de maquina invalido";
        return false;
    }
    if (m->getCusto() > creditos) {
        delete m;  // não há créditos
        erro = "Creditos insuficientes";
        return false;
    }
    creditos -= m->getCusto();
    maquinas[pos.getLinha()][pos.getColuna()] = m;
    numMaquinas++;
    return true;
}

bool Fabrica::vendeMaquina(const Coordenada& pos, string& erro) {
    if (!coordenadaValida(pos)) {
        erro = "Posicao fora da fabrica";
        return false;
    }
    Maquina* m = maquinas[pos.getLinha()][pos.getColuna()];
    if (m == nullptr) {
        erro = "Nao existe nenhuma maquina nessa posicao";
        return false;
    }
    creditos += m->getCusto() * Settings::maquina_percentagem_venda / 100;
    delete m;  // os itens que lá estiverem perdem-se
    maquinas[pos.getLinha()][pos.getColuna()] = nullptr;
    numMaquinas--;
    return true;
}

bool Fabrica::rodaMaquina(const Coordenada& pos, char dir, string& erro) {
    if (!coordenadaValida(pos)) {
        erro = "Posicao fora da fabrica";
        return false;
    }
    Maquina* m = maquinas[pos.getLinha()][pos.getColuna()];
    if (m == nullptr) {
        erro = "Nao existe nenhuma maquina nessa posicao";
        return false;
    }
    m->setDirecao(dir);
    return true;
}

Maquina* Fabrica::vizinha(int l, int c, char dir) const {
    if (dir == 'c') l--;
    else if (dir == 'b') l++;
    else if (dir == 'e') c--;
    else if (dir == 'd') c++;
    if (!coordenadaValida(Coordenada(l, c))) return nullptr;
    return maquinas[l][c];
}

void Fabrica::registaEvento(const string& texto) {
    if (numEventos < maxEventos) {  // o que não cabe no painel é ignorado
        eventos[numEventos] = texto;
        numEventos++;
    }
}

void Fabrica::registaEnvio(const Item& item) {
    creditos += item.getValor();
    ostringstream out;
    out << "enviado " << item.getSimbolo() << " (+" << item.getValor() << " creditos)";
    registaEvento(out.str());
    if (item.getSimbolo() == 'f') enviados[0]++;
    else if (item.getSimbolo() == 's') enviados[1]++;
    else if (item.getSimbolo() == 'g') enviados[2]++;
}

void Fabrica::avancaInstante() {
    instante++;
    numEventos = 0;

    for (int l = 0; l < linhas; l++)
        for (int c = 0; c < colunas; c++)
            if (maquinas[l][c] != nullptr) maquinas[l][c]->iniciaInstante();

    for (int l = 0; l < linhas; l++) {
        for (int c = 0; c < colunas; c++) {
            Maquina* m = maquinas[l][c];
            if (m == nullptr) continue;
            bool eraDeposito = Celula::tipoDeposito(grelha[l][c].getTipo());
            m->atua(*this, grelha[l][c], vizinha(l, c, m->getDirecao()));
            if (eraDeposito && grelha[l][c].getTipo() == '.')
                registaEvento("deposito esgotado em " + Coordenada(l, c).obterTexto());
        }
    }
}

string Fabrica::obterEstado() const {
    ostringstream out;
    out << "Instante: " << instante << "\n";
    out << "Creditos: " << creditos << "\n";
    out << "Maquinas (" << numMaquinas << "):\n";
    for (int l = 0; l < linhas; l++)
        for (int c = 0; c < colunas; c++)
            if (maquinas[l][c] != nullptr)
                out << "  " << Coordenada(l, c).obterTexto() << ": " << maquinas[l][c]->getAsString() << "\n";
    out << "Engenheiros: " << numEngenheiros << "\n";
    out << "Enviados para a Terra: minerio de ferro " << enviados[0]
        << ", silicio bruto " << enviados[1] << ", gelo " << enviados[2] << "\n";
    return out.str();
}

string Fabrica::obterDescricaoPosicao(const Coordenada& centro, int raio) const {
    ostringstream out;
    int maximo = linhas;
    if (colunas > maximo) maximo = colunas;
    if (raio < 0) raio = 0;
    if (raio > maximo) raio = maximo; // mais do que isto, já "apanha" tudo

    for (int l = centro.getLinha() - raio; l <= centro.getLinha() + raio; l++) {
        for (int c = centro.getColuna() - raio; c <= centro.getColuna() + raio; c++) {
            Coordenada atual(l, c);
            if (!coordenadaValida(atual)) continue;  // o que sai da fábrica é cortado
            out << atual.obterTexto() << ": " << getPosicao(atual).obterDescricao();
            if (maquinas[l][c] != nullptr)
                out << "; " << maquinas[l][c]->getAsString();
            out << "\n";
        }
    }
    return out.str();
}
