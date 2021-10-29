#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

/*2. Um laboratório de pesquisas governamental conclui que um adoçante artificial comumente usado em
refrigerantes dietéticos causa a morte de ratos de laboratório. Um amigo seu está desesperado para perder
peso e não consegue deixar de tomar refrigerantes. Seu amigo quer saber quanto refrigerante dietético é
possível tomar sem morrer. Escreva um programa para dar essa resposta. Os dados de entrada serão a
quantidade de adoçante artificial necessária para matar um rato, o peso do rato e o peso da pessoa em
dieta. Para garantir a segurança do seu amigo, faça com que o programa requisite o peso com o qual ele
deseja ficar, em vez do peso atual. Assuma que o refrigerante dietético contém um décimo de 1% de adoçante
artificial. Utilize uma declaração de variável com o modificador const para dar um nome a esta fração.
Você pode querer expressar a porcentagem como o valor double 0.001*/

int main()
{
    setlocale(LC_ALL, "Portuguese");
    const double porcentagem = 0.001;
    double quantidadeAdocante, pesoRato, pesoPessoa, litrosRefrigerante;
    cout << "Digite a quantidade de adoçante artificial necessária para matar um rato: ";
    cin >> quantidadeAdocante;
    cout << "Digite o peso do Rato: ";
    cin >> pesoRato;
    cout << "Digite o peso que você deseja ficar: ";
    cin >> pesoPessoa;
    litrosRefrigerante = (pesoPessoa*quantidadeAdocante/pesoRato)/porcentagem;
    cout << endl << "A quantidade de refrigerante dietético consumida deverá ser menor do que " << litrosRefrigerante << " litros.\n";
    return 0;
}
