//q3: obrigatório definir uma função contarCedulas(int valor, int cedula) e chamá-la na main.
// Questão 1018
/*
Leia um valor inteiro. A seguir, calcule o menor número de notas possíveis (cédulas) no qual o valor pode ser decomposto. As notas consideradas são de 100, 50, 20, 10, 5, 2 e 1. A seguir mostre o valor lido e a relação de notas necessárias.
Entrada
O arquivo de entrada contém um valor inteiro N (0 < N < 1000000).
Saída
Imprima o valor lido e, em seguida, a quantidade mínima de notas de cada tipo necessárias, conforme o exemplo fornecido. Não esqueça de imprimir o fim de linha após cada linha, caso contrário seu programa apresentará a mensagem: “Presentation Error”.
Exemplo de Entrada	    Exemplo de Saída
576
                        576
                        5 nota(s) de R$ 100,00
                        1 nota(s) de R$ 50,00
                        1 nota(s) de R$ 20,00
                        0 nota(s) de R$ 10,00
                        1 nota(s) de R$ 5,00
                        0 nota(s) de R$ 2,00
                        1 nota(s) de R$ 1,00
*/

#include <stdio.h>

int contarCedulas(int valor, int cedula) {
    return valor / cedula;
}

int main() {
    int N;
    scanf("%d", &N);

    int valor = N;
    int cedulas[] = {100, 50, 20, 10, 5, 2, 1};

    printf("%d\n", N);

    for (int i = 0; i < 7; i++) {
        int qtd = contarCedulas(valor, cedulas[i]);
        printf("%d nota(s) de R$ %d,00\n", qtd, cedulas[i]);
        valor = valor % cedulas[i];
    }

    return 0;
}
