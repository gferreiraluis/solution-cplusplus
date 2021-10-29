#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


/*5. Escreva um programa que peça a altura, o peso e a idade do usuário e calcule o tamanho das roupas de
acordo com as seguintes fórmulas.
 Tamanho do chapéu = peso em libras* dividido pela altura em polegadas e tudo isso multiplicado por 2.9.
 Tamanho do casaco (tórax em polegadas) = altura vezes peso dividido por 288 e um ajuste efetuado
pelo acréscimo de um oitavo de uma polegada para cada 10 anos acima dos 30 anos. (Observe que o
ajuste só ocorre após 10 anos completos. Assim, não há ajuste para as idades de 30 a 39, mas um oitavo de
uma polegada é acrescentado para a idade 40.)
 Cintura em polegadas = peso dividido por 5.7 e um ajuste efetuado pelo acréscimo de um décimo de
uma polegada para cada 2 anos acima dos 28 anos. (Observe que o ajuste só ocorre após 2 anos completos.
Assim, não há ajuste para os 29 anos, mas um décimo de uma polegada é acrescentado para os 30 anos.)
Utilize funções para cada cálculo. Seu programa deve permitir que o usuário repita esse cálculo quantas
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
        cout << "A medida do chapéu é: " << tamanhoChapeu(peso,altura) <<" polegadas."<<endl;
        cout << "A medida do casaco é: " << tamanhoCasaco(peso,altura,idade) <<" polegadas."<<endl;
        cout << "A medida da cintura  é: " << tamanhoCintura(peso,idade) <<" polegadas."<<endl;
        cout << "Deseja realizar outro cálculo (Y para sim): ";
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
