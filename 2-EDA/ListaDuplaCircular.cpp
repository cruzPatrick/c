#include <iostream>
// esse sou eu fazendo com o que tenho do anterior
struct no{
    struct no* ante;
    int info;
    struct no* prox;
};
typedef struct no* noPtr;
using namespace std;

void inserir(noPtr *);
void retirar(noPtr *);
void listar(noPtr);

int main(int argc, char* argv[]){
    noPtr topo = NULL;
    int op, qtd=0;
    do{
        //colocar um pra perguntar qual ele quer entrar
        cin >> op;
        switch(op){
            case 1: inserir(&topo);
                    break;
            case 2: retirar(&topo);
                    break;
            case 3: listar(topo);
                    break;
        }

    }while(op != 0);
}

void inserir(noPtr *topo){
    noPtr p = new no;
    cin >> p->info;
    if(*topo == NULL){
        p->ante = p;
        p->prox = p;
        (*topo) = p;
    }
    else{
        noPtr aux = *topo;
        p->prox = *topo;
        p->ante = aux->ante;
        aux->ante->prox = p;
        aux->ante = p;
        *topo = p;
    }
}

void retirar(noPtr *topo){
    noPtr aux = *topo;
    if(*topo==NULL){
        cout << "Lista vazia!";
        return;
    }
    if((*topo)->prox == *topo && (*topo)->ante == *topo){
        *topo = NULL;
        delete(aux);
    }
    else{
        aux->prox->ante = aux->ante;
        aux->ante->prox = aux->prox;
        *topo = aux->prox;
        delete(aux);
    }
    
}

void listar(noPtr topo){

}