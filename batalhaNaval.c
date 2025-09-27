#include <stdio.h>

int main(){

    char linhaletras[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int i, j;
    int navio1I = 0, navio1J = 1;
    int navio2I = 2, navio2J = 3;

    //iniciando o tabuleiro com todas posições = 0
    int tabuleiro[10][10];
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }
    
    //posicionando o navio 1 na horizontal com tamanho de 3 casas
    for (i = 0; i < 3; i++){
        tabuleiro[navio1I][navio1J + i] = 3;
    }

    //posicionando o navio 2 na vertical com tamanho de 3 casas
    for (j = 0; j < 3; j++){
        tabuleiro[navio2I + j][navio2J] = 3;
    }
    
    // imprime o tabuleiro
    printf("   === BATALHA NAVAL ===\n");
    printf("   ");
    for (i = 0; i < 10; i++) {
        printf(" %c", linhaletras[i]); // imprime a linha de letras
    }
    printf("\n");

    for (i = 0; i < 10; i++) {
        printf(" %2d ", i + 1); // imprime a coluna de numeros
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}
