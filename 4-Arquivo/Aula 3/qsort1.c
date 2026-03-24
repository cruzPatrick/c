#include <stdio.h>
#include <stdlib.h>
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

 //Preciso garantir que seja um null pointer para o qsort funcionar, se não fica trocando de posição e da ruim, por isso se tem esse const void

int compara(const void *e1, const void *e2){ 
    return strncmp(((Endereco*)e1)->cep, ((Endereco*)e2)->cep, 8);
}


int main(int argc, char** argv){

    FILE *f, *saida, *x;
    Endereco *e;

    long posicao, qtd, metade;

    f = fopen("cep.dat", "rb"); // abre o arquivo no modo leitura binária

    if(!f){
        fprintf(stderr, "Arquivo %s não pode ser aberto para leitura \n", argv[1]);
        return 1;
    }

    fseek(f, 0, SEEK_END); // pega do inicio e vai pro final 
    posicao = ftell(f); // pega a posição do final que é retornarda como long
    
    // como quero saber a quantidade de coisas dentro, divido pela estrutura, pois nesse arquivo em especifico tem 72, mas tem coisas que são uma letra ↓
    qtd = posicao/sizeof(Endereco); 
    e = (Endereco*) malloc(qtd*sizeof(Endereco)); // Aqui o e recebe o tamanho dos dados


    //a ideia é pegar metade, que seria FILE *x fseek(x, metade, SEEK_SET) 

    metade = qtd/2;

    rewind(f); // volta pro inicio = fseek(f, 0, SEEK_SET)


    if(fread(e, sizeof(Endereco), metade, f) == metade){
        printf("Lido até a metade\n");
    }
    qsort(e, metade, sizeof(Endereco), compara);
    printf("Ordenado até a metade\n");
    x = fopen("cep-metade.dat", "wb");
    
    fwrite(e, sizeof(Endereco), qtd, x);

    long resto = qtd-metade;

    fseek(f, metade*sizeof(Endereco), SEEK_SET);
    if(fread(e, sizeof(Endereco), resto, f) == qtd){
        printf("Lido da metade até o final\n");
    }
    qsort(e, resto, sizeof(Endereco), compara);
    printf("Ordenado da metade pro final\n");

    saida = fopen("cep-metade-final.dat", "wb");
    fwrite(e,sizeof(Endereco), qtd, saida);

    fclose(saida);
    fclose(f);
    fclose(x);
    free(e);

    return 0;
}