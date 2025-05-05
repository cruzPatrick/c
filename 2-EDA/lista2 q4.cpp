/*
4 - Faça uma função que retire sempre o primeiro elemento que foi inserido.
First in First Out = FIFO
*/

#include <iostream>
using namespace std;

struct no{
    int info;
    struct no* prox;
};
typedef struct no* noPtr;

noPtr topo = NULL;

/*
    O que ele faz? pega o 1° nó e exclui ele
    Quais são os casos especiais?
        1° Não haver lista vai ser lista==NULL
        2° Ter um só nó, ou seja lista->prox == NULL (errado, isso é redundante e desnecessário)
        3° Ter mais de um, para isso vou precisar de uma lista auxiliar que esteja adiantada em relação ao primeiro
*/

void fifo(noPtr& lista){
    noPtr aux, next;
    aux = lista;
    if(lista==NULL){
        cout<<"Não existe elemento na lista"<<endl;
        return;
    }
    next = aux->prox;
    delete aux;
    lista = next;
    return;

}