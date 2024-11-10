#include <stdio.h>
float nota1, nota2, notapf, media=0;

float mediaS(float not1, float not2){
    float soma1;
    soma1 = (nota1 + nota2)/2;
    return soma1;
}

float mediapf(float nota1, float nota2){
    float soma1 = 0;
    float notapf;
    printf("Por favor insira a nota da pf: ");
    scanf("%f", &notapf);
    return soma1 = (nota1+nota2+notapf)/3;

}
void aprov(){
    printf("Aprovado!");
}
void reprov(){
    printf("Reprovado ;-;");
}
int main(){
    printf("Bem vindo ao sistema de verificação de situação acedêmica! ");
    printf("Por favor, insira a nota da prova 1: ");
    scanf("%f", &nota1);
    printf("Por favor, insira a nota da prova 2: ");
    scanf("%f", &nota2);

    
    media=mediaS(nota1, nota2);
    if(media<7){
        media = mediapf(nota1, nota2);
        if(media<5){
            reprov();
        }
        else{
            aprov();
        }
    }
    else{
        aprov();
    }
    return 0;
}