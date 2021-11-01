#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*2. Escreva uma fun��o chamada apagaRepetidas que tenha um vetor de caracteres parcialmente preenchido
como par�metro formal e que remova todas as letras repetidas do vetor. Como um vetor parcialmente
preenchido exige dois argumentos, a fun��o na realidade ter� dois par�metros formais: um par�metro vetorial
 e um par�metro formal de tipo int que fornece o n�mero de posi��es vetoriais usadas. Quando
uma letra � removida, as letras restantes s�o movidas para a frente para preencher as vagas. Isso criar� posi��es
 vazias no final do vetor, de modo que uma parte menor do vetor � utilizada. Como o par�metro
formal � um vetor parcialmente preenchido, um segundo par�metro formal de tipo int dir� quantas posi��es do vetor
s�o preenchidas. Este segundo par�metro formal ser� um par�metro chamado por refer�ncia
e ser� alterado para mostrar quanto do vetor � usado depois que as letras repetidas s�o removidas. Por
exemplo, considere o seguinte c�digo:
char a[10];
a[0] = �a�;
a[1] = �b�;
a[2] = �a�;
a[3] = �c�;
int tamanho = 4;
apagaRepetidas(a, tamanho);
Depois que esse c�digo � executado, o valor de a[0] � �a�, o valor de a[1] � �b�, o valor de a[2] � �c� e o
valor de tamanho � 3. (O valor de a[3] n�o importa, j� que o vetor parcialmente preenchido n�o utiliza
mais essa vari�vel indexada.) Voc� pode assumir que o vetor parcialmente preenchido contenha apenas letras min�sculas.
Insira sua fun��o em um programa-teste adequado.*/

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
        cout<<"Digite o tamanho do vetor (valor m�ximo "<< TAMANHO_VETOR <<"): ";
        cin >> aux;
        if(aux<1||aux>TAMANHO_VETOR)
            cout<<"Valor inv�lido."<<endl;
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
    cout << "O tamanho do vetor ap�s apagar os caracteres repetidos �: " << tamanho <<endl;
    cout << "Vetor: ";
    for(int i = 0; i<tamanho; i++)
        cout << a[i] << " ";
}
