#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//17
typedef struct _Materiais material;
struct _Materiais{//q1
    char ferramenta[18];
    int qtd;
    float custo;
};

void cria_arquivo(){ //q2
    FILE *f = fopen("ferramentas.dat", "wb");

    if(f == NULL){
        fprintf(stderr, "erro ao abrir");
        return;
    }

    material m; // poderia ser m = {0}
    m.custo = 0.0;
    strcpy(m.ferramenta, "");
    m.qtd = 0;
    for(int i = 0; i<100; i++){
        fwrite(&m, sizeof(material), 1, f);
    }
    fclose(f);
    printf("Arquivo criado\n");
}

void insere_registro(int indice, char ferramenta[], int quantidade, float valor){
    FILE *f = fopen("ferramentas.dat", "rb+");

    material m_lido;
    material m_novo;


    if(f == NULL){
        fprintf(stderr, "Erro ao abrir");
        return;
    }

    fseek(f, indice * sizeof(material), SEEK_SET);

    fread(&m_lido, sizeof(material), 1, f);
    if(strcmp(m_lido.ferramenta, "") == 0){
        m_novo.custo = valor;
        m_novo.qtd = quantidade;
        strcpy(m_novo.ferramenta, ferramenta);
        fseek(f, indice* sizeof(material), SEEK_SET);
        fwrite(&m_novo,sizeof(material), 1, f);
        fclose(f);
    }
    else{
        fprintf(stderr, "O campo está ocupado, retornando...\n");
        fclose(f);
        return;
    }
}

void lista_ferramentas(){
    FILE *f = fopen("ferramentas.dat","rb");

    if(!f){
        fprintf(stderr, "Erro ao abrir");
        return;
    }
    material m;
    fseek(f, 0, SEEK_END);
    long tamanho = ftell(f); //tamanho do arquivo
    long qtd = tamanho / sizeof(material); // isso me da a quantidade de elementos
    int soma = 0;
    int ferdif = 0;
    rewind(f);
    
    while(fread(&m, sizeof(material), 1, f) == 1){// não precisa do qtd pq não quero pegar todo de uma vez quero pegar só um registro de cada vez
        if(strcmp(m.ferramenta, "") != 0){
            printf("Ferramenta:%s\tCusto:%.2f\tQuantidade%d\n", m.ferramenta, m.custo, m.qtd);
            printf("Temos %d %s\n", m.qtd, m.ferramenta);
            ferdif++;
            soma += m.qtd;
        }
    }
    printf("Total de ferramentas = %d", soma);
    printf("Total de ferramentas Distintas= %d", ferdif);
    fclose(f);
}
