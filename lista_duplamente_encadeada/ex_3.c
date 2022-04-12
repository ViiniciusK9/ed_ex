#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct numero {
    int num;
    struct numero *proximo;
    struct numero *anterior;
};
typedef struct numero Numero;


typedef struct {
    Numero *primeiro;
    Numero *ultimo;
} ListaInt;


Numero* alocar_numero(int num){
    Numero *novo_numero = (Numero*)malloc(sizeof(Numero)); 
    novo_numero->num = num;
    return novo_numero;
}


void adicionar_final(ListaInt *list, int num){
    Numero *aux = alocar_numero(num);

    if(list->primeiro == NULL && list->ultimo == NULL){
        list->primeiro = aux;
        list->ultimo = aux;
    }else {
        list->ultimo->proximo = aux;
        aux->anterior = list->ultimo;
        list->ultimo = aux;
    }
}


ListaInt* constroiLista(int n, int *v){
    ListaInt *list;
    list = malloc(sizeof(ListaInt));
    list->primeiro = NULL;
    list->ultimo = NULL;
    for(int i = 0; i < n; i++){
        adicionar_final(list, v[i]);
    }
    return list;
}


void mostrar_lista(ListaInt *list){
    Numero *aux;
    for(aux = list->primeiro; aux != NULL; aux=aux->proximo){
        printf("%d ", aux->num);
    }
    printf("\n");
}


int main(){
    
    int vet[4] = {1, 21, 4, 6};
    int tam_vet = sizeof(vet)/sizeof(int);

    ListaInt *list = constroiLista(tam_vet, vet); 
    mostrar_lista(list); 
    return 0;
}