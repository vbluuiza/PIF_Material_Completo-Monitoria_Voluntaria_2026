// Lista de Exercícios 1: Estruturas de controle
#include <stdio.h>

// 1160 | Crescimento Populacional | Nível 5 | Peso 100 | OBRIGATÓRIA
int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        long long PA, PB;
        double G1, G2;
        scanf("%lld %lld %lf %lf", &PA, &PB, &G1, &G2);

        int anos = 0;
        while (PA <= PB && anos <= 100) {
            PA += (long long)(PA * (G1 / 100.0));
            PB += (long long)(PB * (G2 / 100.0)); 
            anos++;
        }

        if (anos > 100) {
            printf("Mais de 1 seculo.\n");
        } else {
            printf("%d anos.\n", anos);
        }
    }
    return 0;
}