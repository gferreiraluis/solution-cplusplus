#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*3. Aperfeiçoe o programa do exercício anterior fazendo com que apresente também o preço estimado do
item um e dois anos depois da época do cálculo. O aumento no custo em um ano é estimado como a
taxa de inflação multiplicada pelo preço no início do ano. Defina uma segunda função para determinar o
custo estimado de um item em um número especificado de anos, dados o preço atual do item e a taxa de
inflação como argumentos.*/

using namespace std;

double taxaInflacao(double precoAntigo, double precoAtual);
double precoEstimado(double precoAtual, double taxa);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char op;
    double precoAntigo, precoAtual;
    do{
        cout << "Digite o preço atual do item: ";
        cin >> precoAtual;
        cout << "Digite o preço do item referente ao ano passado: ";
        cin >> precoAntigo;
        cout << "O valor estimado da taxa de inflação é: " << taxaInflacao(precoAntigo, precoAtual) <<"%."<<endl;
        cout << "O valor estimado do preço do produto em dois anos é: R$ " << precoEstimado(precoAtual, taxaInflacao(precoAntigo,precoAtual)) <<"."<<endl;
        cout << "Deseja realizar um novo cálculo (Y para sim): ";
        cin >> op;
    }while(op=='y'||op=='Y');
    return 0;
}

double taxaInflacao(double precoAntigo, double precoAtual)
{
        return ((precoAtual-precoAntigo)/precoAntigo)*100;
}

double precoEstimado(double precoAtual, double taxa)
{
    return precoAtual*(1+taxa/100)*(1+taxa/100);
}
