// q5: obrigatório definir uma função calcularDuracao(double horaInicio, double minutoInicio, double horaFim, double minutoFim)
// Questão 1047
/*
Leia a hora inicial, minuto inicial, hora final e minuto final de um jogo. A seguir calcule a duração do jogo.
Obs: O jogo tem duração mínima de um (1) minuto e duração máxima de 24 horas.

Entrada
Quatro números inteiros representando a hora de início e fim do jogo.

Saída
Mostre a seguinte mensagem: “O JOGO DUROU XXX HORA(S) E YYY MINUTO(S)” .  

Exemplo de Entrada	        Exemplo de Saída
7 8 9 10                    O JOGO DUROU 2 HORA(S) E 2 MINUTO(S)
*/

#include <stdio.h>

void calcularDuracao(int horaInicio, int minutoInicio, int horaFim, int minutoFim) {
    int inicio = horaInicio * 60 + minutoInicio;
    int fim = horaFim * 60 + minutoFim;

    if (fim <= inicio) {
        fim += 24 * 60;
    }

    int duracao = fim - inicio;
    int horas = duracao / 60;
    int minutos = duracao % 60;

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", horas, minutos);

}
int main() {
    int horaInicio, minutoInicio, horaFim, minutoFim;
    scanf("%d %d %d %d", &horaInicio,  &minutoInicio,  &horaFim, &minutoFim);
    calcularDuracao(horaInicio, minutoInicio, horaFim, minutoFim);

    return 0;
}