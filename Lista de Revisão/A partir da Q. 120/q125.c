#include <stdio.h>
#include <string.h>

// Escreva um código em C que leia duas horas no formato HH:MM:SS (24 h), definindo-as como uma struct e imprima a diferença entre elas em segundos.

typedef struct {
    int h, m, s;
} Hora;


int hora_para_segundos(Hora t) {
    return t.h * 3600 + t.m * 60 + t.s;
}

int main() {
    Hora h1, h2;

    printf("Digite a primeira hora (HH:MM:SS): ");
    scanf("%d:%d:%d", &h1.h, &h1.m, &h1.s);

    printf("Digite a segunda hora (HH:MM:SS): ");
    scanf("%d:%d:%d", &h2.h, &h2.m, &h2.s);

    int t1 = hora_para_segundos(h1);
    int t2 = hora_para_segundos(h2);

    int diferenca = t1 - t2;
    if (diferenca < 0)
        diferenca = -diferenca;

    printf("Diferença entre as horas: %d segundos\n", diferenca);

}