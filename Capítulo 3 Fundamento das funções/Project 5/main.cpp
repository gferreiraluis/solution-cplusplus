#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


/*5. Escreva um programa que pe�a a altura, o peso e a idade do usu�rio e calcule o tamanho das roupas de
acordo com as seguintes f�rmulas.
 Tamanho do chap�u = peso em libras* dividido pela altura em polegadas e tudo isso multiplicado por 2.9.
 Tamanho do casaco (t�rax em polegadas) = altura vezes peso dividido por 288 e um ajuste efetuado
pelo acr�scimo de um oitavo de uma polegada para cada 10 anos acima dos 30 anos. (Observe que o
ajuste s� ocorre ap�s 10 anos completos. Assim, n�o h� ajuste para as idades de 30 a 39, mas um oitavo de
uma polegada � acrescentado para a idade 40.)
 Cintura em polegadas = peso dividido por 5.7 e um ajuste efetuado pelo acr�scimo de um d�cimo de
uma polegada para cada 2 anos acima dos 28 anos. (Observe que o ajuste s� ocorre ap�s 2 anos completos.
Assim, n�o h� ajuste para os 29 anos, mas um d�cimo de uma polegada � acrescentado para os 30 anos.)
Utilize fun��es para cada c�lculo. Seu programa deve permitir que o usu�rio repita esse c�lculo quantas
vezes desejar.*/

using namespace std;

const double MEDIDACHAPEU = 2.9;
const double MEDIDACASACO = 288;
const double AJUSTECASACO = 0.125;
const double MEDIDACINTURA = 5.7;
const double AJUSTECINTURA = 0.1;

double tamanhoChapeu(double peso, double altura);
double tamanhoCasaco(double peso, double altura, int idade);
double tamanhoCintura(double peso, int idade);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char op;
    double altura, peso;
    int idade;
    do{
        cout << "Digite a sua altura (polegadas): ";
        cin >> altura;
        cout << "Digite o seu peso (libras): ";
        cin >> peso;
        cout << "Digite a sua idade: ";
        cin >> idade;
        cout << "A medida do chap�u �: " << tamanhoChapeu(peso,altura) <<" polegadas."<<endl;
        cout << "A medida do casaco �: " << tamanhoCasaco(peso,altura,idade) <<" polegadas."<<endl;
        cout << "A medida da cintura  �: " << tamanhoCintura(peso,idade) <<" polegadas."<<endl;
        cout << "Deseja realizar outro c�lculo (Y para sim): ";
        cin >> op;
    }while(op=='y'||op=='Y');
    return 0;
}

double tamanhoChapeu(double peso, double altura)
{
    return (peso/altura)*MEDIDACHAPEU;
}

double tamanhoCasaco(double peso, double altura, int idade)
{
    return (altura*peso/MEDIDACASACO + floor((idade - 30)/10)*AJUSTECASACO);
}

double tamanhoCintura(double peso, int idade)
{
   return (peso/MEDIDACINTURA + floor((idade - 28)/2)*AJUSTECINTURA);
}
