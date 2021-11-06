#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*1. Modifique a defini��o da classe Dinheiro mostrada no Painel 8.5 para acrescentar o seguinte:
a. Os operadores <, <=, > e >= foram todos sobrecarregados para ser aplicados ao tipo Dinheiro.
(Dica: veja Exerc�cio de Autoteste 8.)
b. A seguinte fun��o-membro foi acrescentada � defini��o de classe. (Mostramos a declara��o de fun��o como
deve aparecer na defini��o de classe. A defini��o da pr�pria fun��o incluir� o qualificador Dinheiro::.)
const Dinheiro porcentagem(int cifraPorcentagem) const;
//Retorna uma porcentagem da quantia de dinheiro no objeto que faz a chamada.
//Por exemplo, se cifraPorcentagem for 10, ent�o o valor retornado �
//10% da quantia de dinheiro representada pelo objeto que faz a chamada.
Por exemplo, se carteira � um objeto de tipo Dinheiro cujo valor representa a quantia R$ 100,10, ent�o
a chamada
 carteira.porcentagem(10);
retorna 10% de R$ 100,10; ou seja, retorna um valor de tipo Dinheiro que representa a quantia R$ 10,01.*/

using namespace std;

class Money
 {
 public:
 Money( );
 Money(double amount);
 Money(int theDollars, int theCents);
 Money(int theDollars);
 double getAmount( ) const;
 int getDollars( ) const;
 int getCents( ) const;
 const Money porcentagem(int cifraPorcentagem) const;
 friend const Money operator +(const Money& amount1, const Money& amount2);
 friend const Money operator -(const Money& amount1, const Money& amount2);
 friend bool operator ==(const Money& amount1, const Money& amount2);
 friend const Money operator -(const Money& amount);
 friend const bool operator <(const Money& amount1, const Money& amount2);
 friend const bool operator <=(const Money& amount1, const Money& amount2);
 friend const bool operator >(const Money& amount1, const Money& amount2);
 friend const bool operator >=(const Money& amount1, const Money& amount2);
 //friend ostream& operator <<(ostream& outputStream, const Money& amount);
 //friend istream& operator >>(istream& inputStream, Money& amount);

 private:
 int dollars; //Uma quantia negativa � representada como d�lares negativos e
 int cents; //centavos negativos. $4.50 � representado como -4 e -50.
 int dollarsPart(double amount) const;
 int centsPart(double amount) const;
 int round(double number) const;
};

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Money count1(100,50);
    Money count2(50,25);
    Money percent;

    if(count1>count2)
        cout<<"Count1 � maior que Count2."<<endl;
    else
        cout<<"Count1 � menor ou igual que Count2."<<endl;

    if(count1>=count2)
        cout<<"Count1 � maior ou igual que Count2."<<endl;
    else
        cout<<"Count1 � menor que Count2."<<endl;

   if(count1<count2)
        cout<<"Count1 � menor que Count2."<<endl;
    else
        cout<<"Count1 � maior ou igual que Count2."<<endl;

    if(count1<=count2)
        cout<<"Count1 � menor ou igual que Count2."<<endl;
    else
        cout<<"Count1 � maior que Count2."<<endl;

    percent = count1.porcentagem(10);
    cout << "10% de Count1 �: R$ " << percent.getAmount() <<"."<<endl;
    percent = count2.porcentagem(10);
    cout << "10% de Count2 �: R$ " << percent.getAmount() <<"."<<endl;


    return 0;
}

Money::Money( ): dollars(0), cents(0)
{/*Corpo propositadamente vazio.*/}

Money::Money(double amount):dollars(dollarsPart(amount)), cents(centsPart(amount))
{/*Corpo propositadamente vazio*/}

Money::Money(int theDollars):dollars(theDollars), cents(0)
{/*Corpo propositadamente vazio*/}

Money::Money(int theDollars, int theCents)
{
 if ((theDollars < 0 && theCents > 0) || (theDollars > 0 && theCents < 0))
 {
    cout << "Dados monet�rios inconsistentes.\n";
    exit(1);
 }
 dollars = theDollars;
 cents = theCents;
}

double Money::getAmount( ) const
{
    return (dollars + cents*0.01);
}

int Money::getDollars( ) const
{
 return dollars;
}

int Money::getCents( ) const
{
 return cents;
}

const Money operator +(const Money& amount1, const Money& amount2)
{
 int allCents1 = amount1.getCents( ) + amount1.getDollars( )*100;
 int allCents2 = amount2.getCents( ) + amount2.getDollars( )*100;
 int sumAllCents = allCents1 + allCents2;
 int absAllCents = abs(sumAllCents); //O dinheiro pode ser negativo.
 int finalDollars = absAllCents/100;
 int finalCents = absAllCents%100;
 if (sumAllCents < 0)
 {
    finalDollars = -finalDollars;
    finalCents = -finalCents;
 }
 return Money(finalDollars, finalCents);
}

const Money operator -(const Money& amount1, const Money& amount2)
{
 int allCents1 = amount1.getCents( ) + amount1.getDollars( )*100;
 int allCents2 = amount2.getCents( ) + amount2.getDollars( )*100;
 int diffAllCents = allCents1 - allCents2;
 int absAllCents = abs(diffAllCents);
 int finalDollars = absAllCents/100;
 int finalCents = absAllCents%100;
 if (diffAllCents < 0)
 {
    finalDollars = -finalDollars;
    finalCents = -finalCents;
 }
 return Money(finalDollars, finalCents);
}

bool operator ==(const Money& amount1, const Money& amount2)
{
 return ((amount1.getDollars( ) == amount2.getDollars( ))&&(amount1.getCents( ) == amount2.getCents( )));
}

const Money operator -(const Money& amount)
{
 return Money(-amount.getDollars( ), -amount.getCents( ));
}

const bool operator <(const Money& amount1, const Money& amount2)
{
    return ((amount1.getDollars()+amount1.getCents()*0.01)<(amount2.getDollars()+amount2.getCents()*0.01));
}

const bool operator <=(const Money& amount1, const Money& amount2)
{
    return ((amount1.getDollars()+amount1.getCents()*0.01)<=(amount2.getDollars()+amount2.getCents()*0.01));
}

const bool operator >(const Money& amount1, const Money& amount2)
{
    return ((amount1.getDollars()+amount1.getCents()*0.01)>(amount2.getDollars()+amount2.getCents()*0.01));
}

const bool operator >=(const Money& amount1, const Money& amount2)
{
    return ((amount1.getDollars()+amount1.getCents()*0.01)>=(amount2.getDollars()+amount2.getCents()*0.01));
}

const Money Money::porcentagem(int cifraPorcentagem) const
{
    double aux;
    aux = (dollars+cents*0.01)*cifraPorcentagem/100;
    Money a(aux);
    return a;
}

int Money::dollarsPart(double amount) const
{
 return static_cast<int>(amount);
}

int Money::centsPart(double amount) const
{
 double doubleCents = amount*100;
 int intCents = (round(fabs(doubleCents)))%100;//% pode se comportar mal com negativos
 if (amount < 0)
 intCents = -intCents;
 return intCents;
}

int Money::round(double number) const
{
 return static_cast<int>(floor(number + 0.5));
}
