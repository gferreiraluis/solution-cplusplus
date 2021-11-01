#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


/*8. Escreva um programa que aceite dados de entrada como o programa no Painel 5.4 e que apresente como
saída um gráfico de barras como o daquele programa, a não ser pelo fato de que seu programa apresentará
as barras verticalmente e não horizontalmente. Um vetor bidimensional pode ser útil.*/

using namespace std;

//Lê dados e exibe um gráfico de barras mostrando a produtividade de cada fábrica.

const int NUMBER_OF_PLANTS = 4;
void inputData(int a[], int lastPlanNumber);
//Pré-condição: lastPlantNumber é o tamanho declarado do vetor a.
//Pós-condição: Para plantNumber = 1 até lastPlantNumber:
//a[plantNumber-1] é igual à produção total da fábrica de número plantNumber.
 void scale(int a[], int size1);
//Pré-condição: a[0] até a[size-1] tem todos valor não-negativo.
//Pós-condição: a[i] foi alterado para o número de milhares (arredondado para
//um inteiro) que estava originalmente em a[i], para todo i, tal que 0 <= i <= size-1.
void graph(const int asteriskCount[], int lastPlantNumber);
//Pré-condição: a[0] até a[lastPlantNumber-1] tem todos valor não-negativo.
//Pós-condição: Um gráfico de barras foi apresentado dizendo que a fábrica
//número N produziu a[N-1] milhares de unidades para cada N, tal que
//1 <= N <= lastPlantNumber
void getTotal(int& sum);
//Lê inteiros não-negativos a partir do teclado e
//coloca o total em sum.
int round1(double number);
//Pré-condição: number >= 0.
//Retorna número arredondado para o inteiro mais próximo.
void printAsterisks(int n);
//Imprime n asteriscos na tela.
int main( )
{
     setlocale(LC_ALL, "Portuguese");
     int production[NUMBER_OF_PLANTS];
     cout << "Este programa apresenta um gráfico mostrando\n"
     << "a produção de cada fábrica na companhia.\n";
     inputData(production, NUMBER_OF_PLANTS);
     scale(production, NUMBER_OF_PLANTS);
     graph(production, NUMBER_OF_PLANTS);
     return 0;
}
void inputData(int a[], int lastPlantNumber)
{
    for(int plantNumber=1;plantNumber<=lastPlantNumber;plantNumber++)
    {
        cout << endl
        << "Informe os dados de produção para a fábrica número "
        << plantNumber << endl;
        getTotal(a[plantNumber-1]);
    }
}
void getTotal(int& sum)
{
     cout << "Informe o número de unidades produzidas por cada departamento.\n"
     << "Inclua um número negativo ao final da lista.\n";
     sum = 0;
     int next;
     cin >> next;
     while (next >= 0)
     {
     sum = sum + next;
     cin >> next;
     }
     cout << "Total = " << sum << endl;
}

void scale(int a[], int size1)
{
    for(int index=0;index<size1;index++)
        a[index] = round1(a[index]/1000.0);

}
int round1(double number)
{
    return static_cast<int>(floor(number + 0.5));
}
void graph(const int asteriskCount[], int lastPlantNumber)
{
     cout << "Unidades produzidas em milhares de unidades:\n";
     for (int plantNumber = 1;plantNumber <= lastPlantNumber; plantNumber++)
    {
         cout << "Fábrica #" << plantNumber << " "<<endl<<endl;
         printAsterisks(asteriskCount[plantNumber-1]);
         cout << endl;
     }
 }
 void printAsterisks(int n)
{
    for (int count1 = 1; count1 <= n; count1++)
    cout << "*"<<endl;
}
