//busca binária - lista precisa obrigatóriamente estar ordenado em crescente

//a repetição da busca binária é uma repetição indeterminada
/*
Sempre será a média do inicio e do fim para achar de forma mais eficiente
quando o valor procurado for maior que a media, o inicio será a media+1
quando o valor procurado for menor que a media, o final será media-1
*/

#include <stdio.h>
int buscabinaria(int v[], int qt, int want){
    int ini = 0;
    int fim = qt-1;
    while(fim>=ini){
        int meio = (ini + fim)/2;
        if(v[meio] == want)
            return meio;
        if(procurado>v[meio])
            inicio = meio+1;
        else
            fim = meio-1;
    }
    return -1;
}

void main(){
    
}