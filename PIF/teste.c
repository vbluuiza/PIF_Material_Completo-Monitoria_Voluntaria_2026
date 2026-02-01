#include <stdio.h>

int main() {
    int scores[5] = {0};

    for(int i = 0; i < 5; i ++) {
        printf("Enter a score: ");
        scanf("%d", &scores[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("Posição %d | Score: %d\n", i + 1, scores[i]);
    }

    return 0;
}