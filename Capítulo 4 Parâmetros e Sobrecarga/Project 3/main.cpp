#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*3. Escreva um programa que diga quantas moedas retornar para qualquer quantia de 1 a 99 centavos. Por
exemplo, se a quantia � 86 centavos, a sa�da deve ser algo parecido com:
86 centavos podem ser fornecidos como
3 de 25 centavo(s), 1 de 10 centavo(s) e 1 de 1 centavo(s)
Utilize denomina��es para moedas de 25 centavos, 10 centavos e 1 centavo. N�o utilize as moedas de 50
centavos nem de 5 centavos.
Seu programa utilizar� a seguinte fun��o (entre outras):
void calculaMoedas(int valorDaMoeda, int& numero, int& quantiaRestante);
//Pr�-condi��o: 0 < valorDaMoeda < 100; 0 <= quantiaRestante < 100.
//P�s-condi��o: n�mero fixado como igual ao n�mero m�ximo
//de moedas de denomina��o valorDaMoeda centavos que possa ser obtido
//a partir de quantiaRestante centavos. quantiaRestante diminui conforme
//o valor das moedas, ou seja, diminui de numero*valorDaMoeda.
Por exemplo, suponha que o valor da vari�vel quantiaRestante seja 86. Ent�o, depois da seguinte chamada, o
valor de numero ser� 3 e o valor da quantiaRestante ser� 11 (porque se voc� tira 75 de 86, restam 11):
calculaMoedas(25, numero, quantiaRestante);
Inclua um loop que permita ao usu�rio repetir esse c�lculo para novos dados de entrada at� o usu�rio dizer que deseja encerrar
 o programa. (Dica: utilize divis�o de inteiros e o operador % para implementar
essa fun��o.)*/

using namespace std;

void calculaMoedas(int valorDaMoeda, int& numero, int& quantiaRestante);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int numero, quantiaRestante;
    char op;
    do
    {
        do
        {
            cout << "Digite uma quantia de moedas (de 1 a 99 centavos): ";
            cin >> quantiaRestante;
            if(quantiaRestante<0||quantiaRestante>=100)
                cout << "Quantia de moedas inv�lidas" <<endl;
        }while(quantiaRestante<0||quantiaRestante>=100);
        cout << quantiaRestante << "podem ser fornecidos com ";
        calculaMoedas(25,numero,quantiaRestante);
        cout << numero << " de 25 centavos, ";
        calculaMoedas(10,numero,quantiaRestante);
        cout << numero << " de 10 centavos, ";
        calculaMoedas(1,numero,quantiaRestante);
        cout << numero << " de 1 centavo." << endl;
        cout << "Deseja realizar outro c�lculo? (S/N): ";
        cin >> op;
    }while(op=='s'||op=='S');
    return 0;
}

void calculaMoedas(int valorDaMoeda, int& numero, int& quantiaRestante)
{
    if(quantiaRestante>=valorDaMoeda)
    {
        numero = quantiaRestante/valorDaMoeda;
        quantiaRestante = quantiaRestante%valorDaMoeda;
    }
    else
    {
        numero = 0;
    }
}
