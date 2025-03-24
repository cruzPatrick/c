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
/*
códigos que estavam errados da questao 7, mas fiz 
void questao7 (int saque){ primeira tentativa
    int valor, resto;
    resto = saque % 100;
    valor = saque/100; 
    resto += (valor%50);
    valor = saque / 50;
    resto += (valor%20);
    valor = saque / 20;
    resto += (valor%10);
    valor = saque / 10;
    resto += (valor%5);
    valor = saque / 5;
    resto += (valor%2);
    valor = saque/1;
    resto += (valor%1);
    printf("A menor quantidade de cedulas será: %d", resto);
}
int main(){

    printf("Qual o valor que você quer sacar? ");
    scanf("%d", &valor);
    questao7(valor);
    return 0;
}



void questao7 (int saque){ versao 2.0
    int cedulas100 = saque/100;
    int restante = saque%100;

    int cedulas50 = restante/50;
    restante = restante %50;

    int cedulas20 = restante/20;
    restante %= 20;

    int cedulas10 = restante/10;
    restante %= 10;

    int cedulas5 = restante/5;
    restante %= 5;

    int cedulas2 = restante/2;
    restante %= 2;

    int cedulas = restante/1;
    restante %=1;

    int soma = cedulas100+cedulas50+cedulas20+cedulas10+cedulas5+cedulas2+cedulas;
    printf("A menor quantidade de cedulas será: %d, para o valor %d", soma, saque);
}
 */

void questao7 (int saque){
    int cedulas100 = saque/100;
    int restante = saque%100;

    int cedulas50 = restante/50;
    restante %= 50;

    int cedulas20 = restante/20;
    restante %= 20;

    int cedulas10 = restante/10;
    restante %= 10;

    int cedulas5 = restante/5;
    restante %= 5;

    int cedulas2 = restante/2;
    restante %= 2;

    int cedulas = restante;

    int soma = cedulas100+cedulas50+cedulas20+cedulas10+cedulas5+cedulas2+cedulas;
    printf("A menor quantidade de cedulas sera: %d, para o valor %d", soma, saque);
    printf("São:\n%d de 100\n%d de 50\n%d de 20\n%d de 10\n%d de 5\n%d de 2\n%d de 1", cedulas100, cedulas50, cedulas20, cedulas10, cedulas5, cedulas2, cedulas);
}
int main(){
    int valordias, valor;
    printf("Escreva o valor de dias do evento: ");
    scanf("%d", &valordias);
    questao6(valordias);
    printf("Qual o valor que você quer sacar? ");
    scanf("%d", &valor);
    questao7(valor);
    return 0;
}