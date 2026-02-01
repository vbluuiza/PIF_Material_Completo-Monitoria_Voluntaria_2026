#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// 1049 - Uso obrigatório de um enum para representar as categorias de animais e uma struct para armazenar as características.

typedef enum {
    VERTEBRADO,
    INVERTEBRADO
} Categoria;

typedef enum {
    AVE,
    MAMIFERO,
    INSETO,
    ANELIDEO
} Tipo;

typedef enum {
    CARNIVORO,
    ONIVORO,
    HEMATOFAGO,
    HERBIVORO
} Alimentacao;

typedef struct {
    char nome[50];
    Categoria categoria;
    Tipo tipo;
    Alimentacao alimentacao;
} Animal;

int main() {
    char word1[50], word2[50], word3[50];
    scanf("%s", word1);
    scanf("%s", word2);
    scanf("%s", word3);

    Animal animais[] = {
        {"aguia", VERTEBRADO, AVE, CARNIVORO},
        {"pomba", VERTEBRADO, AVE, ONIVORO},
        {"homem", VERTEBRADO, MAMIFERO, ONIVORO},
        {"vaca", VERTEBRADO, MAMIFERO, HERBIVORO},
        {"pulga", INVERTEBRADO, INSETO, HEMATOFAGO},
        {"lagarta", INVERTEBRADO, INSETO, HERBIVORO},
        {"sanguessuga", INVERTEBRADO, ANELIDEO, HEMATOFAGO},
        {"minhoca", INVERTEBRADO, ANELIDEO, ONIVORO}
    };

    Categoria cat;
    Tipo tipo;
    Alimentacao alim;

    if (strcmp(word1, "vertebrado") == 0) {
        cat = VERTEBRADO;
    }    
    else {
        cat = INVERTEBRADO;
    }

    if (strcmp(word2, "ave") == 0)
        tipo = AVE;
    else if (strcmp(word2, "mamifero") == 0)
        tipo = MAMIFERO;
    else if (strcmp(word2, "inseto") == 0)
        tipo = INSETO;
    else
        tipo = ANELIDEO;

    if (strcmp(word3, "carnivoro") == 0)
        alim = CARNIVORO;
    else if (strcmp(word3, "onivoro") == 0)
        alim = ONIVORO;
    else if (strcmp(word3, "herbivoro") == 0)
        alim = HERBIVORO;
    else
        alim = HEMATOFAGO;

    for (int i = 0; i < 8; i++) {
        if (animais[i].categoria == cat && 
            animais[i].tipo == tipo &&
            animais[i].alimentacao == alim) {
                printf("%s\n", animais[i].nome);
                break;
            }
    }
    
    return 0;
}