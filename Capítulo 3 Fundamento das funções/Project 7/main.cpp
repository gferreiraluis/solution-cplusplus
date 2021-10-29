#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*7. Quando está frio, os meteorologistas transmitem um índice chamado fator de frio do vento, que leva em
consideração a velocidade do vento e a temperatura. O índice fornece uma medida do efeito resfriador do
vento em uma dada temperatura do ar. Esse índice pode ser aproximado pela seguinte fórmula:
W = 13.12 + 0.6215*t – 11.37*v^0.16 + 0.3965*t*v^0.016
em que
 v = velocidade do vento em m/s
 t = temperatura em graus Celsius: t <= 10
 W = índice de frio do vento (em graus Celsius)
Escreva uma função que forneça o índice de frio do vento. Seu código deve assegurar que a restrição a
respeito da temperatura não seja violada. Verifique alguns boletins meteorológicos em edições anteriores
de jornais em sua biblioteca e compare o índice de frio do vento que você calculou com o resultado divulgado no jornal*/

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
            cout << "Valor de temperatura inválido."<<endl;
      }while(temperatura>10);
    cout << "O índice Fator Frio é " << indiceFatorFrio(velocidade,temperatura)<<" Celsius."<<endl;
    return 0;
}

double indiceFatorFrio(double velocidade, double temperatura)
{
    return 13.12 + 0.6215*temperatura - 11.37*pow(velocidade,0.16) + 0.3965*temperatura*pow(velocidade,0.016);
}
