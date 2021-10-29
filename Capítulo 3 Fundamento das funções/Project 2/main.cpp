#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*2. Escreva um programa para medir a taxa de inflação no ano passado. O programa pede o preço de um
item (como um cachorro quente ou um diamante de um quilate) no ano passado e hoje. Estima a taxa de
inflação como a diferença no preço dividida pelo preço do ano passado. Seu programa deve permitir que o
usuário repita esse cálculo quantas vezes desejar. Defina uma função para calcular a taxa de inflação. A taxa de
inflação deve ser um valor de tipo double, fornecendo a taxa como porcentagem, por exemplo, 5.3 para 5.3%.*/

using namespace std;

double taxaInflacao(double precoAntigo, double precoAtual);

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
        cout << "Deseja realizar um novo cálculo (Y para sim): ";
        cin >> op;
    }while(op=='y'||op=='Y');
    return 0;
}

double taxaInflacao(double precoAntigo, double precoAtual)
{
        return ((precoAtual-precoAntigo)/precoAntigo)*100;
}
