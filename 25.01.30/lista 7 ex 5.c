#include <stdio.h>
#include <string.h>

struct depto{
    int qtd;
    float soma;
};
typedef struct depto Tdepto;

void media(Tdepto depart[30]){
    float media[30];
    for(int i = 0; i < 30; i++){
        if(depart[i].qtd>0){
            media[i] = depart[i].soma/depart[i].qtd;
        }
        else{
            media[i] = 0;
        }
        printf("O departamento %d, teve como a média salarial de: %f", i+1, media[i]);
    }
}


int main(){
    Tdepto depart[30];
    for(int i = 0; i < 30; i++){
        printf("Quantos funcionários tem? ");
        scanf("%d", &depart[i].qtd);
        printf("Qual a soma dos salários do departamento: ");
        scanf("%f", &depart[i].soma);
    }
    media(depart);
    return 0;
}
//O GPT só corrigiu o caso de divisão por zero que não havia colocado e corrigido coisas do compilador