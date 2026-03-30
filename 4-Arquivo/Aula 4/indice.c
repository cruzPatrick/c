#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Endereco Endereco;
typedef struct _Indice Indice;

//O que eu preciso fazer, colocar um indice, dividir o arquivo pelo indice criado, depois ordenar os indices, por fim fazer a buscabinaria pelo indice
struct _Endereco{
    char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
};

struct _Indice{
	char cep[8];
	int ind;
};

int compara(const void *a, const void *b);
int buscaBinaria(Indice *ind, int total, char *cep);

int main(int argc, char**argv){

    FILE *file, *saida;
	Endereco e;

	file = fopen("cep.dat", "rb");

	if(!file){
		fprintf(stderr, "Erro ao abrir arquivo\n");
		return 1;
	}

	fseek(file, 0, SEEK_END);
	long tamanho = ftell(file);
	int total = tamanho / sizeof(Endereco);
	rewind(file);

	Indice *in = malloc(sizeof(Indice)*total); // vetor da struct indices
	if(in == NULL){
		fprintf(stderr, "Erro!\n");
		return 1;
	}
	int i = 0;
	while(fread(&e, sizeof(Endereco), 1, file) == 1){//seria melhor for pq eu sei o tamanho total, mas eu quero fazer com for
		strncpy(in[i].cep,e.cep, 8);
		in[i].ind = i;
		i++;
	}

	qsort(in, total, sizeof(Indice), compara);
	saida = fopen("indice_ordenado.dat", "wb");
	if(!saida){
		printf("Erro ao abrir");
		return 1;
	}
	fwrite(in, sizeof(Indice), total, saida);

	fclose(file);
	fclose(saida);

    return 0;
}

int compara(const void *a, const void *b){
	return strncmp(((Indice*)a)->cep, ((Indice*)b)->cep, 8);
}