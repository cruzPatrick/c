#include <stdio.h>


void learray (int v[], int n){
    for(int i = 0; i<n; i++){
        printf("Escreva os valores da celula %d: ", i+1);
        scanf("%d", &v[i]);
    }
}

int maiorvalor(int v[], int n){
    int maior;
    for (int i = 0; i<n; i++){
        if(i==0||v[i]>maior)
            maior = v[i];
    }
    return maior;
}


int busca(int v[], int n, int x){
    for(int i = 0; i<n; i++){
        if(v[i]==x){
            return i;
        }
    }
    return -1;
}


void main(){
    int vetor [5], val;
    learray(vetor, 5);
    printf("O maior valor é: %d", maiorvalor(vetor, 5));
    printf("qual valor quer achar? ");
    scanf("%d", &val);
    printf("O valor %d está na célula %d do array", val, busca(vetor, 5, val));    
    
    
}