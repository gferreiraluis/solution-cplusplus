#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*7. Escreva um programa que leia o peso em libras (1 libra = 453,59 gramas) e on�as (1 on�a = 28,34 gramas)
e apresente como sa�da o equivalente em quilogramas e gramas. Use pelo menos tr�s fun��es: uma
para entrada, uma ou mais para o c�lculo e uma para a sa�da. Inclua um loop que permita ao usu�rio repetir
 esse c�lculo para novos dados de entrada at� o usu�rio dizer que deseja encerrar o programa. Existem
2.2046 libras em um quilograma, 1.000 gramas em um quilograma e 16 on�as em uma libra.*/

using namespace std;

void getData(double& libra, double& onca);
void convertePeso(double& libra, double& onca);
void outData(double libra, double once);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double libra, onca;
    char op;
    do
    {
        getData(libra,onca);
        convertePeso(libra,onca);
        outData(libra,onca);
        cout << "Deseja realizar outro c�lculo? (S/N): ";
        cin >> op;
    }while(op=='s'||op=='S');
    return 0;
}

void getData(double& libra, double& onca)
{
    cout << "Digite o peso em libras: ";
    cin >> libra;
    cout << "Digite o peso em on�as: ";
    cin >> onca;
}

void convertePeso(double& libra, double& onca)
{
    double quilo, grama;
    quilo = (453.59*libra + 28.34*onca)/1000;
    grama = fmod(quilo,1)*1000;
    libra = floor(quilo);
    onca = grama;
}

void outData(double libra, double onca)
{
    cout << "A medida fornecida equivale a " << libra << " quilos e " << onca << " gramas."<<endl;
}
