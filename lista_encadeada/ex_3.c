/*
    Implemente uma função que receba um vetor de valores inteiros com N
    elementos e construa uma lista encadeada armazenando os elementos do
    vetor (elemento a elemento). Assim, se for recebido por parâmetro o vetor
    v[4] = {1,21,4,6} a função deve retornar uma lista encadeada onde o primeiro
    elemento é ‘1’, o segundo o ‘21’, o terceiro o ‘4’ e assim por diante. A função
    deve ter a seguinte assinatura: ListaInt *constroiLista (int n, int *v);
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct listaInt ListaInt;

struct listaInt{
    int num;
    struct listaInt *prox;
};



ListaInt* alocar_elemento(){
    ListaInt *elemento_alocado = (ListaInt*)malloc(sizeof(ListaInt));
    return elemento_alocado;
}


ListaInt* inserir_elemento_fim(ListaInt* Lista, int num){
    ListaInt *novo_elemento = alocar_elemento();
    novo_elemento->num = num;
    novo_elemento->prox = NULL;

    if(Lista == NULL){
        Lista = novo_elemento;
    }else {
        ListaInt *aux = Lista;

        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo_elemento;
    }
    return Lista;
}


ListaInt* constroi_lista(int n, int *v){
    ListaInt *Lista = NULL;
    int i;
    for(i = 0; i < n; i++){
        Lista = inserir_elemento_fim(Lista, v[i]);
    }
    return Lista;
}


void imprimir_lista(ListaInt* Lista){
    ListaInt *aux = Lista;
    while(aux != NULL){
        printf("%d ", aux->num);
        aux = aux->prox;
    }
}

int main(){
    ListaInt *Lista = NULL;
    int tam;
    int v[4] = {1,21,4,6};
    tam = sizeof(v)/sizeof(int);


    Lista = constroi_lista(tam, v);
    imprimir_lista(Lista);
    return 0;
}