#include <iostream>
struct no{
    struct no* esq;
    int info;
    struct no* dir;
};

typedef struct no* noPtr;
using namespace std;

void inserir(noPtr *, int);
bool busca(noPtr, int);
void listaremordem(noPtr);
void listarpreordem(noPtr);
void listarposordem(noPtr);
void remover(noPtr *, int);
noPtr maior(noPtr *);

int main(){
    noPtr raiz = NULL;
    int op, x;
    do{
        cin >> op;
        switch(op){
            case 1: cout << "Qual valor você quer inserir? ";
                    cin >> x;
                    inserir(&raiz, x);
                    break;
            case 2: cout << "Qual valor você quer buscar? ";
                    cin >> x;
                    busca(raiz, x);
                    break;
        }
    }while(op!=0);
    return 0;
}

void inserir(noPtr *raiz, int x){
    if(*raiz == NULL){
        noPtr p = new no;
        p->info = x;
        p->dir = NULL;
        p->esq = NULL;
        *raiz = p;
        return;
    }
    if((*raiz)->info > x){
        inserir(&(*raiz)->esq, x);
    }
    else{
        inserir(&(*raiz)->dir, x);
    }
}

bool busca(noPtr p, int x){
    bool achei = false;
    if(p == NULL){
        cout << "Árvore vazia" << endl;
        return false;
    }
    if(x == p->info){
        cout << "o elemento " << p->info << " Foi encontrado!" << endl;
        return true;
    }
    else{
        if(x < p->info){
            return busca(p->esq, x);
        }
        else{
            return busca(p->dir, x);
        }
    }
}

void listaremordem(noPtr p){
    if(p != NULL){
        listaremordem(p->esq);
        cout << "\t" << p->info;
        listaremordem(p->dir);
    }
}

void listarpreordem(noPtr p){
    if(p!=NULL){
        cout << "\t" << p->info;
        listarpreordem(p->esq);
        listarpreordem(p->dir);
    }
}

void listarposordem(noPtr p){
    if(p!=NULL){
        listarposordem(p->esq);
        listarposordem(p->dir);
        cout << "\t" << p->info;
    }
}

//jeito da prof
/*


void remover(noPtr *p, int x){
    noPtr aux;
    if(*p != NULL){
        if(x == (*p)->info){
            aux = *p;
            if((*p)->esq == NULL)
                *p = (*p)->dir;
            else{
                if((*p)->dir == NULL)
                    *p = (*p)->esq;
                else{
                    aux = maior(&(*p)->esq);
                    (*p)->info = aux->info;
                }
            delete(aux);
            cout << "\n O elemento foi removido" << endl;
            }
        }
        else{
            if(x<(*p)->info)
                remover(&(*p)->esq, x);
            else
                remover(&(*p)->dir, x);
        }
    }
}
*/

void remover(noPtr* p, int x) {
    if (*p == NULL){
        cout << "\nElemento não encontrado na árvore!" << endl;
        return;
    }

    if (x == (*p)->info) {
        noPtr aux = *p;

        // Caso 1: Nó só tem a direita (ou nenhum filho na direita)
        if ((*p)->esq == NULL) {
            *p = (*p)->dir;
            delete aux;
            cout << "\nO elemento foi removido!" << endl;
            return;
        }

        // Caso 2: Nó só tem a esquerda
        if ((*p)->dir == NULL) {
            *p = (*p)->esq;
            delete aux;
            cout << "\nO elemento foi removido!" << endl;
            return;
        }

        // Caso 3: Nó com dois filhos
        aux = maior(&(*p)->esq); // Função que retorna o maior da subárvore esquerda
        (*p)->info = aux->info;
        remover(&(*p)->esq, aux->info);  // Remove o nó duplicado agora
        return;
    }

    if (x < (*p)->info) {
        remover(&(*p)->esq, x);
        return;
    }

    remover(&(*p)->dir, x);
}

noPtr maior(noPtr *p){
    noPtr t = *p;
    if(t->dir == NULL){
        *p = (*p)->esq;
        return t;
    }
    return maior(&(*p)->dir);
}
