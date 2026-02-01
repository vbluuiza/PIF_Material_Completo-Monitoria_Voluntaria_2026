#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Implemente um procedimento que converta todos os caracteres de uma string para maiúsculo sem usar o procedimento strupr.

void to_upper(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        s[i] = toupper(s[i]);
        i++;
    }
}

int main() {
    char texto[] = "Quero comer uma costela do outback";
    to_upper(texto);
    printf("%s\n", texto);
}