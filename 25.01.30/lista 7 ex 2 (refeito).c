#include <stdio.h>
#include <string.h>

void parimpar(int v[], int n, int* par, int* impar){
    for(int i = 0; i < n; i++){
        if(v[i]%2==0){
            (*par)++;
        }
        else{
            (*impar)++;
        }
    }
}


int main(){
    int v[3], par=0, impar=0;
    for(int i = 0; i < 3; i++){
        printf("Qual o valor você quer colocar nesse vetor? ");
        scanf("%d", &v[i]);
    }
    parimpar(v, 3, &par, &impar);
    printf("%d %d", par, impar);
    return 0;
}