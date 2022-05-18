# include <iostream>
# include "pilha_encadeada.h"
# include <cstddef>

using namespace std;


    pilha_encadeada::pilha_encadeada() // construtor
    {
        NoTopo = NULL;
    }

    pilha_encadeada::~pilha_encadeada() // destrutor
    {
        No* NoTemp = new No;
        while(NoTopo != NULL){
            NoTemp = NoTopo;
            NoTopo = NoTopo->proximo;
            delete NoTemp;
        }
    }

    bool pilha_encadeada::esta_cheio() // verificar se a pilha esta cheia
    {
        No* NovoNo;
        try
        {
            NovoNo = new No;
            delete NovoNo;
            return false;
        }
        catch(bad_alloc exception)
        {
            return true;
        }
        
    }

    bool pilha_encadeada::esta_vazio() // verificar se a pilha esta vazia
    {
        return (NoTopo == NULL);
    }

    void pilha_encadeada::inserir(TipoItem item) // inserir um novo elemento no topo da pilha
    {
        if (esta_cheio()){    
            cout << "Pilha esta cheia!\n";
            cout << "Não foi possivel inserir este elemento!\n";
        } else {
            No* NovoNo = new No;
            NovoNo->valor = item;
            NovoNo->proximo = NoTopo;
            NoTopo = NovoNo;
        }
    }

    TipoItem pilha_encadeada::remover() // remover um elemento do topo da pilha
    {
        TipoItem item;
        if (esta_vazio()){
            cout << "A pilha esta vazia!\n";
            cout << "Não tem elementos para remover!\n"; 
            return item;
        } else {
            No* NoTemp = new No;
            NoTemp = NoTopo;
            item = NoTopo->valor;
            NoTopo = NoTopo->proximo;
            delete NoTemp;
            return item;
        }
    }

    void pilha_encadeada::imprimir() // imprimir na tela todos os elementos que estao na pilha
    {
        No* NoAux = new No;
        cout << "Pilha : [";

        for(NoAux = NoTopo; NoAux != NULL; NoAux = NoAux->proximo){
            cout << NoAux->valor << ", ";
        }

        cout << "]\n";
    }

    int pilha_encadeada::qual_tamanho()
    {
        No* NoAux = new No;
        int quantidade = 0;

        for(NoAux = NoTopo; NoAux != NULL; NoAux = NoAux->proximo){
            quantidade++;
        }
        
        return quantidade;
    }