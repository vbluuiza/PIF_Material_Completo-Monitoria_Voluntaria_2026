#include <stdio.h>

#include <string.h> // biblioteca necessária para funções de string

#include <ctype.h>


int main() {
    char str1[] = "hello";
    char str2[] = "hello";
    char str3[] = "world";
    int result;

    result = strcmp(str1, str2);
    if (result == 0) {
        printf("str1 e str2 são iguais\n");
    }

    result = strcmp(str1, str3);
    if (result < 0) {
        printf("str1 vem antes de str3 na ordem alfabética\n");
    }

    return 0;
    //%[^\name]
}

