#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*7. Escreva um programa para atribuir assentos a passageiros em um avião. Considere um avião pequeno com
assentos numerados da seguinte forma;
1 A B C D
2 A B C D
3 A B C D
4 A B C D
5 A B C D
6 A B C D
7 A B C D
O programa deve exibir o padrão dos assentos, com um ’X’ assinalando os assentos já atribuídos. Por
exemplo, depois que os assentos 1A, 2B e 4C já foram atribuídos, o padrão deve ser o seguinte:
1 X B C D
2 A X C D
3 A B C D
4 A B X D
5 A B C D
6 A B C D
7 A B C D
Depois de mostrar os assentos disponíveis, o programa pede que o usuário indique o assento desejado, o
usuário digita a informação pedida e depois o quadro de assentos disponíveis é atualizado. Isso prossegue
até que todos os assentos sejam ocupados ou até o usuário pedir que o programa termine. Se o usuário escolher
um assento já atribuído, o programa deve dizer que o assento está ocupado e pedir que o usuário
escolha outro*/

using namespace std;

const int LINHAS_MATRIZ = 7;
const int COLUNAS_MATRIZ = 4;
void iniciaAssentos(char dados[][COLUNAS_MATRIZ]);
void printAssentos(const char dados[][COLUNAS_MATRIZ]);
bool reservaAssento(char dados[][COLUNAS_MATRIZ], int fileira, char assento);



int main()
{
    setlocale(LC_ALL, "Portuguese");
    char assentos[LINHAS_MATRIZ][COLUNAS_MATRIZ], assento, op;
    int fila, contador=0;
    bool aux;
    iniciaAssentos(assentos);

    do
    {
            cout <<endl<< "ASSENTOS DISPONÍVEIS: "<< endl;
            printAssentos(assentos);
            do
            {
                cout<<endl<<"Escolha a fileira desejada: ";
                cin>>fila;
                if(fila<1||fila>LINHAS_MATRIZ)
                    cout<<"Opção inválida."<<endl;
            }while(fila<1||fila>LINHAS_MATRIZ);

            do
            {
                cout<<endl<<"Escolha o assento desejado: ";
                cin>>assento;
                if(assento=='a')
                    assento='A';
                if(assento=='b')
                    assento='B';
                if(assento=='c')
                    assento='C';
                if(assento=='d')
                    assento='D';
                if(assento!='A'&&assento!='B'&&assento!='C'&&assento!='D')
                    cout<<"Opção inválida."<<endl;
            }while(assento!='A'&&assento!='B'&&assento!='C'&&assento!='D');

            aux = reservaAssento(assentos,fila,assento);
            if(aux==true)
                contador++;
            if(contador==LINHAS_MATRIZ*COLUNAS_MATRIZ)
            {
                cout<<endl<<"Todos os assentos estão reservados."<<endl;
                cout <<endl<< "ASSENTOS DISPONÍVEIS: "<< endl;
                printAssentos(assentos);
                cout<<endl<<"Deseja reiniciar o programa?(S/N): ";
                cin>> op;
                if(op=='s'||op=='S')
                    iniciaAssentos(assentos);
                else
                    break;
            }
            cout <<endl<< "ASSENTOS DISPONÍVEIS: "<< endl;
            printAssentos(assentos);
            cout<<endl<<"Deseja reservar outro assento?(S/N): ";
            cin >> op;
    }while(op=='s'||op=='S');

    return 0;
}

void iniciaAssentos(char dados[][COLUNAS_MATRIZ])
{
    for(int i=0;i<LINHAS_MATRIZ;i++)
    {
        for(int j=0;j<COLUNAS_MATRIZ;j++)
        {
            dados[i][j] = j + 65;
        }
    }
}

void printAssentos(const char dados[][COLUNAS_MATRIZ])
{
    cout<<endl;
    for(int i=0; i<LINHAS_MATRIZ;i++)
    {
        cout<<"\t"<<i+1<<"  ";
        for(int j=0; j<COLUNAS_MATRIZ; j++)
        {
            cout<<dados[i][j]<<" ";
            if(j%2==1)
                cout<<"   ";
        }
        cout<<endl;
    }
}

bool reservaAssento(char dados[][COLUNAS_MATRIZ], int fileira, char assento)
{
    if(dados[fileira-1][assento-65]=='X')
    {
        cout<<"Assento indisponível."<<endl;
        return false;
    }
    else
    {
        dados[fileira-1][assento-65] = 'X';
        return true;
    }
}
