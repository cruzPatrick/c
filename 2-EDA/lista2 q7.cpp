/*
7.Construa uma função que insira sempre em ordem crescente.
    Minhas ideias pra resolver:
    fazer um algoritmo para achar onde esse valor tem que entrar (usar menor/maior?)
    Se lista for NULL esse vai ser o maior valor
    se tiver um, tenho que descobrir se fica a esquerda ou se fica a direita
    se tiver mais de um eu choro em posição fetal pq a lista já tem que estar ordenada
*/
#include <iostream>
using namespace std;

struct no{
    int info;
    struct no* prox;
};
typedef struct no* noPtr;
noPtr topo = NULL;
