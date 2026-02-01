// q4: obrigatório definir uma função calcularRaizes(double A, double B, double C) e chamá-la na main.
// Questão 1036
/*
Leia 3 valores de ponto flutuante e efetue o cálculo das raízes da equação de Bhaskara. Se não for possível calcular as raízes, mostre a mensagem correspondente “Impossivel calcular”, caso haja uma divisão por 0 ou raiz de numero negativo.
Entrada
Leia três valores de ponto flutuante (double) A, B e C.
Saída
Se não houver possibilidade de calcular as raízes, apresente a mensagem "Impossivel calcular". Caso contrário, imprima o resultado das raízes com 5 dígitos após o ponto, com uma mensagem correspondente conforme exemplo abaixo. Imprima sempre o final de linha após cada mensagem.
Exemplos de Entrada	        Exemplos de Saída
10.0 20.1 5.1               R1 = -0.29788
                            R2 = -1.71212
*/

#include <stdio.h>
#include <math.h>

double calcularRaizes(double A, double B, double C) {
    double raiz1, raiz2, delta;

    delta = (B * B) - (4 * A * C);  // b² - 4ac 
    raiz1 = (-B + sqrt(delta)) / (2 * A);
    raiz2 = (-B - sqrt(delta)) / (2 * A);

    if ( delta <= 0 || A == 0 || B == 0 || C == 0) {
		  printf("Impossivel calcular\n");
	} 
    else
	{
		  printf("R1 = %.5lf\n", raiz1);
		  printf("R2 = %.5lf\n", raiz2);
	}

    return 0;
}


int main() {
    double A, B, C;
    scanf("%lf %lf %lf", &A, &B, &C);

    calcularRaizes(A, B, C);

    return 0;
}