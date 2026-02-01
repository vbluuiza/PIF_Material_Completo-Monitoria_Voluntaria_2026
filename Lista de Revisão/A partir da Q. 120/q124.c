#include <stdio.h>

typedef enum {
    JANEIRO = 1,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
} Mes;

int main() {
    int num;

    printf("Digite o número do mês (1 a 12): ");
    scanf("%d", &num);

    switch(num){
        case JANEIRO:    printf("Janeiro\n"); break;
        case FEVEREIRO:  printf("Fevereiro\n"); break;
        case MARCO:      printf("Março\n"); break;
        case ABRIL:      printf("Abril\n"); break;
        case MAIO:       printf("Maio\n"); break;
        case JUNHO:      printf("Junho\n"); break;
        case JULHO:      printf("Julho\n"); break;
        case AGOSTO:     printf("Agosto\n"); break;
        case SETEMBRO:   printf("Setembro\n"); break;
        case OUTUBRO:    printf("Outubro\n"); break;
        case NOVEMBRO:   printf("Novembro\n"); break;
        case DEZEMBRO:   printf("Dezembro\n"); break;
        default:         printf("Mês inválido!\n"); break;
    }

    return 0;
}