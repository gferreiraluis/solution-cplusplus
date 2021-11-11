#include <iostream>
#include <locale.h>
#include <cctype>


/*1. Escreva um programa que leia uma senten�a de at� 100 caracteres. Na senten�a de sa�da dois ou mais espa�os
em branco dever�o ser comprimidos em apenas um espa�o em branco. Al�m disso, a senten�a deve
come�ar com uma letra mai�scula, mas n�o deve conter outras letras mai�sculas. N�o se preocupe com os
nomes pr�prios; se sua primeira letra for alterada para min�scula, n�o h� problema. Trate uma quebra de
linha como se fosse um espa�o em branco, no sentido de que uma quebra de linha e qualquer n�mero de
espa�os em branco sejam comprimidos em um �nico espa�o em branco. Presuma que a senten�a termine
com um ponto final e n�o contenha outros pontos finais. Por exemplo, a entrada
a Resposta para a Vida, o Universo e Sabe L� O Que Mais
� 42.
deve produzir a seguinte sa�da:
A resposta para a vida, o universo e sabe l� o que mais � 42.*/

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
    cout<< "A frase �: ";
    for(int i=0;frase[i]!='\0';i++)
        cout<<frase[i];
    cout<<endl;
}

void formataFrase(char frase[])
{
    // converte primeiro caractere da frase para mai�sculo
    frase[0] = toupper(frase[0]);

    // converte o restante dos caracteres da frase para min�sculo.
    for(int i=1; frase[i]!='\0'; i++)
        frase[i] = tolower(frase[i]);

    // retira excesso de espa�os em brancos da frase
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
