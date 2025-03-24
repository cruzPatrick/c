#include <stdio.h>
#include <string.h>
/*
Faça uma função que receba como parametro um vetor de numeros reais,
um numero real ao ser procurado no vetor e a quantidade de numeros armazedos no vetor
Essa função deverá retornar -1 caso o número não seja encontrado ou a posição do onde o numero foi encontrado
*/

int buscaNum(float v[], float num, int qtd){
    for(int i = 0; i < qtd; i++){
        if(v[i] == num)
            return i;
    }
    return -1;
}

int main(){
    float v[3], num;
    int qtd = 3;
    for(int i = 0; i<qtd;i++){
        printf("Escreva os numeros do vetor: ");
        scanf("%f", &v[i]);
    }
    printf("Qual o numero você quer encontrar no vetor? ");
    scanf("%f", &num);
    printf("%d", buscaNum(v, num, qtd));
    return 0;
}