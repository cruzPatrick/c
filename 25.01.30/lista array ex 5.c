#include <string.h>
#include <stdio.h>
float maior(float v[], int qtd){
    float maior;
    for(int i = 0; i < qtd; i++){
        if(v[i] == 0 || v[i]>maior){
            maior = v[i];
        }
    }
    return maior;
}

int main(){
    float v[3];
    int qtd = 3;
    for(int i = 0; i < qtd; i++){
        printf("Digite os valores do vetor: ");
        scanf("%f", &v[i]);
    }
    printf("O maior valor é: %.2f", maior(v, qtd));
    return 0;
}