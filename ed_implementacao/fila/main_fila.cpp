# include <iostream>
# include "fila.h"

using namespace std;

int main(){
    fila fila1;
    int opcao;
    TipoItem item;

    cout << "Programa gerador de filas:\n";

    do
    {
        cout << "Digite 0 para parar o programa!\n";
        cout << "Digite 1 para inserir um elemento!\n";
        cout << "Digite 2 para remover um elemento!\n";
        cout << "Digite 3 para imprimir os elementos da fila!\n";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Digite o elemento a ser inserido na fila: ";
            cin >> item;
            fila1.inserir(item);
            break;

        case 2:
            item = fila1.remover();
            cout << "O elemento removido é: " << item << '\n';
            break;

        case 3:
            fila1.imprimir();
            break;
        
        default:
            cout << "Opcao invalida, tente novamente!\n";
            break;
        }

    } while (opcao != 0);
    



    return 0;
}

// g++ main_fila.cpp fila.cpp -o fila.exe