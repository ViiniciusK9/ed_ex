#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include<conio.h>


typedef struct {
    int dia;
    int mes;
    int ano;
} Data;


struct funcionario{
    int id;
    char nome[41];
    double salario;
    Data nascimento;
    struct funcionario *prox;
};
typedef struct funcionario Funcionario;


Funcionario* alocar_funcionario(){
    Funcionario *novo = (Funcionario*)malloc(sizeof(Funcionario));
    return novo;
}


Funcionario* inserir_no_inicio(Funcionario* Lista, int id, char nome[41], double salario, Data nascimento){
    Funcionario *novo_elemento = alocar_funcionario();
    novo_elemento->id = id;
    strcpy(novo_elemento->nome, nome);
    novo_elemento->salario = salario;
    novo_elemento->nascimento = nascimento;

    if(Lista == NULL){
        Lista = novo_elemento;
        novo_elemento->prox = NULL;
    }else {
        novo_elemento->prox = Lista;
        Lista = novo_elemento;
    }
    return Lista;
}


void imprimir_lista(Funcionario* Lista){
    Funcionario *aux = Lista;
    while(aux != NULL){
        printf("%d \n", aux->id);
        printf("%s \n", aux->nome);
        printf("%.2lf \n", aux->salario);
        printf("%d/%d/%d \n", aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano);
        aux = aux->prox; 
    }
}

void deletar_elemento(Funcionario* Lista, int id){
    Funcionario *aux, *anterior;
    for(aux = Lista; aux != NULL; aux = aux->prox){
        if(id == aux->id){
            if(Lista == aux){
                Lista = Lista->prox;
            }else {
                anterior->prox = aux->prox;
            }
            free(aux);
            break;
        }
        anterior = aux;
    }
}


int main(){
    int n, id, i = 0;
    double salario;
    char nome[41];
    Data data;
    
    Funcionario *Lista = NULL;

    //printf("Quantidade de registros: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        //printf("id: ");
        scanf("%d", &id);
        //printf("nome: ");
        scanf("%s", nome);
        //printf("salario: ");
        scanf("%lf", &salario);
        //printf("dia: ");
        scanf("%d", &data.dia);
       // printf("mes: ");
        scanf("%d", &data.mes);
        //printf("ano: ");
        scanf("%d", &data.ano);
        
        Lista = inserir_no_inicio(Lista, id,  nome, salario, data);
    }

    deletar_elemento(Lista, 2);
    imprimir_lista(Lista);


    return 0;
}