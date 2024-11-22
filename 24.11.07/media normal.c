#include <stdio.h>
float nota1, nota2, notapf, media;
main()
{
    printf("Bem vindo ao sistema de verificação de situação acedêmica! ");
    printf("Por favor, insira a nota da prova 1: ");
    scanf("%f", &nota1);
    printf("Por favor, insira a nota da prova 2: ");
    scanf("%f", &nota2);
    
    media=(nota1+nota2)/2;
    if(media<7){
        printf("Por favor, insira a nota da PF: ");
        scanf("%f", &notapf);
        media = (nota1+nota2+notapf)/3;
        if(media<5){
            printf("Reprovado ;-;");
        }
        else{
            printf("Aprovado!");
        }
    }
    else{
        printf("Aprovado!");
    }

}
