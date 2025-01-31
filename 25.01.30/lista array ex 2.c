#include <string.h>
#include <stdio.h>

void parimpar (int v[], int qtd, int* par, int* impar){
    for(int i = 0; i < qtd; i++){
        if(v[i]%2==0){
            (*par)++;
        }
        else
            (*impar)++;
    }
}

int main(){
    int v[3], qtd = 3;
    int par=0, impar=0;
    for(int i = 0; i < qtd; i++){
        printf("Escreva o numero: ");
        scanf("%d", &v[i]);
    }
    parimpar(v, qtd, &par, &impar);
    printf("A quantidade de números par é: %d\nA quantidade de números impar é: %d", par, impar);
    return 0;
}