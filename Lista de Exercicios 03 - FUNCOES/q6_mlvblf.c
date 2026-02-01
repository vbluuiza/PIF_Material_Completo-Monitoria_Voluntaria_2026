// q6: obrigatório definir uma função calcularReajuste(double salario)
// Questão 1048
/*
A empresa ABC resolveu conceder um aumento de salários a seus funcionários de acordo com a tabela abaixo:

Salário	Percentual de Reajuste
0 - 400.00 ----> 15%
400.01 - 800.00 ---> 12%
800.01 - 1200.00 ---> 10%
1200.01 - 2000.00 ---> 7%
Acima de 2000.00 ---> 4%

Leia o salário do funcionário e calcule e mostre o novo salário, bem como o valor de reajuste ganho e o índice reajustado, em percentual.

Entrada
A entrada contém apenas um valor de ponto flutuante, com duas casas decimais.

Saída
Imprima 3 linhas na saída: o novo salário, o valor ganho de reajuste (ambos devem ser apresentados com 2 casas decimais) e o percentual de reajuste ganho, conforme exemplo abaixo.

Exemplo de Entrada	Exemplo de Saída
400.00              Novo salario: 460.00
                    Reajuste ganho: 60.00
                    Em percentual: 15 %
*/

#include <stdio.h>

void calcularReajuste(double salario) {
    double novoSalario, reajuste;
    int percentual;

    if (salario <= 400.00) {
        percentual = 15;
    } else if (salario <= 800.00) {
        percentual = 12;
    } else if (salario <= 1200.00) {
        percentual = 10;
    } else if (salario <= 2000.00) {
        percentual = 7;
    } else {
        percentual = 4;
    }

    reajuste = salario * percentual / 100.0;
    novoSalario = salario + reajuste;

    printf("Novo salario: %.2lf\n", novoSalario);
    printf("Reajuste ganho: %.2lf\n", reajuste);
    printf("Em percentual: %d %%\n", percentual);
};

int main() {
    double salario;
    scanf("%lf", &salario);
    calcularReajuste(salario);
    return 0;
}