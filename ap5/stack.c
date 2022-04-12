#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _elStack {
    char element[100]; //troque para char *
    struct _elStack *next;
};
typedef struct _elStack ElementStack;

typedef struct {
    ElementStack *top;
} Stack;

void push(Stack *stack, char element[100]);

// int isEmpty(Stack *stack){
//     if (stack->top == NULL)
//         return 1;
    
//     return 0;
// }
//condição ternaria
int isEmpty(Stack *stack){
    return (stack->top == NULL)? 1: 0;
}


void printStack(ElementStack *element){
    if (element == NULL)
        return;
    printStack(element->next);
    printf("%s -> ", element->element);
}

void freeStack(Stack *stack){
    ElementStack *aux = stack->top, *prev;
    while ( aux != NULL ){
        prev = aux;
        aux = aux->next;
        free(prev);
        printf("@");
    }
    free(stack);
    printf("\n");
}

void pop (Stack *stack){
    ElementStack *aux;
    

    aux = stack->top;
    stack->top = stack->top->next;
    printf("%s\n", aux->element);
    free(aux);
}


int main (){
    Stack *stack = malloc(sizeof(Stack));
    char op[100];
    char aux2[100];
    stack->top = NULL;
    scanf("%s", op);
    while(strcmp(op, "E") != 0){
        if(strcmp(op, "B") == 0){
            if(isEmpty(stack)){
                printf("Vazio\n");
            }else {
                pop(stack);
            }
        }else {
            push(stack, op);
        }
        scanf("%s", op);
    }
    if(isEmpty(stack)){
        printf("!\n");
    }else {
        freeStack(stack);
    }

    return 0;
}


void push(Stack *stack, char element[100]){
    ElementStack *newElement = malloc(sizeof(ElementStack));
    newElement->next = NULL;
    strcpy(newElement->element,  element);

    newElement->next = stack->top;
    stack->top = newElement;
}

