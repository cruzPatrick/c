//corrigido

#include <stdio.h>
#include <string.h>

//somar os dois vetores em um separado
void somadevetores(float vec1[], float vec2[], int qtd, float *vecaux){
    for(int i = 0; i < qtd; i++){
        vecaux[i] = vec1[i] + vec2[i];
    }
    for(int i = 0; i < qtd; i++){
        printf("A soma de %.2f + %.2f = %.2f\n", vec1[i], vec2[i], vecaux[i]);
    }
} 


int main(){
    float v[] = {1,2,3}, a[] = {4,5,6}, aux[3];
    int qtd = 3;
    somadevetores(v, a, qtd, aux);
    //poderia colocar o printf aqui pq o que é alterado em um ponteiro permanece mesmo que seja void
    return 0;
}





/*
Meu erro foi quanto ao vetor auxiliar que coloquei sendo um vetor ponteiro de float, 
sendo que vetor já é um ponteiro


void somadevetores(float vec1[], float vec2[], int qtd, float* vecaux[]){
    for(int i = 0; i < qtd; i++){
        *vecaux[i] = vec1[i] + vec2[i];
    }
    for(int i = 0; i < qtd; i++){
        printf("A soma de %f + %f = %f", vec1[i], vec2[i], *vecaux[i]);
    }
} 


int main(){
    float v[] = {1,2,3}, a[] = {4,5,6}, aux[3];
    int qtd = 3;
    somadevetores(v, a, qtd, &aux);
    return 0;
}

 */