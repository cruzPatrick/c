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

