#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*5. Escreva um programa como o do exerc�cio anterior que converta metros e cent�metros em p�s e polegadas.
 Utilize fun��es para as subtarefas.*/

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
    cout << "Digite o comprimento em metros: ";
    cin >> pe;
    cout << "Digite o comprimento em cent�metros: ";
    cin >> polegada;
}

void converteComprimento(double& pe, double& polegada)
{
    double metro, centimetro;
    metro = (pe + polegada/100)/0.3048;
    centimetro = fmod(metro,1)*12;
    pe = floor(metro);
    polegada = centimetro;
}

void outData(double pe, double polegada)
{
    cout << "A medida fornecida equivale a " << pe << " p�s e " << polegada << " polegadas."<<endl;
}
