#include <stdio.h>
#include <string.h>

// 1332 - Uso obrigatório de enum para representar os números e uma struct para armazenar a palavra e sua correspondência numérica.

typedef enum {
    one = 1,
    two = 2,
    three = 3
} Numero;

typedef struct {
    char texto[20];
    Numero valor;
} Palavra;

int main() {
    int N;
    scanf("%d", &N);

    while(N--) {
        Palavra p;
        scanf("%s", p.texto);

        int len = strlen(p.texto);
        if (len == 5) {
            p.valor = three;
        }
        else {
            int ONE = 0;
            char ref[] = "one";

            for (int i = 0; i < 3; i++) {
                if (p.texto[i] == ref[i]) {
                    ONE++;
                }
            }

            if (ONE >= 2) {
                p.valor = one;
            }
            else {
                p.valor = two;
            }
        }
        printf("%d\n", p.valor);
    }

    return 0;
}