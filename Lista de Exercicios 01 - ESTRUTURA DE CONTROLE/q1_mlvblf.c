// Lista de Exercícios 1: Estruturas de controle
#include <stdio.h>

// 1013 | O maior | Nível 3 | Peso 100 | OBRIGATÓRIA
int main(void) {
 
    int val1, val2, val3, maiorAB, maior;
    
    scanf("%d", &val1);
    scanf("%d", &val2);
    scanf("%d", &val3);
 
    maiorAB = (val1 + val2 + abs(val1 - val2)) / 2;
    maior = (maiorAB + val3 + abs (maiorAB - val3)) / 2;
    
    printf("%d eh o maior\n", maior);
    return 0;
}