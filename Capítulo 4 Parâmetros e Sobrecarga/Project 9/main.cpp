#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*9. (Você deve fazer os dois projetos de programação anteriores antes de fazer este.) Escreva um programa
que combine as funções dos dois projetos de programação anteriores. O programa pergunta ao usuário se
deseja converter libras e onças em quilogramas e gramas ou quilogramas e gramas em libras e onças.
Então o programa efetua a conversão desejada. Faça com que o usuário responda digitando o inteiro 1 para
um tipo de conversão e 2 para o outro. O programa lê a resposta do usuário e executa o comando ifelse.
Cada ramificação do comando if-else será uma chamada de função. As duas funções chamadas no
comando if-else terão definições de função bastante similares às dos programas dos dois projetos de programação
 anteriores. Assim, serão definições de função bastante complexas que chamam outras funções.
Inclua um loop que permita ao usuário repetir esse cálculo para novos dados de entrada até o usuário dizer que
deseja encerrar o programa.*/

using namespace std;

void getData(double& libra, double& onca, int aux);
void convertePeso(double& libra, double& onca, int aux);
void outData(double libra, double once, int aux);

int main()
{
       setlocale(LC_ALL, "Portuguese");
    double libra, onca;
    char op;
    int aux;
    do
    {
        do
        {
            cout << "Selecione uma das opções abaixo: "<<endl;
            cout <<"(1)Converter libras/onças para quilos/gramas."<<endl;
            cout <<"(2)Converter quilos/gramas para libras/onças."<<endl;
            cin >> aux;
            if(!(aux==1||aux==2))
                cout << "Opção inválida." << endl;
        }while(!(aux==1||aux==2));
        getData(libra,onca,aux);
        convertePeso(libra,onca,aux);
        outData(libra,onca,aux);
        cout << "Deseja realizar outro cálculo? (S/N): ";
        cin >> op;
    }while(op=='s'||op=='S');
    return 0;
}

void getData(double& libra, double& onca, int aux)
{
    if(aux==1)
    {
        cout << "Digite o peso em libras: ";
        cin >> libra;
        cout << "Digite o peso em onças: ";
        cin >> onca;
    }
    else
    {
        cout << "Digite o peso em quilos: ";
        cin >> libra;
        cout << "Digite o peso em gramas: ";
        cin >> onca;
    }

}

void convertePeso(double& libra, double& onca, int aux)
{
    double quilo, grama;
    if(aux==1)
    {
        quilo = (453.59*libra + 28.34*onca)/1000;
        grama = fmod(quilo,1)*1000;
        libra = floor(quilo);
        onca = grama;
    }
    else
    {
        quilo = libra*2.2046 + onca/(28.34*16);
        grama = fmod(quilo,1)*16;
        libra = floor(quilo);
        onca = grama;
    }
}

void outData(double libra, double onca, int aux)
{
    if(aux==1)
    {
        cout << "A medida fornecida equivale a " << libra << " quilos e " << onca << " gramas."<<endl;
    }
    else
    {
        cout << "A medida fornecida equivale a " << libra << " libras e " << onca << " onças."<<endl;
    }
}
