#include <stdio.h>
#include <string.h>

/*
strlen → tamanho da string.
strcpy / strncpy → copiar strings.
strcat / strncat → concatenar strings.
strcmp / strncmp → comparar strings.
strchr / strrchr → achar primeira e última ocorrência de um caractere.
strstr → achar uma substring dentro de outra string.
*/

int main() {
    // ===== strlen =====
    char palavra[] = "Luiza";
    printf("strlen -> Tamanho de '%s' = %lu\n\n", palavra, strlen(palavra));
    // Conta os caracteres (sem contar o '\0').

    // ===== strcpy e strncpy =====
    char origem[] = "Vieira";
    char destino1[20];
    char destino2[20];

    strcpy(destino1, origem);  // Copia a string inteira
    strncpy(destino2, origem, 3); // Copia só 3 chars
    destino2[3] = '\0'; // precisa finalizar manualmente

    printf("strcpy -> Copiando '%s' para destino1: %s\n", origem, destino1);
    printf("strncpy -> Copiando 3 chars de '%s' para destino2: %s\n\n", origem, destino2);

    // ===== strcat e strncat =====
    char nome[50] = "Luiza";
    char sobrenome[] = " Vieira";

    strcat(nome, sobrenome);  // Concatena string inteira
    printf("strcat -> Nome completo: %s\n", nome);

    strncat(nome, "12345", 2); // Concatena só 2 chars
    printf("strncat -> Depois de adicionar 2 chars: %s\n\n", nome);

    // ===== strcmp e strncmp =====
    char s1[] = "abc";
    char s2[] = "abc";
    char s3[] = "abd";

    printf("strcmp -> '%s' vs '%s' = %d (0 = iguais)\n", s1, s2, strcmp(s1, s2));
    printf("strcmp -> '%s' vs '%s' = %d (negativo = s1 < s3)\n\n", s1, s3, strcmp(s1, s3));

    // ===== strchr e strrchr =====
    char frase[] = "banana";

    char *ptr1 = strchr(frase, 'a');   // primeira ocorrência
    char *ptr2 = strrchr(frase, 'a');  // última ocorrência

    printf("strchr -> Primeira letra 'a' em '%s': posição %ld\n", frase, ptr1 - frase);
    printf("strrchr -> Última letra 'a' em '%s': posição %ld\n\n", frase, ptr2 - frase);

    // ===== strstr =====
    char texto[] = "programar em C é divertido";
    char *sub = strstr(texto, "C"); // procura substring

    if(sub != NULL) {
        printf("strstr -> Substring 'C' encontrada em: %s\n\n", sub);
    }

    return 0;
}
