#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int quartos;
    int banheiros;
    char acabamento; // 'B' Básico, 'P' Premium
    int distancia;   // Distância até a diagonal princiapl
} Casa;

int main(){
    int N, i, j;
    printf("Dimensão da matriz: ");
    scanf("%d", &N);

    // Alocar dinamicamente uma matriz NxN de struct Casa
    Casa **condominio; // condominio é um Casa ** (ponteiro para ponteiro). Então condominio é um vetor de ponteiros para Casa
    condominio = malloc(N * sizeof(Casa*));
    if (condominio == NULL) {printf("Erro ao alocar memória.\n"); return 1;}

    // B) Receba do usuário a dimensão N
    for (i = 0; i < N; i++){
        condominio[i] = malloc(N * sizeof(Casa));
        if (condominio[i] == NULL) {
            printf("Erro ao alocar memória.\n"); 
            for (int j = 0; j < i; j++) {
                free(condominio[j]);
            }
            free(condominio);
            return 1;
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            Casa *p = &condominio[i][j]; // = Casa *p = &(*(*(condominio + i) + j));

            printf("\nCasa %d,%d\n", i, j);

            printf("Quartos: ");
            scanf("%d", &p->quartos);

            printf("Banheiros: ");
            scanf("%d", &p->banheiros);

            printf("Acabamento (P/B): ");
            scanf(" %c", &p->acabamento);

            p->distancia = abs(i - j);
        }
    }

    // D) Calcule e imprima o preço de cada casa
    printf("\nPreços das casas no condomínio:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            Casa *p = &condominio[i][j]; // = Casa *p = &(*(*(condominio + i) + j));

            int valorAcabamento;
            if(&p->acabamento == 'P' || &p->acabamento == 'p') {
                valorAcabamento = 200;
            }
            else{valorAcabamento == 100;}

            double preco = (p->quartos * 20) + (p->banheiros * 30) + valorAcabamento + (p->distancia * 10);

            printf("Casa (%d,%d): Quartos = %d, Banheiros = %d, Acabamento = %c, D=%d -> Preco = %d\n",
                   i, j,
                   p->quartos,
                   p->banheiros,
                   p->acabamento,
                   p->distancia,
                   preco);
        }
    }
    // Liberar memória alocada
    for (i = 0; i < N; i++) {
        free(condominio[i]);
    }
    free(condominio);
    condominio = NULL;

    return 0;
}