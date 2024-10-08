#ifndef COMPLEMENTOSCINEMA_H
#define COMPLEMENTOSCINEMA_H
#include <cctype>

struct Filme{
    string nomeFilme;
    float valorBilhete;
    string data; //dd/mm/aaaa
    int sala[tmf][tf];
    float valorganhodevendasf;

};
char MenuCinema(void){
    system("cls");
    char op1;
    cout << "[A] - Ajustar Filme" << endl << "[B] - Consultar Lugar Livre" <<
     endl << "[E] - Exibir Filmes do Momento" <<endl<<"[V] - Vender Ingresso" << endl << "[X] - Exibir Caixa " <<endl;
    cout << "Selecione uma Opcao: ";
    cin >> op1;
    op1 = toupper(op1);
    return op1;
}

int MenuSala(void){
    system("cls");
    int slct;
    cout << "[1] - Sala 1" << endl << "[2] - Sala 2" << endl  << "[3] - Sala 3" << endl << "[0] - Sair"<< endl;
    cin >> slct;
    return slct;
}
int MenuAlteracao(void){
    system("cls");
    int slct;
    cout << "[1] - Alterar Nome Filme" << endl << "[2] - Alterar Valor Bilhete" << endl  << "[3] - Alterar Data Filme " << endl << "[0] - Sair"<< endl;
    cin >> slct;
    return slct;
}
void alterarSala(int numero, Filme *filme){
    int op;
    string temp;float valor;
    do{
        op = MenuAlteracao();
        switch (op)
        {
        case 1: 
            cout << "Nome atual: "<< filme[numero].nomeFilme << " Digite o novo nome do Filme" << endl;
            cin >> temp;
            filme[numero].nomeFilme = temp;
            cout  << "Nome Alterado com Sucesso para " << temp;
            break;
        case 2:
            cout << "Valor atual: "<< filme[numero].valorBilhete << " Digite o novo valor do Bilhete" << endl;
            cin >> valor;
            if(valor > 0){
                cout  << "Valor Alterado com Sucesso de R$ " << filme[numero].valorBilhete << " para R$ " << valor <<endl;
                filme[numero].valorBilhete = valor;
            }else
                cout << "Valor digitado invalido!"<< endl;
            break;
        case 3:
            cout << "Data atual: " << filme[numero].data <<" Digite uma Data nova no formato DD/MM/AAAA" << endl; 
            cin >> temp;
            filme[numero].data = temp;
            cout << "Data Alterado com Sucesso para " << temp ;
            break;
        case 0:
            break;
        default:
            cout << "Selecione uma Opcao Valida "<< endl;
            break;
        }
    }while(op != 0);
    
}

void ImportaDados(Filme* f){
   
    f[0].nomeFilme = "Velozes e Furiosos 13";
    f[0].valorBilhete = 19.50;
    f[0].data = "25/12/2024";
    f[0].valorganhodevendasf = 0;
    f[1].nomeFilme = "Minecraft o Filme";
    f[1].valorBilhete = 9.50;
    f[1].data = "25/12/2024";
    f[1].valorganhodevendasf = 0;
    f[2].nomeFilme = "Bem 10 Super Dragons 3D";
    f[2].valorBilhete = 29.50;
    f[2].data = "25/12/2024";
    f[2].valorganhodevendasf = 0;
   
}
void Exibir(Filme* fil){
    system("cls");
    for(int i = 0; i<3 ; i++){
        cout << "Nome: " << fil[i].nomeFilme << "\nValor bilhete: R$ " << fil[i].valorBilhete << "\nData: " << fil[i].data << endl << endl;
    }
    cout << endl;
}
void ComprarIngresso(int num, Filme* f){
    system("cls");
    int cont = 0,slc;
    cout << "Filme: " << f[num].nomeFilme << " | Cadeiras marcadas com 0 significa que ja foram a venda" << endl<<endl ;   
        for(int  i=0; i < 7 ; i ++){
            cout << "\t";
            for(int c=0; c < 9 ; c++){
                if(f[num].sala[i][c] == 0)
                    cont++;
                cout << f[num].sala[i][c] << "\t" ;
            }
            cout << endl;
        }
        cout <<endl <<endl << endl << "\t\t\t   [TELA DO FILME AQUI]"<<endl<<endl;
        if(cont == 63)
            cout << "Todas as poltronas ja foram a venda para esse Filme no dia de Hoje!" << endl;
        else{
            cout << "Digite o numero da Poltrona que deja comprar: ";
            cin >> slc;
            for(int  i=0; i < 7 ; i ++){
                for(int c=0; c < 9 ; c++){
                    if(f[num].sala[i][c] == slc){
                        cout << "Deseja reservar essa poltrona? Valor: "<<f[num].valorBilhete<<" [1] - SIM  [2] - NAO" <<endl;
                        cin >> slc;
                        if(slc == 1)
                        {
                            cout << "Poltrona reservada com Sucesso!" << endl;
                            f[num].sala[i][c] = 0;
                            f[num].valorganhodevendasf += f[num].valorBilhete;
                        }else{
                            cout << "Venda cancelada!!" << endl;
                        }
                    }
                }
            }
            
        }
        cout << "Pressione qualquer tecla para continuar";
        getch();
}

void IniciarSalas(Filme* f){
    for(int v = 0; v < 3; v++){
        int cont = 1;
        for(int  i=0; i < 7 ; i ++){
            for(int c=0; c < 9 ; c++){
                f[v].sala[i][c] = cont ++;
            }
        }
    }
}

void ConferirSala(int num, Filme* f){
    system("cls");
        cout << "Filme: " << f[num].nomeFilme << " | Cadeiras marcadas com 0 significa que ja foram a venda" << endl<<endl ;    
        for(int  i=0; i < 7 ; i ++){
            cout << "\t";
            for(int c=0; c < 9 ; c++){
                cout << f[num].sala[i][c] << "\t" ;
            }
            cout << endl;
        }
        cout << "Pressione qualquer tecla para continuar...";
        getch();
}
void ExibirCaixa(Filme* f){
    system("cls");
    cout << "Filme: " << f[0].nomeFilme << "\nValor ganho de vendas: R$ " <<f[0].valorganhodevendasf <<endl<<endl;
    cout << "Filme: " << f[1].nomeFilme << "\nValor ganho de vendas: R$ " <<f[1].valorganhodevendasf <<endl<<endl;
    cout << "Filme: " << f[2].nomeFilme << "\nValor ganho de vendas: R$ " <<f[2].valorganhodevendasf <<endl<<endl;
    cout << "Valor total: R$ " << f[0].valorganhodevendasf + f[1].valorganhodevendasf + f[2].valorganhodevendasf;
    cout << endl <<"Pressione qualquer tecla para continuar...";
    getch();

}
#endif 