#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*3. Defina uma classe para n�meros complexos. Um n�mero complexo � um n�mero da forma
a + b*i
em que, para nossos prop�sitos, a e b s�o n�meros de tipo double, e i � um n�mero que representa a
quantidade raiz(-1). Represente um n�mero complexo como dois valores de tipo double. Chame as vari�veis membros
 de real e imaginaria. (A vari�vel para o n�mero que � multiplicado por i � a que � chamada
imaginaria.) Chame a classe de Complexo. Inclua um construtor com dois par�metros de tipo double que
possa ser usado para fixar em qualquer valor as vari�veis-membros de um objeto. Inclua um construtor
que possua apenas um par�metro �nico de tipo double; chame esse par�metro de parteReal e defina o
construtor para que o objeto seja inicializado como parteReal + 0*i. Inclua um construtor-padr�o que
inicialize um objeto como 0 (ou seja, to 0 + 0*i ). Sobrecarregue todos os seguintes operadores para que
se apliquem corretamente ao tipo Complexo: ==, +, -, *, >> e <<. Escreva, tamb�m, um programa-teste
para testar sua classe. Dicas: para adicionar ou subtrair dois n�meros complexos, adicione ou subtraia as
duas vari�veis-membros de tipo double. O produto de dois n�meros complexos � dado pela seguinte f�rmula:
(a + b*i)*(c + d*i) == (a*c - b*d) + (a*d + b*c)*i
No arquivo de interface, defina uma constante i da seguinte forma:
const Complexo i(0, 1);
Esta constante definida i ser� a mesma que o i de que falamos anteriormente.*/

using namespace std;

class Complexo
{
    public:
    Complexo();
    Complexo(double parteReal);
    Complexo(double parteReal,double parteImaginaria);
    friend ostream& operator <<(ostream& outputStream, const Complexo& obj);
    friend istream& operator >>(istream& inputStream, Complexo& obj);
    friend bool operator ==(const Complexo& num1, const Complexo& num2);
    friend const Complexo operator +(const Complexo& num1, const Complexo& num2);
    friend const Complexo operator -(const Complexo& num1, const Complexo& num2);
    friend const Complexo operator *(const Complexo& num1, const Complexo& num2);
    friend const Complexo operator /(const Complexo& num1, const Complexo& num2);

    private:
    double real_;
    double imaginaria_;

};

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Complexo a(5,6), b(4,-2);
    cout <<"a = " << a <<endl;
    cout <<"b = " << b <<endl;
    if(a==b)
        cout<<"a == b"<<endl;
    else
        cout<<"a != b"<<endl;
    Complexo c;
    c=a+b;
    cout<<"a + b = " << c <<endl;
    c=a-b;
    cout<<"a - b = " << c <<endl;
    c=a*b;
    cout<<"a * b = " << c <<endl;
    c=a/b;
    cout<<"a / b = " << c <<endl;

    cout << "Entre com a parte real do numero imagin�rio: ";
    cin >> c;
    cout << "c = "<<c<<endl;

     return 0;
}

Complexo::Complexo()
{
    real_ = 0;
    imaginaria_ = 0;
}

Complexo::Complexo(double parteReal)
{
    real_ = parteReal;
    imaginaria_ = 0;
}


Complexo::Complexo(double parteReal, double parteImaginaria)
{
    real_ = parteReal;
    imaginaria_ = parteImaginaria;
}

ostream& operator <<(ostream& outputStream, const Complexo& obj)
{
    if(obj.imaginaria_>=0)
    outputStream << obj.real_ << " + " << obj.imaginaria_ <<"*i";
    else
    outputStream << obj.real_ << " - " << obj.imaginaria_*-1 <<"*i";

    return outputStream;
}

istream& operator >>(istream& inputStream, Complexo& obj)
{
  double aux;
  inputStream >> aux;
  Complexo a(aux);
  obj = a;
}

bool operator ==(const Complexo& num1, const Complexo& num2)
{
    return ((num1.real_==num2.real_)&&(num1.imaginaria_==num2.imaginaria_));
}

const Complexo operator +(const Complexo& num1, const Complexo& num2)
{
    Complexo aux(num1.real_+num2.real_,num1.imaginaria_+num2.imaginaria_);
    return aux;
}

const Complexo operator -(const Complexo& num1, const Complexo& num2)
{
    Complexo aux(num1.real_-num2.real_,num1.imaginaria_-num2.imaginaria_);
    return aux;
}

const Complexo operator *(const Complexo& num1, const Complexo& num2)
{
    double aux1, aux2;
    aux1 = num1.real_*num2.real_ - num1.imaginaria_*num2.imaginaria_;
    aux2 = num1.real_*num2.imaginaria_ + num1.imaginaria_*num2.real_;
    Complexo aux(aux1,aux2);
    return aux;
}

const Complexo operator /(const Complexo& num1, const Complexo& num2)
{
    double aux1, aux2;
    aux1 = (num1.real_*num2.real_ + num1.imaginaria_*num2.imaginaria_)/(pow(num2.real_,2)+pow(num2.imaginaria_,2));
    aux2 = (num2.real_*num1.imaginaria_ - num1.real_*num2.imaginaria_)/(pow(num2.real_,2)+pow(num2.imaginaria_,2));
    Complexo aux(aux1,aux2);
    return aux;
}


