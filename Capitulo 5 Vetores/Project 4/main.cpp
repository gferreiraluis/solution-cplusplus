#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*4. Escreva um programa que leia um vetor de tipo int. Você pode presumir que existam menos de 50 elementos
 no vetor. O programa determina quantas posições são ocupadas. A saída deve ser em uma lista de
duas colunas. A primeira coluna é uma lista dos diferentes elementos do vetor; a segunda coluna é a contagem
 do número de ocorrências de cada elemento. A lista deve ser ordenada com base na primeira coluna, do maior para o menor.
Para os seguintes valores:
-12 3 -12 4 1 1 -12 1 -1 1 2 3 4 2 3 -12
a saída deve ser
 N Count
 4 2
 3 3
 2 2
 1 4
-1 1
-12 4*/

using namespace std;

const int TAMANHO_VETOR = 20;
void getData(int dados[], int tamanho);
void contaElementos(int dados[], int tamanho);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int vetor[TAMANHO_VETOR], tamanho;
    char op;
    do{
         do{
                cout<<"Digite o tamanho do vetor (valor máximo "<< TAMANHO_VETOR <<"): ";
                cin >> tamanho;
                if(tamanho<1||tamanho>TAMANHO_VETOR)
                    cout<<"Valor inválido."<<endl;
           }while(tamanho<1||tamanho>TAMANHO_VETOR);
           cout << "Digite os valores dos elementos do vetor: ";
           getData(vetor, tamanho);
           contaElementos(vetor, tamanho);
           cout<< endl<< "Deseja reiniciar o programa (S/N): ";
           cin >> op;
    }while(op=='s'||op=='S');
    return 0;
}

void getData(int dados[], int tamanho)
{
     for(int i=0;i<tamanho;i++)
        cin >> dados[i];
}

void contaElementos(int dados[], int tamanho)
{
    int contador = 1, aux;

    for(int i=0;i<tamanho;i++)
    {
        for(int j=i+1;j<tamanho;j++)
        {

            if(dados[i]<dados[j])
            {
                aux = dados[i];
                dados[i] = dados[j];
                dados[j] = aux;
            }
        }
    }

    cout << "N\t" <<"Count"<<endl;
    for(int i=0;i<tamanho;i++)
    {
        for(int j=i+1;j<tamanho;j++)
        {
            if(dados[i]==dados[j])
            {
                for(int k=j;k<tamanho;k++)
                    dados[k]=dados[k+1];
                tamanho--;
                contador++;
                j--;
            }
        }
        cout << dados[i] <<"\t"<<contador<<endl;
        contador = 1;
    }
}
