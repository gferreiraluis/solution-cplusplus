#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*2. Escreva uma função chamada apagaRepetidas que tenha um vetor de caracteres parcialmente preenchido
como parâmetro formal e que remova todas as letras repetidas do vetor. Como um vetor parcialmente
preenchido exige dois argumentos, a função na realidade terá dois parâmetros formais: um parâmetro vetorial
 e um parâmetro formal de tipo int que fornece o número de posições vetoriais usadas. Quando
uma letra é removida, as letras restantes são movidas para a frente para preencher as vagas. Isso criará posições
 vazias no final do vetor, de modo que uma parte menor do vetor é utilizada. Como o parâmetro
formal é um vetor parcialmente preenchido, um segundo parâmetro formal de tipo int dirá quantas posições do vetor
são preenchidas. Este segundo parâmetro formal será um parâmetro chamado por referência
e será alterado para mostrar quanto do vetor é usado depois que as letras repetidas são removidas. Por
exemplo, considere o seguinte código:
char a[10];
a[0] = ’a’;
a[1] = ’b’;
a[2] = ’a’;
a[3] = ’c’;
int tamanho = 4;
apagaRepetidas(a, tamanho);
Depois que esse código é executado, o valor de a[0] é ’a’, o valor de a[1] é ’b’, o valor de a[2] é ’c’ e o
valor de tamanho é 3. (O valor de a[3] não importa, já que o vetor parcialmente preenchido não utiliza
mais essa variável indexada.) Você pode assumir que o vetor parcialmente preenchido contenha apenas letras minúsculas.
Insira sua função em um programa-teste adequado.*/

using namespace std;

const int TAMANHO_VETOR = 20;
int getData(char dados[]);
void apagaRepetidas(char a[], int& tamanho);
void printResultado(char a[], int tamanho);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char vetor [TAMANHO_VETOR], op;
    int tamanho;
    do{
        tamanho = getData(vetor);
        apagaRepetidas(vetor,tamanho);
        printResultado(vetor, tamanho);
        cout<< endl<< "Deseja reiniciar o programa (S/N): ";
        cin >> op;
      }while(op=='s'||op=='S');
    return 0;
}

int getData(char dados[])
{
    int aux;
    do{
        cout<<"Digite o tamanho do vetor (valor máximo "<< TAMANHO_VETOR <<"): ";
        cin >> aux;
        if(aux<1||aux>TAMANHO_VETOR)
            cout<<"Valor inválido."<<endl;
      }while(aux<1||aux>TAMANHO_VETOR);
    cout << "Digite os caracteres do vetor: ";
    for(int i=0;i<aux;i++)
        cin >> dados[i];
    return aux;
}

void apagaRepetidas(char a[], int& tamanho)
{
    for(int i=0;i<tamanho;i++)
    {
        for(int j=i+1;j<tamanho;j++)
        {
            if(a[i]==a[j])
            {
                a[j] = a[j+1];
                for(int k=j+1;k<tamanho;k++)
                    a[k]=a[k+1];
                tamanho--;
            }
        }
    }
}

void printResultado(char a[], int tamanho)
{
    cout << "O tamanho do vetor após apagar os caracteres repetidos é: " << tamanho <<endl;
    cout << "Vetor: ";
    for(int i = 0; i<tamanho; i++)
        cout << a[i] << " ";
}
