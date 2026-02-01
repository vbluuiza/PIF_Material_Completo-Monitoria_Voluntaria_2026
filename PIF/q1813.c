#include <stdio.h>

int main(void) {

    char T;             // operação (S ou M)
    float M[12][12];    // matriz 12x12
    float soma = 0.0;   // acumulador da soma
    int cont = 0; // contador de elementos



    scanf(" %c", &T);   
    if (T != 'S' && T != 'M') {
        return 1;
    }

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%f", &M[i][j]);
        
        }
    }

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (j > i) {
                soma += M[i][j];
                cont ++;
            }
        }
    }

    if (T == 'S') {
        printf("%.1f\n", soma);       
    } else if (T == 'M') {
        printf("%.1f\n", soma / cont); 
    }
        

    return 0;
}