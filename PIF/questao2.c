/* 
Substituição em Vetor I

Timelimit: 1
Faça um programa que leia um vetor X[10]. Substitua a seguir, todos os valores nulos e negativos do vetor X por 1. Em seguida mostre o vetor X.

Entrada
A entrada contém 10 valores inteiros, podendo ser positivos ou negativos.

Saída
Para cada posição do vetor, escreva "X[i] = x", onde i é a posição do vetor e x é o valor armazenado naquela posição.


*/

#include <stdio.h>

int main(void) {

    int valores[10] = {0};
    
    for (int i = 0; i < 10; i++) {
        scanf("%d", &valores[i]);
        if (valores[i] <= 0) {
            valores[i] = 1;
            printf("X[%d] = %d\n", i, valores[i]);
        }
        else {
            printf("X[%d] = %d\n", i, valores[i]);
        }
    }
    return 0;
}