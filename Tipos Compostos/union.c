#include <stdio.h>

// Definição de union
union Data {
    int inteiro;
    float real;
    char letra;
};

int main() {

    union Data d;
    d.inteiro = 42;
    printf("Memória %p\n", &d.inteiro);
    printf("Inteiro: %d\n", d.inteiro);
    
    d.real = 3.14; // Sobrescreve a memória
    printf("Memória %p\n", &d.real);
    printf("Real: %.2f\n", d.real);

    return 0;
}