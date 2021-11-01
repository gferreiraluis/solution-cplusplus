#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <windows.h>

/*9. O matemático John Horton Conway inventou o "Jogo da Vida". Embora não seja um "jogo" no sentido
tradicional, ele apresenta um comportamento interessante, especificado com poucas regras. Esse projeto
pede que você escreva um programa que lhe permita especificar uma configuração inicial. O programa segue
 as regras da Vida (listadas brevemente) para mostrar o comportamento contínuo da configuração.
VIDA é um organismo que vive em um mundo distinto, bidimensional. Embora esse mundo seja, na realidade,
ilimitado, não temos toda essa liberdade e, assim, restringimos o vetor a 80 caracteres de largura e
22 de altura. Se você tem acesso a uma tela maior, use-a!
Esse mundo é um vetor em que cada célula é capaz de abrigar uma célula da VIDA. As gerações marcam
a passagem do tempo. Cada geração traz nascimentos e mortes para a comunidade da VIDA. Os nascimentos e mortes
seguem o conjunto de regras:
1. Cada célula possui oito células vizinhas. As vizinhas de uma célula são as células diretamente acima,
abaixo, à direita, à esquerda, diagonalmente acima à direita ou à esquerda e diagonalmente abaixo à direita ou à esquerda.
2. Se uma célula ocupada não possui vizinhas ou possui apenas uma, morre de solidão. Se uma célula
ocupada possui mais de três vizinhas, morre de superpopulação.
3. Se uma célula vazia possui exatamente três células vizinhas ocupadas, há o nascimento de uma nova célula para
 substituir a célula vazia.
4. Nascimentos e mortes são instantâneos e ocorrem com as mudanças de geração. Uma célula que morre
por qualquer razão pode ajudar a provocar o nascimento, mas uma célula recém-nascida não pode ressuscitar uma célula
que está morrendo, nem a morte de uma célula impede a morte de outra, digamos,
por meio da redução da população local.
 *
Exemplos: *** vira * depois vira *** de novo e assim por diante.
 *
Observações: algumas configurações crescem a partir de configurações iniciais bem pequenas. Outras se deslocam
pela região. Recomenda-se que, para a saída de texto, você utilize um vetor retangular de char com
80 colunas e 22 linhas para armazenar as sucessivas gerações mundiais de VIDA. Utilize um * para indicar
uma célula viva e um espaço em branco para indicar uma célula vazia (ou morta). Se você possui uma
tela com mais linhas do que isso, não hesite em utilizar a tela toda.
Sugestões: procure configurações estáveis. Ou seja, procure por comunidades que repitam os padrões continuamente.
O número de configurações na repetição é chamado de período. Há configurações que são fixas, ou seja, que permanecem
 sem mudança. Um plano possível é encontrar essas configurações.
Dicas: defina uma função void chamada geração que tome o vetor que chamamos mundo, um vetor de
tipo char de 80 colunas por 22 linhas, que contenha a configuração inicial. A função percorre o vetor e
modifica as células, assinalando as células com nascimentos e mortes de acordo com as regras listadas anteriormente.
 Isso envolve examinar uma célula de cada vez e ou matar a célula, ou deixá-la viver ou, se a
célula estiver vazia, decidir se uma célula deve nascer. Deve haver uma função mostra que aceite o vetor
mundo e exiba o vetor na tela. É preciso haver alguma espécie de intervalo de tempo entre as chamadas a
geração e a mostra. Para fazer isso, seu programa deve gerar e mostrar a próxima geração quando se aperta a tecla Return.
 Você é livre para automatizar isso, mas a automação não é necessária para o programa.*/

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
