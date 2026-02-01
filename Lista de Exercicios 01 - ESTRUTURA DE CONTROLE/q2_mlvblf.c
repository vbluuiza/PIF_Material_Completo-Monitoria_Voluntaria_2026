// Lista de Exercícios 1: Estruturas de controle
#include <stdio.h>
#include <math.h>

// 1021 | Notas e Moedas | Nível 6 | Peso 100 | OPCIONAL
int main(void) {
 
    float val;
    scanf("%f", &val);
    
    int total = (int)(val * 100.0 + 0.5);
    
    int notas[] = {10000, 5000, 2000, 1000, 500, 200};
    int moedas[] = {100, 50, 25, 10, 5, 1};
    
    printf("NOTAS:\n");
    for (int i = 0; i < 6; i++) {
        int qtd = total / notas[i];
        total %= notas[i];
        printf("%d nota(s) de R$ %.2f\n", qtd, notas[i] / 100.0);
    }

    printf("MOEDAS:\n");
    for (int i = 0; i < 6; i++) {
        int qtd = total / moedas[i];
        total %= moedas[i];
        printf("%d moeda(s) de R$ %.2f\n", qtd, moedas[i] / 100.0);
    }
    
    return 0;
}