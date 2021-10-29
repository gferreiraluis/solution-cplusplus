#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/* 1. É difícil elaborar um orçamento que abranja vários anos, porque os preços não são estáveis. Se sua
empresa necessita de 200 lápis por ano, você não pode simplesmente utilizar o preço dos lápis este ano
para uma projeção para daqui dois anos. Devido à inflação, o custo provavelmente será maior do que é
hoje. Escreva um programa para estimar o custo esperado de um item em um número especificado de
anos. O programa pede o custo de cada item, o número de anos, a partir de agora, em que os itens serão
adquiridos e a taxa de inflação. Então, o programa apresenta como saída o custo estimado de cada item
após o período especificado. Faça com que o usuário informe a taxa de inflação como uma porcentagem,
como, por exemplo, 5,6 (por cento). Seu programa deve converter a porcentagem em uma fração, como
0,056, e utilizar um loop para estimar o preço ajustado com a inflação. (Dica: utilize um loop.)*/

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");//habilita a acentuação para o português
    double precoAtual,taxa, precoAjustado=0;
    int qtdAnos;
    cout << "Digite o preço do item: ";
    cin >> precoAtual;
    cout << "Digite a taxa da inflação: ";
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
    cout << "O preço ajustado com valor da inflação é " << precoAjustado << ".";
    return 0;
}
