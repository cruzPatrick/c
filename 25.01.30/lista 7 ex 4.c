#include <stdio.h>
#include <string.h>

int menorque(float v[], int tam){
    int qtd = 0;
    for(int i = 0; i < tam; i++){
        if(v[i]<v[tam]){
            qtd++;
        }
        printf("%f", v[i]);
    }
    return qtd;
}

int main(){
    float v[100];
    int qtd = 0;
    printf("Escreva -1 quando não quiser mais colocar valor\n");
    for(int i = 0; i < 100; i++){
        printf("Escreva o valor que você quer adicionar: ");
        scanf("%f", &v[i]);
        if(v[i]!=-1){
            qtd++;
            printf("%d\n", qtd);
        }
        else{
            qtd--;
            break;
        }
    }
    printf("Qtd de numeros menores que o ultimo é %d", menorque(v, qtd));
    
    //qtd -1 pq são de 0 a 5 
    return 0;
}