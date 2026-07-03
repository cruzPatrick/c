#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _Endereco Endereco;

struct _Endereco
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2]; 
};

int main(int argc, char** argv){
    if(argc < 2){
        fprintf(stderr, "Não colocou o arquivo a ser lido");
        return 1;
    }
    FILE* f = fopen(argv[1], "rb"), *saida = fopen("cep1.dat", "wb"), *saida2 = fopen("cep2.dat", "wb");
    Endereco e;
    if(!f){
        fprintf(stderr, "Erro ao abrir arquivo");
        return 1;
    }
    fseek(f, 0, SEEK_END);
    long tamB = ftell(f);
    long tamReg = tamB/sizeof(Endereco);
    rewind(f);
    srand(time(NULL));
    long entra = 0;

    for(int i = 0; i<tamReg; i++){
        float randomN = 1.0 * rand()/RAND_MAX;
        fread(&e, sizeof(Endereco), 1, f);

        if(randomN < 0.8 && (entra%2) == 0){
            fwrite(&e, sizeof(Endereco), 1, saida);
        }
        if(randomN < 0.8 && (entra%2) != 0){
            fwrite(&e, sizeof(Endereco), 1, saida2);
        }
        entra++;
    }

    fclose(f);
    fclose(saida);
    fclose(saida2);

    return 0;
}