/*
1
Elabore um programa que solicite ao usuário escolher um elemento para retirar de uma lista. 
Caso exista mais de um elemento igual, então apague o primeiro encontrado.


2
Crie uma função de busca e utilize no programa desenvolvido na questão anterior.
*/

#include <iostream>
using namespace std;

struct no{
    int info;
    struct no* prox;
};
typedef struct no* noPtr;
noPtr topo = NULL;


noPtr busca(noPtr lista, int valor){
    while(lista != NULL){
        if(lista->info == valor){
            return lista;
        }
        lista = lista->prox;
    }
    return NULL;
}

void popNum(noPtr& lista){
    noPtr atual = lista;
    noPtr ante = NULL;
    int val;
    cout<<"Escreva o valor que você quer remover da lista";
    cin>>val;
    
    while (atual != NULL && atual->info != val){
        ante = atual;
        atual = atual->prox;
    }

    if(ante == NULL){
        lista = lista->prox;
    }
    else{
        ante->prox = atual->prox;
    }
    delete atual;
}

int main(int argc, char* argv[]){
    noPtr lista;
    lista = new no;
    int valor;
    cout<<"Qual valor você quer procurar? ";
    cin>>valor;

    if(busca(lista, valor)){
        popNum(lista);
    }
    else{
        cout<<"Valor não encontrado";
    }
}