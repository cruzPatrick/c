#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Pagamento pagamento;

struct _Pagamento{
    char cpf[12];
    char nome[80];
    int mes;
    int ano;
    float valor;
};

float total_pago_mes_ano(int mes, int ano){
    pagamento total;
    float pago = 0;
    FILE *f = fopen("beneficios.dat", "rb");

    if(!f){
        fprintf(stderr, "ERRO!");
        return 0;
    }

    while(fread(&total, sizeof(pagamento), 1 , f) == 1){
        if(total.ano == ano && total.mes == mes)
            pago += total.valor;
        else
            if(total.ano > ano || (total.ano == ano &&total.mes > mes))
                break;
    }
    fclose(f);
    return pago;
}


int main(int argc, char** argv){
    FILE *f = fopen("beneficios.dat", "rb+");
    pagamento p, *aux;
    long tamtot, totreg;
    if(!f){
        fprintf(stderr, "Erro ao abrir!");
        return 1;
    }
    fseek(f, 0, SEEK_END);
    
    tamtot = ftell(f);
    totreg = tamtot / sizeof(pagamento);

    FILE *novo = fopen("novo.dat", "rb");
    fseek(novo, 0, SEEK_END);
    long novoTot = ftell(novo);
    long novoReg = novoTot / sizeof(pagamento);
    rewind(novo);


    aux = (pagamento*) malloc(novoReg*sizeof(pagamento));

    if(fread(aux,sizeof(pagamento), novoReg, novo) == novoReg)
        fwrite(aux, sizeof(pagamento), novoReg, f);
    

    free(aux);
    fclose(f);
    fclose(novo);
    return 0;
}
