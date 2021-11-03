#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <windows.h>


/*4. Escreva a defini��o para uma classe chamada BombaDeGasolina para ser usada como modelo para uma
bomba em um posto de gasolina. Antes de come�ar a fazer este exerc�cio, escreva o comportamento que
espera de uma bomba de gasolina do ponto de vista do comprador.
Abaixo, h� uma lista de coisas que se espera que uma bomba de gasolina fa�a. Se sua lista ficar diferente
e voc� achar que a sua � melhor, consulte o orientador. Voc� e seu orientador podem decidir juntos qual
ser� o melhor comportamento a implementar. Ent�o implemente e teste seu projeto para a bomba de gasolina.
a. Apresenta��o da quantidade fornecida.
b. Apresenta��o do pre�o relativo � quantidade fornecida.
c. Apresenta��o do custo por gal�o, litro ou outra unidade de volume usada no local onde voc� mora.
d. Antes de ser usada, a bomba de gasolina deve zerar a quantidade fornecida e o pre�o relativo.
e. Uma vez em funcionamento, a bomba de gasolina continua a fornecer gasolina, controlar a quantidade
fornecida e calcular o pre�o da quantidade fornecida at� parar.
f. � necess�rio algum tipo de controle de parada de fornecimento.
Implemente o comportamento da bomba de gasolina como declara��es de fun��es-membros da classe bomba
de gasolina, depois escreva implementa��es dessas fun��es-membros. Voc� ter� de decidir se h� dados sob o controle
 da bomba de gasolina aos quais o usu�rio da bomba n�o deve ter acesso. Se este for o caso, fa�a com que essas
 vari�veis-membros sejam privadas.*/

 class BombaDeGasolina
 {
     public:
     void ligaBomba();
     void exibirPainel();
     void reiniciarPainel();

     private:
     double custo_ = 6.32;
     double gasolina_ = 0;
 };

 bool task();

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    BombaDeGasolina bomba;
    int op=0;
    do
    {
        cout << endl << "(1) Ligar Bomba de Gasolina  | (2) Exibir Painel | (3) Reiniciar Bomba | (4) Encerrar Programa" <<endl;
        cout <<"Digite a op��o desejada: ";
        cin >> op;
        switch(op)
        {
            case 1:
            bomba.ligaBomba();
            break;
            case 2:
            bomba.exibirPainel();
            break;
            case 3:
            bomba.reiniciarPainel();
            break;
            case 4:
            break;
            default:
            cout << "Op��o inv�lida." <<endl;
        }
    }while(op!=4);


    return 0;
}


void BombaDeGasolina::ligaBomba()
{
        char aux;
        bool noPress = true;
        while(noPress)
        {
            gasolina_ += 0.1;

            system("cls");
            cout << "Digite P para desligar a bomba."<<endl;
            cout << "PAINEL BOMBA DE GASOLINA:"<<endl;
            cout <<"Pre�o da gasolina por litro: " <<custo_<<endl<<endl;
            cout <<"Litros: " << gasolina_ <<" | Pre�o: " <<gasolina_*custo_ <<endl<<endl;

            if (GetKeyState('P') & 0x8000/*Check if high-order bit is set (1 � 15)*/)
            {
                noPress = false;
                cin >> aux;
                getchar();
            }
        }

}

void BombaDeGasolina::exibirPainel()
{
    cout << endl <<"PAINEL BOMBA DE GASOLINA:"<<endl;
    cout <<"Pre�o da gasolina por litro: " <<custo_<<endl<<endl;
    cout <<"Litros: " << gasolina_ <<" | Pre�o: " <<gasolina_*custo_ <<endl<<endl;
}

void BombaDeGasolina::reiniciarPainel()
{
    gasolina_ = 0;
}
