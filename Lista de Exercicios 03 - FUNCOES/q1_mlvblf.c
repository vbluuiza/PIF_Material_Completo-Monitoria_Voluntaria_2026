// q1: cada área deve obrigatoriamente ser calculada por uma função específica (por exemplo: areaTriangulo, areaCirculo, areaTrapezio, areaQuadrado, areaRetangulo);
// Questão 1012 
/*
    Escreva um programa que leia três valores com ponto flutuante de dupla precisão: A, B e C. Em seguida, calcule e mostre:
    a) a área do triângulo retângulo que tem A por base e C por altura.
    b) a área do círculo de raio C. (pi = 3.14159)
    c) a área do trapézio que tem A e B por bases e C por altura.
    d) a área do quadrado que tem lado B.
    e) a área do retângulo que tem lados A e B.

Exemplos de Entrada	                Exemplos de Saída
3.0 4.0 5.2
                                    TRIANGULO: 7.800
                                    CIRCULO: 84.949
                                    TRAPEZIO: 18.200
                                    QUADRADO: 16.000
                                    RETANGULO: 12.000
*/

#include <stdio.h>
#define PI 3.14159

double areaTriangulo(double A, double C) {
    return (A * C ) / 2.0;
}

double areaCirculo(double C) {
    return PI * (C * C);
}

double areaTrapezio(double A, double B, double C) {
    return ((A + B) * C) / 2;
}

double areaQuadrado(double B) {
    return B * B;
}

double areaRetangulo(double A, double B) {
    return A * B;
}

int main() {

    double A, B, C;
    double triangulo, circulo, trapezio, quadrado, retangulo;
    scanf("%lf %lf %lf", &A, &B, &C);

    triangulo = areaTriangulo(A, C);
    circulo = areaCirculo(C);
    trapezio = areaTrapezio(A, B, C);
    quadrado = areaQuadrado(B);
    retangulo = areaRetangulo(A, B);

    
    printf("TRIANGULO: %.3lf\n", triangulo);
    printf("CIRCULO: %.3lf\n", circulo);
    printf("TRAPEZIO: %.3lf\n", trapezio);
    printf("QUADRADO: %.3lf\n", quadrado);
    printf("RETANGULO: %.3lf\n", retangulo);
    
}