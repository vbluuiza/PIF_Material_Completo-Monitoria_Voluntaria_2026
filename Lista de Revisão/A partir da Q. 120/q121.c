#include <stdio.h>

// Escreva uma função que receba um vetor de structs Aluno { char nome[40]; float notas[3]; } e devolva o índice do aluno com maior média.

typedef struct {
    char nome[40];
    float notas[3];
} Aluno;

int aluno_maior_media(Aluno v[], int n) {
    int i, index = 0;
    float maior_media = 0.0;

    for (i = 0; i < n; i++) {
        // Calcula a média das 3 notas do aluno atual (na posição 'i' do vetor).
        float media = (v[i].notas[0] + v[i].notas[1] + v[i].notas[2]) / 3;

        if (media > maior_media) {
            maior_media = media;
            index = i; // Atualiza o índice para a posição do aluno atual.
        }
    }

    return index;
}

int main() {
    Aluno turma[3] = {
        {"Luiza", {8.0, 9.5, 10.0}},
        {"Marcello", {7.0, 8.0, 7.5}},
        {"Eliziane", {9.0, 9.0, 9.0}}
    };

    int cdf = aluno_maior_media(turma, 3);
    printf("Aluno com maior média: %s\n", turma[cdf].nome);
}
