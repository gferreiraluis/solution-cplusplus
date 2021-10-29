#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*4. Escreva um programa que leia um comprimento em p�s e polegadas e apresente a sa�da equivalente em
metros e cent�metros. Utilize pelo menos tr�s fun��es: uma para entrada, uma ou mais para o c�lculo e
uma para a sa�da. Inclua um loop que permita ao usu�rio repetir esse c�lculo para novos dados de entrada
at� o usu�rio dizer que deseja encerrar o programa. Existem 0.3048 metros em um p�, 100 cent�metros
em um metro e 12 polegadas em um p�.*/

using namespace std;

void getData(double& pe, double& polegada);
void converteComprimento(double& pe, double& polegada);
void outData(double pe, double polegada);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double pe, polegada;
    char op;
    do
    {
        getData(pe,polegada);
        converteComprimento(pe,polegada);
        outData(pe,polegada);
        cout << "Deseja realizar outro c�lculo? (S/N): ";
        cin >> op;
    }while(op=='s'||op=='S');
    return 0;
}

void getData(double& pe, double& polegada)
{
    cout << "Digite o comprimento em p�s: ";
    cin >> pe;
    cout << "Digite o comprimento em polegadas: ";
    cin >> polegada;
}

void converteComprimento(double& pe, double& polegada)
{
    double metro, centimetro;
    metro = 0.3048*(pe + polegada/12.0);
    centimetro = fmod(metro,1)*100;
    pe = floor(metro);
    polegada = centimetro;
}

void outData(double pe, double polegada)
{
    cout << "A medida fornecida equivale a " << pe << " metros e " << polegada << " cent�metros."<<endl;
}


