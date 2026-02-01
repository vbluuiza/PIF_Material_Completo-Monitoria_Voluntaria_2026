#include <stdio.h>

int main() {

    int numero;
    scanf("%d", &numero);
    printf("Valor da variável numero é: %d\n", numero);
    printf("Endereço de memória da variável numero: %p\n", &numero);

    int *ptr = &numero;
    printf("Endereço de memória armazenado em ptr: %p\n", ptr);
    printf("Endereço de memória da variável ptr: %p\n", &ptr);
    printf("Valor que a variável ptr guarda: %d\n", *ptr);

    int **sec_ptr = &ptr;
    printf("Endereço de memória armazenado em sec_ptr: %p\n", sec_ptr);
    printf("Endereço de memória da variável sec_ptr: %p\n", &sec_ptr);
    printf("Valor que a variável sec_ptr guarda: %d\n", **sec_ptr);

    return 0;
}