#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

/*5. Escreva um programa que determine se uma sala de confer�ncias est� violando as normas legais de inc�ndio
relativas � sua capacidade m�xima. O programa ler� a m�xima capacidade da sala e o n�mero de pessoas que
comparecer�o � confer�ncia. Se o n�mero de pessoas for menor ou igual � capacidade m�xima
da sala, o programa anuncia que a confer�ncia est� de acordo com as normas legais e diz quantas outras
pessoas poder�o participar conforme essas normas. Se o n�mero de pessoas exceder a capacidade m�xima
da sala, o programa anuncia que a confer�ncia n�o poder� ocorrer, devido �s normas de inc�ndio, e diz
quantas pessoas devem ser exclu�das a fim de obedecer �s normas.*/

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int capacidadeMaxima, numeroPessoas;
    cout << "Digite a capacidade da sala: ";
    cin >> capacidadeMaxima;
    cout << "Digite o n�mero de pessoas que comparecer�o a confer�ncia: ";
    cin >> numeroPessoas;
    if(numeroPessoas<=capacidadeMaxima)
        cout << endl << "A confer�ncia est� de acordo com as normais legais de seguran�a e poder�o participar mais " << capacidadeMaxima - numeroPessoas << " pessoas.\n";
        else
        cout << endl << "A confer�ncia n�o est� de acordo com as normais legais de seguran�a � necess�rio excluir " << numeroPessoas - capacidadeMaxima << " pessoas.\n";
    return 0;
}
