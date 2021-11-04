#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

using namespace std;

/*3. Minha m�e sempre levava um pequeno contador vermelho quando ia � mercearia. O contador era usado
para calcular a quantia de dinheiro que ela deveria pagar se comprasse tudo o que havia colocado na cesta.
 O contador possu�a um painel com quatro d�gitos, bot�es de incremento para cada d�gito e um bot�o
de rein�cio. Um indicador de alerta ficava vermelho se ultrapassasse os R$ 99,99 que ele poderia registrar.
(Isso foi h� muito tempo.)
Escreva e implemente as fun��es-membros de uma classe Contador que simule e generalize, at� certo ponto,
o comportamento desse contador. O construtor deve criar um objeto Contador que pode contar at� o
argumento do construtor. Ou seja, Contador(9999) deve proporcionar um contador que pode contar at�
9999. Um contador recentemente constru�do exibe uma leitura de 0. A fun��o-membro void reinicia( );
faz com que o contador retorne ao 0. A fun��o-membro void incr1( ); incrementa o d�gito da unidade
em 1, void incr10( ); incrementa o d�gito das dezenas em 1 e void incr100( ); e void incr1000( );
incrementam os pr�ximos dois d�gitos. O acr�scimo de qualquer taxa durante o incremento n�o deve exigir
nenhuma outra a��o al�m de adicionar um n�mero adequado aos membros dados privados. Uma fun��o-membro
 bool ultrapassou( ); detecta quando o m�ximo foi ultrapassado. (A ultrapassagem � o resultado de incrementar
os membros dados privados do contador al�m do m�ximo estabelecido na constru��o do contador.)
Utilize esta classe para fornecer uma simula��o do pequeno contador vermelho da minha m�e. Embora o
display seja um inteiro, na simula��o os dois d�gitos mais � direita (a ordem seguida � dos menores para
os maiores) s�o sempre considerados centavos e dezenas de centavos, o pr�ximo d�gito � dos reais e o
quarto d�gito � das dezenas de reais.
Forne�a teclas para centavos, moedas de dez centavos, reais e notas de dez reais. Infelizmente, nenhuma
escolha de teclas parece especialmente mnem�nica. Uma op��o � utilizar as teclas asdfo: a para os centavos,
 seguida por um d�gito de 1 a 9; s para as moedas de dez centavos, seguida por um d�gito de 1 a 9; d
para os reais, seguida por um d�gito de 1 a 9; e f para as notas de dez reais, mais uma vez seguida por
um d�gito de 1 a 9. Cada entrada (uma das asdf seguida por um d�gito de 1 a 9) � seguida pelo pressionamento
 da tecla Return. Quando o valor ultrapassar o m�ximo, isso ser� informado ap�s cada opera��o.
Pode-se consultar o valor de ultrapassagem com a tecla o.*/

class Contador
{
    public:
    Contador(double value);

    void renicia();
    void incremCentavos();
    void incremDezCentavos();
    void incremReais();
    void incremDezReais();
    bool ultrapassou();
    void consulta();

    private:
    double cont_;
    double valorMax_;
};

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double num;
    char op;
    bool aux=false;
    cout << "Digite o valor m�ximo para o contador: ";
    cin >> num;
    Contador c(num);
    do
    {
        if(aux == true)
            cout<<endl<<"SALDO ESTOURADO"<<endl;
        cout<<endl<<"(Y) Reiniciar | (N) Encerrar Programa "<<endl;
        cout<<" (a) 1 Centavo | (b) 10 Centavos | (c) 1 Real | (d) 10 Reais "<<endl;
        cout<<" (o) Consulta saldo"<<endl;
        cout<<"Digite a op��o desejada: ";
        cin >> op;

        if(op=='y'||op=='Y')
             c.renicia();

        if(op=='a'||op=='A')
            c.incremCentavos();

        if(op=='b'||op=='B')
            c.incremDezCentavos();

        if(op=='c'||op=='C')
            c.incremReais();

        if(op=='d'||op=='D')
             c.incremDezReais();

        if(op=='o'||op=='O')
            c.consulta();

        aux = c.ultrapassou();
    }while(!(op=='n'||op=='N'));

    return 0;
}

Contador::Contador(double value)
{
    cont_ = 0;
    if(value<-1)
    valorMax_ = value*-1;
    else
    valorMax_ = value;
}

void Contador::renicia()
{
    cont_=0;
}

void Contador::incremCentavos()
{
    cont_ += 0.01;
}

void Contador::incremDezCentavos()
{
    cont_ += 0.1;
}

void Contador::incremReais()
{
    cont_ += 1;
}

void Contador::incremDezReais()
{
    cont_ += 10;
}

bool Contador::ultrapassou()
{
    if(cont_>valorMax_)
        return true;
    else
        return false;
}

void Contador::consulta()
{
    if(cont_>valorMax_)
        cout<<"Seu saldo estorou em R$ "<< cont_-valorMax_ <<" reais."<<endl;
    else
        cout<<"Voc� possui R$ "<< valorMax_-cont_ <<" reais de saldo."<<endl;
}
