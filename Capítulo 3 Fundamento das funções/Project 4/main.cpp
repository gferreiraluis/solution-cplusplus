#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*A força de atração gravitacional entre dois corpos com massas m1 e m2, separados por uma distância d, é
dada pela seguinte fórmula:
F = Gm1m2/d^2
onde G é a constante de gravitação universal:
G = 6.673 x 10-8 cm3/(g • sec2)
Escreva uma definição de função que utilize argumentos para as massas de dois corpos e a distância entre
eles e forneça a força gravitacional entre eles. Como você irá utilizar a fórmula acima, a força gravitacional
será dada em dynes (dinas). Um dyne (dina) equivale a 1g • cm/sec2

Você deve usar uma constante globalmente definida para a constante de gravitação universal. Insira sua definição
de função em um programa completo que calcule a força gravitacional entre dois objetos com dados de
entrada adequados. Seu programa deve permitir que o usuário repita esse cálculo quantas vezes desejar*/

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
        cout << "Digite a distância entre os corpos: ";
        cin >> distancia;
        cout <<"A força gravitacional entre os corpos é " << forcaGravitacional(massa1, massa2, distancia) << " dynes." <<endl;
        cout << "Deseja realizar outro cálculo (Y para sim): ";
        cin >> op;
    }while(op=='y'||op=='Y');
    return 0;
}

double forcaGravitacional(double massa1, double massa2, double distancia)
{
        return CONSTANTEGRAVITACIONAL*massa1*massa2/(distancia*distancia);
}
