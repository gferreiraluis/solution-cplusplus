#include <iostream>
#include <locale.h>
#include <string>
#include <cctype>

using namespace std;

/*3. Escreva um programa que leia o nome de uma pessoa no seguinte formato: primeiro nome, depois nome do
meio ou inicial e, por fim, o sobrenome. O programa apresenta como sa�da o nome no seguinte formato:
Sobrenome, Primeiro_Nome, Inicial_Do_Meio.
Por exemplo, a entrada
Maria Alegre Usu�ria
deve produzir a sa�da
Usu�ria, Maria A.
A entrada
Maria A. Usu�ria
tamb�m deve produzir a sa�da
Usu�ria, Maria A.
Seu programa deve colocar um ponto final depois da inicial do meio, mesmo se a entrada n�o contiver tal
ponto. Deve tamb�m permitir que os usu�rios n�o forne�am nome do meio ou inicial do meio. Nesse
caso, � �bvio que a sa�da n�o cont�m nome do meio ou inicial. Por exemplo, a entrada
Maria Usu�ria
deve produzir a sa�da
Usu�ria, Maria
Se voc� utilizar strings C, suponha que cada nome tenha no m�ximo 20 caracteres de comprimento. Uma
outra op��o � utilizar a classe string. (Dica: voc� pode querer utilizar tr�s vari�veis string em vez de uma
grande vari�vel string para a entrada. Pode achar mais f�cil n�o usar getline.)*/

void setNome(string& nome1, string& nome2, string& nome3);
void saidaNome(string& nome1, string& nome2);
void saidaNome(string& nome1, string& nome2, string& nome3);


int main()
{
    setlocale(LC_ALL, "Portuguese");
    string nome1, nome2, nome3;
    setNome(nome1,nome2,nome3);
    return 0;
}

void setNome(string& nome1, string& nome2, string& nome3)
{
    char op;
    cout << "Digite o primeiro nome: ";
    cin>>nome1;

    cout<<"Deseja digitar o sobrenome do meio? (S/N): ";
    cin >> op;

    if(op=='s'||op=='S')
    {
        cout<<"Digite o sobrenome do meio: ";
        cin>>nome2;
    }

    cout << "Digite o �ltimo sobrenome: ";
    cin>>nome3;

    if(op=='s'||op=='S')
        saidaNome(nome1,nome2,nome3);
    else
        saidaNome(nome1,nome3);

}

void saidaNome(string& nome1, string& nome2)
{
    nome1[0]= toupper(nome1[0]);
    nome2[0]= toupper(nome2[0]);
    cout << nome2 <<", "<<nome1<<endl;
}

void saidaNome(string& nome1, string& nome2, string& nome3)
{
    nome1[0]= toupper(nome1[0]);
    nome3[0]= toupper(nome3[0]);
    char a = toupper(nome2[0]);
    cout << nome3<<", "<<nome1<<" "<<a<<"."<<endl;
}
