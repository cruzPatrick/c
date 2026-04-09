#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _s S;

struct _s{
    int matricula;
};



int main(int argc, char** argv){
    FILE *arq1, *arq2, *saida;
    S ea, eb;

    arq1 = fopen("Arquivo1.dat", "rb");
    arq2 = fopen("Arquivo2.dat", "rb");
    saida = fopen("Resultado.dat", "wb");

    fseek(arq2, 0, SEEK_END);
    long tamanho = ftell(arq2);
    long posicao = tamanho/sizeof(S);
    long meio;
    
    fread(&eb, sizeof(S), 1, arq2);
    int achou = 0;

    while(fread(&ea,sizeof(S), 1, arq1) == 1){
        long inicio = 0;
        long fim = posicao - 1;
        while(fim >= inicio){
            meio = (inicio + fim)/2;
            fseek(arq2, meio*sizeof(S), SEEK_SET);
            fread(&eb, sizeof(S), 1, arq2);
           
            if(ea.matricula == eb.matricula){
               achou = 1;
               break;
            }
            else{
                if(ea.matricula < eb.matricula)
                    fim = meio - 1;
                else
                    inicio = meio + 1;
            }
        }
        if(achou == 0){
            fwrite(&ea,sizeof(S), 1, saida);
        }
    }

    fclose(arq1);
    fclose(arq2);
    fclose(saida);

}