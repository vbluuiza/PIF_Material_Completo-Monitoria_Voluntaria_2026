#include <stdio.h>

// 1323 - Uso obrigatório de uma struct para representar a grade com seu tamanho e número de quadrados.

typedef struct {
    int tamanho;
    int total;
} Grade;

int calcularTotal(int n) {
    int soma = 0;
    for (int i = 1; i <= n; i++) {
        soma += (n - i + 1) * (n - i + 1);
    }
    
    return soma;
}

int main() {
    Grade grade;

    while (1) {
        scanf("%d", &grade.tamanho);
        if (grade.tamanho == 0) 
            break;

        grade.total = calcularTotal(grade.tamanho);

        printf("%d\n", grade.total);
    }

    return 0;

}