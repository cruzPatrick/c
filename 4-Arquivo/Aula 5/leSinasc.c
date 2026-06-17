#define Teresina 221100
#define Curitiba 410690

// Peso medio ao nascer em teresina e curitiba 
// no ano de 2015

// Proporção de tipos de parto (9, 1 e 2).

// Quantos nascidos prematuros no ano de 2012 ? 
// < 37 semanas

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 2048

// index,CODMUNRES,data_nasc,PESO,SEMAGESTAC,adeq_peso_id_gestac,SEXO,IDANOMAL,RACACOR,ESCMAEAGR1,ESTCIVMAE,IDADEMAE,CONSULTAS,PARTO,STTRABPART,KOTELCHUCK,APGAR5,TPROBSON

struct DadosNascimento {
    int index;
    int CODMUNRES;
    char data_nasc[11];
    int PESO;
    int SEMAGESTAC;
    float adeq_peso_id_gestac;
    int SEXO;
    int IDANOMAL;
    int RACACOR;
    int ESCMAEAGR1;
    int ESTCIVMAE;
    int IDADEMAE;
    int CONSULTAS;
    int PARTO;
    int STTRABPART;
    int KOTELCHUCK;
    int APGAR5;
    int TPROBSON;
};

void separaData(char* data, int *dia, int *mes, int *ano)
{
    *ano = atoi(strtok(data,"-"));
    *mes = atoi(strtok(NULL,"-"));
    *dia = atoi(strtok(NULL,"-"));
}

float totalPesoTeresina = 0;
float totalPesoCuritiba = 0;
int contadorTeresina = 0;
int contadorCuritiba = 0;
int anoBusca = 2015;
//que eu fiz
float mediaCuritiba = 0;
float mediaTeresina = 0;
int prematuraT = 0;
int prematuroC = 0;
int parto1 = 0;
int parto2 = 0;
int parto9 = 0;

void processa(struct DadosNascimento* dn) {
    int dia, mes, ano;
    separaData(dn->data_nasc, &dia, &mes, &ano);
    if(ano == anoBusca && dn->CODMUNRES == Teresina) {
        contadorTeresina++;
        totalPesoTeresina += dn->PESO;
    }
    if(ano == anoBusca && dn->CODMUNRES == Curitiba){
        contadorCuritiba++;
        totalPesoCuritiba += dn->PESO;
    }
    
    //semana de gestação
    if(ano == 2012 && dn->CODMUNRES == Teresina && dn->SEMAGESTAC < 37) {
        prematuraT++;
    }
    if(ano == 2012 && dn->CODMUNRES == Curitiba && dn->SEMAGESTAC < 37) {
        prematuroC++;
    }


    if(ano == anoBusca && (dn->CODMUNRES == Teresina || dn->CODMUNRES == Curitiba)) {//prof não específica, vou de 2015 e coloquei de ambas
        switch(dn->PARTO) {
            case 1:
                parto1++;
                break;
            case 2:
                parto2++;
                break;
            case 9:
                parto9++;
                break;
            default:
                break;
        }
    }

//    printf("%d %d %d %d\n",dn->CODMUNRES, dia, mes, ano);
}

int main()
{
    char *prox = NULL;
    int lc = 0;
    static char buffer[MAX];
    struct DadosNascimento dn;
    char* linha[18]; //Array com 18 ponteiros para char -> Ele não guarda os textos, mas o endereço deles, por isso 18, 18 endereços diferentes
    int i;
    FILE *f = fopen("sinasc.csv","r");
    fgets(buffer,MAX,f); // ele lê até encontrar o \n, ou seja, a linha toda ou até o limite estourar, que é 2k, guarda a linha no buffer
    fgets(buffer,MAX,f);
    while(!feof(f)) {
        linha[0] = strtok_r(buffer,",\n",&prox);
        for(i=1; i<18; i++) {
            linha[i] = strtok_r(NULL,",\n",&prox);
            if(linha[i]==NULL) {
                linha[i]="";
            }
        }
        dn.index = atoi(linha[0]);
        dn.CODMUNRES = atoi(linha[1]);
        strcpy(dn.data_nasc,linha[2]);
        dn.PESO = atoi(linha[3]);
        dn.SEMAGESTAC = atoi(linha[4]);
        dn.adeq_peso_id_gestac = atof(linha[5]);
        dn.SEXO = atoi(linha[6]);
        dn.IDANOMAL = atoi(linha[7]);
        dn.RACACOR = atoi(linha[8]);
        dn.ESCMAEAGR1 = atoi(linha[9]);
        dn.ESTCIVMAE = atoi(linha[10]);
        dn.IDADEMAE = atoi(linha[11]);
        dn.CONSULTAS = atoi(linha[12]);
        dn.PARTO = atoi(linha[13]);
        dn.STTRABPART = atoi(linha[14]);
        dn.KOTELCHUCK = atoi(linha[15]);
        dn.APGAR5 = atoi(linha[16]);
        dn.TPROBSON = atoi(linha[17]);
        processa(&dn);
        lc++;
        fgets(buffer,MAX,f);
        if(lc%1000000 == 0) {
            printf(".");
            fflush(stdout);
        }
    }
    mediaCuritiba = totalPesoCuritiba / contadorCuritiba;
    mediaTeresina = totalPesoTeresina / contadorTeresina;
    fclose(f);
    printf("Contador Teresina: %d\n",contadorTeresina);
    printf("Total Lido: %d\n",lc);
    return 0;
}