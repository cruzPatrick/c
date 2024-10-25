#include <stdio.h>
float val, desc, soma;

/**
float soma (float a, float b){
    
}
**/
int main(){
    printf("Escreva o valor do seu salário: ");
    scanf("%f", &val);
    if(val>=4664.68){
        desc = val*0.275;
        soma = val-desc;
        printf("Seu salário foi: %.2f, o valor a pagar será: %.2f e o valor do desconto foi %.2f ", val, soma, desc);
    }
    else{
        if(val>=3751.06){
            desc = val*0.225;
            soma = val-desc;
            printf("Seu salário foi: %.2f, o valor a pagar será: %.2f e o valor do desconto foi %.2f ", val, soma, desc);
        }
        else{
            if(val>=2826.66){
                desc = val*0.15;
                soma = val-desc;
                printf("Seu salário foi: %.2f, o valor a pagar será: %.2f e o valor do desconto foi %.2f ", val, soma, desc);
            }
            else{
                if(val>=1903.99){
                    desc = val*0.075;
                    soma = val-desc;
                    printf("Seu salário foi: %.2f, o valor a pagar será: %.2f e o valor do desconto foi %.2f ", val, soma, desc);
                }
                else{
                    printf("Seu salário foi: %.2f, o valor a pagar será: %.2f e o valor do desconto foi %.2f ", val);
                }
            }
        }
    }

}