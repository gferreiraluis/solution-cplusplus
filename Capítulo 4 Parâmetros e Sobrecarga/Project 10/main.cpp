#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*10. (Você deve fazer os Projetos de Programação 6 e 9 antes de fazer este.) Escreva um programa que combine
as funções dos dois Projetos de Programação 6 e 9. O programa pergunta ao usuário se deseja converter comprimentos
 ou pesos. Se o usuário escolher comprimentos, o programa pergunta ao usuário se
deseja converter pés (1 pé = 30,5 cm) e polegadas (1 polegada = 2,54 cm) em metros e centímetros ou
metros e centímetros em pés e polegadas. Se o usuário escolher peso, uma pergunta similar é feita a respeito de libras,
 onças, quilogramas e gramas. Assim, o programa efetua a conversão desejada. Faça com
que o usuário responda digitando o inteiro 1 para um tipo de conversão e 2 para o outro. O programa lê
a resposta do usuário e executa o comando if-else. Cada ramificação do comando if-else será uma
chamada de função. As duas funções chamadas no comando if-else terão definições de função bastante
similares às dos programas dos Projetos de Programação 6 e 9. Observe que seu programa terá comandos
if-else inseridos dentro de comandos if-else, mas apenas de maneira indireta. O comando if-else exterior incluirá
    duas chamadas de função, como suas duas ramificações. Essas duas chamadas de função,
por sua vez, incluirão um comando if-else, mas você não precisa pensar nisso. São apenas chamadas de
função e os detalhes estão na caixa preta que você cria quando define essas funções. Se você tentar criar
uma ramificação de quatro caminhos, provavelmente está na pista errada. Você só precisa pensar em ramificações
de dois caminhos (embora o programa inteiro se ramifique, no fim das contas, em quatro casos).
Inclua um loop que permita ao usuário repetir esse cálculo para novos dados de entrada, até o usuário dizer
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

            cout << "Selecione uma das opções abaixo: "<<endl;
            cout <<"(1)Converter Pesos."<<endl;
            cout <<"(2)Converter Comprimentos."<<endl;
            cin >> aux2;

            if(aux2==1)
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
                    getData(num1,num2,aux);
                    convertePeso(num1,num2,aux);
                    outData(num1,num2,aux);
            }
             if (aux2==2)
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
                    getDataComprimento(num1,num2,aux);
                    converteComprimento(num1,num2,aux);
                    outDataComprimento(num1,num2,aux);
            }
            if(!(aux2==1||aux2==2))
                cout << "Opção inválida." << endl;
        }while(!(aux2==1||aux2==2));
        cout << "Deseja realizar outro cálculo? (S/N): ";
        cin >> op;
    }while(op=='s'||op=='S');
    return 0;
}

void getDataComprimento(double& pe, double& polegada, int aux)
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
        cout << "A medida fornecida equivale a " << pe << " metros e " << polegada << " centímetros."<<endl;
    }
    else
    {
        cout << "A medida fornecida equivale a " << pe << " pés e " << polegada << " polegadas."<<endl;
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
