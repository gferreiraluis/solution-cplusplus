#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>



/*5. Um vetor pode ser usado para armazenar grandes inteiros, um d�gito de cada vez. Por exemplo, o inteiro
1234 pode ser armazenado no vetor a fixando-se a[0] como 1, a[1] como 2, a[2] como 3 e a[3] como 4.
Entretanto, para este exerc�cio voc� pode achar mais �til armazenar os d�gitos de tr�s para a frente, ou
seja, colocar o 4 em a[0], o 3 em a[1], o 2 em a[2] e o 1 em a[3]. Neste exerc�cio voc� escrever� um
programa que leia dois inteiros positivos de 20 ou menos d�gitos de comprimento e depois apresente a
soma dos dois n�meros. O programa ler� os d�gitos como valores do tipo char, de forma que o n�mero
1234 � lido como os quatro caracteres �1�, �2�, �3� e �4�. Depois de serem lidos pelo programa, os caracteres
ser�o alterados para valores de tipo int. Os d�gitos ser�o lidos e inseridos em um vetor parcialmente
preenchido, e talvez voc� ache �til inverter a ordem dos elementos no vetor depois que este seja preenchido
 com os dados do teclado. (A op��o entre inverter ou n�o a ordem dos elementos no vetor � sua. O
programa pode ser feito dos dois modos, e cada um tem suas vantagens e desvantagens.) O programa executar�
a adi��o, implementando o algoritmo comum da adi��o. O resultado da adi��o � armazenado em
um vetor de tamanho 20 e, ent�o, o resultado � escrito na tela. Se o resultado da adi��o � um inteiro
com mais do que o n�mero m�ximo de d�gitos (ou seja, mais de 20 d�gitos), seu programa deve emitir
uma mensagem dizendo que encontrou um "estouro de inteiros". Voc� deve ser capaz de alterar o comprimento
m�ximo dos inteiros mudando apenas uma constante definida globalmente. Inclua um loop que
permita ao usu�rio continuar a fazer adi��es at� dizer que o programa deve ser encerrado.*/

using namespace std;

const int TAMANHO_VETOR = 20;
void getData(char dados[], int tamanho);
void inverteVetor(char dados[], int tamanho);
void printVetor(char dados[], int tamanho);
void somaVetor(char dados1[],char dados2[], char resultado[], int tamanho1, int tamanho2, int& tamanho3);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int tamanho1, tamanho2, tamanho3;
    char numero1[TAMANHO_VETOR],numero2[TAMANHO_VETOR], resultado[TAMANHO_VETOR], op;
    do
    {
            do{
                    cout<<"Digite a quantidade de algorismos do primeiro n�mero (valor m�ximo "<< TAMANHO_VETOR <<"): ";
                    cin >> tamanho1;
                    if(tamanho1<1||tamanho1>TAMANHO_VETOR)
                            cout<<"Valor inv�lido."<<endl;
              }while(tamanho1<1||tamanho1>TAMANHO_VETOR);
            cout<<"Digite o n�mero desejado: ";
            getData(numero1,tamanho1);
            inverteVetor(numero1,tamanho1);
            do{
                    cout<<"Digite a quantidade de algorismos do segundo n�mero (valor m�ximo "<< TAMANHO_VETOR <<"): ";
                    cin >> tamanho2;
                    if(tamanho1<1||tamanho1>TAMANHO_VETOR)
                            cout<<"Valor inv�lido."<<endl;
              }while(tamanho1<1||tamanho1>TAMANHO_VETOR);
            cout<<"Digite o n�mero desejado: ";
            getData(numero2,tamanho2);
            inverteVetor(numero2,tamanho2);
            somaVetor(numero1,numero2,resultado,tamanho1,tamanho2,tamanho3);
            if(tamanho3>TAMANHO_VETOR)
                cout<<"O programa encontrou um estouro de inteiros."<<endl;
            else{
            inverteVetor(resultado,tamanho3);
            cout<<"A soma dos dois n�meros �: ";
            printVetor(resultado,tamanho3);
            }
            cout<< endl<< "Deseja reiniciar o programa (S/N): ";
            cin >> op;
    }while(op=='s'||op=='S');
     return 0;
}

void getData(char dados[], int tamanho)
{
    for(int i=0;i<tamanho;i++)
        cin >> dados[i];
    for(int i=TAMANHO_VETOR-1;i>=tamanho;i--)
        dados[i]='0';
}

void printVetor(char dados[], int tamanho)
{
    for(int i=0;i<tamanho;i++)
        cout<<dados[i];
    cout<<endl;
}

void inverteVetor(char dados[], int tamanho)
{
    char aux[TAMANHO_VETOR];
    for(int i=0;i<tamanho;i++)
    {
            aux[i] = dados[tamanho-1-i];
    }
    for(int i=0; i<tamanho;i++)
    {
        dados[i]=aux[i];
    }
}

void somaVetor(char dados1[],char dados2[], char resultado[], int tamanho1, int tamanho2, int& tamanho3)
{
    int tamanhoAux, somaAux, num1, num2, sobeUm=0;

    for(int i=0;i<TAMANHO_VETOR;i++)
        resultado[i]='0';
    if(tamanho1>tamanho2)
    {
        tamanhoAux = tamanho2;
        tamanho3 = tamanho1;
    }

    if(tamanho1<tamanho2)
    {
        tamanhoAux = tamanho1;
        tamanho3 = tamanho2;
    }
    if(tamanho1==tamanho2)
    {
        tamanhoAux = tamanho1;
        tamanho3 = tamanho1;
    }



    for(int i=0; i<tamanhoAux;i++)
    {
        num1 = dados1[i] - '0';
        num2 = dados2[i] - '0';
        somaAux = num1 + num2 + sobeUm;
        if(somaAux>=10)
        {
            resultado[i] = somaAux - 10 + '0';
            sobeUm = 1;
        }else{
            resultado[i] = somaAux + '0';
            sobeUm = 0;
            }
    }

    if(tamanho1>tamanho2)
    {
        for(int i=tamanhoAux;i<tamanho1;i++)
            resultado[i] = dados1[i];
    }
    if(tamanho1<tamanho2)
    {
        for(int i=tamanhoAux;i<tamanho2;i++)
            resultado[i] = dados2[i];
    }

    if(sobeUm==1)
    {
        if(tamanho1>tamanho2)
        {
            num1 = dados1[tamanhoAux] - '0';
            somaAux = num1 + 1;
            if(somaAux==10)
            {
                do
                {
                    resultado[tamanhoAux] = 0 + '0';
                    num2 = dados1[tamanhoAux+1] - '0';
                    somaAux = num2 + 1;
                    tamanhoAux++;
                }while(somaAux==10);
                tamanho3++;
            }

            resultado[tamanhoAux] = somaAux + '0';
        }
        if(tamanho1<tamanho2)
        {
            num1 = dados2[tamanhoAux] - '0';
            somaAux = num1 + 1;
            if(somaAux==10)
            {
                do
                {
                    resultado[tamanhoAux] = 0 + '0';
                    num2 = dados2[tamanhoAux+1] - '0';
                    somaAux = num2 + 1;
                    if(somaAux==10)
                        resultado[tamanhoAux+1] = 0 - '0';
                    else
                        resultado[tamanhoAux+1] = somaAux - '0';
                    tamanhoAux++;
                }while(somaAux==10);
                tamanho3++;
            }
            resultado[tamanhoAux] = somaAux + '0';

        }
        if(tamanho1==tamanho2)
        {
            resultado[tamanho1] = 1 + '0';
            tamanho3++;
        }
    }
}
