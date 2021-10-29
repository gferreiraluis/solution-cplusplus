#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*6. Escreva uma função que calcule o desvio médio e padrão de quatro pontuações. O desvio-padrão é definido
como a raiz quadrada da média dos quatro valores: (si - a)2, em que a é a média das quatro pontuações,
s1, s2, s3 e s4. A função terá seis parâmetros e chamará duas outras funções. Insira a função em um
programa que lhe permita testar a função repetidas vezes até dizer ao programa que terminou.*/

using namespace std;

double media(double s1, double s2, double s3, double s4);
double desvioMedio(double s1, double s2, double s3, double s4, double media);
double desvioPadrao(double s1, double s2, double s3, double s4, double media);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char op;
    double s1, s2, s3, s4;
    do
    {
        cout << "Entre com o valor de s1: ";
        cin >> s1;
        cout << "Entre com o valor de s2: ";
        cin >> s2;
        cout << "Entre com o valor de s3: ";
        cin >> s3;
        cout << "Entre com o valor de s4: ";
        cin >> s4;
        cout << "O desvio médio dos quatro valores é: " << desvioMedio(s1,s2,s3,s4,media(s1,s2,s3,s4))<<endl;
        cout << "O desvio padrão dos quatro valores é: " << desvioPadrao(s1,s2,s3,s4,media(s1,s2,s3,s4))<<endl;
        cout << "Deseja realizar outro cálculo (Y para sim): ";
        cin >> op;
    }while(op=='y'||op=='Y');
    return 0;
}

double media(double s1, double s2, double s3, double s4)
{
    return (s1+s2+s3+s4)/4;
}

double desvioMedio(double s1, double s2, double s3, double s4, double media)
{
    return (abs(s1-media)+abs(s2-media)+abs(s3-media)+abs(s4-media))/4;
}

double desvioPadrao(double s1, double s2, double s3, double s4, double media)
{
    return sqrt((pow(s1-media,2)+pow(s2-media,2)+pow(s3-media,2)+pow(s4-media,2))/4);
}
