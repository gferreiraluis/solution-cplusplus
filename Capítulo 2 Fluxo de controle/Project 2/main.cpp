#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*2. Você acaba de adquirir um aparelho estereofônico que custa R$ 1.000 por meio do seguinte plano de crediário:
zero de entrada, juros de 18% ao ano (e, portanto, 1,5% ao mês) e prestações mensais de R$ 50.
A prestação mensal de R$ 50 é utilizada para pagar os juros, e o restante é utilizado para pagar parte da
dívida remanescente. Assim, no primeiro mês você paga 1,5% de R$ 1.000 em juros. Isso dá R$ 15. Os
restantes R$ 35 são deduzidos do seu débito, o que o deixa com um débito de R$ 965,00. No mês seguinte você paga
um juro de 1,5% sobre R$ 965,00, que dá R$ 14,48. Assim, você pode deduzir R$ 35,52 (que é R$ 50 – R$ 14,48) da soma que deve.
Escreva um programa que lhe diga quantos meses você levará para pagar o que deve, assim como a soma
total paga em juros. Utilize um loop para calcular a soma paga em juros e o tamanho do débito a cada
mês. (Seu programa final não precisa fornecer a quantia paga mensalmente a título de juros, mas você
pode querer escrever uma versão preliminar do programa que apresente esses valores.) Utilize uma variável
para contar o número de iterações do loop e, portanto, o número de meses até que o débito seja zero.
Você pode querer utilizar outras variáveis também. O último pagamento pode ser inferior a R$ 50 se o
débito for menor, mas não se esqueça dos juros. Se você deve R$ 50, então sua prestação mensal de
R$ 50 não saldará seu débito, embora vá chegar perto disso. Os juros de um mês sobre R$ 50 são de
apenas 75 centavo*/

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");//habilita a acentuação para o português
    const double taxaJuros = 0.015, prestacao = 50;
    double debito = 1000;
    int meses=0;
    while(debito>50){
        debito = debito - (50-debito*taxaJuros);
        meses++;
    }
    cout << "A quantidade de meses para pagar o aparelho é " << meses << "meses.";
    return 0;
}
