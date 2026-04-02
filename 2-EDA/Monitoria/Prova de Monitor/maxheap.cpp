#include <iostream>

using namespace std;

void troca(int *a, int *b);
void descer(int a[], int i, int q);
void heapsort(int a[], int n);
void heap(int a[], int t);

int main (){
    int array[5] = {5, 10, 4, 23, 100};

    cout << "O array atualmente é: " ;
    for(int i=0; i<5;i++)
        cout << array[i] << " ";
    

    heapsort(array, 5);


    cout << "Agora temos o array organizado em ordem crescente :D";
     for(int i=0; i<5;i++)
        cout << array[i]<< " ";


    return 0;
}


void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

//a é o array, i a posição e q é o ultimo indice válido do array
void descer (int a[], int i, int q){

    int d = 2*i + 2; // 2+2 =4
    int e = 2*i + 1;//3

    int maior = i;//maior = 1

    if (d <= q && a[d] > a[maior]) //4 é <= 4? SIM e 100 é maior que 10? SIM
        maior = d; //maior = 4

    if (e <= q && a[e] > a[maior]) // 3 é menor ou igual que 4? SIM e 23 é maior que 100? NÃO
        maior = e;
    if (maior != i){ // 4 é diferente de 1? SIM
        troca (&a[i], &a[maior]); // troca de posição -> 10 com 100 -> array fica 5 100 4 23 10
        descer (a, maior, q); // a = (5, 100, 4, 23, 10), maior = 4, q=4 entramos em mais um estado da pilha 
    }

}

void heap(int a[], int t){ // ele é O(n), porque a maioria dos nós estão perto da folha, assim descendo pouco
    for(int i = t/2 - 1; i >= 0; i--){ // a escolha de t/2 -1 é porque estamos discartando folhas, pois folhas JÁ são heaps triviais
        descer(a, i, t-1); //  (5, 10, 4, 23, 100) 5/2 =2-1 =1 -> i=1-> 10 -> passando vai o vetor 5 10 4 23 100, o i é 1 e o t = 4
    }
}

void heapsort(int a[], int n){
    int i;
    heap(a, n);
    for(i = n - 1; i > 0; i--){ // n-1 pois o ultimo indice válido é n-1, começar em n gera memoria invalida e i>0 e não i>= 0 porque se não temos o problema de acessar descer com i valendo -1
        troca(&a[0], &a[i]);
        descer(a, 0, i-1);
    }
}