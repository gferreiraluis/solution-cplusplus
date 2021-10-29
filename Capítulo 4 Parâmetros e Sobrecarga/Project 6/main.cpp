#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*6. (Você deve fazer os dois projetos de programação anteriores antes de fazer este.) Escreva um programa
que combine as funções dos dois projetos de programação anteriores. O programa pergunta ao usuário se
deseja converter pés e polegadas em metros e centímetros ou metros e centímetros em pés e polegadas.
Então, o programa efetua a conversão desejada. Faça com que o usuário responda digitando o inteiro 1
para um tipo de conversão e 2 para o outro. O programa lê a resposta do usuário e executa o comando
if-else. Cada ramificação do comando if-else será uma chamada de função. As duas funções chamadas
no comando if-else terão definições de função bastante similares às dos programas dos dois projetos de
programação anteriores. Assim, serão definições de função bastante complexas que chamam outras funções.
Inclua um loop que permita ao usuário repetir esse cálculo para novos dados de entrada até o usuário dizer
que deseja encerrar o programa.*/

using namespace std;


void getData(double& pe, double& polegada, int aux);
void converteComprimento(double& pe, double& polegada, int aux);
void outData(double pe, double polegada, int aux);


int main()
{
    setlocale(LC_ALL, "Portuguese");
    double pe, polegada;
    char op;
    int aux;
    do
    {
        do
        {
            cout << "Selecione uma das opções abaixo: "<<endl;
            cout <<"(1)Converter pés/polegadas para metros/centímetros."<<endl;
            cout <<"(2)Converter metros/centímetros para pés/polegadas."<<endl;
            cin >> aux;
            if(!(aux==1||aux==2))
                cout << "Opção inválida." << endl;
        }while(!(aux==1||aux==2));
        getData(pe,polegada,aux);
        converteComprimento(pe,polegada,aux);
        outData(pe,polegada,aux);
        cout << "Deseja realizar outro cálculo? (S/N): ";
        cin >> op;
    }while(op=='s'||op=='S');
    return 0;
}

void getData(double& pe, double& polegada, int aux)
{
    if(aux==1){
        cout << "Digite o comprimento em pés: ";
        cin >> pe;
        cout << "Digite o comprimento em polegadas: ";
        cin >> polegada;
    }
    else{
        cout << "Digite o comprimento em metros: ";
        cin >> pe;
        cout << "Digite o comprimento em centímetros: ";
        cin >> polegada;
    }
}

void converteComprimento(double& pe, double& polegada, int aux)
{
    double metro, centimetro;
    if(aux==1)
    {
        metro = 0.3048*(pe + polegada/12.0);
        centimetro = fmod(metro,1)*100;
        pe = floor(metro);
        polegada = centimetro;
    }
    else
    {
        metro = (pe + polegada/100)/0.3048;
        centimetro = fmod(metro,1)*12;
        pe = floor(metro);
        polegada = centimetro;
    }
}

void outData(double pe, double polegada, int aux)
{
    if(aux==1)
    {
        cout << "A medida fornecida equivale a " << pe << " metros e " << polegada << " centímetros."<<endl;
    }
    else
    {
        cout << "A medida fornecida equivale a " << pe << " pés e " << polegada << " polegadas."<<endl;
    }
}
