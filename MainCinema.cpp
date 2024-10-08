#include<iostream>
#include <cstring>// Para manipulação de strings (equivalente a string.h em C).
#include <conio.h>
#include <cctype> //toupper
using namespace std;
#define tmf 7
#define tf 9
#include "ComplementosCInema.h"

int main(){
    const int qtdfilme = 3;
    struct Filme filme[qtdfilme];
    char op;
    int opsala;
    ImportaDados(filme);
    IniciarSalas(filme);
    do{
        op = MenuCinema();
        switch(op){
            case 'A':
                do{
                    opsala = MenuSala();
                    switch (opsala)
                    {
                    case 1:
                        alterarSala(0,filme);
                        break;
                    case 2:
                        alterarSala(1,filme);
                        break;
                    case 3:
                        alterarSala(2,filme);
                        break;
                    default:
                        cout << endl << "Selecione uma Opcap Valida!" << endl;
                        cout << "Pressione qualquer tecla para continuar";
                        getch();
                        break;
                    }
                }while(opsala != 0);
                break;
            case 'B':
                    do{
                    opsala = MenuSala();
                    switch (opsala)
                    {
                    case 1:
                        ConferirSala(0,filme);
                        break;
                    case 2:
                        ConferirSala(1,filme);
                        break;
                    case 3:
                        ConferirSala(2,filme);
                        break;
                    default:
                        cout << endl << "Selecione uma Opcap Valida!" << endl;
                        cout << "Pressione qualquer tecla para continuar";
                        getch();
                        break;
                    }
                }while(opsala != 0);
                break;
            case 'E':
                Exibir(filme);//Exibi Dados de todos os filmes disponiveis
                cout << endl << endl << "Pressione qualquer tecla para continuar";
                getch();
                break;
            case 'V':
                do{
                    system("cls");
                    cout << "[1] - "<< filme[0].nomeFilme << "\n[2] - "<< filme[1].nomeFilme <<"\n[3] - "<<filme[0].nomeFilme<<
                    "[0] - SAIR" << endl ;
                    cout << "Digite o Numero do filme, para comprar ingresso: ";
                    cin >> opsala;
                    switch (opsala)
                    {
                    case 1:
                        ComprarIngresso(0,filme);
                        break;
                    case 2:
                        ComprarIngresso(1,filme);
                        break;
                    case 3:
                        ComprarIngresso(2,filme);
                        break;
                    case 0:
                        break;
                    default:
                        cout << endl << "Selecione uma Opcap Valida!" << endl;
                        cout << "Pressione qualquer tecla para continuar";
                        getch();
                        break;
                    }
                }while(opsala != 0);;
                break;
            case 'X':
                ExibirCaixa(filme);
                cout << endl <<"Pressione qualquer tecla para continuar";
                getch();
                break;
            default:
               cout << endl << "Selecione uma Opcao Valida!!" << endl;
               getch();
        }



    }while(op != 27);

}






