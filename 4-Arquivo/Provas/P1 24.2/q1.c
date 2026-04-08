#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct _animal animal;



struct _animal{
    int id;
    char especie[30];
    char nome[30];
    int idade;
    float peso;

};





void busca(){

    FILE *f = fopen("animais.dat", "rb");

    animal a;

    int idR, achou = 0;

    scanf("%d", &idR);

    while(fread(&a, sizeof(animal), 1, f) == 1){

        if(idR == a.id){

            printf("Animal encontra!");

            printf("Especie: %s\nIdade: %d\nNome: %s\nPeso: %.2fkg\n", a.especie, a.idade, a.nome, a.peso);

            achou = 1;

            break;

        }
    }

    if(achou != 1)
        printf("Animal não encontrado");

    fclose(f);
}


int existeID(FILE *f, int idR){
    animal a;
    int achou = 0;

    while(fread(&a, sizeof(animal), 1, f) == 1){
        if(idR == a.id){
            return 1;
        }
    }
    return 0;
}

void inserir(){
    FILE *f = fopen("animais.dat", "rb+");
    animal aux;

    printf("Escreva o valor de ID\n");
    scanf("%d", &aux.id);
    while(existeID(f, aux.id) != 0){
        printf("Insira um ID válido, esse já está sendo utilizado");
        scanf("%d", &aux.id);
        rewind(f);
    }
    rewind(f);
    fseek(f, 0, SEEK_END);
    
    printf("Qual especie do animal?\n");
    scanf("%s", aux.especie);

    printf("Qual a idade do animal?\n");
    scanf("%d", &aux.idade);

    printf("Qual o nome do animal?\n");
    scanf("%s", aux.nome);

    printf("Qual o peso do animal?\n");
    scanf("%f", &aux.peso);



    fwrite(&aux,sizeof(animal), 1, f);
}

void alterar(){
    FILE *f = fopen("animais.dat", "rb+");
    animal a, aux;
    int idS, achou = 0;

    printf("Qual o ID que deseja procurar?");
    scanf("%d", &idS);

    while(fread(&a, sizeof(animal), 1, f)==1){
        if(a.id == idS){
            printf("Animal encontrado\n");
            printf("Especie: %s\nNome: %s\nIdade: %d\nPeso:%.2fKG", a.especie, a.nome, a.idade, a.peso);
            printf("Escreva a Especie, o nome, a idade, e o peso desse novo animal (nessa ordem)");
            scanf("%s %s %d %f", a.especie, a.nome, &a.idade, &a.peso);
            fseek(f, -sizeof(animal), SEEK_CUR);
            fwrite(&a,sizeof(animal), 1, f);
            printf("Atualização\nEspecie: %s\nNome: %s\nIdade: %d\nPeso:%.2fKG", a.especie, a.nome, a.idade, a.peso);
            
            achou = 1;
            break;
        }
    }
    if(achou == 0)
        printf("Animal não encontrado!");
    
    fclose(f);
}


int main(int argc, char** argv){
    
    return 0;
}