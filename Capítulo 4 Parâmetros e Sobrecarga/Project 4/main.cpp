#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*4. Escreva um programa que leia um comprimento em pés e polegadas e apresente a saída equivalente em
metros e centímetros. Utilize pelo menos três funções: uma para entrada, uma ou mais para o cálculo e
uma para a saída. Inclua um loop que permita ao usuário repetir esse cálculo para novos dados de entrada
até o usuário dizer que deseja encerrar o programa. Existem 0.3048 metros em um pé, 100 centímetros
em um metro e 12 polegadas em um pé.*/

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
        cout << "Deseja realizar outro cálculo? (S/N): ";
        cin >> op;
    }while(op=='s'||op=='S');
    return 0;
}

void getData(double& pe, double& polegada)
{
    cout << "Digite o comprimento em pés: ";
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
    cout << "A medida fornecida equivale a " << pe << " metros e " << polegada << " centímetros."<<endl;
}


