#include <iostream>
#include <locale.h>
#include <string>
#include <cctype>

using namespace std;

/*3. Escreva um programa que leia o nome de uma pessoa no seguinte formato: primeiro nome, depois nome do
meio ou inicial e, por fim, o sobrenome. O programa apresenta como saída o nome no seguinte formato:
Sobrenome, Primeiro_Nome, Inicial_Do_Meio.
Por exemplo, a entrada
Maria Alegre Usuária
deve produzir a saída
Usuária, Maria A.
A entrada
Maria A. Usuária
também deve produzir a saída
Usuária, Maria A.
Seu programa deve colocar um ponto final depois da inicial do meio, mesmo se a entrada não contiver tal
ponto. Deve também permitir que os usuários não forneçam nome do meio ou inicial do meio. Nesse
caso, é óbvio que a saída não contém nome do meio ou inicial. Por exemplo, a entrada
Maria Usuária
deve produzir a saída
Usuária, Maria
Se você utilizar strings C, suponha que cada nome tenha no máximo 20 caracteres de comprimento. Uma
outra opção é utilizar a classe string. (Dica: você pode querer utilizar três variáveis string em vez de uma
grande variável string para a entrada. Pode achar mais fácil não usar getline.)*/

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

    cout << "Digite o último sobrenome: ";
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
