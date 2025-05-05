#include <iostream>
using namespace std;

struct no{
    int info;
    struct no* prox;
};
typedef struct no* noPtr;

noPtr topo=NULL;