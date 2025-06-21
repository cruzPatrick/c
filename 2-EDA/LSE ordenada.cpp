#include <iostream>
using namespace std;
struct no{
    int info;
    struct no* prox;
};
typedef struct no* noPtr;
noPtr topo = NULL;

int main(){
    int op;
    do{
        op = menu();
        switch(op){
            case 1: inserir(); break;
            case 2: consultar(); break;
        }
    }while(op!=0);
    return 0;
}

void inserir(){
    noPtr aux, ant, p = new no;
    cout<<"Digite o valor do elemento";
    cin>> p->info;
    if(topo == NULL){
        p->prox = topo;
        topo=p;
    }else{
        aux = topo;
        while(aux!=NULL && p->info>aux->info){
            ant = aux;
            aux = aux->prox;
        }
        if(aux == topo){
            p->prox = aux;
            topo = p;
        }else{
            p->prox = aux;
            ant->prox = p;
        }
    }
}

void consultar(){
    noPtr p = topo;
    int x;
    bool achei = false;
    if(topo == NULL){
        cout << "Digite um elemento: ";
        cin >> x;
        while(p != NULL && achei == false){
            if(p->info == x){
                cout << "Elemento encontrado";
                achei = true;
            }
            p = p->prox;
        }
        if(!achei)
            cout << "Elemento não encontrado";
    }else
        cout << "Lista vazia";
}

int menu(){
    int x;
    cout << "\n1. Inserir";
    cout << "\n2. Consultar";
    cout << "\n0. Sair";
    cout << "\n Digite uma opção: ";
    cin >> x;
    return x;
}

//Inserir o retirar

void retirar(){
    noPtr aux, ant;
    int valor;
    cout << "Qual valor você quer que seja excluído: ";
    cin >> valor;
    aux = topo;
    if(topo == NULL){
        cout << "Não há valores na lista";
        return;
    }else{
        while(aux != NULL && aux->info != valor){
            ant = aux;
            aux = aux->prox;
        }
        if(aux == NULL){
            cout<<"Elemento não encotrado!";
            return;
        }else{
            if(aux == topo){
                topo = topo->prox;
                delete(aux);
                if(topo == NULL)
                    cout<<"Lista vazia";
            }else{
                ant->prox = aux->prox;
                delete(aux);
            }
        }
    }
}
void crescente(){
    noPtr aux;
    if(topo==NULL)
        cout<<"Lista vazia";
    else{
        aux = topo;
        while(aux != NULL){
            cout << aux->info << endl;
            aux = aux->prox;
        }
    }
}

void decrescente(){
    if(topo == NULL)
    cout << "Lista vazia" << endl;
    else{
        noPtr aux = topo;
        int tam=0;
        while(aux!=NULL){
            tam++;
            aux= aux->prox;
        }
        int vetor[tam], i=0, ajuda;
        aux = topo;
        while(aux != NULL){
            vetor[i] = aux ->info;
            aux = aux->prox;
            i++;
        }
        for(int j = 0; j < tam-1; j++){
            for(int k = 0; k < tam-1-j; k++){
                if(vetor[k] < vetor[k+1]){
                    int ajuda = vetor[k];
                    vetor[k] = vetor[k+1];
                    vetor[k+1] = ajuda;
                }
            }
        }
    }
}