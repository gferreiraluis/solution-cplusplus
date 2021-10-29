#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*6. Escreva uma fun��o que calcule o desvio m�dio e padr�o de quatro pontua��es. O desvio-padr�o � definido
como a raiz quadrada da m�dia dos quatro valores: (si - a)2, em que a � a m�dia das quatro pontua��es,
s1, s2, s3 e s4. A fun��o ter� seis par�metros e chamar� duas outras fun��es. Insira a fun��o em um
programa que lhe permita testar a fun��o repetidas vezes at� dizer ao programa que terminou.*/

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
        cout << "O desvio m�dio dos quatro valores �: " << desvioMedio(s1,s2,s3,s4,media(s1,s2,s3,s4))<<endl;
        cout << "O desvio padr�o dos quatro valores �: " << desvioPadrao(s1,s2,s3,s4,media(s1,s2,s3,s4))<<endl;
        cout << "Deseja realizar outro c�lculo (Y para sim): ";
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
