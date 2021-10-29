#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*9. (Voc� deve fazer os dois projetos de programa��o anteriores antes de fazer este.) Escreva um programa
que combine as fun��es dos dois projetos de programa��o anteriores. O programa pergunta ao usu�rio se
deseja converter libras e on�as em quilogramas e gramas ou quilogramas e gramas em libras e on�as.
Ent�o o programa efetua a convers�o desejada. Fa�a com que o usu�rio responda digitando o inteiro 1 para
um tipo de convers�o e 2 para o outro. O programa l� a resposta do usu�rio e executa o comando ifelse.
Cada ramifica��o do comando if-else ser� uma chamada de fun��o. As duas fun��es chamadas no
comando if-else ter�o defini��es de fun��o bastante similares �s dos programas dos dois projetos de programa��o
 anteriores. Assim, ser�o defini��es de fun��o bastante complexas que chamam outras fun��es.
Inclua um loop que permita ao usu�rio repetir esse c�lculo para novos dados de entrada at� o usu�rio dizer que
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
            cout << "Selecione uma das op��es abaixo: "<<endl;
            cout <<"(1)Converter libras/on�as para quilos/gramas."<<endl;
            cout <<"(2)Converter quilos/gramas para libras/on�as."<<endl;
            cin >> aux;
            if(!(aux==1||aux==2))
                cout << "Op��o inv�lida." << endl;
        }while(!(aux==1||aux==2));
        getData(libra,onca,aux);
        convertePeso(libra,onca,aux);
        outData(libra,onca,aux);
        cout << "Deseja realizar outro c�lculo? (S/N): ";
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
        cout << "Digite o peso em on�as: ";
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
        cout << "A medida fornecida equivale a " << libra << " libras e " << onca << " on�as."<<endl;
    }
}
