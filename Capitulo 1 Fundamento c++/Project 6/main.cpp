#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

/*6. Um empregado recebe R$ 16,78 por horas regulares trabalhadas em uma semana. Se esse empregado fizer
hora extra, deve receber essa mesma taxa multiplicada por 1,5. Do pagamento bruto do empregado, 6%
s�o retidos pela Previd�ncia Social, 14%, pelo Imposto de Renda Federal, 5%, por impostos estaduais, e R$
10 por semana, para o Sindicato. Se o empregado tiver tr�s ou mais dependentes, um adicional de R$ 35 � retido
para cobrir o custo extra do seguro de sa�de. Escreva um programa que leia o n�mero de horas trabalhadas em uma
semana e o n�mero de dependentes como entrada e apresente como sa�da o pagamento bruto do
empregado, o valor de cada imposto retido e o sal�rio l�quido por semana*/

int main()
{
    setlocale(LC_ALL, "Portuguese");
    const double remuneracaoHorasTrabalhadas = 16.78, taxaHoraExtra = 1.5, taxaPrevidencia = 0.06, taxaImpostoFederal = 0.14,
    taxaImpostoEstadual = 0.05, totalHorasSemanais = 40;
    const int impostoSindicato = 10;
    double horasTrabalhadasSemana, pagamentoBruto, salarioLiquidoSemana;
    int seguroSaude = 0, numeroDependentes;
    cout << "Digite o n�mero de horas trabalhadas na semana: ";
    cin >> horasTrabalhadasSemana;
    cout << "Digite o n�mero de dependentes: ";
    cin >> numeroDependentes;
    if(horasTrabalhadasSemana<=totalHorasSemanais)
        pagamentoBruto = horasTrabalhadasSemana*remuneracaoHorasTrabalhadas;
    else
        pagamentoBruto = totalHorasSemanais*remuneracaoHorasTrabalhadas + (horasTrabalhadasSemana-totalHorasSemanais)*remuneracaoHorasTrabalhadas*taxaHoraExtra;
    if(numeroDependentes<3)
        salarioLiquidoSemana = pagamentoBruto - pagamentoBruto*(taxaPrevidencia+taxaImpostoFederal+taxaImpostoEstadual) - impostoSindicato;
    else
    {
        seguroSaude = 35;
        salarioLiquidoSemana = pagamentoBruto - pagamentoBruto*(taxaPrevidencia+taxaImpostoFederal+taxaImpostoEstadual) - impostoSindicato - seguroSaude;
    }
    cout << endl << "O pagamento bruto �: " << pagamentoBruto << " reais.\n"
         << "O valor da Previd�ncia �: " << pagamentoBruto*taxaPrevidencia << " reais.\n"
         << "O valor do Imposto de Renda Federal �: " << pagamentoBruto*taxaImpostoFederal << " reais.\n"
         << "O valor do Imposto de Renda Estadual �: " << pagamentoBruto*taxaImpostoEstadual << " reais.\n"
         << "O valor do Imposto do Sindicato �: " << impostoSindicato << " reais.\n"
         << "O valor do adicional do Seguro de Sa�de �: " << seguroSaude << " reais.\n"
         << "O salario liqu�do semanal �: " << salarioLiquidoSemana << " reais.\n";
    return 0;
}
