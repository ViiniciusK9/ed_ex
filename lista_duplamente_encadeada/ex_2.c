#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct {
    int dia;
    int mes;
    int ano;
} Data;


struct funcionario {
    int id;
    char nome[41];
    double salario;
    Data nascimento;
    struct funcionario *proximo;
    struct funcionario *anterior;
};
typedef struct funcionario Funcionario;


typedef struct {
    Funcionario *primeiro;
    Funcionario *ultimo;
} List;


Funcionario* alocar_dados_funcionario(){
    Data data_aux;
    Funcionario *novo_funcionario;
    novo_funcionario = (Funcionario*)malloc(sizeof(Funcionario));
    scanf("%d", &novo_funcionario->id);
    scanf("%s", &novo_funcionario->nome);
    scanf("%lf", &novo_funcionario->salario);
    scanf("%d/%d/%d", &novo_funcionario->nascimento.dia, &novo_funcionario->nascimento.mes, &novo_funcionario->nascimento.ano);
    novo_funcionario->proximo = NULL;
    novo_funcionario->anterior = NULL;

    return novo_funcionario;
}


void adicionar_funcionario_final(List *list){
    Funcionario *aux = alocar_dados_funcionario();

    if(list->primeiro == NULL && list->ultimo == NULL){
        list->primeiro = aux;
        list->ultimo = aux;
    }else {
        list->ultimo->proximo = aux;
        aux->anterior = list->ultimo;
        list->ultimo = aux;
    }
}


void adicionar_funcionario_inicio(List *list){
    Funcionario *aux = alocar_dados_funcionario();

    if(list->primeiro == NULL && list->ultimo == NULL){
        list->primeiro = aux;
        list->ultimo = aux;
    }else {
        list->primeiro->anterior = aux;
        aux->proximo = list->primeiro;
        list->primeiro = aux;
    }
}


void listar_funcionarios(List *list){
    Funcionario *aux;
    for(aux = list->primeiro; aux != NULL; aux = aux->proximo){
        printf("%d\n%s\n%.2lf\n%d/%d/%d\n", aux->id,aux->nome, aux->salario, aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano);
    }
}


int main(){

    List *list;

    list = malloc(sizeof(List));

    list->primeiro = NULL;
    list->ultimo = NULL;

    adicionar_funcionario_inicio(list);
    adicionar_funcionario_inicio(list);
    adicionar_funcionario_inicio(list);
    adicionar_funcionario_inicio(list);
    adicionar_funcionario_inicio(list);


    listar_funcionarios(list);



    return 0;
}
 
// gcc arquivo.c -o prog
// ./prog < arq.in > arq.out