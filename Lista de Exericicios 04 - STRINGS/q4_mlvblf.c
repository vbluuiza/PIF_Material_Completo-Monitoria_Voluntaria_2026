// 1556 - Removendo Letras

#include <stdio.h>
#include <string.h>

void combine(char word[], char comb[], int start, int depth, int n) {
    for (int i = start; i < n; i++) {
        comb[depth] = word[i];
        comb[depth + 1] = '\0';
        printf("%s\n", comb);
        combine(word, comb, i  + 1, depth + 1, n);
    }
}

int main() {
    char word[100];
    scanf("%s", word);
    int n = strlen(word);
    char comb[100];
    
    combine(word, comb, 0, 0, n);

    return 0;
}
