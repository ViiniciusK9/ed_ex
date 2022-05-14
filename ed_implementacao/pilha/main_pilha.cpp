# include <iostream>
# include "pilha.h"

using namespace std;

int main(){
    pilha pilha1;
    TipoItem item;
    int opcao;
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
            bool resp = pilha1.estavazia();
            if (resp){
                cout << "A pilha esta vazia!\n";
            } else{
                cout << "A pilha nao esta vazia!\n";
            }
            break;

        case 5:
            bool resp = pilha1.estacheia();
            if (resp){
                cout << "A pilha esta cheia!\n";
            } else{
                cout << "A pilha nao esta cheia!\n";
            }
            break;

        case 6:
            int tam = pilha1.qualtamanho();
            cout << "A pilha possui " << tam << " elementos!\n";
            break;

        default:
            break;
        }


    } while (opcao != 0);
    

    return 0;
}

// g++ main_pilha.cpp pilha.cpp -o pilha