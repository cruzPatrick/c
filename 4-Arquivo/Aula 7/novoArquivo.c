#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ArvoreB.h>

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
    ArvoreB* a = ArvoreB_Abre("Arvore.dat");
    FILE *f = fopen("cep2.dat", "rb"), *f2 = fopen("cep1.dat", "rb"), *saida = fopen("final.dat", "wb");
    Endereco e;

    fseek(f, 0, SEEK_END);

    long numB = ftell(f);
    long numR = numB/sizeof(Endereco);
    rewind(f);
    long val;
    for(int i = 0; i < numR; i++){
        fread(&e, sizeof(Endereco), 1, f);
        val = ArvoreB_Busca(a, e.cep);
        if(val != -1){
            fwrite(&e, sizeof(Endereco), 1, saida);
        }
    }


    fclose(f);
    fclose(f2);
    fclose(saida);
    ArvoreB_Fecha(a);
    return 0;
}