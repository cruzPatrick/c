#include <stdio.h>
float soma (float a, float b){
    float c = a+b;
    return c;
    //poderia ser return a+b; pois a função fica redundante fazer esse float c = a+b
}

float soma2 (float a, float b){
    return a+b;
}

int f(){
    return 5;
}


int main(){
    float num1, num2;
    printf("a soma de 1 + 2 é: %.0f, e de quebra toma um número: %d. \t%0.f", soma(1.0,2), f());
    printf("Escreva um número");
    scanf("%f", &num1);
    printf("Escreva outro número");
    scanf("%f", &num2);
    printf("%f + %f = %f", num1, num2, soma2(num1, num2));
}

//Da para colocar o float antes para avisar o compilador que existe a função, 
//ele vai esperar até encontrar o float com mesmo nome dentro do código (isso serve para quando há mais de um arq.c). 
//Por Ex.:


/**

float soma (float, float);

int main(){

bla
bla
bla


flaot(a ,b);

bla
bla
bla

}

flaot soma (float a, float b){
    return a+b;
}
**/
