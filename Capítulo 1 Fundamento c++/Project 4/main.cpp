#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

/*4. Nem sempre � f�cil negociar um empr�stimo ao consumidor. Uma forma de empr�stimo � com abatimento
nas presta��es, que funciona da seguinte forma: suponha que um empr�stimo tenha um valor nominal de R$ 1.000,
taxa de juros de 15% e dura��o de 18 meses. O juro � calculado multiplicando-se o valor nominal de R$ 1.000
por 0,15, o que d� R$ 150. Essa cifra � ent�o multiplicada pelo per�odo do empr�stimo de 1,5 anos, resultando
em R$ 225 como o total de juros devidos. Essa quantia � imediatamente deduzida do valor nominal, deixando o
consumidor apenas com R$ 775. O reembolso � feito em presta��es iguais com base no valor nominal.
Assim, o pagamento mensal do empr�stimo ser� R$ 1.000 dividido por 18, que d� R$ 55,56. Escreva um programa
que necessitar� de tr�s dados de entrada: a quantia que o consumidor precisa receber, a taxa de juros e a
dura��o do empr�stimo em meses. O programa deve, ent�o, calcular o valor nominal requerido para que o consumidor
receba a quantidade necess�ria. Deve tamb�m calcular o pagamento mensal*/

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double quantiaEmprestimo, taxaJuros, valorNominal, pagamentoMensal;
    int duracaoEmprestimoMeses;
    cout << "Digite a quantia de empr�stimo desejada: ";
    cin >> quantiaEmprestimo;
    cout << "Digite o valor da taxa de juros: ";
    cin >> taxaJuros;
    cout << "Digite o per�odo em meses da dura��o do empr�stimo: ";
    cin >> duracaoEmprestimoMeses;
    valorNominal = quantiaEmprestimo/(1-(taxaJuros/100)*(duracaoEmprestimoMeses/12.0));
    pagamentoMensal = valorNominal/duracaoEmprestimoMeses;
    cout << endl << "O valor nominal requerido equivale a: " << valorNominal << " reais.\n"
         << "O valor do pagamento mensal equivale a: " << pagamentoMensal << " reais.\n";
    return 0;
}
