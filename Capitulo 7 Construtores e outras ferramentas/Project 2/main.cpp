#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

using namespace std;

/*2. Redefina a implementa��o da classe Mes descrita no Projeto de Programa��o 1 (ou fa�a a defini��o pela
primeira vez, mas fa�a a implementa��o como descrita aqui). Desta vez, o m�s � implementado como tr�s
vari�veis-membros de tipo char que armazenam as tr�s primeiras letras do nome do m�s. Insira sua defini��o
 em um programa-teste.*/

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
        char letra1_;
        char letra2_;
        char letra3_;
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
        {
            letra1_ = 'J';
            letra2_ = 'A';
            letra3_ = 'N';
            mes_ = 1;
        }
    if((letra1=='F'||letra1=='f')&&(letra2=='E'||letra2=='e')&&(letra3=='V'||letra3=='v'))
          {
            letra1_ = 'F';
            letra2_ = 'E';
            letra3_ = 'V';
            mes_ = 2;
        }
    if((letra1=='M'||letra1=='m')&&(letra2=='A'||letra2=='a')&&(letra3=='R'||letra3=='r'))
          {
            letra1_ = 'M';
            letra2_ = 'A';
            letra3_ = 'R';
            mes_ = 3;
        }
    if((letra1=='A'||letra1=='a')&&(letra2=='B'||letra2=='b')&&(letra3=='R'||letra3=='r'))
          {
            letra1_ = 'A';
            letra2_ = 'B';
            letra3_ = 'R';
            mes_ = 4;
        }
    if((letra1=='M'||letra1=='m')&&(letra2=='A'||letra2=='a')&&(letra3=='I'||letra3=='i'))
          {
            letra1_ = 'M';
            letra2_ = 'A';
            letra3_ = 'I';
            mes_ = 5;
        }
    if((letra1=='J'||letra1=='j')&&(letra2=='U'||letra2=='u')&&(letra3=='N'||letra3=='n'))
        {
            letra1_ = 'J';
            letra2_ = 'U';
            letra3_ = 'N';
            mes_ = 6;

        }
    if((letra1=='J'||letra1=='j')&&(letra2=='U'||letra2=='u')&&(letra3=='L'||letra3=='l'))
          {
            letra1_ = 'J';
            letra2_ = 'U';
            letra3_ = 'L';
            mes_ = 7;
        }
    if((letra1=='A'||letra1=='a')&&(letra2=='G'||letra2=='g')&&(letra3=='O'||letra3=='o'))
          {
            letra1_ = 'A';
            letra2_ = 'G';
            letra3_ = 'O';
            mes_ = 8;
        }
    if((letra1=='S'||letra1=='s')&&(letra2=='E'||letra2=='e')&&(letra3=='T'||letra3=='t'))
          {
            letra1_ = 'S';
            letra2_ = 'E';
            letra3_ = 'T';
            mes_ = 9;
        }
    if((letra1=='O'||letra1=='o')&&(letra2=='U'||letra2=='u')&&(letra3=='T'||letra3=='t'))
          {
            letra1_ = 'O';
            letra2_ = 'U';
            letra3_ = 'T';
            mes_ = 10;
        }
    if((letra1=='N'||letra1=='n')&&(letra2=='O'||letra2=='o')&&(letra3=='V'||letra3=='v'))
          {
            letra1_ = 'N';
            letra2_ = 'O';
            letra3_ = 'V';
            mes_ = 11;
        }
    if((letra1=='D'||letra1=='d')&&(letra2=='E'||letra2=='e')&&(letra3=='Z'||letra3=='z'))
          {
            letra1_ = 'D';
            letra2_ = 'E';
            letra3_ = 'Z';
            mes_ = 12;
        }
}

Mes::Mes(int num)
{
    if(num==1)
        {
            letra1_ = 'J';
            letra2_ = 'A';
            letra3_ = 'N';
            mes_ = 1;
        }
    if(num==2)
          {
            letra1_ = 'F';
            letra2_ = 'E';
            letra3_ = 'V';
            mes_ = 2;
        }
    if(num==3)
          {
            letra1_ = 'M';
            letra2_ = 'A';
            letra3_ = 'R';
            mes_ = 3;
        }
    if(num==4)
          {
            letra1_ = 'A';
            letra2_ = 'B';
            letra3_ = 'R';
            mes_ = 4;
        }
    if(num==5)
          {
            letra1_ = 'M';
            letra2_ = 'A';
            letra3_ = 'I';
            mes_ = 5;
        }
    if(num==6)
        {
            letra1_ = 'J';
            letra2_ = 'U';
            letra3_ = 'N';
            mes_ = 6;

        }
    if(num==7)
          {
            letra1_ = 'J';
            letra2_ = 'U';
            letra3_ = 'L';
            mes_ = 7;
        }
    if(num==8)
          {
            letra1_ = 'A';
            letra2_ = 'G';
            letra3_ = 'O';
            mes_ = 8;
        }
    if(num==9)
          {
            letra1_ = 'S';
            letra2_ = 'E';
            letra3_ = 'T';
            mes_ = 9;
        }
    if(num==10)
          {
            letra1_ = 'O';
            letra2_ = 'U';
            letra3_ = 'T';
            mes_ = 10;
        }
    if(num==11)
          {
            letra1_ = 'N';
            letra2_ = 'O';
            letra3_ = 'V';
            mes_ = 11;
        }
    if(num==12)
          {
            letra1_ = 'D';
            letra2_ = 'E';
            letra3_ = 'Z';
            mes_ = 12;
        }
}

void Mes::leituraMesInt(Mes& obj)
{
    int aux;
    do
    {
        cout<<endl<<"Digite o n�mero referente ao m�s desejado: ";
        cin >> aux;
        Mes dados(aux);
        obj = dados;
        if(aux<1||aux>12)
            cout<<"Valor inv�lido.";
        cout<<endl;
    }while(aux<1||aux>12);

}

void Mes::leituraMesChar(Mes& obj)
{
    char aux[3];
    do
    {
        cout<<"Digite as tr�s primeiras letras referente ao m�s desejado: ";
        for(int i=0; i<3; i++)
            cin >> aux[i];
        Mes dados(aux[0],aux[1],aux[2]);
        obj = dados;
        if(mes_==0)
            cout<<"Valor inv�lido.";
        cout<<endl;
    }while(mes_==0);
}

void Mes::saidaMesInt()
{
    cout << "M�s: " << mes_ <<endl;
}

void Mes::saidaMesChar()
{
    if(mes_==1)
        cout<<"M�s: JAN"<<endl;
    if(mes_==2)
        cout<<"M�s: FEV"<<endl;
    if(mes_==3)
        cout<<"M�s: MAR"<<endl;
    if(mes_==4)
        cout<<"M�s: ABR"<<endl;
    if(mes_==5)
        cout<<"M�s: MAI"<<endl;
    if(mes_==6)
        cout<<"M�s: JUN"<<endl;
    if(mes_==7)
        cout<<"M�s: JUL"<<endl;
    if(mes_==8)
        cout<<"M�s: AGO"<<endl;
    if(mes_==9)
        cout<<"M�s: SET"<<endl;
    if(mes_==10)
        cout<<"M�s: OUT"<<endl;
    if(mes_==11)
        cout<<"M�s: NOV"<<endl;
    if(mes_==12)
        cout<<"M�s: DEZ"<<endl;
}
