// | 2108 - Contando Caracters

#include <stdio.h>
#include <string.h>

int main() {
    char row[101];
    char biggest_word[101] = "";
    int biggest_len = 0;

    while (fgets(row, sizeof(row), stdin)) {
        row[strcspn(row, "\n")] = '\0';

        if (strcmp(row, "0") == 0) {
            break;
        }

        char *palavra = strtok(row, " ");
        int primeira = 1;

        while (palavra != NULL) {
            int tamanho = strlen(palavra);

            if (!primeira) {
                printf("-");
            }
            printf("%d", tamanho);
            primeira = 0;

            if (tamanho >= biggest_len) {
                biggest_len = tamanho;
                strcpy(biggest_word, palavra);
            }

            palavra = strtok(NULL, " ");
        }

        printf("\n");
    }

    printf("\nThe biggest word: %s\n", biggest_word);

    return 0;
}
