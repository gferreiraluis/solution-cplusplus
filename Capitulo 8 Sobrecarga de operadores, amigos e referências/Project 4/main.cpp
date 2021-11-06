#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*4. Modifique cumulativamente o exemplo do Painel 8.7 da seguinte forma:
a. No Painel 8.7, substitua os membros privados char primeiro e segundo por um vetor de char de tamanho
 100 e um membro de dados privado chamado tamanho.
Inclua um construtor-padrão que inicialize tamanho como 10 e fixe as primeiras 10 posições de char
como ’#’. (Utiliza apenas 10 das 100 posições possíveis.)
Inclua uma função de acesso que forneça o valor do membro privado tamanho.
Teste.
b. Acrescente um operador[ ] membro que forneça um char& que permita ao usuário ter acesso a qualquer
 membro do vetor de dados privado ou o estabeleça utilizando um índice não-negativo que seja
menor que tamanho.
Teste.
c. Acrescente um construtor que requeira um argumento int, tm, que fixe os primeiros tm membros do
vetor char como ’#’.
Teste.
d. Acrescente um construtor que requeira um argumento int, tm, e um vetor de char de tamanho tm.
O construtor deve fixar os primeiros tm membros do vetor de dados privado como os tm membros do
vetor argumento de char.
Teste.
OBSERVAÇÕES: quando testar, utilize bons valores conhecidos, valores no limite e valores deliberadamente
 ruins. Não exigimos que você inclua verificações para índices fora dos limites em seu código, mas
isso seria interessante. Alternativas para lidar com erros: envie uma mensagem de erro e depois "caia fora"
(ou seja, chame exit(1)) ou dê ao usuário outra oportunidade de fornecer uma entrada correta.*/

using namespace std;

const int TAMANHO_VETOR = 100;

 class CharPair
{
 public:
 CharPair();
 CharPair(int tm);
 CharPair(int tm, char vetor[]);

 int getTamanho();
 char& operator[](int index);

 private:
 char first[TAMANHO_VETOR];
 int tamanho_;
};

int main()
{
    setlocale(LC_ALL, "Portuguese");
    CharPair a, b(3);
    int tm;

    cout<<"Obj a: "<<endl;
    for(int i=0; i<a.getTamanho();i++)
        cout << a[i] << endl;
    cout<<"Obj b: "<<endl;
    for(int i=0; i<b.getTamanho();i++)
        cout << b[i] << endl;
    do
    {
        cout << endl <<" Entre com o tamanho do vetor: ";
        cin >> tm;
        if(tm>TAMANHO_VETOR||tm<=0)
            cout<<"Valor invalido."<<endl;
    }while(tm>TAMANHO_VETOR||tm<=0);

    char vetor[tm];
    cout<<"Entre com os valores do vetor: ";
    for(int i=0; i<tm; i++)
        cin>>vetor[i];

    CharPair c(tm, vetor);
    cout<<"Obj c: "<<endl;
    for(int i=0; i<c.getTamanho();i++)
        cout << c[i] << endl;

    return 0;
}

CharPair::CharPair( )
{
    tamanho_ = 10;

    for(int i=0; i<tamanho_; i++)
            first[i] = '#';
}

CharPair::CharPair(int tm)
{
      tamanho_ = tm;

    for(int i=0; i<tamanho_; i++)
       first[i] = '#';
}

CharPair::CharPair(int tm, char vetor[])
{
     tamanho_ = tm;

    for(int i=0; i<tamanho_; i++)
       first[i] = vetor[i];
}

int CharPair::getTamanho()
{
    return tamanho_;
}

char& CharPair::operator[](int index)
{
 if(index>=0&&index<=getTamanho())
    return first[index];
 else
    cout<<"Valor inválido."<<endl;
}
