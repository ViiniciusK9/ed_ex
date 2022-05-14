# include <iostream>
# include "pilha.h"

using namespace std;


    pilha::pilha() // contrutora
    {
        tamanho = 0;
        estrutura = new TipoItem[max_itens];
    }

    pilha::~pilha() // destrutora
    {
        delete [] estrutura;
    }

    bool pilha::estacheia() // verifica se a pilha esta cheia
    {
        return (tamanho == max_itens);
    }

    bool pilha::estavazia() // verifica se a pilha esta vazia
    {
        return (tamanho == 0);
    }

    void pilha::inserir(TipoItem item) // inserir um elemento
    {
        if (estacheia()){
            cout << "A pilha esta cheia!\n";
            cout << "Não é possivel inserir este elemento!\n";
        } else{
            estrutura[tamanho] = item;
            tamanho++;
        }
    }

    TipoItem pilha::remover() // remover um elemento
    {
        if (estavazia()){
            cout << "A pilha esta vazia\n";
            cout << "Nao tem elemento para ser removido!\n";
            return 0;
        } else{
            tamanho--;
            return estrutura[tamanho];
        }
    }

    void pilha::imprimir() // imprimir os elementos da estrutura
    {
        cout << "Pilha: [ ";
        for (int i = 0; i < tamanho; i++){
            cout << estrutura[i] << " ";
        }
        cout << "]\n";
    }

    int pilha::qualtamanho() // retorna o a quantidade de elementos da estrutura
    {
        return tamanho;
    }