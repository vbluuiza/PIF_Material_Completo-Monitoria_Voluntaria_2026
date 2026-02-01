#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// a)
typedef struct {
    int captadores;
    int qtd_trastes;
    char madeira;
    int distancia; // distância da diagonal principal
} Guitarra;

// b)
int main() {
    printf("dimensão N, correspondente ao tamanho do lote: ");
    int N, i, j;
    scanf("%d", &N);

    Guitarra **guitarras;
    // *guitarra
    guitarras = malloc(N * sizeof(Guitarra*)); // [ * ] [ * ] [ * ] [ * ] ... (N posições)
    /*
    [guitarras[0] → ?]
    [guitarras[1] → ?]
    [guitarras[2] → ?]
    ...
    [guitarras[N-1] → ?]

    */
    if (guitarras == NULL) {printf("Erro ao alocar memória\n"); return 1;}
    
    for (i = 0; i < N; i++) {
        guitarras[i] = malloc(N * sizeof(Guitarra));
        /*
        guitarras[0] → [ G G G G G ... ]
        guitarras[1] → [ G G G G G ... ]
        guitarras[2] → [ G G G G G ... ]
        ...
        */

        if (guitarras[i] == NULL) {
            printf("Erro ao alocar memória\n");

            for (j = 0; j < i; j++){
                free(guitarras[j]);
            }
            free(guitarras);
        }
    }

    // b)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            Guitarra *p = &guitarras[i][j];

            printf("\n---Guitarra---\n");
            
            printf("Captadores: ");
            scanf("%d", &p->captadores);


            printf("Quantidade Trastes: ");
            scanf("%d", &p->qtd_trastes);


            printf("Tipo madeira (A/N): ");
            scanf(" %c", &p->madeira);

            p->distancia = abs(i - j);

        }
    }

    //d)
    for(i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            Guitarra *p = &guitarras[i][j];
            // preço  = (C × 80) + (T × 15) + M + (distância × 25)

            int valorAcrescentado = 0;
            if (p->madeira == 'N' || p->madeira == 'n') {
                valorAcrescentado = 300;
            }
            else {valorAcrescentado = 120;}

            int preco = (p->captadores * 80) + (p->qtd_trastes * 15) + valorAcrescentado + (p->distancia * 25);
            
            printf("\n---Guitarra [%d][%d]---\n", i, j);
            printf("Preço: %d\n", preco);

        }
    }

    // e)
    for (i = 0; i < N; i++) {
        free(guitarras[i]); // liberei cada linha
    }

    free(guitarras);
    guitarras = NULL;

    return 0;
}