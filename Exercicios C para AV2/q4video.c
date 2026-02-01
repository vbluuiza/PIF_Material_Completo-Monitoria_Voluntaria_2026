#include <stdio.h>

int fatorial(int n) {
    if (n == 0) 
        return 1; // Caso base
    else 
        return n * fatorial(n - 1); // Passo recursivo
}

int main() {
    int x;
    printf("Digite um valor: ");
    scanf("%d", &x);

    printf("Fatorial de %d = %d\n", x, fatorial(x));
    return 0;
}
