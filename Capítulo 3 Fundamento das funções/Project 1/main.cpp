#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*1. Um litro equivale a 0.264179 galões. Escreva um programa que leia o número de litros de gasolina consumidos
pelo carro do usuário e o número de milhas* que o carro andou e apresente como saída o número de milhas por galão
que o carro rendeu. Seu programa deve permitir que o usuário repita o cálculo quantas vezes quiser. Defina uma função
para calcular o número de milhas por galão. Seu programa deve usar uma constante globalmente definida para o número de
galões por litro.*/

using namespace std;

const double GALOES = 0.264179;

double milhasPorGalao(double litros, double milhas);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char op;
    double litros, milhas;
    do{
        cout << "Digite o número de litros de gasolina consumidos: ";
        cin >> litros;
        cout << "Digite o número de milhas que o carro andou: ";
        cin >> milhas;
        cout << "O número de milhas por galão é: " << milhasPorGalao(litros, milhas) << endl;
        cout << "Deseja realizar outro cálculo (Y para sim): ";
        cin >> op;
    }while(op=='y'||op=='Y');
    return 0;
}

double milhasPorGalao(double litros, double milhas)
{
    return milhas/(litros*GALOES);
}


