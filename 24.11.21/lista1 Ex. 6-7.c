//2024.11.21 - lista 1
//6) Faça uma função que receba como parâmetro o número de dias decorrido em um evento e exiba o mesmo
//valor expresso em números de semanas e número de dias. Por exemplo, se o número de dias decorrido em
//um evento for o valor 19, a função deve exibir: “2 semanas e 5 dias"

//7) Faça uma função que receba como parâmetro o valor desejado a ser sacado em um caixa eletrônico por um
//cliente de um banco, calcule e exiba a menor quantidade de cédulas a ser recebida pelo cliente. Considere
//que o caixa eletrônico possui cédulas de R$100,00, R$50,00, R$20,00, R$10,00, R$5,00, R$2,00 e R$1,00.

#include <stdio.h>

void questao6(int dias){
    int semana, dia;
    semana = dias / 7;
    dia = dias%7;
    printf("%d semanas e %d dias", semana, dia);
}

void questao7 (float valdese){
    
}
void main()
{
    int valordias;
    float valor;
    printf("Escreva o valor de dias do evento: ")
    scanf("%d", &valordias);
    questao6(valordias);
    printf("Qual o valor que você quer sacar? ");
    scanf("%f", &valor)
}