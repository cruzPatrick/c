#include <stdio.h>

float a, desc;

float iprf(float val){
    if(val>=4664.68){
        desc = val*0.275;
        return desc-869.36;
    }
    else
        if(val>=3751.06){
            desc = val*0.225;
            return desc-636.13;
        }
        else
            if(val>=2826.66){
                desc = val*0.15;
                return desc-354.80;
            }
            else
                if(val >= 1903.99){
                    desc = val*0.15;
                    return desc-142.80;
                }
                else
                    return 0;
}

int main(){
    printf("Escreva o seu salário: ");
    scanf("%f", &a);
    printf("O valor a pagar de imposto será: %.2f", iprf(a));
}