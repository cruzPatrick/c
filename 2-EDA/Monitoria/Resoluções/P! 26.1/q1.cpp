#include <iostream>
struct no{
    int info;
    struct no* prox;
};

typedef struct no* noPtr;
using namespace std;

noPtr topo1 = nullptr;
noPtr topo2 = nullptr;
noPtr topo3 = nullptr;

void insercao(int valor){
    noPtr p; 
    p = new no;
    p->info = valor;
    
}

void intercala(){
    int contador = 1;
    noPtr aux1 = topo1;
    noPtr aux2 = topo2; 
    while((aux1 != nullptr) || (aux2 != nullptr)){
        if(contador%2==0){
            insercao(aux2->info);
            aux2 = aux2->prox;
        }
        else{
            insercao(aux1->info);
            aux1 = aux1->prox;

        }
        contador++;

    }
}