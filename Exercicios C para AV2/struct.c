#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int duracao;
} Aula;

typedef struct {
    char titulo[50];
    int qtdAlunos;
    Aula aula; // struct Aula dentro de Curso
} Curso;

int main() {
    Curso c;
    Curso *pc = &c; // ponteiro para Curso | cria um Curso e guarda o endereço dele em pc.
    // Agora pode usar pc->campo

    // Preenchendo o curso
    strcpy(pc->titulo, "Programação em C"); // campo de Curso
    pc->qtdAlunos = 40;

    // Acessando a struct interna (Aula)
    strcpy(pc->aula.nome, "Introdução a Ponteiros"); // pc->aula → acessa a struct interna / pc->aula.nome → acessa o campo dentro da struct interna
    pc->aula.duracao = 90;

    printf("Curso: %s\n", pc->titulo);
    printf("Qtd alunos: %d\n", pc->qtdAlunos);
    printf("Aula: %s\n", pc->aula.nome);
    printf("Duracao: %d minutos\n", pc->aula.duracao);

    return 0;
}
