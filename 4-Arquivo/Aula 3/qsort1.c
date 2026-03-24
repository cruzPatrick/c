#include <stdio.h>
#include <string.h>
//Objetivo é dividir em duas partes e organizar do inicio até a metade e depois um outro arquivo da metade+1 até o final
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

int compara(const void *e1, const void *e2){
    return strncmp(((Endereco*)e1)->cep, ((Endereco*)e2)->cep, 8);
}


int main(int argc, char** argv){

    FILE *f, *saida;
    Endereco *e;

    long posicao, qtd, metade;

    f = fopen("cep.dat", "rb"); // abre o arquivo no modo leitura binária
    fseek(f, 0, SEEK_END); // pega do inicio e vai pro final 
    posicao = ftell(f); // pega a posição do final que é retornarda como long
    qtd = posicao/sizeof(Endereco); // como quero saber a quantidade de coisas dentro, divido pela estrutura, pois nesse arquivo em especifico tem 72, mas tem coisas que são uma letra
    e = (Endereco*) malloc(qtd*sizeof(Endereco)); // Aqui o e recebe o tamanho dos dados
    rewind(f); // volta pro inicio = fseek(f, 0, SEEK_SET)

    if(fread(e, sizeof(Endereco), qtd, f) == qtd){ //ler do final, pegando o tamanho da estrutura, a quantidade de elementos no arquivo e o inicio
        printf("Lido = OK");
    }
    qsort(e, qtd, sizeof(Endereco), compara);
    printf("Ordenado = ok");
    saida = fopen("cep-ordenado.dat", "wb");
    fwrite(e, sizeof(Endereco), qtd, saida);
    fclose(saida);
    free(e);

    return 0;
}