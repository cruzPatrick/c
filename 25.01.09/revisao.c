// 2025.01.09
//Dois jeitos de inicializar um Array
/*
Jeito 1:
int v[1000] = {0};

Jeito 2 (antigo):
for(i=0; i<100;i++) <- assim que se lê o array
    v[i] = 0;

ambos estão certos, mas o primeiro é mais prátrico por mais que eu não esteja acostumado
*/
#include <stdio.h>
int x(int a); 
int main(){
    float notas[30], soma = 0;
    for(int i = 0;i<30;i++){
        printf("Escreva a %d nota: ", i);
        scanf("%f", &notas[i]);
        soma += notas[i];
    }
    float media = soma / 30;
    for(int i = 0; i<30; i++){
        if(notas[i]>media)
            printf("%.2f", notas[i]);
    }
    
    return 0;
}

/*
-> array é o ponteiro do primeiro valor e o pc segue o abaixo pois ele sabe onde estão as outras memórias
O prof fez assim para que a gente fixasse a ideia de dividir o programa grande em alguns menores



void lenotas(float notas[], int quant){
    for(int i=0; i<quant; i++){
        scanf("%f", &notas[i]);
    }
}
float media (float notas[], int quant){
    float soma = 0;
    for(int i = 0; i<quant; i++){
        soma+=notas[i];
    }
    return soma/quant;
}

*/