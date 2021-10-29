#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

using namespace std;

/*1. Uma tonelada métrica, ou simplesmente tonelada, equivale a 35.273,92 onças. Escreva um programa que
leia o peso de um pacote de cereal matinal em onças e apresente na saída o peso em toneladas métricas,
assim como o número de caixas necessárias para fornecer uma tonelada métrica de cereal.*/

int main()
{
    setlocale(LC_ALL, "Portuguese");//habilita a acentuação para o português
    const double razaoOncaTonelada = 35273.92;
    double pesoPacoteOnca, pesoPacoteTonelada, numeroCaixasTonelada;
    cout << "Digite o peso em onças de um pacote de cereal: ";
    cin >> pesoPacoteOnca;
    pesoPacoteTonelada = pesoPacoteOnca/razaoOncaTonelada;
    numeroCaixasTonelada = razaoOncaTonelada/pesoPacoteOnca;
    cout << endl << "O peso do pacote em toneladas equivale a: " << pesoPacoteTonelada << " toneladas.\n"
         << "O numero de caixas necessárias para fornecer uma tonelada de cereal equivale a: " << ceil(numeroCaixasTonelada) << " caixas.\n";
         //função ceil arredonda para cima um valor de ponto flutuante.
    return 0;
}
