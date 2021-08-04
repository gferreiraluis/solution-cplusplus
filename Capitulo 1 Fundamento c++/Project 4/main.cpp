#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

/*4. Nem sempre é fácil negociar um empréstimo ao consumidor. Uma forma de empréstimo é com abatimento
nas prestações, que funciona da seguinte forma: suponha que um empréstimo tenha um valor nominal de R$ 1.000,
taxa de juros de 15% e duração de 18 meses. O juro é calculado multiplicando-se o valor nominal de R$ 1.000
por 0,15, o que dá R$ 150. Essa cifra é então multiplicada pelo período do empréstimo de 1,5 anos, resultando
em R$ 225 como o total de juros devidos. Essa quantia é imediatamente deduzida do valor nominal, deixando o
consumidor apenas com R$ 775. O reembolso é feito em prestações iguais com base no valor nominal.
Assim, o pagamento mensal do empréstimo será R$ 1.000 dividido por 18, que dá R$ 55,56. Escreva um programa
que necessitará de três dados de entrada: a quantia que o consumidor precisa receber, a taxa de juros e a
duração do empréstimo em meses. O programa deve, então, calcular o valor nominal requerido para que o consumidor
receba a quantidade necessária. Deve também calcular o pagamento mensal*/

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double quantiaEmprestimo, taxaJuros, valorNominal, pagamentoMensal;
    int duracaoEmprestimoMeses;
    cout << "Digite a quantia de empréstimo desejada: ";
    cin >> quantiaEmprestimo;
    cout << "Digite o valor da taxa de juros: ";
    cin >> taxaJuros;
    cout << "Digite o período em meses da duração do empréstimo: ";
    cin >> duracaoEmprestimoMeses;
    valorNominal = quantiaEmprestimo/(1-(taxaJuros/100)*(duracaoEmprestimoMeses/12.0));
    pagamentoMensal = valorNominal/duracaoEmprestimoMeses;
    cout << endl << "O valor nominal requerido equivale a: " << valorNominal << " reais.\n"
         << "O valor do pagamento mensal equivale a: " << pagamentoMensal << " reais.\n";
    return 0;
}
