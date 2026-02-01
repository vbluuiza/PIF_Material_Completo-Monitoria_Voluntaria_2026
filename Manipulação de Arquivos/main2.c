#include <stdio.h>

int main() {
    int i;
    FILE *arquivo;

    // 1) Abre para escrita
    arquivo = fopen("dados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para escrita.\n");
        return 1;
    }

    // 2) Escreve
    for (i = 0; i < 10; i++) {
        fprintf(arquivo, "%d\n", i);
    }
    fclose(arquivo);

    // 3) Reabre para leitura
    arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para leitura.\n");
        return 1;
    }

    // 4) Lê e imprime
    while (fscanf(arquivo, "%d", &i) == 1) {
        printf("%d\n", i);
    }

    fclose(arquivo);
    return 0;
}
