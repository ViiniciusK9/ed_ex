#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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
    struct funcionario *proximo;
};
typedef struct funcionario Funcionario;


Funcionario* alocar_funcionario(){
    Funcionario *novo = (Funcionario*)malloc(sizeof(Funcionario));
    return novo;
}


Funcionario* inserir_no_inicio(*Funcionario Lista, int id, char nome[41], double salario, Data nascimento){
    Funcionario *novo_elemento = alocar_funcionario();
    novo_elemento->id = id;
    novo_elemento->nome = nome;
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
    printf("%d ", aux->id);
    while(aux != NULL){
        printf("%d ", aux->id);
        printf("");
        aux = aux->prox; 
    }
}



int main(){
    
    Funcionario *Lista = NULL;

    Data data;
    data.dia = 27;
    data.mes = 01;
    data.ano = 2003;

    Lista = inserir_no_inicio(Lista, 0,  "vinicius", 500, data);
    imprimir_lista(Lista);



    return 0;
}