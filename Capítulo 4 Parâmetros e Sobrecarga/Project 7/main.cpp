#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*7. Escreva um programa que leia o peso em libras (1 libra = 453,59 gramas) e onças (1 onça = 28,34 gramas)
e apresente como saída o equivalente em quilogramas e gramas. Use pelo menos três funções: uma
para entrada, uma ou mais para o cálculo e uma para a saída. Inclua um loop que permita ao usuário repetir
 esse cálculo para novos dados de entrada até o usuário dizer que deseja encerrar o programa. Existem
2.2046 libras em um quilograma, 1.000 gramas em um quilograma e 16 onças em uma libra.*/

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
        cout << "Deseja realizar outro cálculo? (S/N): ";
        cin >> op;
    }while(op=='s'||op=='S');
    return 0;
}

void getData(double& libra, double& onca)
{
    cout << "Digite o peso em libras: ";
    cin >> libra;
    cout << "Digite o peso em onças: ";
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
