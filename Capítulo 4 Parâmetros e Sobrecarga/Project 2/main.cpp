#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*2. A �rea de um tri�ngulo arbitr�rio pode ser calculada por meio da f�rmula
area = raiz(s(s-a)(s-b)(s-c))
onde a, b e c s�o as medidas dos lados e s � o semiper�metro.
s = (a+b+c)/2
Escreva uma fun��o void que utilize cinco par�metros: tr�s par�metros chamados por valor que forne�am
a medida dos lados e dois par�metros chamados por refer�ncia que calculem a �rea e o per�metro (n�o o
semiper�metro). Torne sua fun��o robusta. Observe que nem todas as combina��es de a, b e c produzem
um tri�ngulo. Sua fun��o deve corrigir resultados para dados legais e resultados coerentes para combina��es ilegais.*/

using namespace std;

void funcaoTriangulo(double a, double b, double c, double& area, double& perimetro);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double a, b, c, area, perimetro;
    do
    {
        cout << "Digite o valor do lado a do tri�ngulo: ";
        cin >> a;
        cout << "Digite o valor do lado b do tri�ngulo: ";
        cin >> b;
        cout << "Digite o valor do lado c do tri�ngulo: ";
        cin >> c;
        if(!((abs(b-c)<a&&a<b+c)||(abs(a-c)<b&&b<a+c)||(abs(a-b)<c&&c<b+a)))
            cout << "Os valores fornecidos n�o formam um tri�ngulo." <<endl;
    }while(!((abs(b-c)<a&&a<b+c)||(abs(a-c)<b&&b<a+c)||(abs(a-b)<c&&c<b+a)));

    funcaoTriangulo(a,b,c,area,perimetro);

    cout << "�rea do tri�ngulo: " << area << endl;
    cout << "Per�metro do tri�ngulo: " << perimetro << endl;

    return 0;
}

void funcaoTriangulo(double a, double b, double c, double& area, double& perimetro)
{
    double s = (a+b+c)/2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    perimetro = a+b+c;
}




