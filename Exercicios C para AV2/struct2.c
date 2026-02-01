#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int duracao;
} Aula;

typedef struct {
    char titulo[50];
    int qtdAlunos;
    int qtdAulas;
    Aula *aulas;   // <-- ponteiro para vetor dinâmico de Aulas
} Curso;

int main() {
    Curso curso;
    Curso *pc = &curso;

    strcpy(pc->titulo, "Estruturas de Dados");
    pc->qtdAlunos = 35;

    printf("Quantas aulas o curso tem? ");
    scanf("%d", &pc->qtdAulas);

    // Alocação dinâmica do vetor de Aulas
    pc->aulas = malloc(pc->qtdAulas * sizeof(Aula));

    if (pc->aulas == NULL) {
        printf("Erro ao alocar aulas.\n");
        return 1;
    }

    // Preencher as aulas
    for (int i = 0; i < pc->qtdAulas; i++) {
        printf("\nAula %d\n", i+1); // pc->aulas[i] é uma struct Aula

        printf("Nome da aula: ");
        scanf(" %[^\n]", pc->aulas[i].nome); // pc->aulas[i].nome é o nome daquela aula

        printf("Duracao da aula (min): ");
        scanf("%d", &pc->aulas[i].duracao); // pc->aulas[i].duracao é a duração daquela aula
    }

    printf("\n=== Curso ===\n");
    printf("Titulo: %s\n", pc->titulo);
    printf("Qtd alunos: %d\n", pc->qtdAlunos);
    printf("Aulas:\n");

    for (int i = 0; i < pc->qtdAulas; i++) {
        printf("  Aula %d: %s (%d min)\n", i + 1,
               pc->aulas[i].nome,
               pc->aulas[i].duracao);
    }

    // Liberar memória
    free(pc->aulas);
    pc->aulas = NULL;

    return 0;
}
