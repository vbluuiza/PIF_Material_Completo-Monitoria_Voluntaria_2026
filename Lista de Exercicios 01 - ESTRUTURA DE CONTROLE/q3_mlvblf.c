// Lista de Exercícios 1: Estruturas de controle
#include <stdio.h>

// 1038 | Lanche | Nível 1 | Peso 100 | OPCIONAL
struct cardapio {
    int cod;
    char nome[20];
    float val;
};
 
int main(void) {
 
    struct cardapio dict[] = {
        {1, "Cachorro Quente", 4.00},
        {2, "X-Salada", 4.50},
        {3, "X-Bacon", 5.00},
        {4, "Torrada Simples", 2.00},
        {5, "Refrigerante", 1.50}
    };
    
    int codigo, qtd;
    scanf("%d %d", &codigo, &qtd);
    
    float tamanho = (int)(sizeof(dict)/sizeof(dict[0]));
    float preco = 0.0f;
    for (int i = 0; i < tamanho; i ++){
        if (dict[i].cod == codigo) {
            preco = dict[i].val;
            break;
        }
    }
    
    float total = preco * qtd;
    printf("Total: R$ %.2f\n", total);
 
    return 0;
}