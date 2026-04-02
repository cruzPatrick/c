#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct no{
    
    int info;
    struct no* prox; 

};

int listaVazia();
void push();
void pop();

typedef struct no* noPtr;

noPtr topo = NULL;


int listaVazia(){
    if(topo == NULL)
        return 0;
    else
        return 1;
}
void push(){
    noPtr p;
    int valor;

    p = (noPtr) malloc(sizeof(struct no));

    printf("Insira o valor do elemento\n");
    scanf("%d", &valor);

    p->info = valor;
    p->prox = topo;
    topo = p;
}

void pop(){

    noPtr p = topo;
    if(listaVazia() != 0){
        topo = topo->prox;
        free(p);
        printf("elemento retirado da lista\n");
    }
    else
        printf("Lista vazia\n");
}