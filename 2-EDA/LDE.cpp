#include <iostream>
using namespace std;
struct no{
    struct no* ant;
    int info;
    struct no* prox;
};
typedef struct no* noPtr;

int main(){
    noPtr topo = NULL;
    int val = 10;
    inserirfim(&topo, val);
    return 0;
}
int menu(){

}
void inserirfim(noPtr* topo, int val){
    noPtr p = new no, aux;
    p->info = val;
    p->ant = NULL;
    p->prox = NULL;
    if(*topo == NULL){
        *topo = p;
    }else{
        aux = *topo;
        while(aux->prox != NULL)
            aux = aux->prox;
        p->ant = aux;
        aux->prox = p;
    }

}
void inseririni(noPtr* topo, int val){
    noPtr aux = *topo;
    noPtr p = new no;

    p->info = val;
    p->ant = NULL;

    if(aux == NULL)
        p->prox = NULL;
    else{
        p->prox = aux;
        aux->ant = p;   
    }
    *topo = p;
}
/*
Minha versão ruim
void inserirmeio(noPtr* topo, int val){
    noPtr aux = *topo;
    noPtr p = new no;

    p->info = val;


    if(*topo == NULL){ //lista vazia
        p->ant = NULL;
        p->prox = NULL;
        *topo = p;
    }
    else{
        noPtr ant = NULL;
        while(aux != NULL  && aux->info < p->info){
            ant = aux;
            aux = aux->prox;
        }
        if(aux == NULL){ //final
            aux->prox = p;
            p->ant = ant;
            p->prox = NULL;
        }
        else{
            if(p->info < aux->info){ // inicio
                p->ant = NULL;
                p->prox = *topo;
                (*topo)->ant = p;
                *topo = p;
            }
            else{ //meio
                ant->prox = p;
                p->ant = ant;
                aux->ant = p;
                p->prox = aux;
            }
        }
    }
}

*/

//com ajuda do chat, bem mais limpa
void inserirmeio(noPtr *topo, int val){
    noPtr aux = *topo;
    noPtr p = new no;

    p->info = val;
    p->ant = NULL;
    if((*topo)==NULL){ //lista vazia
        p->prox = NULL;
        (*topo) = p;
        return;
    }

    if(val < (*topo)->info){ //inicio
        p->prox = (*topo);
        (*topo)->ant = p;
        *topo = p;
        return;
    }
    noPtr ante = NULL;
    while(aux != NULL && aux->info < p->info){
        ante = aux;
        aux = aux->prox;
    }
    
    if(aux == NULL){ //fim
        p->ant = ante;
        ante->prox = p;
        p->prox = NULL;
        return;
    }
    else{ //meio
        p->ant = ante;
        p->prox = aux;
        ante->prox = p;
        aux->ant = p;
    }
}