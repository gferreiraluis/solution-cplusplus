#include <iostream>
#include <locale.h>
#include <cctype>


/*1. Escreva um programa que leia uma sentença de até 100 caracteres. Na sentença de saída dois ou mais espaços
em branco deverão ser comprimidos em apenas um espaço em branco. Além disso, a sentença deve
começar com uma letra maiúscula, mas não deve conter outras letras maiúsculas. Não se preocupe com os
nomes próprios; se sua primeira letra for alterada para minúscula, não há problema. Trate uma quebra de
linha como se fosse um espaço em branco, no sentido de que uma quebra de linha e qualquer número de
espaços em branco sejam comprimidos em um único espaço em branco. Presuma que a sentença termine
com um ponto final e não contenha outros pontos finais. Por exemplo, a entrada
a Resposta para a Vida, o Universo e Sabe Lá O Que Mais
É 42.
deve produzir a seguinte saída:
A resposta para a vida, o universo e sabe lá o que mais é 42.*/

using namespace std;

const int NUMERO_CARACTERES = 100;

void setFrase(char frase[]);
void formataFrase(char frase[]);
void getFrase(char frase[]);


int main()
{
    setlocale(LC_ALL, "Portuguese");
    char frase[NUMERO_CARACTERES];
    setFrase(frase);
    formataFrase(frase);
    getFrase(frase);

    return 0;
}

void setFrase(char frase[])
{
    cout<<"Digite a frase desejada: ";
    cin.get(frase,NUMERO_CARACTERES);
}

void getFrase(char frase[])
{
    cout<< "A frase é: ";
    for(int i=0;frase[i]!='\0';i++)
        cout<<frase[i];
    cout<<endl;
}

void formataFrase(char frase[])
{
    // converte primeiro caractere da frase para maiúsculo
    frase[0] = toupper(frase[0]);

    // converte o restante dos caracteres da frase para minúsculo.
    for(int i=1; frase[i]!='\0'; i++)
        frase[i] = tolower(frase[i]);

    // retira excesso de espaços em brancos da frase
    for(int i=0;frase[i]!='\0'; i++)
    {
        if(frase[i]==' '&&frase[i+1]==' ')
        {
            int j;
            for(j=i;frase[j]!='\0';j++)
                frase[j] = frase[j+1];
            i--;
        }
    }
}
