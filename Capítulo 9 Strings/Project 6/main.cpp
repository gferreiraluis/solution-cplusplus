#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string>
#include <cctype>

/*6. Um CD à venda contém imagens .jpeg e .gif de músicas sob domínio público. O CD inclui um arquivo formado
 por linhas contendo os títulos, depois os compositores, um por linha. O nome da música
vem primeiro, depois zero ou mais espaços, depois um caractere de separação (-), depois um ou mais espaços,
 depois o nome do compositor. O nome do compositor pode ser apenas o sobrenome, ou uma inicial e
o sobrenome ou dois nomes (primeiro — último) ou três nomes (primeiro — do meio — último). Existem
algumas canções em que consta "nenhum autor listado" como nome do autor. No processamento subseqüente,
"nenhum autor listado" não deve ser rearranjado. Eis uma lista bem resumida dos títulos e autores.
1. Adagio Sonata "Ao luar" - Ludwig Van Beethoven
2. An Alexis - F.H. Hummel and J.N. Hummel
3. A La Bien Aimee - Ben Schutt
4. At Sunset - E. MacDowell
5. Angelus - J. Massenet
6. Dança de Anitra - Edward Grieg
7. Morte de Ase - Edward Grieg
8. Au Matin- Benj. - Godard
. . .
37. The Dying Poet - L. Gottschalk
38. Marcha Fúnebre - G.F. Handel
39. Do They Think of Me At Home - Chas. W. Glover
40. The Dearest Spot - W.T. Wrighton
1. Evening - L. Van Beethoven
2. Embarrassment - Franz Abt
3. Erin is my Home - nenhum autor listado
4. Ellen Bayne - Stephen C. Foster
. . .
9. Alla Mazurka - A. Nemerowsky
. . .
1. The Dying Volunteer - A.E. Muse
2. Dolly Day - Stephen C. Foster
3. Dolcy Jones - Stephen C. Foster
4. Dickory, Dickory, Dock - nenhum autor listado
5. The Dear Little Shamrock - nenhum autor listado
6. Dutch Warbler - nenhum autor listado
 . . .
A tarefa final é produzir uma lista alfabética de compositores seguida por uma lista de suas músicas em
ordem alfabética por título dentro de cada compositor. Este exercício fica mais fácil se for dividido em
partes:
Escreva código para:
a. Remover números iniciais, pontos finais e qualquer espaço de modo que a primeira palavra do título
seja a primeira palavra da linha.
b. Substituir todos os espaços múltiplos por um único espaço.
c. Alguns títulos podem ter vários caracteres, por exemplo:
20. Ba- Be- Bi- Bo- Bu - nenhum autor listado
Substitua todos os hífens - em qualquer linha antes do final da linha por um espaço, a não ser o último.
d. Talvez a última palavra no título tenha o caractere - sem nenhum espaço entre ele e o caractere =. Inclua o espaço.
e. Quando colocar o título em ordem alfabética, não considere uma inicial "A", "O", "Um" ou "Uma"
no título. Escreva código para deslocar essas palavras iniciais para logo antes do caractere -. Uma vírgula
depois da última palavra no título não é obrigatória, mas seria interessante. Isso pode ser feito depois que
os nomes dos compositores forem deslocados para a frente, mas obviamente o código será diferente.
f. Desloque os nomes dos compositores para o início da linha, seguidos pelo caractere -, seguido pelo título da composição.
g. Desloque qualquer primeira inicial, primeiros e segundos nomes dos compositores para depois do sobrenome do
compositor. Se o compositor for "nenhum autor listado", essa string não deve ser rearranjada. Portanto, teste essa combinação
h. Coloque em ordem alfabética, por compositor, utilizando qualquer rotina que conheça. Pode ignorar
qualquer duplicata do sobrenome do compositor, como CPE Bach e JS Bach, mas colocar em ordem
o segundo nome do compositor seria interessante. Pode-se utilizar a ordenação por inserção, por seleção,
 bubble sort ou outro algoritmo de ordenação.
i. Caso não tenha feito isso ainda, desloque aqueles "A", "O", "Um" ou "Uma" que iniciam alguns títulos
para o final do título. Então, dentro de cada compositor, coloque os títulos das composições em
ordem alfabética.
j. Guarde uma cópia do seu projeto e código. Mais tarde, pediremos para você fazer isso novamente utilizando
 o STL vector container*/


using namespace std;

int const TAMANHO = 100;

void setString(string& str);
void removeInicial(string& str);
void removeEspacos(string& str);
void removeHifens(string& str);
void espacoHifen(string& str);
void printString(const string& str);


int main()
{
    setlocale(LC_ALL, "Portuguese");
    string str;
    setString(str);
    removeInicial(str);
    removeEspacos(str);
    removeHifens(str);
    espacoHifen(str);
    printString(str);
    return 0;
}

void setString(string& str)
{
    cout<<"Digite a frase: ";
    getline(cin,str);
}

void removeInicial(string& str)
{
    do
    {
        if(!(isalpha(str[0])))
        {
            for(int i=0;str[i]!='\0'; i++)
             str[i] = str[i+1];
        }
    }while(!(isalpha(str[0])));
}

void removeEspacos(string& str)
{

    for(int i=0;str[i]!='\0'; i++)
    {
        if(str[i]==' '&&str[i+1]==' ')
        {
            int j;
            for(j=i;str[j]!='\0';j++)
                str[j] = str[j+1];
            i--;
        }
    }
}

void removeHifens(string& str)
{
    int cont=0;
    for(int i=0; str[i]!='\0';i++)
    {
        if(str[i]=='-')
        {
            for(int j=i+1; str[j]!='\0';j++)
            {
                if(str[j]=='-')
                    cont++;
            }

            if(cont>0)
            str[i] = ' ';

            cont=0;
        }
    }
}

void espacoHifen(string& str)
{
    char aux[TAMANHO];
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='-'&&(isgraph(str[i-1])))
        {
            int k = 0;
            for(int j=i;str[j]!='\0';j++)
            {
                aux[k] = str[j];
                k++;
            }
            aux[k] = '\0';
            str[i] = ' ';
            k = 0;
            for(int j=i+1;aux[k]!='\0';j++)
            {
                str[j] = aux[k];
                k++;
            }
        }
        if(str[i]=='-'&&(isgraph(str[i+1])))
        {
            int k = 0;
            for(int j=i+1;str[j]!='\0';j++)
            {
                aux[k] = str[j];
                k++;
            }
            aux[k] = '\0';
            str[i+1] = ' ';
            k = 0;
            for(int j=i+2;aux[k]!='\0';j++)
            {
                str[j] = aux[k];
                k++;
            }
        }
    }
}

void printString(const string& str)
{
    for(int i=0;str[i]!='\0';i++)
        cout<<str[i];
    cout<<endl;
}
