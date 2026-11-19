#include "MateriaPrima.h"
#include "Settings.h"
using namespace std;

string MateriaPrima::nomeDe(char s) {
    if (s == 'f') return "minerio de ferro";
    if (s == 's') return "silicio bruto";
    return "gelo";
}

int MateriaPrima::valorDe(char s) {
    if (s == 'f') return Settings::valor_minerio_ferro;
    if (s == 's') return Settings::valor_silicio_bruto;
    return Settings::valor_gelo;
}

MateriaPrima::MateriaPrima(char s) : Item(nomeDe(s), s, valorDe(s)) {}

string MateriaPrima::getAsString() const {
    return getNome();
}
