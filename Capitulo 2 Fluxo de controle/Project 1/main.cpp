#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/* 1. � dif�cil elaborar um or�amento que abranja v�rios anos, porque os pre�os n�o s�o est�veis. Se sua
empresa necessita de 200 l�pis por ano, voc� n�o pode simplesmente utilizar o pre�o dos l�pis este ano
para uma proje��o para daqui dois anos. Devido � infla��o, o custo provavelmente ser� maior do que �
hoje. Escreva um programa para estimar o custo esperado de um item em um n�mero especificado de
anos. O programa pede o custo de cada item, o n�mero de anos, a partir de agora, em que os itens ser�o
adquiridos e a taxa de infla��o. Ent�o, o programa apresenta como sa�da o custo estimado de cada item
ap�s o per�odo especificado. Fa�a com que o usu�rio informe a taxa de infla��o como uma porcentagem,
como, por exemplo, 5,6 (por cento). Seu programa deve converter a porcentagem em uma fra��o, como
0,056, e utilizar um loop para estimar o pre�o ajustado com a infla��o. (Dica: utilize um loop.)*/

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");//habilita a acentua��o para o portugu�s
    double precoAtual,taxa, precoAjustado=0;
    int qtdAnos;
    cout << "Digite o pre�o do item: ";
    cin >> precoAtual;
    cout << "Digite a taxa da infla��o: ";
    cin >> taxa;
    cout << "Digite a quantidade de anos: ";
    cin >> qtdAnos;
    for(int i = 1; i <= qtdAnos; i++)
    {
        if(precoAjustado==0)
        precoAjustado = precoAtual*(1+taxa/100);
        else
        precoAjustado = precoAjustado*(1+taxa/100);
    }
    cout << "O pre�o ajustado com valor da infla��o � " << precoAjustado << ".";
    return 0;
}
