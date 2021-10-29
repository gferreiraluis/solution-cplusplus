#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

using namespace std;

/*1. Escreva um programa que converta da notação de 24 horas para a notação de 12 horas. Por exemplo, o
programa deve converter 14:25 em 2:25 P.M. A entrada é dada em dois inteiros. Deve haver pelo menos
três funções: uma para a entrada, uma para fazer a conversão e uma para a saída. Registre a informação
A.M./P.M. como um valor de tipo char, ’A’ para A.M. e ’P’ para P.M. Assim, a função para efetuar as
conversões terá um parâmetro formal chamado por referência de tipo char para registrar se é A.M. ou
P.M. (A função terá outros parâmetros também.) Inclua um loop que permita que o usuário repita esse
cálculo para novos valores de entrada todas as vezes que desejar, até o usuário dizer que deseja encerrar o
programa.*/

void getData(int &hora, int &minuto);
void converteData(int &hora, char &def);
void outData(int hora, int minuto, char def);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char def, op;
    int hora, minuto;
    do{
        getData(hora,minuto);
        converteData(hora,def);
        outData(hora,minuto,def);
        cout << "Deseja realizar outra conversão? (S/N): ";
        cin >> op;
    }while(op=='s'||op=='S');
    return 0;
}

void getData(int &hora, int &minuto)
{
    do
    {
        cout << "Digite a hora desejada (Entre 0 e 23): ";
        cin >> hora;
        if(hora<0||hora>23)
            cout << "Valor inválido."<<endl;
    }while(hora<0||hora>23);

    do
    {
        cout << "Digite o minuto hora desejada (Entre 0 e 59): ";
        cin >> minuto;
        if(minuto<0||minuto>59)
            cout << "Valor inválido."<<endl;
    }while(minuto<0||minuto>59);
}

void converteData(int &hora, char &def)
{
    if(hora>=0&&hora<12)
        def = 'A';
    else
        def = 'P';

    switch(hora)
    {
        case 13:
        hora = 1;
        break;
        case 14:
        hora = 2;
        break;
        case 15:
        hora = 3;
        break;
        case 16:
        hora = 4;
        break;
        case 17:
        hora = 5;
        break;
        case 18:
        hora = 6;
        break;
        case 19:
        hora = 7;
        break;
        case 20:
        hora = 8;
        break;
        case 21:
        hora = 9;
        break;
        case 22:
        hora = 10;
        break;
        case 23:
        hora = 11;
        break;
        case 0:
        hora = 12;
        break;
    }
}

void outData(int hora, int minuto, char def)
{
    if(def == 'A')
        cout << "O horário informado é "<<hora<<":"<<minuto<<" A.M."<<endl;
    else
        cout << "O horário informado é "<<hora<<":"<<minuto<<" P.M."<<endl;
}
