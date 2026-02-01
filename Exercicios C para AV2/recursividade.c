#include <stdio.h>

int fatorial(int n){
    if (n == 0) {
        return 1; // Caso base
    }
    return n * fatorial(n - 1); // Passo recursivo
}

int potencia(int a, int b) {
    if (b == 0) {
        return 1; // Caso base
    }

    return a * potencia(a, b - 1); // Passo recursivo
}

int fibonacci(int n) {
    if (n == 0) {
        return 0; // Caso base 1
    }
    if (n == 1) {
        return 1; // Caso base 2
    }

    return fibonacci(n - 1) + fibonacci(n - 2); // Passo recursivo;
}

int main() {
    int num;
    printf("Digite um número para calcular o fatorial: ");
    scanf("%d", &num);
    int resultado = fatorial(num);
    printf("Fatorial de %d é %d\n", num, resultado);

    int a, b, n;

    printf("Digite base e expoente: ");
    scanf("%d %d", &a, &b);
    printf("%d^%d = %d\n", a, b, potencia(a, b));
    printf("\n");

    printf("Digite n para Fibonacci: ");
    scanf("%d", &n);
    printf("Fib(%d) = %d\n", n, fibonacci(n));


    return 0;
}