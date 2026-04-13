#include <iostream>

using namespace std;
typedef struct Carta* carta;

struct Carta{
    int valor; 
    char naipe;
    char cor;
    Carta* prox;
};

carta movimentacao [8] = {NULL};

carta aux [4] = {NULL};
carta definitiva [4] = {NULL};

void push(int coluna, char naipe, char cor, int valor){
    carta nova = new(Carta);
    nova->valor = valor;
    nova->naipe = naipe;
    nova->cor = cor;

    nova->prox = movimentacao[coluna];
    movimentacao[coluna] = nova;
}

carta retirar(int coluna){
    if(movimentacao[coluna] != NULL){
        carta aux = movimentacao[coluna];
        movimentacao[coluna] = aux->prox;
        aux->prox = NULL;
        return aux;
    }
    else
        return NULL;
}

void inserir_na_pilha(int coluna, carta aux){
    aux->prox = movimentacao[coluna];
    movimentacao[coluna] = aux;
}

void tentarMover(int indiceOrigem, int indiceDestino) {
    carta movida = movimentacao[indiceOrigem];
    carta destino = movimentacao[indiceDestino];

    if (movida == NULL)
        return; 

    if (destino == NULL || (movida->cor != destino->cor && movida->valor == destino->valor - 1)) {
        carta c = retirar(indiceOrigem);
        inserir_na_pilha(indiceDestino, c);
    } else {
        printf("Movimentação impossível\n");
    }
}

void naipeCerto(int indiceOrigem, int indiceDestino){
    carta origem = movimentacao[indiceOrigem];
    carta destino = definitiva[indiceDestino];

    if(destino == NULL && origem->valor == 1) {
        origem->prox = destino;
    }
    else{
        if(origem->naipe == destino->naipe && origem->valor == destino->valor + 1){
            origem->prox = destino;
            destino = origem;
        }
        else{
            printf("Movimentação inválida");
        }
    }
}

/* Versão resumida e mais elegante do chat gpt

void naipeCerto(int indiceOrigem, int indiceDestino) {
    carta movida = movimentacao[indiceOrigem];
    carta topoDef = definitiva[indiceDestino];

    // 1. Verificação básica: Tem carta para mover?
    if (movida == NULL) return;

    // 2. Validação: O movimento é possível?
    bool ehPrimeiraEAs = (topoDef == NULL && movida->valor == 1);
    bool ehSequenciaCerta = (topoDef != NULL && movida->naipe == topoDef->naipe && movida->valor == topoDef->valor + 1);

    if (!ehPrimeiraEAs && !ehSequenciaCerta) {
        printf("Movimentacao invalida para a definitiva.\n");
        return;
    }

    // 3. Execução: Se chegou aqui, é porque passou nas validações
    carta c = retirar(indiceOrigem);
    c->prox = topoDef; // Se topoDef for NULL, c->prox será NULL (o que está certo)
    definitiva[indiceDestino] = c;
}
*/