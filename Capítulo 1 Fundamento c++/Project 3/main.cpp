#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

/*3. Os trabalhadores de uma empresa em particular receberam um aumento de 7,6% retroativo a seis meses.
Escreva um programa que tome o sal�rio anual anterior de um empregado como entrada e apresente como sa�da
a quantidade de pagamento retroativo devido ao empregado, o novo sal�rio anual e o novo sal�rio mensal.
Utilize uma declara��o de vari�vel com o modificador const para expressar o aumento de pagamento.*/

int main()
{
    setlocale(LC_ALL, "Portuguese");
    const double aumentoRetroativo = 0.076;
    const int periodoMeses = 6;
    double pagamentoRetroativo, velhoSalarioAnual ,novoSalarioAnual,novoSalarioMensal;
    cout << "Digite o sal�rio anual anterior do funcion�rio: R$ ";
    cin >> velhoSalarioAnual;
    pagamentoRetroativo = (velhoSalarioAnual/12)*aumentoRetroativo*periodoMeses;
    novoSalarioAnual = velhoSalarioAnual*(1+aumentoRetroativo);
    novoSalarioMensal = novoSalarioAnual/12;
    cout << endl << "A quantidade de pagamento retroativo equivale a: " << pagamentoRetroativo << " reais.\n"
         << "O novo sal�rio anual equivale a: " << novoSalarioAnual << " reais.\n"
         << "O novo sal�rio mensal equivale a: " << novoSalarioMensal << " reais.\n";
    return 0;
}
