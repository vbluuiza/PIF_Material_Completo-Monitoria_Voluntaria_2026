#include <stdio.h>

#define MAX_VINIS 100
#define MAX_PRATELEIRAS 100

typedef struct {
    int codigo_vinil;          	 // código do vinil guardado nesta prateleira
    int numero_prateleira;    	 // número físico da prateleira
    char nome_prateleira[50]; 	 // nome descritivo da prateleira
} Prateleira;

typedef struct {
    int codigo_vinil;         	 // código do vinil
    char titulo[50];          	 // título do vinil
    int quantidade_musicas;    // quantidade de músicas no vinil
    int foi_ouvido;            	// flag: 0 = ainda não foi ouvido, 1 = já foi ouvido
    char nome_musica[50];      // nome de uma música (por exemplo, favorita)
    int ano;                  	// ano de lançamento do vinil
} Vinil;

int main() {
    Vinil vinis[MAX_VINIS];
    Prateleira prateleiras[MAX_PRATELEIRAS];

    int N, M;
    int i, j;

    /* =========================
       a) Leitura dos vinis
       ========================= */

    printf("Informe a quantidade de vinis (N): ");
    scanf("%d", &N);

    if (N > MAX_VINIS) {
        printf("Quantidade de vinis excede o limite máximo (%d).\n", MAX_VINIS);
        return 1;
    }

    for (i = 0; i < N; i++) {
        printf("\n--- Vinil %d ---\n", i + 1);

        printf("Codigo do vinil: ");
        scanf("%d", &vinis[i].codigo_vinil);

        printf("Titulo do vinil: ");
        scanf(" %[^\n]", vinis[i].titulo);

        printf("Quantidade de musicas: ");
        scanf("%d", &vinis[i].quantidade_musicas);

        printf("Ja foi ouvido? (0 = não, 1 = sim): ");
        scanf("%d", &vinis[i].foi_ouvido);

        printf("Nome de uma música: ");
        scanf(" %[^\n]", vinis[i].nome_musica);

        printf("Ano de lançamento: ");
        scanf("%d", &vinis[i].ano);
    }

    /* Leitura das prateleiras (necessário para as letras b e d) */

    printf("\nInforme a quantidade de prateleiras (M): ");
    scanf("%d", &M);

    if (M > MAX_PRATELEIRAS) {
        printf("Quantidade de prateleiras excede o limite máximo (%d).\n", MAX_PRATELEIRAS);
        return 1;
    }

    for (i = 0; i < M; i++) {
        printf("\n--- Prateleira %d ---\n", i + 1);

        printf("Codigo do vinil desta prateleira: ");
        scanf("%d", & prateleiras[i].codigo_vinil);

        printf("Numero da prateleira: ");
        scanf("%d", & prateleiras[i].numero_prateleira);

        printf("Nome da prateleira: ");
        scanf(" %[^\n]", prateleiras[i].nome_prateleira);
    }

    /* =========================
       b) Vinis ouvidos na prateleira e entre 2010 e 2020
       ========================= */

    printf("\n=== Vinis ouvidos, na prateleira, com ano entre 2010 e 2020 ===\n");

    for (i = 0; i < N; i++) {
        if (vinis[i].foi_ouvido == 1 && vinis[i].ano > 2010 && vinis[i].ano < 2020) {
            int encontrado = 0;

            // verifica se existe alguma prateleira com o mesmo código de vinil
            for (j = 0; j < M; j++) {
                if (prateleiras[j].codigo_vinil == vinis[i].codigo_vinil) {
                    encontrado = 1;
                    break;
                }
            }

            if (encontrado) {
                printf("Titulo: %s (codigo %d, ano %d)\n",
                       vinis[i].titulo,
                       vinis[i].codigo_vinil,
                       vinis[i].ano);
            }
        }
    }

    /* =========================
       c) Listar vinis ouvidos entre 1990 e 2010 (inclusive)
       ========================= */

    printf("\n=== Vinis ouvidos entre 1990 e 2010 (inclusive) ===\n");

    int contadorIntervalo = 0;

    for (i = 0; i < N; i++) {
        if (vinis[i].foi_ouvido == 1 &&
            vinis[i].ano >= 1990 &&
            vinis[i].ano <= 2010) {

            printf("Codigo: %d | Título: %s | Ano: %d\n",
                   vinis[i].codigo_vinil,
                   vinis[i].titulo,
                   vinis[i].ano);

            contadorIntervalo++;
        }
    }

    printf("Total de vinis encontrados no intervalo: %d\n", contadorIntervalo);

    /* =========================
       d) Marcar como ouvidos por numero de prateleira
       ========================= */

    int numero_busca;
    int atualizados = 0;

    printf("\nInforme um numero de prateleira para marcar vinis como ouvidos: ");
    scanf("%d", &numero_busca);

    // percorre prateleiras com o número informado
    for (j = 0; j < M; j++) {
        if (prateleiras[j].numero_prateleira == numero_busca) {

            // para cada prateleira encontrada,
            // procura vinis com o mesmo codigo_vinil
            for (i = 0; i < N; i++) {
                if (vinis[i].codigo_vinil == prateleiras[j].codigo_vinil) {
                    if (vinis[i].foi_ouvido == 0) {
                        vinis[i].foi_ouvido = 1;
                        atualizados++;
                    }
                }
            }
        }
    }

    printf("Total de vinis marcados como 'já ouvidos': %d\n", atualizados);

    return 0;
}
