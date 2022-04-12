#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct {
    int dia;
    int mes;
    int ano;
} Data;


struct matricula{
    char matricula[15];
    char nome[50];
    Data nascimento;
    float nota;
    struct matricula *prox;
    struct matricula *ant;
};
typedef struct matricula Matricula;


typedef struct {
    Matricula *primeiro;
    Matricula *ultimo;
} List;


Matricula *alocar_dados_matricula(){
    char nome_aux[50];
    Matricula *nova_matricula = (Matricula*)malloc(sizeof(Matricula));
    scanf("%s", &nova_matricula->matricula);
    scanf("%s", &nova_matricula->nome);
    scanf("%d/%d/%d", &nova_matricula->nascimento.dia, &nova_matricula->nascimento.mes, &nova_matricula->nascimento.ano);
    scanf("%f", &nova_matricula->nota);
    nova_matricula->prox = NULL;
    nova_matricula->ant = NULL;

    return nova_matricula;
}


void inserir_matricula(List *list, char matricula[15]){
    Matricula *aux = alocar_dados_matricula();
    Matricula *aux_loop;
    int inseriu = 0;

    if(list->primeiro == NULL && list->ultimo == NULL){
        list->primeiro = aux;
        list->ultimo = aux;
    }else{
        for(aux_loop = list->primeiro; aux_loop != NULL; aux_loop = aux_loop->prox){
            if(strcmp(aux_loop->matricula, matricula) == 0){
                inseriu = 1;
                if(list->ultimo == aux_loop){
                    aux_loop->prox = aux;
                    aux->ant = aux_loop;
                    list->ultimo = aux;
                    break;
                }else {
                    aux_loop->prox->ant = aux;
                    aux->prox = aux_loop->prox;
                    aux->ant = aux_loop;
                    aux_loop->prox = aux;
                    break;
                }
            }
        }
        if(!inseriu){
            list->primeiro->ant = aux;
            aux->prox = list->primeiro;
            list->primeiro = aux;
        }
    }
}


void excluir_elemento(List *list, char matricula[15]){
    if(list->primeiro == NULL){
        printf("Lista Vazia!\n");
    }else{
        Matricula *aux;
        for(aux = list->primeiro; aux != NULL; aux = aux->prox){
            if(strcmp(aux->matricula, matricula) == 0){ 
                if (aux == list->primeiro && aux == list->ultimo){
                    list->primeiro == NULL;
                    list->ultimo == NULL;
                }else if(aux == list->primeiro){
                    aux->prox->ant = NULL;
                    list->primeiro = aux->prox;
                }else if (aux == list->ultimo){
                    aux->ant->prox = NULL;
                    list->ultimo = aux->ant;
                }else {
                    aux->ant->prox = aux->prox;
                    aux->prox->ant = aux->ant;
                }
                free(aux);
            }
        }
    }
}


void listar_a_partir_primeiro(List *list){
    Matricula *aux_loop = list->primeiro;
    if(aux_loop == NULL){
        printf("Lista Vazia!\n");
    } else {
        for(aux_loop = list->primeiro; aux_loop != NULL; aux_loop = aux_loop->prox){
            printf("%s, %s, %d/%d/%d, %.2f\n", aux_loop->matricula, aux_loop->nome, aux_loop->nascimento.dia, aux_loop->nascimento.mes, aux_loop->nascimento.ano, aux_loop->nota);
        }
    }
    
}


void listar_a_partir_ultimo(List *list){
    Matricula *aux_loop = list->ultimo;
    if(aux_loop == NULL){
        printf("Lista Vazia!\n");
    }else {
        for(aux_loop = list->ultimo; aux_loop != NULL; aux_loop = aux_loop->ant){
            printf("%s, %s, %d/%d/%d, %.2f\n", aux_loop->matricula, aux_loop->nome, aux_loop->nascimento.dia, aux_loop->nascimento.mes, aux_loop->nascimento.ano, aux_loop->nota);
        }
    }
    
}


void sair_do_programa(List *list){
    Matricula *aux = list->primeiro;
    Matricula *anterior;
    while(aux != NULL){
        anterior = aux;
        aux = aux->prox;
        free(anterior);
        printf("*");
    }
    printf("\n");
}


int main(){
    int op;
    char mat_aux[15];

    List *list = malloc(sizeof(List));
    list->primeiro = NULL;
    list->ultimo = NULL;
    

    do{
        scanf("%d", &op);
        switch (op)
        {
            case 1 :
                scanf("%s", &mat_aux);
                inserir_matricula(list, mat_aux);
                break;
            case 2 :
                scanf("%s", &mat_aux);
                excluir_elemento(list, mat_aux);
                break;
            case 3 :
                listar_a_partir_primeiro(list);
                break;
            case 4 :
                listar_a_partir_ultimo(list);
                break;
            case 0 :
                sair_do_programa(list);
                break;
        }

    }while(op != 0);

    return 0;
}


// gcc 21500058_lista.c -o prog
// prog.exe < input > output