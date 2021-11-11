#include <iostream>
#include <locale.h>
#include <string>
#include <cctype>

/*5. Escreva um programa que possa ser usado para treinar o usuário a utilizar uma linguagem menos machista,
 sugerindo versões alternativas de sentenças dadas pelo usuário. O programa pedirá uma sentença, lerá a
sentença para uma variável string e substituirá todas as ocorrências de pronomes masculinos com pronomes
de gênero neutro. Por exemplo, substituirá "ele" por "ela ou ele". Assim, a sentença de entrada
Consulte um orientador, fale com ele e escute o que ele disser.
deve produzir a seguinte versão alterada:
Consulte um orientador, fale com ela ou ele e escute o que ela ou ele disser.
Não deixe de preservar as letras maiúsculas na primeira palavra da sentença. O pronome "dele" pode ser
substituído por "dela ou dele"; não é necessário que seu programa decida entre "dele" ou "delas". Permita
que o usuário repita o processo para mais sentenças até dizer que deseja encerrar o programa. Será um
longo programa, que exigirá uma boa dose de paciência. Seu programa não deve substituir a string "ele"
quando ocorrer dentro de outra palavra, como "elemento". Uma palavra é qualquer string formada por
letras e delimitada em cada extremidade por um espaço em branco, o final da linha ou qualquer outro caractere
 que não seja uma letra. Permita que suas sentenças tenham até 100 caracteres de extensão.*/

using namespace std;

const int TAMANHO = 100;

void setString(char str[]);
void alternativaString(char str[]);
void printString(const char str[]);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char str[TAMANHO], op;
    do
    {
        setString(str);
        alternativaString(str);
        printString(str);
        cout<<endl<<"Deseja reiniciar o programa? (S/N): ";
        cin>> op;
        cin.ignore(10,'\n');
    }while(op=='s'||op=='S');
    return 0;
}

void setString(char str[])
{
    cout<<endl<<"Digite a frase: ";
    cin.get(str,TAMANHO);
}

void alternativaString(char str[])
{

    for(int i=0; i<TAMANHO; i++)
    {
        if((str[i]=='e'||str[i]=='E')&&(str[i+1]=='l'||str[i+1]=='L')&&(str[i+2]=='e'||str[i+2]=='E')&&(!(isalnum(str[i+3])))&&(!(isalnum(str[i-1]))))
        {
            int k=i+11;
            for(int j=TAMANHO;j>i+10;j--)
            {
                str[j] = str[j-7];
            }

            str[i+4] = 'o';
            str[i+5] = 'u';
            str[i+6] = ' ';
            str[i+7] = 'e';
            str[i+8] = 'l';
            str[i+9] = 'a';
            str[i+10] = ' ';
        }

        if((str[i]=='D'||str[i]=='d')&&(str[i+1]=='e'||str[i+1]=='E')&&(str[i+2]=='l'||str[i+2]=='L')&&(str[i+3]=='e'||str[i+3]=='E')&&(!(isalnum(str[i+4])))&&(!(isalnum(str[i-1]))))
        {
            int k=i+11;
            for(int j=TAMANHO;j>i+12;j--)
            {
                str[j] = str[j-8];
            }

            str[i+5] = 'o';
            str[i+6] = 'u';
            str[i+7] = ' ';
            str[i+8] = 'd';
            str[i+9] = 'e';
            str[i+10] = 'l';
            str[i+11] = 'a';
            str[i+12] = ' ';
        }
    }
}

void printString(const char str[])
{
    cout<<endl<<"Versão alternativa: "<<endl;
    for(int i=0;str[i]!='\0';i++)
        cout<<str[i];
    cout<<endl;
}
