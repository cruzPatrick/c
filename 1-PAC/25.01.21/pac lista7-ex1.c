//lista 7 de pac
#include <stdio.h>

int produtovetor(int v[], int num){
    int produto = 1;
    for(int i = 0; i < num; i++){
        printf("Escreva o numéro do vetor ");
        scanf("%d", &v[i]);
        produto *= v[i];
    }
    return produto;
}

void main(){
    int num;
    printf("Escreva a quantidade de numéros do vetor: ");
    scanf("%d", &num);
    int v[num];
    printf("a multiplicação de todos os valores do vetor é: %d", produtovetor(v, num));
}