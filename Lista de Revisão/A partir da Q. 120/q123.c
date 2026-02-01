#include <stdio.h>

// Crie um programa que leia N números e use uma função para calcular o máximo divisor comum (MDC) de todos eles.

int calcular_mdc(int n[], int size) {
    int mdc = n[0]; // Começa assumindo que o MDC inicial é o primeiro número do vetor

    for (int i = 1; i < size; i++) {
        int a = mdc;    // 'a' recebe o MDC atual (inicialmente o primeiro número)
        int b = n[i];   // 'b' recebe o próximo número do vetor

        // Algoritmo de Euclides: calcula o MDC entre 'a' e 'b'
        while (b != 0) {
            int temp = b;
            b = a % b;  // Atualiza b com o resto da divisão de a por b
            a = temp;   // Atualiza a com o valor anterior de b
        }
        mdc = a;        // Quando b chega a 0, o MDC entre os dois números está em 'a'
    }
    return mdc;
}

int main() {

    int N;
    printf("Quantos números deseja informar? ");
    scanf("%d", &N);

    int numeros[N];

    printf("Digite os %d números:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &numeros[i]);
    }

    int resultado = calcular_mdc(numeros, N);
    printf("MDC: %d\n", resultado);

    return 0;
}