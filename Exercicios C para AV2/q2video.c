#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int codigo_vinil;
    int numero_prateleira;
    char nome_prateleira[50];
} Prateleira;

typedef struct {
    int codigo_vinil;
    char titulo[50];
    int quantidade_musicas;
    int foi_ouvido;         
    char nome_musica[50];
    int ano;
} Vinil;

int main() {
    Vinil *vinis = NULL;
    Prateleira *prateleiras = NULL;
    int N, M;
    int i;


    printf("Informe a quantidade de vinis (N): ");
    scanf("%d", &N);

    vinis = malloc(N * sizeof(Vinil));
    if (vinis == NULL) {
        printf("Erro ao alocar memória para vinis.\n");
        return 1;
    }

    Vinil *pv;  // ponteiro auxiliar para percorrer vinis

    pv = vinis; // pv = vinis = vinis[0]
    for (i = 0; i < N; i++, pv++) {
        printf("\n--- Vinil %d ---\n", i + 1);

        printf("Codigo do vinil: ");
        scanf("%d", &pv->codigo_vinil); // &((*pv).codigo_vinil)

        printf("Título do vinil: ");
        scanf(" %49[^\n]", pv->titulo);

        printf("Quantidade de músicas: ");
        scanf("%d", &pv->quantidade_musicas);

        printf("Já foi ouvido? (0 = não, 1 = sim): ");
        scanf("%d", &pv->foi_ouvido);

        printf("Nome de uma música: ");
        scanf(" %49[^\n]", pv->nome_musica);

        printf("Ano de lançamento: ");
        scanf("%d", &pv->ano);
    }

    // a)

    printf("\nInforme a quantidade de prateleiras (M): ");
    scanf("%d", &M);

    prateleiras = malloc(M * sizeof(Prateleira));
    if (prateleiras == NULL) {
        printf("Erro ao alocar memoria para prateleiras.\n");
        return 1;
    }

    Prateleira *pp;  // ponteiro auxiliar para percorrer prateleiras

    pp = prateleiras; // pp = prateleiras = prateleiras[0]
    for (i = 0; i < M; i++, pp++) {
        printf("\n--- Prateleira %d ---\n", i + 1);

        printf("Codigo do vinil desta prateleira: ");
        scanf("%d", &pp->codigo_vinil);

        printf("Numero da prateleira: ");
        scanf("%d", &pp->numero_prateleira);

        printf("Nome da prateleira: ");
        scanf(" %49[^\n]", pp->nome_prateleira);
    }

    // b)

    printf("\n=== Vinis ouvidos, com prateleira, ano entre 2010 e 2020 ===\n");

    for (pv = vinis; pv < vinis + N; pv++) { // pv = vinis[0] // pv++
        if (pv->foi_ouvido == 1 && pv->ano > 2010 && pv->ano < 2020) {
            int encontrado = 0;

            for (pp = prateleiras; pp < prateleiras + M; pp++) { // pp = prateleiras[0]
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

    // c)

    printf("\n=== Vinis ouvidos entre 1990 e 2010 (inclusive) ===\n");

    int contadorIntervalo = 0;

    for (pv = vinis; pv < vinis + N; pv++) { // pv = vinis = pv = vinis[0]
        if (pv->foi_ouvido == 1 &&
            pv->ano >= 1990 &&
            pv->ano <= 2010) {

            printf("Codigo: %d | Título: %s | Ano: %d\n",
                   pv->codigo_vinil,
                   pv->titulo,
                   pv->ano);

            contadorIntervalo++; // ++ = v = v + 1 // v++
        }
    }

    printf("Total de vinis encontrados no intervalo: %d\n", contadorIntervalo);

    // d)

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
    
    free(prateleiras);
    free(vinis);

    return 0;
}
