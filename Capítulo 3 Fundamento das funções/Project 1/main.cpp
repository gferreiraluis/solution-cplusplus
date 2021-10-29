#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*1. Um litro equivale a 0.264179 gal�es. Escreva um programa que leia o n�mero de litros de gasolina consumidos
pelo carro do usu�rio e o n�mero de milhas* que o carro andou e apresente como sa�da o n�mero de milhas por gal�o
que o carro rendeu. Seu programa deve permitir que o usu�rio repita o c�lculo quantas vezes quiser. Defina uma fun��o
para calcular o n�mero de milhas por gal�o. Seu programa deve usar uma constante globalmente definida para o n�mero de
gal�es por litro.*/

using namespace std;

const double GALOES = 0.264179;

double milhasPorGalao(double litros, double milhas);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char op;
    double litros, milhas;
    do{
        cout << "Digite o n�mero de litros de gasolina consumidos: ";
        cin >> litros;
        cout << "Digite o n�mero de milhas que o carro andou: ";
        cin >> milhas;
        cout << "O n�mero de milhas por gal�o �: " << milhasPorGalao(litros, milhas) << endl;
        cout << "Deseja realizar outro c�lculo (Y para sim): ";
        cin >> op;
    }while(op=='y'||op=='Y');
    return 0;
}

double milhasPorGalao(double litros, double milhas)
{
    return milhas/(litros*GALOES);
}


