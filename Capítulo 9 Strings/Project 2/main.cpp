#include <iostream>
#include <locale.h>
#include <string>
#include <cctype>

using namespace std;

/*2. Escreva um programa que leia uma linha de texto e apresente como saída o número de palavras na linha
e o número do ocorrências de cada letra. Defina uma palavra como qualquer string de letras que seja delimitada
 em cada extremidade por um espaço em branco, um ponto final, uma vírgula ou o início ou fim
da linha. Pode supor que a entrada consista inteiramente em letras, espaços em branco, vírgulas e pontos
finais. Quando enviar à saída o número de letras que ocorrem em uma linha, não deixe de contar as versões
maiúsculas e minúsculas de uma letra como a mesma letra. Apresente na saída as letras em ordem alfabética
e liste apenas aquelas letras que ocorrem na linha de entrada. Por exemplo, a linha de entrada
Eu sou dez.
deve produzir uma saída semelhante à seguinte:
3 palavras
2 e
2 u
1 s
1 o
1 d
1 z*/

void setString(string& str);
void contadorString(string& str);
void printPalavras(int num);
void printLetras(char a, int num);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    string str;
    setString(str);
    contadorString(str);
    return 0;
}

void setString(string& str)
{
    cout<<"Digite a frase: ";
    getline(cin,str);
}

void contadorString(string& str)
{
    string aux = str;
    char letra;
    int palavras = 0, contador = 1;

    for(int i=0; aux[i]!='\0'; i++)
    {
        if((aux[i]!=' '&&aux[i]!='.'&&aux[i]!=',')&&(aux[i+1]==' '||aux[i+1]=='.'||aux[i+1]==','||aux[i+1]=='\0'))
            palavras++;
    }

    printPalavras(palavras);

    for(int i=0; aux[i]!='\0'; i++)
        aux[i] = tolower(aux[i]);

    for(int i=0; aux[i]!='\0'; i++)
    {
        if(aux[i]==' '||aux[i]=='.'||aux[i]==',')
        {
            int j;
            for(j=i;aux[j]!='\0';j++)
                aux[j] = aux[j+1];
            i--;
        }
    }

    for(int i=0; aux[i]!='\0';i++)
    {
        for(int j=i+1; aux[j]!='\0'; j++)
        {
            if(aux[j]<aux[i])
            {
                letra = aux[i];
                aux[i] = aux[j];
                aux[j] = letra;
            }
        }
    }

    for(int i=0; aux[i]!='\0'; i++)
    {
        int j;
        for(j=i+1; aux[i]==aux[j]; j++)
            contador++;
        printLetras(aux[i], contador);
        i=j-1;
        contador = 1;
    }

}

void printPalavras(int num)
{
    cout<<endl<<num<<"  Palavras"<<endl;
}

void printLetras(char a, int num)
{
    cout<<num<<"  "<<a<<endl;
}

