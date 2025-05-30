#include <iostream>                 
#include <unordered_map>           // Mapa hash para associar prefixos aos multiplicadores
#include <cmath>                   // Biblioteca matemática (não usada diretamente, mas pode ser útil)
#include <iomanip>                 // Para manipulação de saída formatada (ex: precisão de casas decimais)
#include <string>                  

using namespace std;

// Função que retorna o multiplicador com base no prefixo ("" = 1, "K" = 1.000, etc)
double getMultiplier(const string& unit) {
    unordered_map<string, double> prefixes = {
        {"", 1},
        {"K", 1e3},
        {"M", 1e6},
        {"G", 1e9},
        {"T", 1e12}
    };

    // Extrai o prefixo (removendo os dois últimos caracteres da unidade: "FE", "IF", "RF" ou "J")
    string prefix = unit.substr(0, unit.length() - 2);

    // Retorna o multiplicador associado ao prefixo, ou 1 se não for encontrado
    if (prefixes.find(prefix) != prefixes.end()) {
        return prefixes[prefix];
    }

    return 1.0;
}

// Função que extrai a unidade base (ex: FE, RF, IF, J)
string getBaseUnit(const string& unit) {
    return unit.substr(unit.length() - 2); // Pega os dois últimos caracteres
}

// Função que verifica se a unidade base é válida
bool isValidBase(const string& base) {
    return base == "FE" || base == "RF" || base == "J" || base == "IF";
}

int main() {
    double value;           // Valor numérico informado pelo usuário
    string fromUnit;        // Unidade de origem
    string toUnit;          // Unidade de destino

    // Interface de entrada
    cout << "Conversor de Energia (FE, RF, J, IF)\n";
    cout << "-------------------------------------\n";

    cout << "Digite o valor: ";
    cin >> value;

    cout << "Digite a unidade de origem (ex: MFE, kIF, GJ): ";
    cin >> fromUnit;

    cout << "Digite a unidade de destino (ex: FE, MJ, kRF): ";
    cin >> toUnit;

    // Converte todas as letras para maiúsculas para evitar erros de leitura
    for (char& c : fromUnit) c = toupper(c);
    for (char& c : toUnit) c = toupper(c);

    // Obtém o multiplicador dos prefixos (ex: k = 1000, M = 1.000.000)
    double fromMultiplier = getMultiplier(fromUnit);
    double toMultiplier = getMultiplier(toUnit);

    // Obtém as unidades base (FE, RF, IF, J)
    string fromBase = getBaseUnit(fromUnit);
    string toBase = getBaseUnit(toUnit);

    // Validação das unidades
    if (!isValidBase(fromBase)) {
        cout << "Unidade de origem inválida.\n";
        return 1;
    }

    if (!isValidBase(toBase)) {
        cout << "Unidade de destino inválida.\n";
        return 1;
    }

    // Converte o valor informado para a unidade base comum (considerando equivalência 1:1 entre FE, RF, IF, J)
    double baseValue = value * fromMultiplier;

    // Converte da unidade base para a unidade de destino
    double converted = baseValue / toMultiplier;

    // Define precisão natural sem mostrar zeros desnecessários
    cout << setprecision(12) << noshowpoint;

    // Exibe o resultado
    cout << "\nResultado: " << converted << " " << toUnit << endl;

    return 0; // Finaliza o programa
}
