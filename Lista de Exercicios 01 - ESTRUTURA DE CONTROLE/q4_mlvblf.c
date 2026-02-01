// Lista de Exercícios 1: Estruturas de controle
#include <stdio.h>

// 1042 | Sort Simples | Nível 2 | Peso 100 | OBRIGATÓRIA

int main(void) {
    int vals[3], orig[3];

    scanf("%d %d %d", &vals[0], &vals[1], &vals[2]);

    orig[0] = vals[0];
    orig[1] = vals[1];
    orig[2] = vals[2];
    
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (vals[i] > vals[j]) {
                int tmp = vals[i];
                vals[i] = vals[j];
                vals[j] = tmp;
            }
        }
    }

    printf("%d\n%d\n%d\n", vals[0], vals[1], vals[2]);

    printf("\n");

    printf("%d\n%d\n%d\n", orig[0], orig[1], orig[2]);

    return 0;
}