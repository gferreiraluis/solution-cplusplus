#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string>
#include <cctype>

/*6. Um CD � venda cont�m imagens .jpeg e .gif de m�sicas sob dom�nio p�blico. O CD inclui um arquivo formado
 por linhas contendo os t�tulos, depois os compositores, um por linha. O nome da m�sica
vem primeiro, depois zero ou mais espa�os, depois um caractere de separa��o (-), depois um ou mais espa�os,
 depois o nome do compositor. O nome do compositor pode ser apenas o sobrenome, ou uma inicial e
o sobrenome ou dois nomes (primeiro � �ltimo) ou tr�s nomes (primeiro � do meio � �ltimo). Existem
algumas can��es em que consta "nenhum autor listado" como nome do autor. No processamento subseq�ente,
"nenhum autor listado" n�o deve ser rearranjado. Eis uma lista bem resumida dos t�tulos e autores.
1. Adagio Sonata "Ao luar" - Ludwig Van Beethoven
2. An Alexis - F.H. Hummel and J.N. Hummel
3. A La Bien Aimee - Ben Schutt
4. At Sunset - E. MacDowell
5. Angelus - J. Massenet
6. Dan�a de Anitra - Edward Grieg
7. Morte de Ase - Edward Grieg
8. Au Matin- Benj. - Godard
. . .
37. The Dying Poet - L. Gottschalk
38. Marcha F�nebre - G.F. Handel
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
A tarefa final � produzir uma lista alfab�tica de compositores seguida por uma lista de suas m�sicas em
ordem alfab�tica por t�tulo dentro de cada compositor. Este exerc�cio fica mais f�cil se for dividido em
partes:
Escreva c�digo para:
a. Remover n�meros iniciais, pontos finais e qualquer espa�o de modo que a primeira palavra do t�tulo
seja a primeira palavra da linha.
b. Substituir todos os espa�os m�ltiplos por um �nico espa�o.
c. Alguns t�tulos podem ter v�rios caracteres, por exemplo:
20. Ba- Be- Bi- Bo- Bu - nenhum autor listado
Substitua todos os h�fens - em qualquer linha antes do final da linha por um espa�o, a n�o ser o �ltimo.
d. Talvez a �ltima palavra no t�tulo tenha o caractere - sem nenhum espa�o entre ele e o caractere =. Inclua o espa�o.
e. Quando colocar o t�tulo em ordem alfab�tica, n�o considere uma inicial "A", "O", "Um" ou "Uma"
no t�tulo. Escreva c�digo para deslocar essas palavras iniciais para logo antes do caractere -. Uma v�rgula
depois da �ltima palavra no t�tulo n�o � obrigat�ria, mas seria interessante. Isso pode ser feito depois que
os nomes dos compositores forem deslocados para a frente, mas obviamente o c�digo ser� diferente.
f. Desloque os nomes dos compositores para o in�cio da linha, seguidos pelo caractere -, seguido pelo t�tulo da composi��o.
g. Desloque qualquer primeira inicial, primeiros e segundos nomes dos compositores para depois do sobrenome do
compositor. Se o compositor for "nenhum autor listado", essa string n�o deve ser rearranjada. Portanto, teste essa combina��o
h. Coloque em ordem alfab�tica, por compositor, utilizando qualquer rotina que conhe�a. Pode ignorar
qualquer duplicata do sobrenome do compositor, como CPE Bach e JS Bach, mas colocar em ordem
o segundo nome do compositor seria interessante. Pode-se utilizar a ordena��o por inser��o, por sele��o,
 bubble sort ou outro algoritmo de ordena��o.
i. Caso n�o tenha feito isso ainda, desloque aqueles "A", "O", "Um" ou "Uma" que iniciam alguns t�tulos
para o final do t�tulo. Ent�o, dentro de cada compositor, coloque os t�tulos das composi��es em
ordem alfab�tica.
j. Guarde uma c�pia do seu projeto e c�digo. Mais tarde, pediremos para voc� fazer isso novamente utilizando
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
