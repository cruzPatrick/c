#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char** argv){
    FILE *f = fopen(argv[1], "r");
    char aux;
    int saldo = 0;

    if(!f){
        fprintf(stderr, "Erro ao abrir arquivo");
        return 1;
    }

    while(fread(&aux,sizeof(char), 1, f) == 1){
        saldo+= (aux == '{')? +1 : (aux == '}')? -1: 0;
        if(saldo<0)
            break;
    }
    
    if(saldo != 0)
        printf("Não está balanceado");
    else
        printf("Está balanceada");

    fclose(f);
    return 0;
}