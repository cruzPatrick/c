#include <string.h>
#include <stdio.h>
int maiorqueUltimo(float v[], int qtd){
    int maiores = 0;
    for(int i = 0; i<qtd; i++){
        if(v[i]>v[qtd-1]){
            maiores++;
        }
    }
    return maiores;
}

int main(){
    float v[3];
    int qtd = 3;
    for(int i = 0; i < qtd; i++){
        scanf("%f", &v[i]);
    }
    printf("A quantidade de maiores que o ultimo é: %d", maiorqueUltimo(v, qtd));
    return 0;
}