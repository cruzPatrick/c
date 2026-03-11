#include <iostream>

using namespace std;

// 2 4 25

void troca(int *a, int *b);
void descer(int a[], int i, int q);
void heap(int a[], int n);
void heapsort(int a[], int n);

int main (){
    int array[3] = {2, 4, 25};

    cout << "O array atualmente é: " ;
    for(int i=0; i<3;i++)
        cout << array[i] << " ";
    

    heapsort(array, 3);


    cout << "Agora temos o array organizado em ordem crescente :D\n";
     for(int i=0; i<3;i++)
        cout << array[i]<< " ";


    return 0;
}

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void descer(int a[], int i, int q){
    int d = 2*i + 2;
    int e = 2*i + 1;
    int maior = i;
    if (d <= q && a[d] > a[maior])
        maior = d; 
    if (e <= q && a[e] > a[maior])
        maior = e;
    if (maior != i){ 
        troca (&a[i], &a[maior]); 
        descer (a, maior, q);
    }
}

void heap(int a[], int t){ 
    for(int i = t/2 - 1; i >= 0; i--){ 
        descer(a, i, t-1);
    }
}


void heapsort(int a[], int n){
    heap(a, n);
    for(int i = n-1; i>0; i--){
        troca(&a[0], &a[i]);
        descer(a, 0, i-1);
    }
}

// /2/2/2/2/2/2/2/2/2/2 -> n/2^k = 1 -> n = 2^k log(n) -> melhorcaso e piorcaso e casomedio =  n*logn