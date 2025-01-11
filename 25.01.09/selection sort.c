//selection sort ele vai selecionar o menor ou o maior elemento 
//dever de casa, implementar bsuca binária e sequencial e tbm ordenação por seleção
#include <stdio.h>
void sort(v[], qt){
    int fim = qt-1;
    for(int inicio = 0; inicio < fim; inicio++){
        int menor = incio;
        for(i=inicio+1;i<=fim;i++){
            if(v[i]<v[menor])
                menor=i;
            if(menor != inicio){
                int aux = v[inicio];
                v[inicio] = v[menor];
                v[menor] = aux;
            }
        }
    }
}