#include <iostream>
#include <unordered_map>
#include <string>
#include <iomanip>
using namespace std;

// Função que retorna o multiplicador com base no prefixo
double getMultiplier(const string& unit) {
    unordered_map<string, double> prefixes = {
        {"", 1},
        {"K", 1e3},
        {"M", 1e6},
        {"G", 1e9},
        {"T", 1e12}
    };
    string prefix = unit.substr(0, unit.length() - 2); // remove o sufixo (ex: FE, RF)
    if (prefixes.find(prefix) != prefixes.end())
        return prefixes[prefix];
    return 1.0;
}

// Função que extrai a unidade base (ex: FE, RF, IF, J)
string getBaseUnit(const string& unit) {
    return unit.substr(unit.length() - 2); // últimos 2 caracteres
}

// Valida as unidades base permitidas
bool isValidBase(const string& base) {
    return base == "FE" || base == "RF" || base == "IF" || base == "J";
}

// Converte tudo para maiúsculas
void toUpperCase(string& str) {
    for (char& c : str) c = toupper(c);
}

int main() {
    double energiaPorTick;
    string unidadeOrigem, unidadeDestino, intervalo;

    // Introdução
    cout << "=== Calculadora de Energia por Intervalo ===\n";
    cout << "Informe a energia gerada/gasta por tick e converta para segundo, minuto ou hora.\n\n";

    // Entrada do valor
    cout << "Digite a energia por tick (ex: 80): ";
    cin >> energiaPorTick;

    cout << "Digite a unidade da energia (ex: FE, kRF, MJ): ";
    cin >> unidadeOrigem;

    cout << "Digite a unidade desejada do resultado (ex: MJ, FE, kJ): ";
    cin >> unidadeDestino;

    cout << "Informe o intervalo (segundo, minuto ou hora): ";
    cin >> intervalo;

    // Converte tudo para maiúsculas
    toUpperCase(unidadeOrigem);
    toUpperCase(unidadeDestino);
    toUpperCase(intervalo);

    // Valida as bases
    string baseOrigem = getBaseUnit(unidadeOrigem);
    string baseDestino = getBaseUnit(unidadeDestino);

    if (!isValidBase(baseOrigem) || !isValidBase(baseDestino)) {
        cout << "Unidade inválida.\n";
        return 1;
    }

    // Determina o número de ticks no intervalo informado
    int ticks = 0;
    if (intervalo == "SEGUNDO") ticks = 20;
    else if (intervalo == "MINUTO") ticks = 20 * 60;
    else if (intervalo == "HORA") ticks = 20 * 60 * 60;
    else {
        cout << "Intervalo inválido. Use: segundo, minuto ou hora.\n";
        return 1;
    }

    // Calcula energia total no intervalo na unidade base
    double multiplicadorOrigem = getMultiplier(unidadeOrigem);
    double multiplicadorDestino = getMultiplier(unidadeDestino);

    double energiaTotalBase = energiaPorTick * multiplicadorOrigem * ticks;

    // Converte para a unidade desejada
    double resultado = energiaTotalBase / multiplicadorDestino;

    // Mostra o resultado com precisão ajustada
    cout << setprecision(12) << noshowpoint;
    cout << "\nResultado: " << resultado << " " << unidadeDestino << " por " << intervalo << "." << endl;

    return 0;
}
