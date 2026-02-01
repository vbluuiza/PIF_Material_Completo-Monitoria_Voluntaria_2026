#include <stdio.h>

int main(void) {
    int L;              // linha escolhida pelo usuário (0 a 11)
    char T;             // operação (S ou M)
    float M[12][12];    // matriz 12x12
    float soma = 0.0;   // acumulador da soma


    // lê o número da linha que será processada
    scanf("%d", &L);
    if (L < 0 || L > 11) {
        return 1;
    }

    // lê o caractere da operação
    // espaço antes de %c é para ignorar o ENTER da leitura anterior
    scanf(" %c", &T);   
    if (T != 'S' && T != 'M') {
        return 1;
    }


    // leitura dos 144 números da matriz (12 linhas × 12 colunas)
    for (int i = 0; i < 12; i++) {      // percorre cada linha
        for (int j = 0; j < 12; j++) {  // percorre cada coluna da linha
            scanf("%f", &M[i][j]);      // guarda o valor na posição [i][j]
        }
    }

    // percorre apenas a linha escolhida (L)
    for (int j = 0; j < 12; j++) {
        soma += M[L][j]; // soma = soma + M[L][j];
    }

    // imprime o resultado de acordo com a operação
    if (T == 'S') {
        printf("%.1f\n", soma);         // se operação for soma
    } else if (T == 'M') {
        printf("%.1f\n", soma / 12.0);  // se operação for média (divide por 12)
    }

    return 0;
}
