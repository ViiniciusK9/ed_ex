# include <iostream>
# include "pilha_encadeada.h"

using namespace std;

int main(){
    pilha_encadeada pilha1;
    TipoItem item;
    int opcao, tam;
    bool resp;
    cout << "Programa gerador de pilhas:\n";

    do
    {
        cout << "Digite 0 para parar o programa!\n";
        cout << "Digite 1 para inserir um elemento!\n";
        cout << "Digite 2 para remover um elemento!\n";
        cout << "Digite 3 para imprimir a pilha!\n";
        cout << "Digite 4 para verificar se a pilha esta vazia!\n";
        cout << "Digite 5 para verificar se a pilha esta cheia!\n";
        cout << "Digite 6 para verificar o tamanho da pilha!\n";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Digite o elemento a ser inserido: ";
            cin >> item;
            pilha1.inserir(item);
            break;
        
        case 2:
            item = pilha1.remover();
            cout << "Elemento Removido: " << item << '\n';
            break;

        case 3:
            pilha1.imprimir();
            break;

        case 4:
            resp = pilha1.esta_vazio();
            if (resp){
                cout << "A pilha esta vazia!\n";
            } else{
                cout << "A pilha nao esta vazia!\n";
            }
            break;

        case 5:
            resp = pilha1.esta_cheio();
            if (resp){
                cout << "A pilha esta cheia!\n";
            } else{
                cout << "A pilha nao esta cheia!\n";
            }
            break;

        case 6:
            tam = pilha1.qual_tamanho();
            cout << "A pilha possui " << tam << " elementos!\n";
            break;

        default:
            break;
        }


    } while (opcao != 0);
    

    return 0;
}

// g++ main_pilha.cpp pilha.cpp -o pilha