#include <string.h>
#include <stdio.h>

int acimadaMedia(float v[], int qtd, float media){
    int acima = 0;
    for(int i = 0; i < qtd; i++){
        if(media<v[i]){
            acima++;
        }
    }
    return acima;
}

int main(){
    float v[3], media, soma=0;
    int qtd = 3;
    for(int i = 0; i < qtd; i++){
        printf("Escreva os números do vetor: ");
        scanf("%f", &v[i]);
        soma+=v[i];
    }
    media = soma / qtd;
    printf("Os números acima da média são: %d", acimadaMedia(v, qtd, media));
    return 0;
}