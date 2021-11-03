#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*1. Escreva um programa de notas para uma classe com as seguintes regras:
a. Existem duas provas, cada uma com nota máxima 10.
b. Existe um exame no meio do ano e um final, cada um com nota máxima 100.
c. O exame final vale 50% da nota final, o de meio de ano vale 25% e as duas provas juntas valem um
total de 25%. (Não se esqueça de normalizar as notas das provas. Elas devem ser convertidas em uma
porcentagem antes de se fazer a média.)
Qualquer nota de 90 ou mais equivale a A; entre 80 e 90, B; entre 70 e 80, C; entre 60 e 70, D; e menos
de 60, E. O programa lerá as notas dos alunos e apresentará como saída o boletim do estudante, que
consiste nas duas provas e nos dois exames, além da média numérica de todo o curso e da letra final. Defina
 e utilize uma estrutura para o boletim do aluno.*/

 using namespace std;

 struct BoletimAluno
 {
    double prova1;
    double prova2;
    double exame1;
    double exameFinal;
    double media;
    char conceito;
 };

 void getData(BoletimAluno& dados);
 void calculaMedia(BoletimAluno& dados);
 void printBoletim(const BoletimAluno& dados);


int main()
{
    setlocale(LC_ALL, "Portuguese");
    BoletimAluno aluno;
    char op;
    do{
        getData(aluno);
        printBoletim(aluno);
        cout <<endl<< "Deseja reiniciar o programa (S/N): ";
        cin >> op;
      }while(op=='s'||op=='S');

    return 0;
}

void getData(BoletimAluno& dados)
{
    do{
        cout << "Digite a nota do aluno da primeira prova: ";
        cin >> dados.prova1;
        if(dados.prova1<0||dados.prova1>10)
            cout <<"Valor inválido."<<endl;
      }while(dados.prova1<0||dados.prova1>10);

    do{
        cout << "Digite a nota do aluno da segunda prova: ";
        cin >> dados.prova2;
        if(dados.prova2<0||dados.prova2>10)
            cout <<"Valor inválido."<<endl;
      }while(dados.prova2<0||dados.prova2>10);

    do{
        cout << "Digite a nota do aluno do primeiro exame: ";
        cin >> dados.exame1;
        if(dados.exame1<0||dados.exame1>100)
            cout <<"Valor inválido."<<endl;
      }while(dados.exame1<0||dados.exame1>100);

    do{
        cout << "Digite a nota do aluno exame final: ";
        cin >> dados.exameFinal;
        if(dados.exameFinal<0||dados.exameFinal>100)
            cout <<"Valor inválido."<<endl;
      }while(dados.exameFinal<0||dados.exameFinal>100);

      calculaMedia(dados);

}

void calculaMedia(BoletimAluno& dados)
{
    dados.media = ((dados.prova1+dados.prova2)*5+dados.exame1+dados.exameFinal*2)/4;
    if(dados.media>=90)
        dados.conceito = 'A';
    if(dados.media>=80&&dados.media<90)
        dados.conceito = 'B';
    if(dados.media>=70&&dados.media<80)
        dados.conceito = 'C';
    if(dados.media>=60&&dados.media<70)
        dados.conceito = 'D';
    if(dados.media<60)
        dados.conceito = 'E';
}

void printBoletim(const BoletimAluno& dados)
{
    cout << endl << "BOLETIM" <<endl;
    cout << "Nota da primeira prova: " << dados.prova1 << endl;
    cout << "Nota da segunda prova: " << dados.prova2 << endl;
    cout << "Nota do primeiro exame: " << dados.exame1 << endl;
    cout << "Nota do exame final: " << dados.exameFinal << endl;
    cout << "Média final: "<< dados.media <<endl;
    cout << "Conceito final: " << dados.conceito <<endl;
}

