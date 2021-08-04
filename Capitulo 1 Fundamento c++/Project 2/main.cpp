#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

/*2. Um laborat�rio de pesquisas governamental conclui que um ado�ante artificial comumente usado em
refrigerantes diet�ticos causa a morte de ratos de laborat�rio. Um amigo seu est� desesperado para perder
peso e n�o consegue deixar de tomar refrigerantes. Seu amigo quer saber quanto refrigerante diet�tico �
poss�vel tomar sem morrer. Escreva um programa para dar essa resposta. Os dados de entrada ser�o a
quantidade de ado�ante artificial necess�ria para matar um rato, o peso do rato e o peso da pessoa em
dieta. Para garantir a seguran�a do seu amigo, fa�a com que o programa requisite o peso com o qual ele
deseja ficar, em vez do peso atual. Assuma que o refrigerante diet�tico cont�m um d�cimo de 1% de ado�ante
artificial. Utilize uma declara��o de vari�vel com o modificador const para dar um nome a esta fra��o.
Voc� pode querer expressar a porcentagem como o valor double 0.001*/

int main()
{
    setlocale(LC_ALL, "Portuguese");
    const double porcentagem = 0.001;
    double quantidadeAdocante, pesoRato, pesoPessoa, litrosRefrigerante;
    cout << "Digite a quantidade de ado�ante artificial necess�ria para matar um rato: ";
    cin >> quantidadeAdocante;
    cout << "Digite o peso do Rato: ";
    cin >> pesoRato;
    cout << "Digite o peso que voc� deseja ficar: ";
    cin >> pesoPessoa;
    litrosRefrigerante = (pesoPessoa*quantidadeAdocante/pesoRato)/porcentagem;
    cout << endl << "A quantidade de refrigerante diet�tico consumida dever� ser menor do que " << litrosRefrigerante << " litros.\n";
    return 0;
}
