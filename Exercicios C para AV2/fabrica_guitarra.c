#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int captadores;             // quantidade de captadores
    int trastes_acima12;        // trastes acima da 12ª casa
    char madeira;               // 'A' = acessível, 'N' = nobre
    double distancia;           // distância até a diagonal principal
} Guitarra;

int main() {
    int N, i, j;
    printf("Dimensão do lote (NxN): ");
    scanf("%d", &N);

    Guitarra **guitarras;
    guitarras = malloc(N * sizeof(Guitarra*)); // aloca o vetor de ponteiros
    if (guitarras == NULL) {printf("Erro ao alocar memória\n"); return 1; }
    
    for (i = 0; i < N; i++) {
        guitarras[i] = malloc(N * sizeof(Guitarra));  // aloca cada guitarra

        if (guitarras[i] == NULL) {
            printf("Erro ao alocar memória\n");

            for (j = 0; j < i; j++) {
                free(guitarras[j]);
            }
            free(guitarras);
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            Guitarra *p = &guitarras[i][j];
            
            printf("\n---Guitarra---\n");

            printf("Captadores: ");
            scanf("%d", &p->captadores);

            printf("Quantidade Trastes: ");
            scanf("%d", &p->trastes_acima12);

            printf("Tipo madeira (A/N): ");
            scanf(" %c", &p->madeira);

            p->distancia = (double)abs(i - j);

        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            Guitarra *p = &guitarras[i][j];

            int valorAcrescentado;
            valorAcrescentado = (p->madeira == 'N' || p->madeira == 'n') ? 300 : 120;

            double preco = (p->captadores * 80) + (p->trastes_acima12 * 15) + valorAcrescentado + (p->distancia * 25);

            printf("Guitarra %d,%d: Captadores = %d | Trastes = %d | Madeira = %c | Distância = %lf | Preço = R$%.2lf\n", i, 
                                                                        j, 
                                                                        p->captadores, 
                                                                        p->trastes_acima12, 
                                                                        p-> madeira, 
                                                                        p->distancia,
                                                                        preco
                                                                    );
        }
    }
    for (i = 0; i < N; i++) {
        free(guitarras[i]);
    }
    free(guitarras);
    guitarras = NULL;

    return 0;
}