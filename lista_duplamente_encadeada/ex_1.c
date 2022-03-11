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


void adicionar_funcionario(List *list, Funcionario funcionario){
    
}



int main(){

    return 0;
}
 
// gcc arquivo.c -o prog
// ./prog < arq.in > arq.out