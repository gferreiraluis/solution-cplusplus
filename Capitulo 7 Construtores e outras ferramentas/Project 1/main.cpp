#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

using namespace std;

/*1. Defina uma classe chamada Mes que é um tipo de dado abstrato para um mês. Sua classe terá uma variável-membro
 de tipo int para representar um mês (1 para janeiro, 2 para fevereiro, e assim por diante).
Inclua todas as seguintes funções-membros: um construtor para estabelecer o mês utilizando as primeiras
três letras do nome do mês como três argumentos, um construtor para estabelecer o mês utilizando um
inteiro como argumento (1 para janeiro, 2 para fevereiro, e assim por diante), um construtor-padrão, uma
função de entrada que leia o mês como um inteiro, uma função de entrada que leia o mês como as primeiras três
 letras do nome do mês, uma função de saída que retorne o mês como um inteiro, uma função
de saída que retorne o mês como as três primeiras letras do nome do mês e uma função-membro que retorne o mês
seguinte como um valor do tipo Mes. Insira sua definição de classe em um programa-teste.*/

class Mes
{
    public:
        Mes();
        Mes(char letra1, char letra2, char letra3);
        Mes(int num);

        void leituraMesInt(Mes& obj);
        void leituraMesChar(Mes& obj);
        void saidaMesInt();
        void saidaMesChar();

    private:
        int mes_=0;
};


int main()
{
    setlocale(LC_ALL, "Portuguese");
    Mes obj;
    obj.leituraMesChar(obj);
    obj.saidaMesChar();
    obj.leituraMesInt(obj);
    obj.saidaMesInt();
    return 0;
}

Mes::Mes(){};

Mes::Mes(char letra1, char letra2, char letra3)
{
    if((letra1=='J'||letra1=='j')&&(letra2=='A'||letra2=='a')&&(letra3=='N'||letra3=='n'))
        mes_ = 1;
    if((letra1=='F'||letra1=='f')&&(letra2=='E'||letra2=='e')&&(letra3=='V'||letra3=='v'))
        mes_ = 2;
    if((letra1=='M'||letra1=='m')&&(letra2=='A'||letra2=='a')&&(letra3=='R'||letra3=='r'))
        mes_ = 3;
    if((letra1=='A'||letra1=='a')&&(letra2=='B'||letra2=='b')&&(letra3=='R'||letra3=='r'))
        mes_ = 4;
    if((letra1=='M'||letra1=='m')&&(letra2=='A'||letra2=='a')&&(letra3=='I'||letra3=='i'))
        mes_ = 5;
    if((letra1=='J'||letra1=='j')&&(letra2=='U'||letra2=='u')&&(letra3=='N'||letra3=='n'))
        mes_ = 6;
    if((letra1=='J'||letra1=='j')&&(letra2=='U'||letra2=='u')&&(letra3=='L'||letra3=='l'))
        mes_ = 7;
    if((letra1=='A'||letra1=='a')&&(letra2=='G'||letra2=='g')&&(letra3=='O'||letra3=='o'))
        mes_ = 8;
    if((letra1=='S'||letra1=='s')&&(letra2=='E'||letra2=='e')&&(letra3=='T'||letra3=='t'))
        mes_ = 9;
    if((letra1=='O'||letra1=='o')&&(letra2=='U'||letra2=='u')&&(letra3=='T'||letra3=='t'))
        mes_ = 10;
    if((letra1=='N'||letra1=='n')&&(letra2=='O'||letra2=='o')&&(letra3=='V'||letra3=='v'))
        mes_ = 11;
    if((letra1=='D'||letra1=='d')&&(letra2=='E'||letra2=='e')&&(letra3=='Z'||letra3=='z'))
        mes_ = 12;
}

Mes::Mes(int num)
{
    if(num>=1&&num<=12)
        mes_ = num;
}

void Mes::leituraMesInt(Mes& obj)
{
    int aux;
    do
    {
        cout<<endl<<"Digite o número referente ao mês desejado: ";
        cin >> aux;
        Mes dados(aux);
        obj = dados;
        if(aux<1||aux>12)
            cout<<"Valor inválido.";
        cout<<endl;
    }while(aux<1||aux>12);

}

void Mes::leituraMesChar(Mes& obj)
{
    char aux[3];
    do
    {
        cout<<"Digite as três primeiras letras referente ao mês desejado: ";
        for(int i=0; i<3; i++)
            cin >> aux[i];
        Mes dados(aux[0],aux[1],aux[2]);
        obj = dados;
        if(mes_==0)
            cout<<"Valor inválido.";
        cout<<endl;
    }while(mes_==0);
}

void Mes::saidaMesInt()
{
    cout << "Mês: " << mes_ <<endl;
}

void Mes::saidaMesChar()
{
    if(mes_==1)
        cout<<"Mês: JAN"<<endl;
    if(mes_==2)
        cout<<"Mês: FEV"<<endl;
    if(mes_==3)
        cout<<"Mês: MAR"<<endl;
    if(mes_==4)
        cout<<"Mês: ABR"<<endl;
    if(mes_==5)
        cout<<"Mês: MAI"<<endl;
    if(mes_==6)
        cout<<"Mês: JUN"<<endl;
    if(mes_==7)
        cout<<"Mês: JUL"<<endl;
    if(mes_==8)
        cout<<"Mês: AGO"<<endl;
    if(mes_==9)
        cout<<"Mês: SET"<<endl;
    if(mes_==10)
        cout<<"Mês: OUT"<<endl;
    if(mes_==11)
        cout<<"Mês: NOV"<<endl;
    if(mes_==12)
        cout<<"Mês: DEZ"<<endl;
}
