/*
6. Elabore uma função que insira sempre no final da lista.
    Precisa correr a lista inteira e adicionar no final

Esquici do caso de lista vazia
*/
#include <iostream>
using namespace std;

struct no{
    int info;
    struct no* prox;
};
typedef struct no* noPtr;
noPtr topo = NULL;

void insertFinal(noPtr& lista, int valor){
    noPtr aux = new no, proxi;
    aux->info = valor;
    aux->prox = NULL;
    proxi = lista;
    if(lista == NULL){
        lista = aux;
        return;
    }
    while(proxi->prox != NULL){
        proxi = proxi->prox;
    }
    proxi->prox = aux;
    return;
}