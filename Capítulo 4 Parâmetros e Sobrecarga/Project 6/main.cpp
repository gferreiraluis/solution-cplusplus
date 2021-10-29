#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*6. (Voc� deve fazer os dois projetos de programa��o anteriores antes de fazer este.) Escreva um programa
que combine as fun��es dos dois projetos de programa��o anteriores. O programa pergunta ao usu�rio se
deseja converter p�s e polegadas em metros e cent�metros ou metros e cent�metros em p�s e polegadas.
Ent�o, o programa efetua a convers�o desejada. Fa�a com que o usu�rio responda digitando o inteiro 1
para um tipo de convers�o e 2 para o outro. O programa l� a resposta do usu�rio e executa o comando
if-else. Cada ramifica��o do comando if-else ser� uma chamada de fun��o. As duas fun��es chamadas
no comando if-else ter�o defini��es de fun��o bastante similares �s dos programas dos dois projetos de
programa��o anteriores. Assim, ser�o defini��es de fun��o bastante complexas que chamam outras fun��es.
Inclua um loop que permita ao usu�rio repetir esse c�lculo para novos dados de entrada at� o usu�rio dizer
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
            cout << "Selecione uma das op��es abaixo: "<<endl;
            cout <<"(1)Converter p�s/polegadas para metros/cent�metros."<<endl;
            cout <<"(2)Converter metros/cent�metros para p�s/polegadas."<<endl;
            cin >> aux;
            if(!(aux==1||aux==2))
                cout << "Op��o inv�lida." << endl;
        }while(!(aux==1||aux==2));
        getData(pe,polegada,aux);
        converteComprimento(pe,polegada,aux);
        outData(pe,polegada,aux);
        cout << "Deseja realizar outro c�lculo? (S/N): ";
        cin >> op;
    }while(op=='s'||op=='S');
    return 0;
}

void getData(double& pe, double& polegada, int aux)
{
    if(aux==1){
        cout << "Digite o comprimento em p�s: ";
        cin >> pe;
        cout << "Digite o comprimento em polegadas: ";
        cin >> polegada;
    }
    else{
        cout << "Digite o comprimento em metros: ";
        cin >> pe;
        cout << "Digite o comprimento em cent�metros: ";
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
        cout << "A medida fornecida equivale a " << pe << " metros e " << polegada << " cent�metros."<<endl;
    }
    else
    {
        cout << "A medida fornecida equivale a " << pe << " p�s e " << polegada << " polegadas."<<endl;
    }
}
