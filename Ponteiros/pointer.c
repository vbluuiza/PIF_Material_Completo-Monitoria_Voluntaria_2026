#include <stdio.h>

int main() {

    int a = 5;
    int *p = &a;

    printf("Endereço de memória de A: %p\n", &a);
    printf("Valor armazenado em p %p\n", p);
    printf("Endereço de memória de p %p\n", &p);

    printf("Valor da variavel A: %d\n", a);
    printf("Valor desreferenciado de p: %d\n", *p);

    int b = 10;
    // * -> desreferencia (pega o valor guardado no endereco de memoria que o ponteiro armazena)
    // * -> criar um ponteiro
    // & -> obter um endereco de memoria
    // %p -> printar o endereco de memoria
    // Podemos manipular as variaves pelos ponteiros

    *p = *p + b;
    printf("Novo valor de A: %d\n", a);
}