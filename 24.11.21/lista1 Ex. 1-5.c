//2024.11.21 - lista 1
//1 Faça uma função que receba como parametro os 2 num inteiros, calcule exiba e retorne a soma dos números
//2 Faça uma função que receba como parâmetros as 2 notas de um aluno (valores reais), calcule e retorne a média aritmética.
//3 Faça uma função que receba como parâmetros o preço unitário de um produto. Esta função deverá calcular e retornar o novo preço unitário considerando que 
//houve um aumento de 20% no preço unitário.
// 4) Faça a função calculaValor que receba como parâmetros o valor do litro de um combustível (número real)
//e a quantidade de litros abastecida por um cliente (número real). A função deverá calcular e exibir o valor a
//ser pago.
/*
5
a) Faça uma função que receba como parâmetros dois números inteiros: horas e minutos. Esta função deverá retornar o horário convertido em minutos.
b) Faça uma função que receba como parâmetros quatro números inteiros: horas e minutos do horário previsto de chegada de um vôo e horas e minutos do horário efetivo de chegada
de um vôo. Esta função
deverá utilizar, obrigatoriamente, a função anterior e retornar a diferença em minutos dos 2 horários.
Considere que o primeiro horário ocorre sempre antes do segundo.
*/

#include <stdio.h>
int exerci1(int num1, int num2){
    int soma = num1 + num2;
    printf("%d", soma);
    return soma;
}

float exerci2(float not1, float not2){
    float media = 0;
    return media = (not1+not2)/2;
}

float exercicio3(float preuni){
    return (preuni*0.2)+preuni;
}

float calculaValor(float litcomb, float qtdlit){
    printf("O valor a ser pago é %f", litcomb*qtdlit);
    return litcomb+qtdlit;
}

int hourcon(int hora, int min){
    int conv, ret;
    conv = hora*60;
    return conv + min;
}

int hourfly(int horaprev, int minprev, int horac, int minc){
    int chegadaprev = hourcon(horaprev, minprev);
    int chegadaefe = hourcon(horac, minc);
    return chegadaprev - chegadaefe;
    
}

void main()
{
    int num1, num2, hprev, mprev, hc, mc, test1, test2;
    float nota1, nota2, preuni, litcomb, qtdlit;
    /* Q1
    printf("Escreva os dois valores que você quer somar: ");
    scanf("%d %d", &num1, &num2);
    printf("\nO valor da soma é: %d", exerci1(num1, num2));
    */
    
    /* Q2
    printf("Entre com os valores das notas: ");
    scanf("%f %f", &nota1, &nota2);
    printf("%.2f",exerci2(nota1, nota2));
    */
    
    /* Q3
    printf("Escreva o valor do preço unitário: ");
    scanf("%f", &preuni);
    printf("%.2f", exercicio3(preuni));
    */
    
    /* Q4
    printf("Fale o valor do litro e quantos litros você colocou: ");
    scanf("%f %f", &litcomb, &qtdlit);
    calculaValor(litcomb, qtdlit);
    */
    //Q5
    /*
    
    */
    printf("escreva a quantidade de Horas e minutos: ");
    scanf("%d %d", &test1, &test2);
    printf("%d\n", hourcon(test1, test2));
    printf("Escreva a hora de prevista de chegada: ");
    scanf("%d %d", &hprev, &mprev);
    printf("Escreva a hora de chegada efetiva: ");
    scanf("%d %d", &hc, &mc);
    printf("%d\n", hourfly(hprev, mprev, hc, mc));
    
}