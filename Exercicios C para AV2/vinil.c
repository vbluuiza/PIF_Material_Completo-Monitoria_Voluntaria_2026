#include <stdio.h>
#include <stdlib.h>

#define TAM_STR 50

typedef struct {
    int codigo_vinil;
    int numero_prateleira;
    char nome_prateleira[TAM_STR];
} Prateleira;

typedef struct {
    int codigo_vinil;
    char titulo[TAM_STR];
    int quantidade_musicas;
    int foi_ouvido;          // 0 = não, 1 = sim
    char nome_musica[TAM_STR];
    int ano;
} Vinil;

int main() {
    Vinil *vinis = NULL;
    Prateleira *prateleiras = NULL;
    int N, M;
    int i;

    /* =========================
       a) Leitura dos vinis com ponteiros
    ========================= */

    printf("Informe a quantidade de vinis (N): ");
    scanf("%d", &N);

    vinis = malloc(N * sizeof(Vinil));
    if (vinis == NULL) {
        printf("Erro ao alocar memória para vinis.\n");
        return 1;
    }

    Vinil *pv;  // ponteiro auxiliar para percorrer vinis

    pv = vinis;
    for (i = 0; i < N; i++, pv++) {
        printf("\n--- Vinil %d ---\n", i + 1);

        printf("Codigo do vinil: ");
        scanf("%d", &pv->codigo_vinil);

        printf("Título do vinil (sem espaços): ");
        scanf(" %49s", pv->titulo);

        printf("Quantidade de músicas: ");
        scanf("%d", &pv->quantidade_musicas);

        printf("Já foi ouvido? (0 = não, 1 = sim): ");
        scanf("%d", &pv->foi_ouvido);

        printf("Nome de uma música (sem espaços): ");
        scanf(" %49s", pv->nome_musica);

        printf("Ano de lançamento: ");
        scanf("%d", &pv->ano);
    }

    /* =========================
       Leitura das prateleiras com ponteiros
    ========================= */

    printf("\nInforme a quantidade de prateleiras (M): ");
    scanf("%d", &M);

    prateleiras = malloc(M * sizeof(Prateleira));
    if (prateleiras == NULL) {
        printf("Erro ao alocar memoria para prateleiras.\n");
        free(vinis);
        return 1;
    }

    Prateleira *pp;  // ponteiro auxiliar para percorrer prateleiras

    pp = prateleiras;
    for (i = 0; i < M; i++, pp++) {
        printf("\n--- Prateleira %d ---\n", i + 1);

        printf("Codigo do vinil desta prateleira: ");
        scanf("%d", &pp->codigo_vinil);

        printf("Numero da prateleira: ");
        scanf("%d", &pp->numero_prateleira);

        printf("Nome da prateleira (sem espaços): ");
        scanf(" %49s", pp->nome_prateleira);
    }

    /* =========================
       b) Filtrar vinis ouvidos, com prateleira e ano entre 2010 e 2020
    ========================= */

    printf("\n=== Vinis ouvidos, com prateleira, ano entre 2010 e 2020 ===\n");

    for (pv = vinis; pv < vinis + N; pv++) {
        if (pv->foi_ouvido == 1 && pv->ano > 2010 && pv->ano < 2020) {
            int encontrado = 0;

            for (pp = prateleiras; pp < prateleiras + M; pp++) {
                if (pp->codigo_vinil == pv->codigo_vinil) {
                    encontrado = 1;
                    break;
                }
            }

            if (encontrado) {
                printf("Título: %s (codigo %d, ano %d)\n",
                       pv->titulo,
                       pv->codigo_vinil,
                       pv->ano);
            }
        }
    }

    /* =========================
       c) Vinis ouvidos entre 1990 e 2010 (inclusive)
    ========================= */

    printf("\n=== Vinis ouvidos entre 1990 e 2010 (inclusive) ===\n");

    int contadorIntervalo = 0;

    for (pv = vinis; pv < vinis + N; pv++) {
        if (pv->foi_ouvido == 1 &&
            pv->ano >= 1990 &&
            pv->ano <= 2010) {

            printf("Codigo: %d | Título: %s | Ano: %d\n",
                   pv->codigo_vinil,
                   pv->titulo,
                   pv->ano);

            contadorIntervalo++;
        }
    }

    printf("Total de vinis encontrados no intervalo: %d\n", contadorIntervalo);

    /* =========================
       d) Atualizar flag 'foi_ouvido' com base no número da prateleira
    ========================= */

    int numero_busca;
    int atualizados = 0;

    printf("\nInforme um numero de prateleira para marcar vinis como ouvidos: ");
    scanf("%d", &numero_busca);

    for (pp = prateleiras; pp < prateleiras + M; pp++) {
        if (pp->numero_prateleira == numero_busca) {

            for (pv = vinis; pv < vinis + N; pv++) {
                if (pv->codigo_vinil == pp->codigo_vinil) {
                    if (pv->foi_ouvido == 0) {
                        pv->foi_ouvido = 1;
                        atualizados++;
                    }
                }
            }
        }
    }

    printf("Total de vinis marcados como 'ja ouvidos': %d\n", atualizados);

    /* =========================
       Libera memoria
    ========================= */

    free(prateleiras);
    free(vinis);

    return 0;
}
