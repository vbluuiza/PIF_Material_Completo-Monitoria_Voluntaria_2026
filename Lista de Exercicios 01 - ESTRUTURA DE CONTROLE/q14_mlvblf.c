// Lista de Exercícios 1: Estruturas de controle
#include <stdio.h>

// 1156 | Sequência S II | Nível 2 | Peso 100 | OBRIGATÓRIA
// S = 1 + 3/2 + 5/4 + 7/8 + ... + 39/?

int main(void) {

    double S = 1;
    double numerador = 3.0;
    double denominador = 2.0;

    while (numerador <= 39) {
        S += numerador / denominador;
        numerador += 2.0;
        denominador *= 2.0;
        
    }
    printf("S = %.2lf\n", S);
    
    return 0;
}