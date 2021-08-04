#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

/*6. Um empregado recebe R$ 16,78 por horas regulares trabalhadas em uma semana. Se esse empregado fizer
hora extra, deve receber essa mesma taxa multiplicada por 1,5. Do pagamento bruto do empregado, 6%
são retidos pela Previdência Social, 14%, pelo Imposto de Renda Federal, 5%, por impostos estaduais, e R$
10 por semana, para o Sindicato. Se o empregado tiver três ou mais dependentes, um adicional de R$ 35 é retido
para cobrir o custo extra do seguro de saúde. Escreva um programa que leia o número de horas trabalhadas em uma
semana e o número de dependentes como entrada e apresente como saída o pagamento bruto do
empregado, o valor de cada imposto retido e o salário líquido por semana*/

int main()
{
    setlocale(LC_ALL, "Portuguese");
    const double remuneracaoHorasTrabalhadas = 16.78, taxaHoraExtra = 1.5, taxaPrevidencia = 0.06, taxaImpostoFederal = 0.14,
    taxaImpostoEstadual = 0.05, totalHorasSemanais = 40;
    const int impostoSindicato = 10;
    double horasTrabalhadasSemana, pagamentoBruto, salarioLiquidoSemana;
    int seguroSaude = 0, numeroDependentes;
    cout << "Digite o número de horas trabalhadas na semana: ";
    cin >> horasTrabalhadasSemana;
    cout << "Digite o número de dependentes: ";
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
    cout << endl << "O pagamento bruto é: " << pagamentoBruto << " reais.\n"
         << "O valor da Previdência é: " << pagamentoBruto*taxaPrevidencia << " reais.\n"
         << "O valor do Imposto de Renda Federal é: " << pagamentoBruto*taxaImpostoFederal << " reais.\n"
         << "O valor do Imposto de Renda Estadual é: " << pagamentoBruto*taxaImpostoEstadual << " reais.\n"
         << "O valor do Imposto do Sindicato é: " << impostoSindicato << " reais.\n"
         << "O valor do adicional do Seguro de Saúde é: " << seguroSaude << " reais.\n"
         << "O salario liquído semanal é: " << salarioLiquidoSemana << " reais.\n";
    return 0;
}
