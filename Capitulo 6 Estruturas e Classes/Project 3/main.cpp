#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*3. O tipo Point é um tipo de dados bastante simples, mas sob outro nome (a classe modelo pair) esse tipo
de dados é definido e utilizado na Standard Template Library (Biblioteca Modelo Padrão) do C++, embora
você não precise saber nada sobre a Standard Template Library para fazer este exercício. Escreva uma
definição de classe chamada Ponto que pode ser usada para armazenar e manipular a localização de um
ponto no plano. Você vai precisar declarar e implementar as seguintes funções-membros:
a. uma função-membro set que fixe os dados privados depois que um objeto dessa classe é criado.
b. uma função-membro que mova o ponto de uma certa quantidade ao longo das direções vertical e horizontal
especificadas pelo primeiro e segundo argumentos.
c. uma função-membro para girar o ponto em 90 graus no sentido horário ao redor da origem.
d. duas funções inspetoras const para recuperar as coordenadas atuais do ponto.
Documente essas funções com os comentários adequados. Insira sua classe em um programa-teste que
peça ao usuário dados para vários pontos, crie os pontos e exercite as funções-membros.*/

using namespace std;

class Ponto
{
    public:
    void setCoordenada(double x, double y);
    void moveCoordenada(double x, double y);
    void giraCoordenadaNoventaGraus();
    void printCoordenada();

    private:
    double coordenadaX_;
    double coordenadaY_;
};

void insereCoordenada(Ponto& dados);
void alteraCoordenada(Ponto& dados);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Ponto ponto;
    int op;
    insereCoordenada(ponto);
    do
    {
        cout<<endl<<"(1) Deslocar o ponto | (2) Girar o ponto 90º | (3) Mostrar coordenadas do ponto | (4) Encerrar programa"<<endl;
        cout<<"Selecione a opção desejada: ";
        cin >> op;
        switch(op)
        {
            case 1:
            alteraCoordenada(ponto);
            break;
            case 2:
            ponto.giraCoordenadaNoventaGraus();
            break;
            case 3:
            ponto.printCoordenada();
            break;
            case 4:
            break;
            default:
            cout << "Opção inválida." <<endl;
        }
    }while(op!=4);
    return 0;
}

void insereCoordenada(Ponto& dados)
{
    double x,y;
    cout<<"Digite a coordenada inicial para o ponto na coordenada X: ";
    cin >> x;
    cout<<"Digite a coordenada inicial para o ponto na coordenada Y: ";
    cin >> y;
    dados.setCoordenada(x,y);
}

void alteraCoordenada(Ponto& dados)
{
    double x,y;
    cout<<endl<<"Digite o valor para locomover o ponto na coordenada X: ";
    cin >> x;
    cout<<"Digite o valor para locomover o ponto na coordenada Y: ";
    cin >> y;
    dados.moveCoordenada(x,y);
}

void Ponto::setCoordenada(double x, double y)
{
    coordenadaX_ = x;
    coordenadaY_ = y;
}

void Ponto::moveCoordenada(double x, double y)
{
    coordenadaX_ += x;
    coordenadaY_ += y;
}

void Ponto::giraCoordenadaNoventaGraus()
{
    if(coordenadaX_>0&&coordenadaY_>0)
    {
        coordenadaY_ *= -1;
        return;
    }

    if(coordenadaX_>0&&coordenadaY_<0)
    {
        coordenadaX_ *= -1;
        return;
    }

    if(coordenadaX_<0&&coordenadaY_<0)
    {
        coordenadaY_ *= -1;
        return;
    }

    if(coordenadaX_<0&&coordenadaY_>0)
    {
        coordenadaX_ *= -1;
        return;
    }

    if((coordenadaX_==0&&coordenadaY_>0)||(coordenadaX_==0&&coordenadaY_<0))
    {
        coordenadaX_ = coordenadaY_;
        coordenadaY_ = 0;
        return;
    }

    if((coordenadaX_>0&&coordenadaY_==0)||(coordenadaX_<0&&coordenadaY_==0))
    {
        coordenadaY_ = coordenadaX_*-1;
        coordenadaX_ = 0;
        return;
    }



}

void Ponto::printCoordenada()
{
    cout<<endl<<"Coordenada atual X: "<< coordenadaX_ <<endl;
    cout<<"Coordenada atual Y: "<< coordenadaY_ <<endl;
}
