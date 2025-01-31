#include <stdio.h>
#include <string.h>

int acimadamedia(float v[], int qtd, float media){
    int acima = 0;
    for(int i = 0; i < qtd; i++){
        if(v[i]>media){
            acima++;
        }
    }
    return acima;
}

int main(){
    float v[100], media = 0, soma = 0;
    int qtd = 0;
    printf("Quando quiser parar tecle -1\n");
    for(int i = 0; i < 100; i++){
        printf("Escreva o valor a ser computado: ");
        scanf("%f", &v[i]);
        if(v[i]!=-1){
            qtd++;
            soma += v[i];
        }
        else{
            break;
        }
    }
    media = soma/qtd;
    printf("A quantidade de notas acima da média são: %d", acimadamedia(v, qtd, media));
    return 0;
}