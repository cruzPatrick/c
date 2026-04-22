#include <iostream>

/*
Respostas:
1) (A) O(1)
2) (B) A inserção no final é sempre O(1)
3) (A) Acessar elemento o elemento na posição i
4) (C) O(n)
5) Um array não é dinâmico, então se quero adicionar ele vai ser menos eficiente uma vez que chega no seu limite, LSE é mais tranquila quanto a isso, pois é alocação dinamica na memória, porem para achar o valor é pior, pois precisa percorrer toda a lista, enquanto o array é mais eficiente pelo indice
6) Você basicamente vai pegar e analisar onde exatamente quer inserir, no inicio e vazio é simples, pois é só adicionar, no final precisa rodar até o final e colocar lá. já no meio é o mais complexo, pois demanda comparação dos valores no meio e precisa tomar cuidado para não perder o resto da lista
7) Pois por ser ordenada eu tenho uma noção de onde estará o valor que quero, poupando bastante tempo e não precisando necessariamente ir até o final
8) Não é viável, pois acessar o meio da lista demoraria, o que mata o propósito da busca binária fazendo com que de log n fosse n


12) Bubble sort, quicksort, selection sort, insertion sort 
13) quicksorte, mergersort
14) mergesort
15) Busca Sequencial passará um por um enquanto a busca binária está constantemente dividndo o array em partes usando dividir pra conquistar

*/