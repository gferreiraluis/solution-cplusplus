#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*2. A área de um triângulo arbitrário pode ser calculada por meio da fórmula
area = raiz(s(s-a)(s-b)(s-c))
onde a, b e c são as medidas dos lados e s é o semiperímetro.
s = (a+b+c)/2
Escreva uma função void que utilize cinco parâmetros: três parâmetros chamados por valor que forneçam
a medida dos lados e dois parâmetros chamados por referência que calculem a área e o perímetro (não o
semiperímetro). Torne sua função robusta. Observe que nem todas as combinações de a, b e c produzem
um triângulo. Sua função deve corrigir resultados para dados legais e resultados coerentes para combinações ilegais.*/

using namespace std;

void funcaoTriangulo(double a, double b, double c, double& area, double& perimetro);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double a, b, c, area, perimetro;
    do
    {
        cout << "Digite o valor do lado a do triângulo: ";
        cin >> a;
        cout << "Digite o valor do lado b do triângulo: ";
        cin >> b;
        cout << "Digite o valor do lado c do triângulo: ";
        cin >> c;
        if(!((abs(b-c)<a&&a<b+c)||(abs(a-c)<b&&b<a+c)||(abs(a-b)<c&&c<b+a)))
            cout << "Os valores fornecidos não formam um triângulo." <<endl;
    }while(!((abs(b-c)<a&&a<b+c)||(abs(a-c)<b&&b<a+c)||(abs(a-b)<c&&c<b+a)));

    funcaoTriangulo(a,b,c,area,perimetro);

    cout << "Área do triângulo: " << area << endl;
    cout << "Perímetro do triângulo: " << perimetro << endl;

    return 0;
}

void funcaoTriangulo(double a, double b, double c, double& area, double& perimetro)
{
    double s = (a+b+c)/2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    perimetro = a+b+c;
}




