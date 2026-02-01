// q2: obrigatório definir a função calcularDistancia(double x1, double y1, double x2, double y2) e chamá-la na main.
// Questão 1015
/*
Leia os quatro valores correspondentes aos eixos x e y de dois pontos quaisquer no plano, p1(x1,y1) e p2(x2,y2) e calcule a distância entre eles, mostrando 4 casas decimais, segundo a fórmula:
Distancia = √(x2 - x1)² +  (y2 - y1)²
Entrada
O arquivo de entrada contém duas linhas de dados. A primeira linha contém dois valores de ponto flutuante: x1 y1 e a segunda linha contém dois valores de ponto flutuante x2 y2.
Saída
Calcule e imprima o valor da distância segundo a fórmula fornecida, considerando 4 casas decimais.

Exemplo de Entrada	        Exemplo de Saída
1.0 7.0                     4.4721
5.0 9.0
*/

#include <stdio.h>
#include <math.h>

double calcularDistancia(double x1, double y1, double x2, double y2) {
    double distancia;
    distancia = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    return distancia;

}
int main() {
    double x1, y1, x2, y2, distancia;
    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);

    distancia = calcularDistancia(x1, y1, x2, y2);

    printf("%.4lf\n", distancia);
    
    return 0;
}
