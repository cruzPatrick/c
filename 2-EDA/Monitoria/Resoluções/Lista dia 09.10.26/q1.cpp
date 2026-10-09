#include <iostream>
using namespace std;

struct no {
    string info;
    no* ant;
    no* prox;
};

typedef no* noPtr;

noPtr topo = nullptr;

void i(){
    noPtr novo = new no;
    cout<<"Escreva o texto abaixo"<<endl;
    getline(cin, novo->info);
    novo->ant = nullptr;
    novo->prox = nullptr;

    noPtr aux = topo;

    if(topo==nullptr)
        topo = novo;
    else{
        while(aux->prox != nullptr){
            aux = aux->prox;
        }
        novo->ant = aux;
        aux->prox = novo;
    }
}

void p(int l){
    noPtr aux = topo;
    int contador = 1;
    while(aux != nullptr){
        if(contador >= l ){
            cout<<aux->info<<endl;
        }
        contador++;
        aux= aux->prox;
    }
}

void x(){
    if(topo == nullptr){
        cout<<"Não há texto"<<endl;
        return;
    }
    else{
        if(topo->prox == nullptr){
            delete(topo);
            topo = nullptr;
        }
        else{
            noPtr aux = topo;
            noPtr anterior = topo->prox;
            topo = anterior;
            delete(aux);
        }

    }
}

void m(int linha1, int linha2){
    if (linha1 >= linha2 || topo == nullptr) 
        return;

    noPtr noL1 = topo;
    int pos = 1;
    while (noL1 != nullptr && pos < linha1) {
        noL1 = noL1->prox;
        pos++;
    }

    noPtr noL2 = topo;
    pos = 1;
    while (noL2 != nullptr && pos < linha2) {
        noL2 = noL2->prox;
        pos++;
    }

    if(noL1 == nullptr || noL2 == nullptr)
        return;
    
    if (noL1->ant != nullptr) 
        noL1->ant->prox = noL1->prox;
    else 
        topo = noL1->prox;
        
    if (noL1->prox != nullptr) 
        noL1->prox->ant = noL1->ant;
    

}