#include <stdio.h>
#include <string.h>

int main() {
    int i;
    char nome[20] = "jogador";
    FILE *arquivo;
    arquivo = fopen("dados.txt", "w");
    
    for (i=0; i < 10; i++) {
        fprintf(arquivo, "%s %d\n", nome, i);
    }
    fclose(arquivo);

    arquivo = fopen("dados.txt", "r");

    while(fscanf(arquivo, "%19s %d", nome, &i) == 2) {
        printf("%s %d\n", nome, i);
    }

    fclose(arquivo);

    return 0;
}