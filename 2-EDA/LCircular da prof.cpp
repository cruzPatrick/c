#include <iostream>

struct no{
    int info;
    struct no* prox;
};

typedef struct no* noPtr;
using namespace std;

int inserir(noPtr *, int *); 
void retirar(noPtr *, int *); 
void listar(noPtr, int); 
bool listaVazia(noPtr);

void main() {
    noPtr topo = NULL; 
    int op, qtde = 0;
    do { 
        cin >> op; 
        switch(op) {
        case 1: inserir(&topo, &qtde); //redundância – acertar 
            cout << "\nA lista possui " << qtde << "no(s). " << endl; break;
        case 2: retirar(&topo, &qtde); break; 
        case 3: listar(topo, qtde); break; 
    }
    } while (op !=0); 
}

int inserir (noPtr * i, int * q) {
//É uma lista circular? Acertar
    noPtr p = new no; 
    cout << "\nDigite o valor do elemento: "; 
    cin >> p->info; 
    if (listaVazia(*i)) { 
        *i = p; 
        p->prox = *i;
    } 
    else { 
        noPtr aux = *i;
        while(aux->prox != *i)
            aux= aux->prox;
        p->prox = *i;    
        aux->prox = p; 
        *i = p;
    }
    (*q) += 1; 
    return *q;
}

void retirar (noPtr * i, int * q) {
    noPtr p = *i; 
    if (!listaVazia(*i)) { 
        if (*q == 1) 
            *i = NULL;
        else 
            *i = p->prox; //*i = (*i)->prox;
        delete(p); 
        cout << "\nO elemento foi retirado da lista!\n"; 
        (*q) -= 1;
    } 
    else 
        cout << "\n\nLista Vazia!\n"; 
}

void listar(noPtr i, int q) {
    if (!listaVazia(i)) { 
        for (int j = 0; j < q; j++) {
            cout << i->info << "\t"; 
            i = i->prox;
        } 
    }
    else 
        cout << "\n\nLista vazia!";
}