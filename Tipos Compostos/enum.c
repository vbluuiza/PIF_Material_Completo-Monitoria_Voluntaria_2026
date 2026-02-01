#include <stdio.h>

// Definição de enum
typedef enum  {
    OK = 1,
    ERRO = -1,
    PROCESSANDO = 0
} Status ;

int main() {
    Status resposta = ERRO;

    switch (resposta) {
        case OK:
            printf("Operação concluída com sucesso!.\n");
            break;
        case ERRO:
            printf("Ocorreu um erro.\n");
            break;
        case PROCESSANDO:
            printf("Ainda processando...\n");
            break;
    }

    return 0;
}