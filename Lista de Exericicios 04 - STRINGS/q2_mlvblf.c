// 2356 - Bactéria I

#include <stdio.h>
#include <string.h>

int main() {
    char D[101], S[101];
    char *ptr_subtring;

    while (scanf("%s", D) != EOF && scanf("%s", S) != EOF) {
        ptr_subtring = strstr(D, S);

        if (ptr_subtring != NULL) {
            printf("Resistente\n");
        } else {
            printf("Nao resistente\n");
        }
    }

    return 0;
}
