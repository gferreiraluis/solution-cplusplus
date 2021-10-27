#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*2. Voc� acaba de adquirir um aparelho estereof�nico que custa R$ 1.000 por meio do seguinte plano de credi�rio:
zero de entrada, juros de 18% ao ano (e, portanto, 1,5% ao m�s) e presta��es mensais de R$ 50.
A presta��o mensal de R$ 50 � utilizada para pagar os juros, e o restante � utilizado para pagar parte da
d�vida remanescente. Assim, no primeiro m�s voc� paga 1,5% de R$ 1.000 em juros. Isso d� R$ 15. Os
restantes R$ 35 s�o deduzidos do seu d�bito, o que o deixa com um d�bito de R$ 965,00. No m�s seguinte voc� paga
um juro de 1,5% sobre R$ 965,00, que d� R$ 14,48. Assim, voc� pode deduzir R$ 35,52 (que � R$ 50 � R$ 14,48) da soma que deve.
Escreva um programa que lhe diga quantos meses voc� levar� para pagar o que deve, assim como a soma
total paga em juros. Utilize um loop para calcular a soma paga em juros e o tamanho do d�bito a cada
m�s. (Seu programa final n�o precisa fornecer a quantia paga mensalmente a t�tulo de juros, mas voc�
pode querer escrever uma vers�o preliminar do programa que apresente esses valores.) Utilize uma vari�vel
para contar o n�mero de itera��es do loop e, portanto, o n�mero de meses at� que o d�bito seja zero.
Voc� pode querer utilizar outras vari�veis tamb�m. O �ltimo pagamento pode ser inferior a R$ 50 se o
d�bito for menor, mas n�o se esque�a dos juros. Se voc� deve R$ 50, ent�o sua presta��o mensal de
R$ 50 n�o saldar� seu d�bito, embora v� chegar perto disso. Os juros de um m�s sobre R$ 50 s�o de
apenas 75 centavo*/

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");//habilita a acentua��o para o portugu�s
    const double taxaJuros = 0.015, prestacao = 50;
    double debito = 1000;
    int meses=0;
    while(debito>50){
        debito = debito - (50-debito*taxaJuros);
        meses++;
    }
    cout << "A quantidade de meses para pagar o aparelho � " << meses << "meses.";
    return 0;
}
