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


11) resumindo é só pegar o inserir da pilha e fazer um chines simples, está no pdf
12) Bubble sort, quicksort, selection sort, insertion sort 
13) quicksorte, mergersort
14) mergesort
15) Busca Sequencial passará um por um enquanto a busca binária está constantemente dividndo o array em partes usando dividir pra conquistar
16) está no pdf
*/

//9) Pilha
using namespace std;
struct no {
     int info; 
     struct no * prox;
};
typedef struct no * noPtr; 
noPtr topo = NULL;

bool listaVazia(){
    if(topo == nullptr)//pode ser NULL
        return true;
    else
        return false;
}

void insercao() {
    noPtr p; 
    int valor;

    p = new no;
    cout << "Digite o valor: ";
    cin>> valor; //poderia ser p->info
    p->info = valor;
    p->prox = topo;
    topo = p;
}

void remocao(){
    noPtr p = topo; 
    if (!listaVazia()) {
        topo = topo->prox; 
        delete(p);
        cout<<"Elemento retirado"<<endl;
    }
    else 
        cout<<"\nLista Vazia!"<<endl;
}

void mostrarLista(){
    if(topo == nullptr){
        cout<<"Lista vazia"<<endl;
        return;
    }

    noPtr aux = topo;
    while(aux != nullptr){
        cout<<"Valor:" << aux->info <<"\n";
        aux = aux->prox; 
    }
}

//10 Lista Ordenada

void inserirOrdenada() {
    noPtr aux, ant, p = new no;
    cout << "Digite o valor do elemento: "; cin >> p->info; 
    if (listaVazia()){ //lista sem elementos 
        p->prox = topo; 
        topo = p;
    }
    else { // tem elementos
        aux = topo;
        while(aux !=NULL && p->info>aux->info){//roda a lista para pegar a posição
            ant = aux;
            aux = aux->prox;
        }
        if(aux == topo){ //menor valor de todos
            p->prox = aux;
            topo = p;
        }
        else{ //meio ou final
            p->prox = aux;
            ant->prox = p;
        }
   }
}

void consultarOrdenada() { 
    noPtr p = topo; 
    int x; 
    bool achei = false;
    if (!listaVazia()) { 
        cout << "Digite o elemento: "; 
        cin >> x; 
        while (p != NULL && achei == false) { 
            if (p->info == x) { 
                cout << "Elemento encontrado"; 
                achei = true;
            } 
            p = p->prox; 
        }
        if (!achei) 
            cout << "Elemento não encontrado";
    }
    else 
        cout << "Lista Vazia!"; 
}

//17)

struct peca{
    int numeroDaPeca;
    struct peca *prox;
};
typedef struct peca* pecaPtr;
pecaPtr fila = nullptr;

bool filaVazia(){
    if(fila == nullptr)//pode ser NULL
        return true;
    else
        return false;
}

void montar(){ //aqui se recebesse o numero da peça como parametro e só alocasse o valor no ponteiro estaria tudo bem e é até melhor, mas decidi fazer isso para ficar mais igual ao que a professora deu em aula
    pecaPtr aux, p = new peca; 
    cout << "\nDigite o numero da peça: "; 
    cin >> p->numeroDaPeca;
    p->prox = NULL;
    if (filaVazia()) 
        fila = p;
    else { 
        aux = fila; 
        while(aux->prox != NULL) 
            aux = aux->prox;
        aux->prox = p; 
    } 
}

void desmontarTudo() { 
    pecaPtr p; 
    if (filaVazia()) 
        cout << "\nFila Vazia!";
    else {
        while(!filaVazia()){
            p = fila; 
            fila = p -> prox; //topo = topo->prox 
            delete p; 
            cout << "\nO elemento foi retirado da fila!\n";
        }
    } 
}