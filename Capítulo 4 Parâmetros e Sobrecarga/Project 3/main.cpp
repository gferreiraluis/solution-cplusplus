#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*3. Escreva um programa que diga quantas moedas retornar para qualquer quantia de 1 a 99 centavos. Por
exemplo, se a quantia é 86 centavos, a saída deve ser algo parecido com:
86 centavos podem ser fornecidos como
3 de 25 centavo(s), 1 de 10 centavo(s) e 1 de 1 centavo(s)
Utilize denominações para moedas de 25 centavos, 10 centavos e 1 centavo. Não utilize as moedas de 50
centavos nem de 5 centavos.
Seu programa utilizará a seguinte função (entre outras):
void calculaMoedas(int valorDaMoeda, int& numero, int& quantiaRestante);
//Pré-condição: 0 < valorDaMoeda < 100; 0 <= quantiaRestante < 100.
//Pós-condição: número fixado como igual ao número máximo
//de moedas de denominação valorDaMoeda centavos que possa ser obtido
//a partir de quantiaRestante centavos. quantiaRestante diminui conforme
//o valor das moedas, ou seja, diminui de numero*valorDaMoeda.
Por exemplo, suponha que o valor da variável quantiaRestante seja 86. Então, depois da seguinte chamada, o
valor de numero será 3 e o valor da quantiaRestante será 11 (porque se você tira 75 de 86, restam 11):
calculaMoedas(25, numero, quantiaRestante);
Inclua um loop que permita ao usuário repetir esse cálculo para novos dados de entrada até o usuário dizer que deseja encerrar
 o programa. (Dica: utilize divisão de inteiros e o operador % para implementar
essa função.)*/

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
                cout << "Quantia de moedas inválidas" <<endl;
        }while(quantiaRestante<0||quantiaRestante>=100);
        cout << quantiaRestante << "podem ser fornecidos com ";
        calculaMoedas(25,numero,quantiaRestante);
        cout << numero << " de 25 centavos, ";
        calculaMoedas(10,numero,quantiaRestante);
        cout << numero << " de 10 centavos, ";
        calculaMoedas(1,numero,quantiaRestante);
        cout << numero << " de 1 centavo." << endl;
        cout << "Deseja realizar outro cálculo? (S/N): ";
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
