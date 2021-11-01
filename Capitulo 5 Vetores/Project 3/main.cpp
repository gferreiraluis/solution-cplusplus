#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*3. O desvio-padrão de uma lista de números é a medida de quanto os números se desviam da média. Se o
desvio-padrão é pequeno, os números estão aglomerados junto à média. Se o desvio-padrão é grande, os
números estão dispersos em relação à média. O desvio-padrão, S, de uma lista de N números xi é definido
da seguinte forma:
S = raíz(soma(xi - x-)^2 / N)
em que x– é a média de N números x1, x2, ... Defina uma função que tome um vetor parcialmente preenchido de números
e seu argumento e retorne o desvio-padrão dos números no vetor parcialmente preenchido.
Como um vetor parcialmente preenchido requer dois argumentos, a função, na realidade, terá dois parâmetros
formais: um parâmetro vetorial e um parâmetro formal de tipo int que fornece o número de posições vetoriais
utilizado. Os números no vetor serão de tipo double. Insira sua função em um
programa-teste adequado.*/

using namespace std;

const int TAMANHO_VETOR = 20;
void getData(double dados[], int tamanho);
double calculaDesvioPadrao(const double dados[], int tamanho);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double vetor[TAMANHO_VETOR], resultado;
    char op;
    int tamanho;
    do{
         do{
                cout<<"Digite a quantidade de números para o cálculo do desvio padrão (valor máximo "<< TAMANHO_VETOR <<"): ";
                cin >> tamanho;
                if(tamanho<1||tamanho>TAMANHO_VETOR)
                    cout<<"Valor inválido."<<endl;
           }while(tamanho<1||tamanho>TAMANHO_VETOR);
           cout << "Digite os valores: ";
           getData(vetor, tamanho);
           resultado = calculaDesvioPadrao(vetor, tamanho);
           cout<<"O desvio padrão é: "<<resultado<<"."<<endl;
           cout<< endl<< "Deseja reiniciar o programa (S/N): ";
            cin >> op;
    }while(op=='s'||op=='S');
    return 0;
}

void getData(double dados[], int tamanho)
{
     for(int i=0;i<tamanho;i++)
        cin >> dados[i];
}

double calculaDesvioPadrao(const double dados[], int tamanho)
{
    double soma = 0, media, aux = 0, desvioPadrao;
    for(int i=0; i<tamanho; i++)
        soma += dados[i];
    media = soma/tamanho;
    for(int i=0; i<tamanho;i++)
            aux+=pow(dados[i]-media,2);
    desvioPadrao = sqrt(aux/tamanho);
    return desvioPadrao;
}
