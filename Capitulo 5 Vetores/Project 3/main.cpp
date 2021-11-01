#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*3. O desvio-padr�o de uma lista de n�meros � a medida de quanto os n�meros se desviam da m�dia. Se o
desvio-padr�o � pequeno, os n�meros est�o aglomerados junto � m�dia. Se o desvio-padr�o � grande, os
n�meros est�o dispersos em rela��o � m�dia. O desvio-padr�o, S, de uma lista de N n�meros xi � definido
da seguinte forma:
S = ra�z(soma(xi - x-)^2 / N)
em que x� � a m�dia de N n�meros x1, x2, ... Defina uma fun��o que tome um vetor parcialmente preenchido de n�meros
e seu argumento e retorne o desvio-padr�o dos n�meros no vetor parcialmente preenchido.
Como um vetor parcialmente preenchido requer dois argumentos, a fun��o, na realidade, ter� dois par�metros
formais: um par�metro vetorial e um par�metro formal de tipo int que fornece o n�mero de posi��es vetoriais
utilizado. Os n�meros no vetor ser�o de tipo double. Insira sua fun��o em um
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
                cout<<"Digite a quantidade de n�meros para o c�lculo do desvio padr�o (valor m�ximo "<< TAMANHO_VETOR <<"): ";
                cin >> tamanho;
                if(tamanho<1||tamanho>TAMANHO_VETOR)
                    cout<<"Valor inv�lido."<<endl;
           }while(tamanho<1||tamanho>TAMANHO_VETOR);
           cout << "Digite os valores: ";
           getData(vetor, tamanho);
           resultado = calculaDesvioPadrao(vetor, tamanho);
           cout<<"O desvio padr�o �: "<<resultado<<"."<<endl;
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
