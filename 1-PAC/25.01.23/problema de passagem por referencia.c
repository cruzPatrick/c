#include <stdio.h>

void parimpar(int v[], int tam, int* par, int* impar){
    *par = 0;
    *impar = 0;
    for(int i = 0; i < tam; i++){
        if((v[i]%2)==0){
            (*par)++; // não usar *par++, isso da pau
        }
        else{
            (*impar)++;
        }
    }
}

void main(){
    int tam;
    int *par, *impar;
    printf("Escreva o tamanho do vetor ");
    scanf("%d", &tam);
    int v[tam];
    for(int i = 0; i < tam; i++){
        printf("Escreva o valor do numero na posição %d: ",i+1);
        scanf("%d",&v[i]);
    }
    parimpar(v, tam, &par, &impar);

}

/*
corrigido:

#include <stdio.h>

void parimpar(int v[], int tam, int* par, int* impar){
    *par = 0;
    *impar = 0;
    for(int i = 0; i < tam; i++){
        if((v[i]%2)==0){
            (*par)++; // não usar *par++, isso da pau
        }
        else{
            (*impar)++;
        }
    }
}

void main(){
    int tam, par, impar;
    printf("Escreva o tamanho do vetor ");
    scanf("%d", &tam);
    int v[tam];
    for(int i = 0; i < tam; i++){
        printf("Escreva o valor do numero na posição %d: ",i+1);
        scanf("%d",&v[i]);
    }
    parimpar(v, tam, &par, &impar);

}


*/