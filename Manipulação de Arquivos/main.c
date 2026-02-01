#include <stdio.h>
#include <string.h>

struct Player {
    char nome[20];
    int pontuacao;
} typedef Player;

void sortPlayers(Player *ranking, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (ranking[i].pontuacao > ranking[j].pontuacao) {
                Player aux = ranking[i];
                ranking[i] = ranking[j];
                ranking[j] = aux;
            }
        }
    } 
}

int main() {
    
    Player ranking[10];
    
	FILE *arquivo;
    
    arquivo = fopen("dados.txt", "r");
    
    int i = 0;
    while(fscanf(arquivo, "%19s %d", ranking[i].nome, &ranking[i].pontuacao) == 2) {
        i++;
    }
    
    sortPlayers(ranking, 10);
    
    for (int i = 0; i < 10; i++)
        printf("%s %d\n", ranking[i].nome, ranking[i].pontuacao);
    
    fclose(arquivo);
    
    return 0;
}