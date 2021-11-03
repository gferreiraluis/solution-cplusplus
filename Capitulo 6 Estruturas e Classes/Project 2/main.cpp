#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*2. Defina uma classe para um tipo chamado TipoContador. Um objeto desse tipo � utilizado para contar
coisas, registrando uma contagem que � um n�mero inteiro n�o-negativo. Inclua uma fun��o mutator que
fixe o contador a uma contagem dada como argumento. Inclua fun��es-membros para aumentar a contagem em
um e diminuir a contagem em um. Assegure-se de que nenhuma fun��o-membro permita que o
valor do contador se torne negativo. Inclua tamb�m uma fun��o-membro que retorne o valor atual da
contagem e um que apresente a contagem como sa�da. Insira sua defini��o de classe em um programa-teste.*/

using namespace std;

class TipoContador
{
    public:
        bool mutator(int a);
        void aumentaContagem();
        void diminuiContagem();
        void printContador();
    private:
        int cont_;
};

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int valor, op;
    bool aux;
    TipoContador contador;
    do{
        cout <<"Digite uma valor n�o-negativo para inicializar o contador: ";
        cin >> valor;
        aux = contador.mutator(valor);
      }while(aux==false);

    do{
        cout<<endl<<" (1) Aumentar a contagem | (2) Diminuir a contagem | (3) Mostrar a contagem | (4) Encerrar o programa."<<endl;
        "Selecione a op��o desejada: ";
        cin >> op;
        switch(op)
        {
            case 1:
            contador.aumentaContagem();
            break;
            case 2:
            contador.diminuiContagem();
            break;
            case 3:
            contador.printContador();
            break;
            case 4:
            break;
            default:
                cout<<"Op��o inv�lida."<<endl;
        }
    }while(op!=4);

    return 0;
}

bool TipoContador::mutator(int a)
{
    if(a<0)
    {
        cout<<"Valor inv�lido."<<endl<<endl;
        return false;
    }
    else{
            cont_ = a;
            return true;
        }
}

void TipoContador::aumentaContagem()
{
    cont_++;
}

void TipoContador::diminuiContagem()
{
    if(cont_-1<0)
        cout<<"N�o � poss�vel diminuir a contagem."<<endl;
    else
        cont_--;
}

void TipoContador::printContador()
{
    cout<<"O valor do contador �: "<< cont_ <<endl;
}
