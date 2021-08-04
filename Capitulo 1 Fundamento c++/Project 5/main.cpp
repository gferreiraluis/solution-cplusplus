#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

/*5. Escreva um programa que determine se uma sala de conferências está violando as normas legais de incêndio
relativas à sua capacidade máxima. O programa lerá a máxima capacidade da sala e o número de pessoas que
comparecerão à conferência. Se o número de pessoas for menor ou igual à capacidade máxima
da sala, o programa anuncia que a conferência está de acordo com as normas legais e diz quantas outras
pessoas poderão participar conforme essas normas. Se o número de pessoas exceder a capacidade máxima
da sala, o programa anuncia que a conferência não poderá ocorrer, devido às normas de incêndio, e diz
quantas pessoas devem ser excluídas a fim de obedecer às normas.*/

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int capacidadeMaxima, numeroPessoas;
    cout << "Digite a capacidade da sala: ";
    cin >> capacidadeMaxima;
    cout << "Digite o número de pessoas que comparecerão a conferência: ";
    cin >> numeroPessoas;
    if(numeroPessoas<=capacidadeMaxima)
        cout << endl << "A conferência está de acordo com as normais legais de segurança e poderão participar mais " << capacidadeMaxima - numeroPessoas << " pessoas.\n";
        else
        cout << endl << "A conferência não está de acordo com as normais legais de segurança é necessário excluir " << numeroPessoas - capacidadeMaxima << " pessoas.\n";
    return 0;
}
