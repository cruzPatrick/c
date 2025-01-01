#include <stdio.h>


float media (float v[], int n){
    float soma = 0;
    for(int i=0; i<n;i++){
        soma +=v[i];
    }
    return soma/n;
}

int vector(){
	int v [1000] = {0};
	int *p = v;
	v[0]=15;
	printf("%d", p[0];
	p = &v[20];

}

void lenotas(float v[], int n){
    for(int i = 0; i<n; i++){
        scanf("%f", &v[i]);
    }
}

/*

int main(){
    float notas [30];
    lenotas(notas, 30);
    printf("%f", media (notas, 30));
    flaot *p = notas; // colocar float *p = &notas[0]; == overkill
    p+1;
}

se p é um ponteiro p+1 é outro ponteiro

*/



void main(){
    float notas [5] = {0};
    float soma = 0, media;
    for(int i = 0; i<5; i++){
        printf("Escreva as notas: ");
        scanf("%f", &notas[i]);
        soma += notas[i];
    }
    media = soma/5;
    printf("média é: %.2f\n", media);
    for(int i = 0; i<5; i++){
        if(notas[i]<media){
            printf("O aluno %d ficou abaixo da média e teve nota: %.2f\n", i+1, notas[i]);
        }
    }
}