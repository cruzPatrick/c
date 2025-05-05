/*
3. Faça uma função que retire sempre o último elemento que foi inserido.
last in last out
*/

#include <iostream>
using namespace std;

//declaração da lista
struct no{
    int info;
    struct no* prox;
};
typedef struct no* noPtr;
noPtr topo=NULL;

//não pede mas vou refazer busca para garantir que aprendi a ideia
noPtr busca(noPtr lista){
    int valor;
    cout<<"Qual valor quer achar?";
    cin>>valor;
    while(lista != NULL){
        if(lista->info == valor)
            return lista;
        lista = lista->prox;
    }
    return NULL;
}

/*
Qual a ideia do código?
    pegar o primeiro valor da lista e excluir
Quais são as possibilidades?
    A lista estar vazia, então não tem o que excluir
    A lista ter um só elemento, então lista->prox vai ser NULL
    A lista ter mais de um elemento, então preciso de uma lista auxiliar para atribuir o valor de lista->prox para o segundo elemento
*/

void lilo(noPtr& lista){
    noPtr aux, ante;
    aux=lista;
    if(aux==NULL){
        cout<<"Lista Vazia"<<endl;
        return;
    }
    else{
        if(aux->prox == NULL){ //se for um só nó
            ante = NULL; //sei que é redundante e poderia fazer lista=NULL, mas quis deixar assim pq foi como pensei a primeira vez
            delete aux;
            lista = ante;
            return;
        }
        while(aux->prox != NULL){//roda tudo
            ante = aux;
            aux = aux->prox;
        }
        ante->prox = NULL;//faz a lista apontar para o NULL
        delete aux;
    }
}