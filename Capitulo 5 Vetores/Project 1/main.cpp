#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*1. Escreva um programa que leia a quantidade média de chuva mensal de uma cidade para cada mês do ano
e depois leia a quantidade real de chuva para cada um dos 12 meses anteriores. Assim, o programa imprime
uma tabela bem formatada que mostra a quantidade de chuva para cada um dos 12 meses anteriores
e também quão acima ou quão abaixo da média a quantidade de chuva foi a cada mês. A média mensal é
dada pelos meses de janeiro, fevereiro e assim por diante, em seqüência. Para obter a quantidade de chuva
real nos 12 meses anteriores, o programa primeiro pergunta qual é o mês atual e depois pede as cifras da
quantidade de chuva nos 12 meses anteriores. A saída deve nomear corretamente os meses.
Existem várias formas de se lidar com nomes de meses. Um método simples é codificar os meses como
inteiros e depois fazer uma conversão antes de executar a saída. Um grande comando switch é aceitável
em uma função de saída. A entrada dos meses pode ser tratada da maneira que você desejar, desde que
seja relativamente fácil e agradável para o usuário.
Depois que houver acabado o programa acima, produza uma versão aperfeiçoada que também apresente
um gráfico exibindo a quantidade média e a quantidade real de chuva para cada um dos 12 meses anteriores.
 O gráfico deve ser similar àquele mostrado no Painel 5.4, a não ser pelo fato de que deve haver
duas barras para cada mês e estas devem receber os rótulos de quantidade média de chuva e quantidade
de chuva no último mês. Seu programa deve perguntar se o usuário deseja ver a tabela ou o gráfico de
barras, e depois deve exibir o formato requisitado. Inclua um loop que permita que o usuário veja um ou
outro formato quantas vezes desejar até requisitar que o programa se encerre.*/

using namespace std;

const int NUMERO_MESES = 12;

void getDataMedia(double dados[]);
void getDataQtdade(double dados[]);
void tabelaChuva(double dados1[], double dados2[]);
void graficoChuva(double dados1[], double dados2[]);
void printAsterisco(double print);



int main()
{
    setlocale(LC_ALL, "Portuguese");
    double mediaChuva[NUMERO_MESES], qtdadeChuva[NUMERO_MESES];
    char op;
    do{
        getDataMedia(mediaChuva);
        getDataQtdade(qtdadeChuva);
        tabelaChuva(qtdadeChuva,mediaChuva);
        graficoChuva(qtdadeChuva,mediaChuva);
        cout<<"Deseja reiniciar o programa? (Y/N): ";
        cin >> op;
      }while(op=='Y'||op=='y');

    return 0;
}

void getDataMedia(double dados[])
{
    cout << "Digite a quantidade MÉDIA de chuva mensal." << endl;
    for(int i=0; i<NUMERO_MESES; i++)
    {
        switch(i)
        {
            case 0:
            cout<<"Janeiro: ";
            cin >> dados[i];
            break;
            case 1:
            cout<<"Fevereiro: ";
            cin >> dados[i];
            break;
            case 2:
            cout<<"Março: ";
            cin >> dados[i];
            break;
            case 3:
            cout<<"Abril: ";
            cin >> dados[i];
            break;
            case 4:
            cout<<"Maio: ";
            cin >> dados[i];
            break;
            case 5:
            cout<<"Junho: ";
            cin >> dados[i];
            break;
            case 6:
            cout<<"Julho: ";
            cin >> dados[i];
            break;
            case 7:
            cout<<"Agosto: ";
            cin >> dados[i];
            break;
            case 8:
            cout<<"Setembro: ";
            cin >> dados[i];
            break;
            case 9:
            cout<<"Outubro: ";
            cin >> dados[i];
            break;
            case 10:
            cout<<"Novembro: ";
            cin >> dados[i];
            break;
            case 11:
            cout<<"Dezembro: ";
            cin >> dados[i];
            break;
        }
    }
}

void getDataQtdade(double dados[])
{
    int aux;
    do
    {
        cout<<"Digite o mês atual (1 a 12):";
        cin >> aux;
        if(aux<1||aux>12)
            cout<<"Mês inválido."<<endl;
    }while(aux<1||aux>12);
    aux = aux-1;
    cout << "Digite o valor da quantidade real de chuva dos ultimos 12 meses." << endl;
    for(int i=(aux-12); i<(NUMERO_MESES-(12-aux)); i++)
    {
            if(i==0){
            cout<<"Janeiro: ";
            cin >> dados[0];
            }
            if(i==1||i==-11){
            cout<<"Fevereiro: ";
            cin >> dados[1];
            }
            if(i==2||i==-10){
            cout<<"Março: ";
            cin >> dados[2];
            }
            if(i==3||i==-9){
            cout<<"Abril: ";
            cin >> dados[3];
            }
            if(i==4||i==-8){
            cout<<"Maio: ";
            cin >> dados[4];
            }
            if(i==5||i==-7){
            cout<<"Junho: ";
            cin >> dados[5];
            }
            if(i==6||i==-6){
            cout<<"Julho: ";
            cin >> dados[6];
            }
            if(i==7||i==-5){
            cout<<"Agosto: ";
            cin >> dados[7];
            }
            if(i==8||i==-4){
            cout<<"Setembro: ";
            cin >> dados[8];
            }
            if(i==9||i==-3){
            cout<<"Outubro: ";
            cin >> dados[9];
            }
            if(i==10||i==-2){
            cout<<"Novembro: ";
            cin >> dados[10];
            }
            if(i==11||i==-1){
            cout<<"Dezembro: ";
            cin >> dados[11];
            }
        }
}

void tabelaChuva(double dados1[], double dados2[])
{
    cout<<endl<<endl<<"\t\t Quantidade de chuva\t\tMédia de chuva\t\tDiferença Quantidade e Média" <<endl;
    for(int i=0; i<NUMERO_MESES;i++)
    {
        switch(i){
            case 0:
            cout<<"Janeiro  \t         "<<dados1[i]<<"\t                  "<<dados2[i]<<"\t                       "<< dados1[i]-dados2[i] <<endl;
            break;
            case 1:
            cout<<"Fevereiro\t         "<<dados1[i]<<"\t                  "<<dados2[i]<<"\t                       "<< dados1[i]-dados2[i] <<endl;
            break;
            case 2:
            cout<<"Março    \t         "<<dados1[i]<<"\t                  "<<dados2[i]<<"\t                       "<< dados1[i]-dados2[i] <<endl;
            break;
            case 3:
            cout<<"Abril    \t         "<<dados1[i]<<"\t                  "<<dados2[i]<<"\t                       "<< dados1[i]-dados2[i] <<endl;
            break;
            case 4:
            cout<<"Maio     \t         "<<dados1[i]<<"\t                  "<<dados2[i]<<"\t                       "<< dados1[i]-dados2[i] <<endl;
            break;
            case 5:
            cout<<"Junho    \t         "<<dados1[i]<<"\t                  "<<dados2[i]<<"\t                       "<< dados1[i]-dados2[i] <<endl;
            break;
            case 6:
            cout<<"Julho    \t         "<<dados1[i]<<"\t                  "<<dados2[i]<<"\t                       "<< dados1[i]-dados2[i] <<endl;
            break;
            case 7:
            cout<<"Agosto   \t         "<<dados1[i]<<"\t                  "<<dados2[i]<<"\t                       "<< dados1[i]-dados2[i] <<endl;
            break;
            case 8:
            cout<<"Setembro \t         "<<dados1[i]<<"\t                  "<<dados2[i]<<"\t                       "<< dados1[i]-dados2[i] <<endl;
            break;
            case 9:
            cout<<"Outubro  \t         "<<dados1[i]<<"\t                  "<<dados2[i]<<"\t                       "<< dados1[i]-dados2[i] <<endl;
            break;
            case 10:
            cout<<"Novembro \t         "<<dados1[i]<<"\t                  "<<dados2[i]<<"\t                       "<< dados1[i]-dados2[i] <<endl;
            break;
            case 11:
            cout<<"Dezembro \t         "<<dados1[i]<<"\t                  "<<dados2[i]<<"\t                       "<< dados1[i]-dados2[i] <<endl;
            break;
        }
    }
}

void graficoChuva(double dados1[], double dados2[])
{
    cout <<endl<<endl<< "Gráfico da quantidade média e quantidade real de chuva."<<endl<<endl;
    for(int i=0; i<NUMERO_MESES; i++)
    {
        switch(i)
        {
            case 0:
            cout <<"Janeiro: " <<endl;
            break;
            case 1:
            cout <<"Fevereiro: " <<endl;
            break;
            case 2:
            cout <<"Março: " <<endl;
            break;
            case 3:
            cout <<"Abril: " <<endl;
            break;
            case 4:
            cout <<"Maio: " <<endl;
            break;
            case 5:
            cout <<"Junho: " <<endl;
            break;
            case 6:
            cout <<"Julho: " <<endl;
            break;
            case 7:
            cout <<"Agosto: " <<endl;
            break;
            case 8:
            cout <<"Setembro: " <<endl;
            break;
            case 9:
            cout <<"Outubro: " <<endl;
            break;
            case 10:
            cout <<"Novembro: " <<endl;
            break;
            case 11:
            cout <<"Dezembro: " <<endl;
            break;
        }

        cout << "Quantidade real:  ";
        printAsterisco(dados1[i]);
        cout <<endl<< "Quantidade média: ";
        printAsterisco(dados2[i]);
        cout<<endl<<endl;
    }
}

void printAsterisco(double print)
{
    for(int i=0; i<print; i++)
        cout<<"*";
}
