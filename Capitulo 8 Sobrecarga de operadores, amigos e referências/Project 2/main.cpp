#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*2. Defina uma classe para números racionais. Um número racional é um número que pode ser representado
como o quociente de dois inteiros. Por exemplo, 1/2, 3/4 e 64/2 são números racionais. (Com 1/2, etc.,
queremos dizer as frações comuns, não a divisão inteira que essa expressão produziria em um programa
em C++.) Represente números racionais como dois valores de tipo int, um para o numerador e outro
para o denominador. Chame a classe de Racional. Inclua um construtor com dois argumentos que possa
ser usado para fixar as variáveis-membros de um objeto como qualquer valor legítimo. Inclua também um
construtor que possua um único parâmetro de tipo int; chame esse único parâmetro de numeroInteiro e
defina o construtor de modo que o objeto seja inicializado com o número racional numeroInteiro/1. Inclua
 um construtor-padrão que inicialize um objeto como 0 (ou seja, 0/1). Sobrecarregue os operadores de
entrada e saída >> e <<. Os números devem entrar e sair na forma 1/2, 15/32, 300/401, e assim por
diante. Observe que o numerador, o denominador ou ambos podem conter um sinal de menos, de modo
que -1/2, 15/-32 e -300/-401 também são entradas possíveis. Sobrecarregue todos os seguintes operadores
para que se apliquem corretamente ao tipo Racional: ==, <, <=, >, >=, +, -, * e /. Escreva um programa teste
 para testar sua classe. Dicas: dois números racionais a/b e c/d são iguais se a*d é igual a c*b. Se b e d
são números racionais positivos, a/b é menor que c/d desde que a*d seja menor que c*b. Inclua uma função
para normalizar os valores armazenados de forma que, após a normalização, o denominador seja positivo e
o numerador e o denominador sejam tão pequenos quanto possível. Por exemplo, depois da normalização,
4/-8 deve ser representado como -1/2.*/

using namespace std;

class Racional
{
    public:
    Racional();
    Racional(int numeroInteiro);
    Racional(int num, int den);
    friend ostream& operator <<(ostream& outputStream, const Racional& racional);
    friend istream& operator >>(istream& inputStream, Racional& racional);
    friend bool operator ==(const Racional& num1, const Racional& num2);
    friend bool operator >(const Racional& num1, const Racional& num2);
    friend bool operator >=(const Racional& num1, const Racional& num2);
    friend bool operator <(const Racional& num1, const Racional& num2);
    friend bool operator <=(const Racional& num1, const Racional& num2);
    friend const Racional operator +(const Racional& num1, const Racional& num2);
    friend const Racional operator -(const Racional& num1, const Racional& num2);
    friend const Racional operator *(const Racional& num1, const Racional& num2);
    friend const Racional operator /(const Racional& num1, const Racional& num2);
    void simplificaFracao();


    private:
    int numerador_;
    int denominador_;
};

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Racional r(3,-5), s(1,2);
    Racional a;
    cout << "Fração r: " << r<<endl;
    cout << "Fração s: " << s<<endl;
    a = r+s;
    cout <<"r+s = " << a << endl;
    a= r-s;
    cout <<"r-s = "<< a << endl;
    a = r*s;
    cout <<"r*s = "<< a << endl;
    a = r/s;
    cout <<"r/s ="<< a << endl;

    if(r==s)
        cout<<"r==s"<<endl;
    else
        cout<<"r!=s"<<endl;

     if(r>s)
        cout<<"r>s"<<endl;
     else
        cout<<"r<s"<<endl;

      if(r>=s)
        cout<<"r>=s"<<endl;
      else
        cout<<"r<s"<<endl;

     if(r<s)
        cout<<"r<s"<<endl;
     else
        cout<<"r>=s"<<endl;

     if(r<=s)
        cout<<"r<=s"<<endl;
     else
        cout<<"r>s"<<endl;

    cout << "Digite uma número racional (precisão 3 casas decimais): ";
    cin >> a;
    cout <<"a = " << a << endl;
    a.simplificaFracao();
    cout <<"Fração a simplificada = "<< a <<endl;

    return 0;
}

Racional::Racional()
{
    numerador_ = 0;
    denominador_ = 1;
}

Racional::Racional(int numeroInteiro)
{
    numerador_ = numeroInteiro;
    denominador_ = 1;
}

Racional::Racional(int num, int den)
{
    if((num<0&&den<0)||(num>0&&den<0))
    {
        num *= -1;
        den *= -1;
    }

    numerador_ = num;

    if(den!=0)
        denominador_ = den;
    else
        denominador_ = 1;
}

ostream& operator <<(ostream& outputStream, const Racional& racional)
{
    int numerador = racional.numerador_;
    int denominador = racional.denominador_;
    outputStream << numerador << "/" << denominador;
    return outputStream;
}

istream& operator >>(istream& inputStream, Racional& racional)
{
    double num;

    inputStream >> num;
    if(num-floor(num)==0)
    {
        racional.numerador_ = num;
        racional.denominador_ = 1;
    }
    else
    {
        racional.numerador_ = num*pow(10,3);
        racional.denominador_ = pow(10,3);
        for(int i=pow(10,3);i>=10;i/=10)
        {
            if(racional.numerador_%i==0)
            {
                racional.numerador_ /=i;
                racional.denominador_/=i;
            }
        }
    }
}

void Racional::simplificaFracao()
{
    bool aux = true;
    if(numerador_%denominador_==0)
    {
        numerador_ /= denominador_;
        denominador_ = 1;
    }
    else
    {
        for(int i=2; i<1000; i++)
        {
            if(numerador_%i==0&&denominador_%i==0)
            {
                do
                {
                    if(numerador_%i==0&&denominador_%i==0)
                    {
                        numerador_ /= i;
                        denominador_ /= i;
                    }
                    else
                    {
                        aux = false;
                    }
                }while(aux);
            }
        }
    }
}

bool operator ==(const Racional& num1, const Racional& num2)
{
    double aux1 = num1.numerador_, aux2 = num1.denominador_;
    double aux3 = num2.numerador_, aux4 = num2.denominador_;
    return ((aux1/aux2)==(aux3/aux4));
}

bool operator >(const Racional& num1, const Racional& num2)
{
    double aux1 = num1.numerador_, aux2 = num1.denominador_;
    double aux3 = num2.numerador_, aux4 = num2.denominador_;
    return ((aux1/aux2)>(aux3/aux4));
}

bool operator >=(const Racional& num1, const Racional& num2)
{
    double aux1 = num1.numerador_, aux2 = num1.denominador_;
    double aux3 = num2.numerador_, aux4 = num2.denominador_;
    return ((aux1/aux2)>=(aux3/aux4));
}

bool operator <(const Racional& num1, const Racional& num2)
{
    double aux1 = num1.numerador_, aux2 = num1.denominador_;
    double aux3 = num2.numerador_, aux4 = num2.denominador_;
    return ((aux1/aux2)<(aux3/aux4));
}

bool operator <=(const Racional& num1, const Racional& num2)
{
    double aux1 = num1.numerador_, aux2 = num1.denominador_;
    double aux3 = num2.numerador_, aux4 = num2.denominador_;
    return ((aux1/aux2)<=(aux3/aux4));
}

const Racional operator +(const Racional& num1, const Racional& num2)
{
    int num,denom;
    denom = num1.denominador_*num2.denominador_;
    num = (num1.numerador_*denom)/num1.denominador_ + (num2.numerador_*denom)/num2.denominador_;
    Racional aux(num,denom);
    return aux;
}

const Racional operator -(const Racional& num1, const Racional& num2)
{
    int num,denom;
    denom = num1.denominador_*num2.denominador_;
    num = (num1.numerador_*denom)/num1.denominador_ - (num2.numerador_*denom)/num2.denominador_;
    Racional aux(num,denom);
    return aux;
}

const Racional operator *(const Racional& num1, const Racional& num2)
{
    int num,denom;
    denom = num1.denominador_*num2.denominador_;
    num = num1.numerador_*num2.numerador_;
    Racional aux(num,denom);
    return aux;
}

const Racional operator /(const Racional& num1, const Racional& num2)
{
    int num,denom;
    denom = num1.denominador_*num2.numerador_;
    num = num1.numerador_*num2.denominador_;
    Racional aux(num,denom);
    return aux;
}
