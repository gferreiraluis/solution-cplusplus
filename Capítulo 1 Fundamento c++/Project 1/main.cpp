#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

using namespace std;

/*1. Uma tonelada m�trica, ou simplesmente tonelada, equivale a 35.273,92 on�as. Escreva um programa que
leia o peso de um pacote de cereal matinal em on�as e apresente na sa�da o peso em toneladas m�tricas,
assim como o n�mero de caixas necess�rias para fornecer uma tonelada m�trica de cereal.*/

int main()
{
    setlocale(LC_ALL, "Portuguese");//habilita a acentua��o para o portugu�s
    const double razaoOncaTonelada = 35273.92;
    double pesoPacoteOnca, pesoPacoteTonelada, numeroCaixasTonelada;
    cout << "Digite o peso em on�as de um pacote de cereal: ";
    cin >> pesoPacoteOnca;
    pesoPacoteTonelada = pesoPacoteOnca/razaoOncaTonelada;
    numeroCaixasTonelada = razaoOncaTonelada/pesoPacoteOnca;
    cout << endl << "O peso do pacote em toneladas equivale a: " << pesoPacoteTonelada << " toneladas.\n"
         << "O numero de caixas necess�rias para fornecer uma tonelada de cereal equivale a: " << ceil(numeroCaixasTonelada) << " caixas.\n";
         //fun��o ceil arredonda para cima um valor de ponto flutuante.
    return 0;
}
