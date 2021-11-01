#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <windows.h>

/*9. O matem�tico John Horton Conway inventou o "Jogo da Vida". Embora n�o seja um "jogo" no sentido
tradicional, ele apresenta um comportamento interessante, especificado com poucas regras. Esse projeto
pede que voc� escreva um programa que lhe permita especificar uma configura��o inicial. O programa segue
 as regras da Vida (listadas brevemente) para mostrar o comportamento cont�nuo da configura��o.
VIDA � um organismo que vive em um mundo distinto, bidimensional. Embora esse mundo seja, na realidade,
ilimitado, n�o temos toda essa liberdade e, assim, restringimos o vetor a 80 caracteres de largura e
22 de altura. Se voc� tem acesso a uma tela maior, use-a!
Esse mundo � um vetor em que cada c�lula � capaz de abrigar uma c�lula da VIDA. As gera��es marcam
a passagem do tempo. Cada gera��o traz nascimentos e mortes para a comunidade da VIDA. Os nascimentos e mortes
seguem o conjunto de regras:
1. Cada c�lula possui oito c�lulas vizinhas. As vizinhas de uma c�lula s�o as c�lulas diretamente acima,
abaixo, � direita, � esquerda, diagonalmente acima � direita ou � esquerda e diagonalmente abaixo � direita ou � esquerda.
2. Se uma c�lula ocupada n�o possui vizinhas ou possui apenas uma, morre de solid�o. Se uma c�lula
ocupada possui mais de tr�s vizinhas, morre de superpopula��o.
3. Se uma c�lula vazia possui exatamente tr�s c�lulas vizinhas ocupadas, h� o nascimento de uma nova c�lula para
 substituir a c�lula vazia.
4. Nascimentos e mortes s�o instant�neos e ocorrem com as mudan�as de gera��o. Uma c�lula que morre
por qualquer raz�o pode ajudar a provocar o nascimento, mas uma c�lula rec�m-nascida n�o pode ressuscitar uma c�lula
que est� morrendo, nem a morte de uma c�lula impede a morte de outra, digamos,
por meio da redu��o da popula��o local.
 *
Exemplos: *** vira * depois vira *** de novo e assim por diante.
 *
Observa��es: algumas configura��es crescem a partir de configura��es iniciais bem pequenas. Outras se deslocam
pela regi�o. Recomenda-se que, para a sa�da de texto, voc� utilize um vetor retangular de char com
80 colunas e 22 linhas para armazenar as sucessivas gera��es mundiais de VIDA. Utilize um * para indicar
uma c�lula viva e um espa�o em branco para indicar uma c�lula vazia (ou morta). Se voc� possui uma
tela com mais linhas do que isso, n�o hesite em utilizar a tela toda.
Sugest�es: procure configura��es est�veis. Ou seja, procure por comunidades que repitam os padr�es continuamente.
O n�mero de configura��es na repeti��o � chamado de per�odo. H� configura��es que s�o fixas, ou seja, que permanecem
 sem mudan�a. Um plano poss�vel � encontrar essas configura��es.
Dicas: defina uma fun��o void chamada gera��o que tome o vetor que chamamos mundo, um vetor de
tipo char de 80 colunas por 22 linhas, que contenha a configura��o inicial. A fun��o percorre o vetor e
modifica as c�lulas, assinalando as c�lulas com nascimentos e mortes de acordo com as regras listadas anteriormente.
 Isso envolve examinar uma c�lula de cada vez e ou matar a c�lula, ou deix�-la viver ou, se a
c�lula estiver vazia, decidir se uma c�lula deve nascer. Deve haver uma fun��o mostra que aceite o vetor
mundo e exiba o vetor na tela. � preciso haver alguma esp�cie de intervalo de tempo entre as chamadas a
gera��o e a mostra. Para fazer isso, seu programa deve gerar e mostrar a pr�xima gera��o quando se aperta a tecla Return.
 Voc� � livre para automatizar isso, mas a automa��o n�o � necess�ria para o programa.*/

using namespace std;

void verifica(char matriz[22][80]);
void imprime(char matriz[22][80]);


int main()
{
    char matriz[22][80];
    int i, j, ciclos = 30, op;
    for(i=0;i<22;i++)
	{
	   for(j=0;j<80;j++)
	   {
		   matriz[i][j]= ' ';
	   }
	}
    cout<<"/t======== JOGO DA VIDA ========"<<endl
	<< "O programa simula o Jogo da Vida inventado pelo matematico John Horton Conway."<<endl
	<< "Foram implementadas duas matrizes pre-definidas baseadas nos dois primeiros exemplos do video https://www.youtube.com/watch?v=23MBR2pZoDQ  disponibilizado na Lista de Exercicios."<<endl
	<< "Selecione a matriz desejada para simulacao:"<<endl<<"(1) Exemplo 1  | (2) Exemplo 2"<<endl;
    cin>>op;
    if(op==1)
    {
        matriz[10][40] = '*';
        matriz[11][41] = '*';
        matriz[12][39] = '*';
        matriz[12][40] = '*';
        matriz[12][41] = '*';
    }
    if(op==2)
    {
    matriz[10][40] = '*';
	matriz[11][39] = '*';
	matriz[11][40] = '*';
	matriz[11][41] = '*';
	matriz[12][39] = '*';
	matriz[12][41] = '*';
	matriz[13][40] = '*';
    }
    if(op!=1&&op!=2)
    {
        cout<<"Opcao Invalida!!!";
        return 0;
    }
    for(i=0; i<ciclos; i++)
    {
        imprime(matriz);
        verifica(matriz);
    }
    return 0;
}

void verifica(char matriz[22][80])
{
    int i,j, aux;

    char matrizaux[22][80];

    for(i=0;i<22;i++)
    {
        for(j=0; j<80; j++)
        {
            matrizaux[i][j] = matriz[i][j];
        }
    }


    for(i=0;i<22;i++)
	{
	   for(j=0;j<80;j++)
	   {
	       aux = 0;

	       if(matrizaux[i][j]=='*')
           {
                if(i==0&&j==0)
                {
                    if((matrizaux[i][j+1]==' ')&&(matrizaux[i+1][j+1]==' ')&&(matrizaux[i+1][j+2]==' '))
                    {
                        aux=0;
                    }
                    if((matrizaux[i][j+1]=='*')&&(matrizaux[i+1][j+1]=='*')&&(matrizaux[i+1][j+2]=='*'))
                    {
                        aux=0;
                    }

                }

                if(i==0&&j==79)
                {
                    if((matrizaux[i][j-1]==' ')&&(matrizaux[i+1][j-1]==' ')&&(matrizaux[i+1][j]==' '))
                    {
                        aux=0;
                    }
                    if((matrizaux[i][j-1]=='*')&&(matrizaux[i+1][j-1]=='*')&&(matrizaux[i+1][j]=='*'))
                    {
                        aux=0;
                    }
                }

                if(i==21&&j==0)
                {
                    if((matrizaux[i-1][j]==' ')&&(matrizaux[i-1][j+1]==' ')&&(matrizaux[i][j+1]==' '))
                    {
                        aux=0;
                    }
                    if((matrizaux[i-1][j]=='*')&&(matrizaux[i-1][j+1]=='*')&&(matrizaux[i][j+1]=='*'))
                    {
                        aux=0;
                    }
                }

                if(i==21&&j==79)
                {
                    if((matrizaux[i-1][j-1]==' ')&&(matrizaux[i-1][j]==' ')&&(matrizaux[i][j-1]=' '))
                    {
                        aux=0;
                    }
                    if((matrizaux[i-1][j-1]=='*')&&(matrizaux[i-1][j]=='*')&&(matrizaux[i][j-1]='*'))
                    {
                        aux=0;
                    }
                }

                if(i==0&&j!=0&&j!=79)
                {
                   if(matrizaux[i][j-1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i][j+1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i+1][j-1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i+1][j]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i+1][j+1]=='*')
                   {
                       aux++;
                   }
                }

                if(i==21&&j!=0&&j!=79)
                {
                   if(matrizaux[i][j-1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i][j+1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i-1][j-1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i-1][j]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i-1][j+1]=='*')
                   {
                       aux++;
                   }
                }

                if(i!=0&&i!=21&&j==0)
                {
                   if(matrizaux[i-1][j]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i-1][j+1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i][j+1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i+1][j+1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i+1][j+2]=='*')
                   {
                       aux++;
                   }
                }

                if(i!=0&&i!=21&&j==79)
                {
                   if(matrizaux[i-1][j]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i-1][j-1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i][j-1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i+1][j-2]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i+1][j-1]=='*')
                   {
                       aux++;
                   }
                }

                if((i!=0)&&(i!=22)&&(j!=0)&&(j!=79))
                {
                    if(matrizaux[i-1][j-1]=='*')
                    {
                        aux++;
                    }
                    if(matrizaux[i-1][j]=='*')
                    {
                        aux++;
                    }
                    if(matrizaux[i-1][j+1]=='*')
                    {
                        aux++;
                    }
                    if(matrizaux[i][j-1]=='*')
                    {
                        aux++;
                    }
                    if(matrizaux[i][j+1]=='*')
                    {
                        aux++;
                    }
                    if(matrizaux[i+1][j-1]=='*')
                    {
                        aux++;
                    }
                    if(matrizaux[i+1][j]=='*')
                    {
                        aux++;
                    }
                    if(matrizaux[i+1][j+1]=='*')
                    {
                        aux++;
                    }
                }


                if(aux<=1||aux>3)
                {
                    matriz[i][j]=' ';
                }


           }


            if(matrizaux[i][j]==' ')
            {

                if(i==0&&j==0)
                {
                    if((matrizaux[i][j+1]=='*')&&(matrizaux[i+1][j+1]=='*')&&(matrizaux[i+1][j+2]=='*'))
                    {
                        aux = 3;
                    }

                }

                if(i==0&&j==79)
                {
                    if((matrizaux[i][j-1]=='*')&&(matrizaux[i+1][j-1]=='*')&&(matrizaux[i+1][j]=='*'))
                    {
                        aux = 3;
                    }
                }

                if(i==21&&j==0)
                {
                    if((matrizaux[i-1][j]=='*')&&(matrizaux[i-1][j+1]=='*')&&(matrizaux[i][j+1]=='*'))
                    {
                        aux = 3;
                    }

                }

                if(i==21&&j==79)
                {
                    if((matrizaux[i-1][j-1]=='*')&&(matrizaux[i-1][j]=='*')&&(matrizaux[i][j-1]='*'))
                    {
                       aux = 3;
                    }
                }

                if(i==0&&j!=0&&j!=79)
                {
                   if(matrizaux[i][j-1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i][j+1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i+1][j-1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i+1][j]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i+1][j+1]=='*')
                   {
                       aux++;
                   }
                }

                if(i==21&&j!=0&&j!=79)
                {
                   if(matrizaux[i][j-1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i][j+1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i-1][j-1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i-1][j]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i-1][j+1]=='*')
                   {
                       aux++;
                   }
                }

                if(i!=0&&i!=21&&j==0)
                {
                   if(matrizaux[i-1][j]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i-1][j+1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i][j+1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i+1][j+1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i+1][j+2]=='*')
                   {
                       aux++;
                   }
                }

                if(i!=0&&i!=21&&j==79)
                {
                   if(matrizaux[i-1][j]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i-1][j-1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i][j-1]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i+1][j-2]=='*')
                   {
                       aux++;
                   }
                   if(matrizaux[i+1][j-1]=='*')
                   {
                       aux++;
                   }
                }

                if((i!=0)&&(i!=22)&&(j!=0)&&(j!=79))
                {
                    if(matrizaux[i-1][j-1]=='*')
                    {
                        aux++;
                    }
                    if(matrizaux[i-1][j]=='*')
                    {
                        aux++;
                    }
                    if(matrizaux[i-1][j+1]=='*')
                    {
                        aux++;
                    }
                    if(matrizaux[i][j-1]=='*')
                    {
                        aux++;
                    }
                    if(matrizaux[i][j+1]=='*')
                    {
                        aux++;
                    }
                    if(matrizaux[i+1][j-1]=='*')
                    {
                        aux++;
                    }
                    if(matrizaux[i+1][j]=='*')
                    {
                        aux++;
                    }
                    if(matrizaux[i+1][j+1]=='*')
                    {
                        aux++;
                    }
                }


                if(aux==3)
                {
                    matriz[i][j] = '*';
                }

           }

	   }
    }

}

void imprime(char matriz[22][80])
{
    int i, j;

    system("cls");

     for(i=0;i<22;i++)
	{
	   for(j=0;j<80;j++)
	   {
		   cout<<matriz[i][j];
	   }
		cout<<endl;
	}

	Sleep(100);

}
