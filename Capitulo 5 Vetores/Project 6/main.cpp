#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*6. Escreva um programa que permita dois usuários jogar o jogo-da-velha. O programa deve pedir que os jogadores
 X e O informem os lances alternadamente. O programa exibe as posições do jogo da seguinte forma:
1 2 3
4 5 6
7 8 9
O jogador faz o lance informando o número da posição que deseja assinalar. Após cada lance, o programa
exibe o tabuleiro. Um exemplo de configuração de tabuleiro:
X X O
4 5 6
O 8 9*/

using namespace std;

void imprimeTabuleiro(const char dados[]);
void lance(char dados[], int id);
bool verificaVencedor(const char dados[]);
void limpaTabuleiro(char dados[]);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char tabuleiro[9]={'1','2','3','4','5','6','7','8','9'}, op;
    int id=0;
    bool vencedor;
    do{
            cout<<"##### JOGO DA VELHA ######"<<endl;
            imprimeTabuleiro(tabuleiro);
            do
            {
                lance(tabuleiro,id);
                imprimeTabuleiro(tabuleiro);
                vencedor = verificaVencedor(tabuleiro);
                id++;
                if(id==9)
                    break;
            }while(vencedor==false);
             if(id==9&&vencedor==false)
                cout<<"A partida terminou empatada."<<endl;
             if(vencedor==true&&id%2==0)
                cout<<"O jogador O venceu a partida."<<endl;
             if(vencedor==true&&id%2!=0)
                cout<<"O jogador X venceu a partida."<<endl;
            cout<< endl<< "Deseja iniciar uma nova partida(S/N): ";
            cin >> op;
            if(op=='s'||op=='S')
            {
                id=0;
                limpaTabuleiro(tabuleiro);
            }
        }while(op=='s'||op=='S');


    return 0;
}

void imprimeTabuleiro(const char dados[])
{
    cout<<endl;
    for(int i=0; i<9; i++)
    {
        if(i==0||i==3||i==6)
            cout<<"\t";
        cout<< dados[i] <<"   ";
        if(i==2||i==5||i==8)
            cout<<endl;
    }
    cout<<endl;
}

void lance(char dados[], int id)
{
    int posicao;
    if(id%2==0)
    {
        do
        {
           cout<<"Escolha uma posição da tabela para assinalar o X: ";
           cin >> posicao;
           if(posicao<0||posicao>9)
                cout<<"Posição informada é inválida."<<endl;
           if(dados[posicao-1]=='X'||dados[posicao-1]=='O')
                cout<<"A posição já foi preenchida. Escolha outra posição."<<endl;
        }while(posicao<0||posicao>9||dados[posicao-1]=='X'||dados[posicao-1]=='O');
        dados[posicao-1] = 'X';
    }
    if(id%2!=0)
    {
        do
        {
           cout<<"Escolha uma posição da tabela para assinalar o O: ";
           cin >> posicao;
           if(posicao<0||posicao>9)
                cout<<"Posição informada é inválida."<<endl;
           if(dados[posicao-1]=='X'||dados[posicao-1]=='O')
                cout<<"A posição já foi preenchida. Escolha outra posição."<<endl;
        }while(posicao<0||posicao>9||dados[posicao-1]=='X'||dados[posicao-1]=='O');
        dados[posicao-1] = 'O';
    }
}

bool verificaVencedor(const char dados[])
{
    if(dados[0]==dados[1]&&dados[1]==dados[2])
        return true;
    if(dados[3]==dados[4]&&dados[4]==dados[5])
        return true;
    if(dados[6]==dados[7]&&dados[7]==dados[8])
        return true;
    if(dados[0]==dados[3]&&dados[3]==dados[6])
        return true;
    if(dados[1]==dados[4]&&dados[4]==dados[7])
        return true;
    if(dados[2]==dados[5]&&dados[5]==dados[8])
        return true;
    if(dados[0]==dados[4]&&dados[4]==dados[8])
        return true;
    if(dados[2]==dados[4]&&dados[4]==dados[6])
        return true;

    return false;
}

void limpaTabuleiro(char dados[])
{
    for(int i=0; i<9; i++)
        dados[i] = i + 1 + '0';
}
