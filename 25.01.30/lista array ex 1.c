#include <stdio.h>
#include <string.h>

int mediaInt(int v[], int qtd){
    int soma =0, media;
    for(int i = 0; i<qtd; i++)
        soma+=v[i];
    return soma/qtd;
}

int main(){
    int v [] = {1,2,3}, qtd = 3;
    
    printf("%d", mediaInt(v, qtd));
    return 0;
}