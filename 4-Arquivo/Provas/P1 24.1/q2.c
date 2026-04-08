#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void crialetras(){
    FILE *f = fopen("letras.dat", "wb");

    if (f == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    fwrite(alfabeto, sizeof(char), 26, f);

    fclose(f);
    printf("Arquivo 'letras.dat' criado com sucesso (26 bytes).\n");

}

int main(int argc, char** argv){
    crialetras();
    char bloco[3] = { '\0' };
    FILE* f = fopen("letras.dat","rb");
    fseek(f,-2,SEEK_END);
    fread(bloco,sizeof(char),3,f);
    printf("(a) %3.3s %ld %d\n", bloco, ftell(f), feof(f));
    fseek(f,-3,SEEK_END);
    fread(bloco,sizeof(char),3,f);
    printf("(b) %3.3s %ld %d\n", bloco, ftell(f), feof(f));
    fseek(f,10,SEEK_SET);
    fread(bloco,sizeof(char),3,f);
    printf("(c) %3.3s %ld %d\n", bloco, ftell(f), feof(f));
    fread(bloco,sizeof(char),3,f);
    printf("(d) %3.3s %ld %d\n", bloco, ftell(f), feof(f));
    fseek(f,-3,SEEK_CUR);
    fread(bloco,sizeof(char),3,f);
    printf("(e) %3.3s %ld %d\n", bloco, ftell(f), feof(f));
    fclose(f);
    return 0;
}