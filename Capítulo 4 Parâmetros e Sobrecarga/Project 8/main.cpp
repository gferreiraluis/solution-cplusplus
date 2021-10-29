#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*8. Escreva um programa como o do exercício anterior que converta quilogramas e gramas em libras e onças.
Utilize funções para as subtarefas.*/

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
    cout << "Digite o peso em quilos: ";
    cin >> libra;
    cout << "Digite o peso em gramas: ";
    cin >> onca;
}

void convertePeso(double& libra, double& onca)
{
    double quilo, grama;
    quilo = libra*2.2046 + onca/(28.34*16);
    grama = fmod(quilo,1)*16;
    libra = floor(quilo);
    onca = grama;
}

void outData(double libra, double onca)
{
    cout << "A medida fornecida equivale a " << libra << " libras e " << onca << " onças."<<endl;
}
