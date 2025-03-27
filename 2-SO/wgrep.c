#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(int argc, char *argv[]){
    if(argc <= 1){
        printf("wgrep: searchterm [file ...]");
        exit(1);
    }

    char *termo = argv[1];
    char linha[];

    if(argc == 2){
        while(getline(linha, sizeof(linha), stdin)){
            if(strstr(linha, termo) != NULL){
                printf("%s", linha);
            }
        }
        return 0;
    }

    for(int = 2; i < argc; i++){
        FILE *fp = fopen(argv[i], "r");
        if(fp == NULL){
            printf("wgrep: cannot open file");
            exit(1);
        }
        
    }


    return 0;
}