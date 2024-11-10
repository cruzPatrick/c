#include <stdio.h>
int var;
int menu(){
    int opt = 0, cont = 1;
    printf("----Bem vindo ao menu!----\n");
    printf("Escolha um das opções para poder usar nosso menu: \n1)Buscar Cliente\n2)Cadastra Cliente\n3)Relatório\n4)Excluir Cadastro\n5)Sair\n");
    scanf("%d", &opt);
    while(opt<1 || opt>5){
        printf("escreva um valor válido, até agora já errou %d vezes: ", cont);
        scanf("%d", &opt);
        cont++;
    }
    return opt;
}
int main(){
    var = menu();
    printf("%d", var);
    return 0;
}