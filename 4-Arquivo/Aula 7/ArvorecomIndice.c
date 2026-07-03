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
    ArvoreB* a = Arvore_Abre("Arvore.dat");
    FILE *f = fopen("cep1.dat", "rb");
    if(!f){
        fprintf(stderr, "Erro ao abrir");
        return 1;
    }
    Endereco e;


    fseek(f, 0, SEEK_END);
    long numB = ftell(f);
    long numR = numB/sizeof(Endereco);
    rewind(f);
    int posicao = 0;
    for(int i = 0; i< numR; i++){
        fread(&e, sizeof(Endereco), 1, f);
        ArvoreB_Insere(a, e.cep, posicao);
        posicao++;
    }
    fclose(f);
    ArvoreB_Fecha(a);

    return 0;
}