# include <iostream>
# include "fila_encadeada.h"
# include <cstddef>
# include <new>


using namespace std;


    fila_encadeada::fila_encadeada() // construtor
    {
        primeiro = NULL;
        ultimo = NULL;
    }

    fila_encadeada::~fila_encadeada() // destrutor
    {
        No* aux;

        while(primeiro != NULL){
            aux = primeiro;
            primeiro = primeiro->proximo;
            delete aux;
        }

        ultimo = NULL;
    }

    bool fila_encadeada::esta_cheio() // verifica se a fila esta cheia
    {
        No* aux;
        try
        {
            aux = new No;
            delete aux;
            return false;
        }
        catch(bad_alloc exception)
        {
            return true;
        }
        
    }

    bool fila_encadeada::esta_vazio() // verifica se a fila esta vazia
    {
        return (primeiro == NULL);
    }

    void fila_encadeada::inserir(TipoItem item) // insere um novo elemento na fila
    {
        if (esta_cheio()){
            cout << "Fila esta cheia!\n";
            cout << "Não foi possivel inserir este elemento!\n";
        } else {
            No* NovoNo = new No;
            NovoNo->valor = item;
            NovoNo->proximo = NULL;

            if(primeiro == NULL){
                primeiro = NovoNo;
            } else{
                ultimo->proximo = NovoNo;
            }
            ultimo = NovoNo;
        }
    }

    TipoItem fila_encadeada::remover() // remove o primeiro elemento da fila
    {
        if (esta_vazio()){
            cout << "A fila esta vazia!\n";
            cout << "Nao possui nenhum elemento para ser removido!\n";
            return 0;
        } else {
            TipoItem item;
            No* aux = primeiro;
            item = primeiro->valor;
            primeiro = primeiro->proximo;
            delete aux;

            if (primeiro == NULL){
                ultimo = NULL;
            }

            return item;
        }
    }

    void fila_encadeada::imprimir() // imprime os elementos da fila
    {
        if (esta_vazio()){
            cout << "A fila esta vazia!\n";
        }
        No* NoAux = new No;
        cout << "Fila : [";

        for(NoAux = primeiro; NoAux != NULL; NoAux = NoAux->proximo){
            cout << NoAux->valor << ", ";
        }

        cout << "]\n";
    }
