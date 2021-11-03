#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <windows.h>


/*4. Escreva a definição para uma classe chamada BombaDeGasolina para ser usada como modelo para uma
bomba em um posto de gasolina. Antes de começar a fazer este exercício, escreva o comportamento que
espera de uma bomba de gasolina do ponto de vista do comprador.
Abaixo, há uma lista de coisas que se espera que uma bomba de gasolina faça. Se sua lista ficar diferente
e você achar que a sua é melhor, consulte o orientador. Você e seu orientador podem decidir juntos qual
será o melhor comportamento a implementar. Então implemente e teste seu projeto para a bomba de gasolina.
a. Apresentação da quantidade fornecida.
b. Apresentação do preço relativo à quantidade fornecida.
c. Apresentação do custo por galão, litro ou outra unidade de volume usada no local onde você mora.
d. Antes de ser usada, a bomba de gasolina deve zerar a quantidade fornecida e o preço relativo.
e. Uma vez em funcionamento, a bomba de gasolina continua a fornecer gasolina, controlar a quantidade
fornecida e calcular o preço da quantidade fornecida até parar.
f. É necessário algum tipo de controle de parada de fornecimento.
Implemente o comportamento da bomba de gasolina como declarações de funções-membros da classe bomba
de gasolina, depois escreva implementações dessas funções-membros. Você terá de decidir se há dados sob o controle
 da bomba de gasolina aos quais o usuário da bomba não deve ter acesso. Se este for o caso, faça com que essas
 variáveis-membros sejam privadas.*/

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
        cout <<"Digite a opção desejada: ";
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
            cout << "Opção inválida." <<endl;
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
            cout <<"Preço da gasolina por litro: " <<custo_<<endl<<endl;
            cout <<"Litros: " << gasolina_ <<" | Preço: " <<gasolina_*custo_ <<endl<<endl;

            if (GetKeyState('P') & 0x8000/*Check if high-order bit is set (1 « 15)*/)
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
    cout <<"Preço da gasolina por litro: " <<custo_<<endl<<endl;
    cout <<"Litros: " << gasolina_ <<" | Preço: " <<gasolina_*custo_ <<endl<<endl;
}

void BombaDeGasolina::reiniciarPainel()
{
    gasolina_ = 0;
}
