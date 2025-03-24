#include <string.h>
#include <stdio.h>

struct _livro{
    char isbn [13];
    char titulo [30];
    char autor[30];
};
typedef struct _livro Livro;

int busca(Livro dados[], int qtd, char* procurado[]){
    for(int i = 0; i < qtd; i++){
        if(strcmp(dados[i].titulo,procurado[i])!=0){
            return -1;
        }
        else{
            return i;
        }
    }
}

void decobreLivros(Livro livro[], int qtd, char* procurado[]){
    char pos = busca(livro, qtd, procurado);
    if(pos == -1){
        printf("Livro não encontrado");
    }
    else{
        printf("%s\n", livro[pos].autor);
        printf("%s\n", livro[pos].isbn);
        printf("%s\n", livro[pos].titulo);
        for(int i = 0; i < qtd; i++){
            if(i!=pos && strcmp(livro[i].autor,livro[pos].autor)==0){
                printf("%s\n", livro[i].titulo);
            }
        }
    }
}