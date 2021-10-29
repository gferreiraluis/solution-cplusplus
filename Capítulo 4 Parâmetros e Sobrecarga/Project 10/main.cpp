#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*10. (Voc� deve fazer os Projetos de Programa��o 6 e 9 antes de fazer este.) Escreva um programa que combine
as fun��es dos dois Projetos de Programa��o 6 e 9. O programa pergunta ao usu�rio se deseja converter comprimentos
 ou pesos. Se o usu�rio escolher comprimentos, o programa pergunta ao usu�rio se
deseja converter p�s (1 p� = 30,5 cm) e polegadas (1 polegada = 2,54 cm) em metros e cent�metros ou
metros e cent�metros em p�s e polegadas. Se o usu�rio escolher peso, uma pergunta similar � feita a respeito de libras,
 on�as, quilogramas e gramas. Assim, o programa efetua a convers�o desejada. Fa�a com
que o usu�rio responda digitando o inteiro 1 para um tipo de convers�o e 2 para o outro. O programa l�
a resposta do usu�rio e executa o comando if-else. Cada ramifica��o do comando if-else ser� uma
chamada de fun��o. As duas fun��es chamadas no comando if-else ter�o defini��es de fun��o bastante
similares �s dos programas dos Projetos de Programa��o 6 e 9. Observe que seu programa ter� comandos
if-else inseridos dentro de comandos if-else, mas apenas de maneira indireta. O comando if-else exterior incluir�
    duas chamadas de fun��o, como suas duas ramifica��es. Essas duas chamadas de fun��o,
por sua vez, incluir�o um comando if-else, mas voc� n�o precisa pensar nisso. S�o apenas chamadas de
fun��o e os detalhes est�o na caixa preta que voc� cria quando define essas fun��es. Se voc� tentar criar
uma ramifica��o de quatro caminhos, provavelmente est� na pista errada. Voc� s� precisa pensar em ramifica��es
de dois caminhos (embora o programa inteiro se ramifique, no fim das contas, em quatro casos).
Inclua um loop que permita ao usu�rio repetir esse c�lculo para novos dados de entrada, at� o usu�rio dizer
que deseja encerrar o programa*/

using namespace std;

void getData(double& libra, double& onca, int aux);
void convertePeso(double& libra, double& onca, int aux);
void outData(double libra, double once, int aux);
void getDataComprimento(double& pe, double& polegada, int aux);
void converteComprimento(double& pe, double& polegada, int aux);
void outDataComprimento(double pe, double polegada, int aux);

int main()
{
       setlocale(LC_ALL, "Portuguese");
    double num1, num2;
    char op;
    int aux, aux2;
    do
    {
        do
        {

            cout << "Selecione uma das op��es abaixo: "<<endl;
            cout <<"(1)Converter Pesos."<<endl;
            cout <<"(2)Converter Comprimentos."<<endl;
            cin >> aux2;

            if(aux2==1)
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
                    getData(num1,num2,aux);
                    convertePeso(num1,num2,aux);
                    outData(num1,num2,aux);
            }
             if (aux2==2)
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
                    getDataComprimento(num1,num2,aux);
                    converteComprimento(num1,num2,aux);
                    outDataComprimento(num1,num2,aux);
            }
            if(!(aux2==1||aux2==2))
                cout << "Op��o inv�lida." << endl;
        }while(!(aux2==1||aux2==2));
        cout << "Deseja realizar outro c�lculo? (S/N): ";
        cin >> op;
    }while(op=='s'||op=='S');
    return 0;
}

void getDataComprimento(double& pe, double& polegada, int aux)
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

void outDataComprimento(double pe, double polegada, int aux)
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
