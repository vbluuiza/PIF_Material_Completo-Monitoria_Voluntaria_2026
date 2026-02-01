#include <stdio.h>
#include <string.h>

// 1581 - Uso obrigatório de struct para armazenar o nome e o idioma de cada participante.


typedef struct {
    char idioma[20];
} Participante;

int main() {
    int N, K;
    scanf("%d", &N);

    while(N--) {
        scanf("%d", &K);

        Participante primeiro;
        scanf("%s", primeiro.idioma);
        
        int todos_iguais = 1;
        for (int i = 1; i < K; i++) {
            Participante p;
            scanf("%s", p.idioma);
            if (strcmp(p.idioma, primeiro.idioma) != 0) {
                todos_iguais = 0;
            }
        }

        if (todos_iguais)
            printf("%s\n", primeiro.idioma);
        else
            printf("ingles\n");
    }

    return 0;
}