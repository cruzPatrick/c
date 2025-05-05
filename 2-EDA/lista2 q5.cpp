/*
5 - Elabore uma função que insira sempre no início da lista.
*/

#include <iostream>
using namespace std;

struct no{
    int info;
    struct no* prox;
};
typedef struct no* noPtr;
noPtr topo = NULL;

void insertIni(noPtr& lista, int valor){
    noPtr aux = new no;
    aux->info = valor;
    aux->prox = lista->prox;
    lista = aux;
    return;
}