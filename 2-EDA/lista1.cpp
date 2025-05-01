//Lista 1 de EDA

/*
1)
Usando como referência a explicação do algoritmo a seguir, 
faça uma função que ordene um array com 50 elementos inteiros. 
Informe a complexidade de pior caso do algoritmo desenvolvido. 
O algoritmo percorre o array e a cada comparação entre os elementos, verifica e, 
caso necessário, troca o maior elemento com o menor. 
Ao chegar na última posição do array e após realizar a verificação final, 
o menor elemento estará na primeira posição da lista. Depois, percorre o array, 
realiza as comparações e caso necessário faz as trocas. Ao alcançar o final desta rodada, 
o segundo menor valor estará na segunda posição do array. 
Este procedimento é realizado sucessivamente, 
até que a lista esteja toda classificada em ordem crescente.


selection sort
O(n²)


2. Usando como referência a explicação do algoritmo a seguir, faça uma função que ordene um array com 
20 elementos inteiros. Informe a complexidade de pior caso do algoritmo desenvolvido. 
O algoritmo percorre todo o array e a cada comparação entre os elementos, verifica e, 
caso necessário, marca o menor valor da lista. Ao chegar no último elemento e 
após realizar a verificação final, coloca o menor elemento selecionado na primeira posição da lista. 
Depois, percorre o array e seleciona o segundo menor valor da lista seguindo a mesma regra, 
para colocá-lo na segunda posição. Faz isso com o terceiro menor valor da lista e assim sucessivamente 
até que todos os elementos da lista sejam usados e que a lista fique classificada em ordem crescente.

dois chatbots disseram que é selection, mas vou continuar com o insertion pq quero praticar, 
mas o codigo tbm serviria

Insertion Sort (errado na real é selection)
O(n²)
*/

//para questão 1 e 2
#include <iostream>
using namespace std;
void selectionSort(int v[], int num){
    for(int i = 0; i<num-1; i++){
        int menor = i; 
        for(int j = i+1; j<num; j++)
            if(v[menor]>v[j])
                menor = j;
         int aux = v[i];
         v[i] = v[menor];
         v[menor] = aux;       
    }
}

/*
3)
Considere um algoritmo de ordenação que percorra um array de números inteiros da esquerda para a 
direita conforme o esquema de funcionamento a seguir.
Verifica-se se o elemento que está na 2ª posição é menor do que o que está na 1ª posição, ou seja, 
se o 5 é menor do que o 3. Como não é, então não há troca.

• Verifica-se se o elemento que está na 3ª posição é menor do que o que está na 2ª posição e na 1ª posição. 
Como o 4 é menor do que o 5 mas não é menor do que o 3, então o 5 troca de lugar com o 4.

• Verifica-se se o elemento que está na 4ª posição é menor do que os elementos anteriores, 
ou seja, se o 2 é menor do que o 5, do que o 4 e do que o 3. Como ele é menor do que 3, então o 5 passa a 
ocupar a posição do 2, o 4 ocupa a posição do 5 e o 3 ocupa a posição do 4, 
assim a posição do 3 fica vazia e o 2 passa para essa posição.
• Este processo se repete até que todos os elementos do array estejam ordenados.

Usando como referência a explicação anterior do algoritmo de ordenação, que parece com o embaralhamento 
de cartas, faça uma função que ordene um array com 10 elementos inteiros. 
Informe também a complexidade de pior caso do algoritmo criado.


Agora sim insertion sort e tbm é o(n²)

*/

void insertionSort(int v[], int num){
    for(int i = 1; i < num; i++){
        int chave = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] > chave){
            v[i + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

