#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*7. Quando est� frio, os meteorologistas transmitem um �ndice chamado fator de frio do vento, que leva em
considera��o a velocidade do vento e a temperatura. O �ndice fornece uma medida do efeito resfriador do
vento em uma dada temperatura do ar. Esse �ndice pode ser aproximado pela seguinte f�rmula:
W = 13.12 + 0.6215*t � 11.37*v^0.16 + 0.3965*t*v^0.016
em que
 v = velocidade do vento em m/s
 t = temperatura em graus Celsius: t <= 10
 W = �ndice de frio do vento (em graus Celsius)
Escreva uma fun��o que forne�a o �ndice de frio do vento. Seu c�digo deve assegurar que a restri��o a
respeito da temperatura n�o seja violada. Verifique alguns boletins meteorol�gicos em edi��es anteriores
de jornais em sua biblioteca e compare o �ndice de frio do vento que voc� calculou com o resultado divulgado no jornal*/

using namespace std;

double indiceFatorFrio(double velocidade, double temperatura);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    double velocidade, temperatura;
    cout << "Digite a velocidade do ventro em m/s: ";
    cin >> velocidade;
    do{
        cout << "Digite a temperatura em graus Celsius (t<=10): ";
        cin >> temperatura;
        if(temperatura > 10)
            cout << "Valor de temperatura inv�lido."<<endl;
      }while(temperatura>10);
    cout << "O �ndice Fator Frio � " << indiceFatorFrio(velocidade,temperatura)<<" Celsius."<<endl;
    return 0;
}

double indiceFatorFrio(double velocidade, double temperatura)
{
    return 13.12 + 0.6215*temperatura - 11.37*pow(velocidade,0.16) + 0.3965*temperatura*pow(velocidade,0.016);
}
