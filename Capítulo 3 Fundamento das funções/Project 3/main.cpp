#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*3. Aperfei�oe o programa do exerc�cio anterior fazendo com que apresente tamb�m o pre�o estimado do
item um e dois anos depois da �poca do c�lculo. O aumento no custo em um ano � estimado como a
taxa de infla��o multiplicada pelo pre�o no in�cio do ano. Defina uma segunda fun��o para determinar o
custo estimado de um item em um n�mero especificado de anos, dados o pre�o atual do item e a taxa de
infla��o como argumentos.*/

using namespace std;

double taxaInflacao(double precoAntigo, double precoAtual);
double precoEstimado(double precoAtual, double taxa);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char op;
    double precoAntigo, precoAtual;
    do{
        cout << "Digite o pre�o atual do item: ";
        cin >> precoAtual;
        cout << "Digite o pre�o do item referente ao ano passado: ";
        cin >> precoAntigo;
        cout << "O valor estimado da taxa de infla��o �: " << taxaInflacao(precoAntigo, precoAtual) <<"%."<<endl;
        cout << "O valor estimado do pre�o do produto em dois anos �: R$ " << precoEstimado(precoAtual, taxaInflacao(precoAntigo,precoAtual)) <<"."<<endl;
        cout << "Deseja realizar um novo c�lculo (Y para sim): ";
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
