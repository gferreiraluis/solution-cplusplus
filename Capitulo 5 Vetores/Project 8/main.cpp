#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


/*8. Escreva um programa que aceite dados de entrada como o programa no Painel 5.4 e que apresente como
sa�da um gr�fico de barras como o daquele programa, a n�o ser pelo fato de que seu programa apresentar�
as barras verticalmente e n�o horizontalmente. Um vetor bidimensional pode ser �til.*/

using namespace std;

//L� dados e exibe um gr�fico de barras mostrando a produtividade de cada f�brica.

const int NUMBER_OF_PLANTS = 4;
void inputData(int a[], int lastPlanNumber);
//Pr�-condi��o: lastPlantNumber � o tamanho declarado do vetor a.
//P�s-condi��o: Para plantNumber = 1 at� lastPlantNumber:
//a[plantNumber-1] � igual � produ��o total da f�brica de n�mero plantNumber.
 void scale(int a[], int size1);
//Pr�-condi��o: a[0] at� a[size-1] tem todos valor n�o-negativo.
//P�s-condi��o: a[i] foi alterado para o n�mero de milhares (arredondado para
//um inteiro) que estava originalmente em a[i], para todo i, tal que 0 <= i <= size-1.
void graph(const int asteriskCount[], int lastPlantNumber);
//Pr�-condi��o: a[0] at� a[lastPlantNumber-1] tem todos valor n�o-negativo.
//P�s-condi��o: Um gr�fico de barras foi apresentado dizendo que a f�brica
//n�mero N produziu a[N-1] milhares de unidades para cada N, tal que
//1 <= N <= lastPlantNumber
void getTotal(int& sum);
//L� inteiros n�o-negativos a partir do teclado e
//coloca o total em sum.
int round1(double number);
//Pr�-condi��o: number >= 0.
//Retorna n�mero arredondado para o inteiro mais pr�ximo.
void printAsterisks(int n);
//Imprime n asteriscos na tela.
int main( )
{
     setlocale(LC_ALL, "Portuguese");
     int production[NUMBER_OF_PLANTS];
     cout << "Este programa apresenta um gr�fico mostrando\n"
     << "a produ��o de cada f�brica na companhia.\n";
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
        << "Informe os dados de produ��o para a f�brica n�mero "
        << plantNumber << endl;
        getTotal(a[plantNumber-1]);
    }
}
void getTotal(int& sum)
{
     cout << "Informe o n�mero de unidades produzidas por cada departamento.\n"
     << "Inclua um n�mero negativo ao final da lista.\n";
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
         cout << "F�brica #" << plantNumber << " "<<endl<<endl;
         printAsterisks(asteriskCount[plantNumber-1]);
         cout << endl;
     }
 }
 void printAsterisks(int n)
{
    for (int count1 = 1; count1 <= n; count1++)
    cout << "*"<<endl;
}
