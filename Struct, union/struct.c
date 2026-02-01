#include <stdio.h>

// numero: 5

struct Aluno {
    char nome[40];
    char sala[10];
    int nota;
};

typedef struct {
    char marca[50];
    int nota;
} Carro;

int main() {

    struct Aluno aluno1 = {"Luiza", "Regular", 10};
    printf("Nome: %s\n", aluno1.nome);
    printf("Sala: %s\n", aluno1.sala);
    printf("Nota: %d\n", aluno1.nota);
    
    Carro carro1 = {"Honda", 9};
    printf("Nota: %d\n", carro1.nota);
    printf("Marca: %s\n", carro1.marca);

    Carro carros[] = {
        {"Honda", 10},
        {"JEEP", 0},
        {"BMW", 7},
    };
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf("Marca: %s | Nota: %d\n", carros[i].marca, carros[i].nota);
    }
}