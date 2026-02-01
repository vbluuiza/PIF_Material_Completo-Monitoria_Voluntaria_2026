#include <stdio.h>

int main() {
    int scores_size;
    int scores[] = {100, 90, 80, 70, 60};

    scores_size = sizeof(scores) / sizeof(scores[0]);
    printf("Tamanho do sizeof(scores): %d", sizeof(scores));
    printf("Tamanho do sizeof(scores[0]): %d\n", sizeof(scores[0]));
    
    for (int i = 0; i < scores_size; i++) {
        printf("Posição %d | Score: %d\n", i, scores[i]);
    }

    return 0;
}