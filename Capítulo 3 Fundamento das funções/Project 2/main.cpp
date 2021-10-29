#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*2. Escreva um programa para medir a taxa de infla��o no ano passado. O programa pede o pre�o de um
item (como um cachorro quente ou um diamante de um quilate) no ano passado e hoje. Estima a taxa de
infla��o como a diferen�a no pre�o dividida pelo pre�o do ano passado. Seu programa deve permitir que o
usu�rio repita esse c�lculo quantas vezes desejar. Defina uma fun��o para calcular a taxa de infla��o. A taxa de
infla��o deve ser um valor de tipo double, fornecendo a taxa como porcentagem, por exemplo, 5.3 para 5.3%.*/

using namespace std;

double taxaInflacao(double precoAntigo, double precoAtual);

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
        cout << "Deseja realizar um novo c�lculo (Y para sim): ";
        cin >> op;
    }while(op=='y'||op=='Y');
    return 0;
}

double taxaInflacao(double precoAntigo, double precoAtual)
{
        return ((precoAtual-precoAntigo)/precoAntigo)*100;
}
