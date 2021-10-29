#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*A for�a de atra��o gravitacional entre dois corpos com massas m1 e m2, separados por uma dist�ncia d, �
dada pela seguinte f�rmula:
F = Gm1m2/d^2
onde G � a constante de gravita��o universal:
G = 6.673 x 10-8 cm3/(g � sec2)
Escreva uma defini��o de fun��o que utilize argumentos para as massas de dois corpos e a dist�ncia entre
eles e forne�a a for�a gravitacional entre eles. Como voc� ir� utilizar a f�rmula acima, a for�a gravitacional
ser� dada em dynes (dinas). Um dyne (dina) equivale a 1g � cm/sec2

Voc� deve usar uma constante globalmente definida para a constante de gravita��o universal. Insira sua defini��o
de fun��o em um programa completo que calcule a for�a gravitacional entre dois objetos com dados de
entrada adequados. Seu programa deve permitir que o usu�rio repita esse c�lculo quantas vezes desejar*/

using namespace std;

const double CONSTANTEGRAVITACIONAL = 6.673/100000000;

double forcaGravitacional(double massa1, double massa2, double distancia);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char op;
    double massa1, massa2, distancia;
    do{
        cout << "Digite a massa do corpo 1: ";
        cin >> massa1;
        cout << "Digite a massa do corpo 2: ";
        cin >> massa2;
        cout << "Digite a dist�ncia entre os corpos: ";
        cin >> distancia;
        cout <<"A for�a gravitacional entre os corpos � " << forcaGravitacional(massa1, massa2, distancia) << " dynes." <<endl;
        cout << "Deseja realizar outro c�lculo (Y para sim): ";
        cin >> op;
    }while(op=='y'||op=='Y');
    return 0;
}

double forcaGravitacional(double massa1, double massa2, double distancia)
{
        return CONSTANTEGRAVITACIONAL*massa1*massa2/(distancia*distancia);
}
