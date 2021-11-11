#include <iostream>
#include <locale.h>
#include <string>
#include <cctype>

/*4. Escreva um programa que leia uma linha de texto e substitua todas as palavras de quatro letras pela palavra
 "amor". Por exemplo, a string de entrada
Silvio � um bobo!
deve produzir a sa�da:
Silvio � um amor!
Claro que a sa�da nem sempre far� sentido. Por exemplo, a string de entrada
Jo�o vai correr para casa.
deve produzir a sa�da:
Amor vai correr amor amor.
Se a palavra de quatro letras come�ar com uma letra mai�scula, deve ser substitu�da por "Amor", n�o por
"amor". N�o � preciso verificar as letras mai�sculas, s� na primeira letra de uma palavra. Uma palavra �
uma string formada pelas letras do alfabeto e delimitada em cada extremidade por um espa�o em branco,
pelo final da linha ou qualquer outro caractere que n�o seja uma letra. Seu programa deve repetir essa
a��o at� o usu�rio dizer que deseja sair.*/

using namespace std;

void setString(string& str);
void alteraString(string& str);
void printString(const string& str);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    string str;
    setString(str);
    alteraString(str);
    printString(str);

    return 0;
}

void setString(string& str)
{
    cout<<"Digite a frase: ";
    getline(cin,str);
}

void alteraString(string& str)
{
    int contador = 0;

    for(int i=0; str[i]!='\0'; i++)
    {
        //retorna true se o caractere for uma letra do alfabeto
        if(isalpha(str[i]))
            contador++;
        else
            contador = 0;

        if(contador==4&&!(isalpha(str[i+1])))
        {
            if(str[i-3]==toupper(str[i-3]))
                str[i-3]='A';
            else
                str[i-3]='a';
            str[i-2]='m';
            str[i-1]='o';
            str[i]='r';
        }
    }

}

void printString(const string& str)
{
    cout<< str<<endl;
}
