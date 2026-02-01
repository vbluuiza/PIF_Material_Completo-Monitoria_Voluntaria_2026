#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int captadores;
    int trastes_acima12;
    char madeira;     // 'A' ou 'N'
    double distancia;
} Guitarra;

/* ------------------------ FUNÇÃO 1 ------------------------ */
/* Aloca matriz dinâmica NxN de Guitarra */
Guitarra** alocarMatriz(int N) {
    int i, j;
    Guitarra **m = malloc(N * sizeof(Guitarra*));
    if (m == NULL) return NULL;

    for (i = 0; i < N; i++) {
        m[i] = malloc(N * sizeof(Guitarra));
        if (m[i] == NULL) {
            // libera tudo que foi alocado antes
            for (j = 0; j < i; j++)
                free(m[j]);
            free(m);
            return NULL;
        }
    }
    return m;
}

/* ------------------------ FUNÇÃO 2 ------------------------ */
/* Preenche todos os campos da matriz */
void preencherGuitarras(Guitarra **m, int N) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            Guitarra *p = &m[i][j];

            printf("\n--- Guitarra %d,%d ---\n", i, j);

            printf("Captadores: ");
            scanf("%d", &p->captadores);

            printf("Trastes acima da 12ª casa: ");
            scanf("%d", &p->trastes_acima12);

            printf("Madeira (A/N): ");
            scanf(" %c", &p->madeira);

            p->distancia = (double)abs(i - j);
        }
    }
}

/* ------------------------ FUNÇÃO 3 ------------------------ */
/* Imprime preços e dados das guitarras */
void imprimirGuitarras(Guitarra **m, int N) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {

            Guitarra *p = &m[i][j];

            int valorMadeira = (p->madeira == 'N' || p->madeira == 'n') ? 300 : 120;

            double preco = (p->captadores * 80)
                         + (p->trastes_acima12 * 15)
                         +  valorMadeira
                         + (p->distancia * 25);

            printf("\nGuitarra (%d,%d):\n", i, j);
            printf("  Captadores: %d\n", p->captadores);
            printf("  Trastes acima 12: %d\n", p->trastes_acima12);
            printf("  Madeira: %c\n", p->madeira);
            printf("  Distância: %.2lf\n", p->distancia);
            printf("  Preço: R$ %.2lf\n", preco);
        }
    }
}

/* ------------------------ FUNÇÃO 4 ------------------------ */
/* Libera a matriz dinâmica */
void liberarMatriz(Guitarra **m, int N) {
    for (int i = 0; i < N; i++)
        free(m[i]);
    free(m);
}

/* ------------------------ MAIN ------------------------ */

int main() {
    int N;
    printf("Dimensão do lote (NxN): ");
    scanf("%d", &N);

    Guitarra **guitarras = alocarMatriz(N);

    if (guitarras == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    preencherGuitarras(guitarras, N);
    imprimirGuitarras(guitarras, N);

    liberarMatriz(guitarras, N);

    return 0;
}
