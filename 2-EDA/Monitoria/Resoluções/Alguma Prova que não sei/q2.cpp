//a
#include <iostream>
struct no{
    int info;
    struct no* prox;
};

typedef struct no* noPtr;
using namespace std;

void remover(noPtr &lista){
    int val;
    cout << "Fale o valor que deseja excluir";
    cin >> val ;

    noPtr atual = lista;
    noPtr ante = NULL;

    while (atual != NULL && atual->info != val){
        ante = atual;
        atual = atual->prox;
    }
    if(atual == NULL)
        cout << "Elemento não encontrado";
    else{
        if(ante == NULL){
            lista = lista->prox;
        }
        else{
            ante->prox = atual->prox;
        }
        delete atual;
    }
}

//b

void funcao(noPtr lista){
    int maior, cont = 0, fim = 0, prox;
    noPtr aux = lista;

    while(aux->prox != nullptr){
        if(cont == 0){
            maior = aux->info;
            prox = aux->prox->info;
            cont++;
        }
        else{
            if(aux->info > maior){
                maior = aux->info;
                if(aux->prox == nullptr){
                    fim++;
                    break;
                }
                prox = aux->prox->info;
                cont++;
            }
        }
        aux = aux->prox;
    }
    if(cont == 1){
        cout << "O maior valor é: " << maior << " Seu sucessor é: "<< prox << "\nE foi o primeiro valor" << endl;
    }
    if(fim == 0)
        cout << "O maior valor é: " << maior << "Não há sucessor" << "\nE foi o último valor" << endl;

}

//c) R: Sim, pois ambos só tem um while que roda n vezes