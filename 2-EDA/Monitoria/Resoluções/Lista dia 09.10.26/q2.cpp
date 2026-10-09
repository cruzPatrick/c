#include <iostream>

struct pontProd{
  int cod;
  pontProd* pr;
};

typedef pontProd* pontProdu;

struct pontCliente{
    pontCliente* ant;
    pontCliente* prox;
    int info;
    pontProdu p;
};

typedef pontCliente* pontCli;
using namespace std;

pontCli T = nullptr;
pontCli F = nullptr;


void chegadaCliente() {
    pontCli novo = new pontCliente;
    
    novo->p = nullptr;
    novo->prox = nullptr;
    
    //Caso de vazio
    if (T == nullptr && F == nullptr) {
        novo->info = 100;
        novo->ant = nullptr;
        T = novo;
        F = novo;
    }
    //Caso tenha mais de um
    else{
        novo->info = F->info + 100;
        novo->ant = F;
        F->prox = novo;
        F = novo;
    }
}

void consumoCliente(){
    int cod;
    cout<<"Qual o código do Cliente?"<< endl;
    cin >> cod;
    
    pontCli aux = T;
    while(aux != nullptr && cod != aux->info){
        aux = aux->prox;
    }
    if(aux == nullptr){
        cout<< "Cliente não encontrado!"<< endl;
        return;
    }
    
    int codigoProduto;
    cout<<"Qual o código do Produto?"<<endl;
    cin>>codigoProduto;
    
    pontProdu produto = new pontProd;
    produto->cod = codigoProduto;
    produto->pr = nullptr;
    
    if(aux->p == nullptr)
        aux->p = produto;
    else{
        pontProdu auxP = aux->p;
        while(auxP->pr != nullptr)
            auxP = auxP->pr;
        
        auxP->pr = produto;
    }
    cout<<"Produto cadastrado com sucesso!"<<endl;
}



int main()
{
    cout<<"Hello World";

    return 0;
}