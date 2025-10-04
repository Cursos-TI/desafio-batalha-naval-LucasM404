#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

int main() {
    int tabuleiro[LINHAS][COLUNAS];
    char letras[COLUNAS] = {'A','B','C','D','E','F','G','H','I','J'};
    int i, j;

    // Inicializa o tabuleiro com 0
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio 1 (horizontal, tamanho 3)
    for (j = 6; j < 9; j++) {
        tabuleiro[0][j] = 3;
    }

    // Navio 2 (vertical, tamanho 3)
    for (i = 0; i < 3; i++) {
        tabuleiro[i][0] = 3;
    }

    // Navio 3 (diagonal principal, tamanho 3)
    for (i = 0; i < 3; i++) {
        tabuleiro[3 + i][4 + i] = 3;
    }

    // Navio 4 (diagonal inversa, tamanho 3)
    for (i = 0; i < 3; i++) {
        tabuleiro[6 + i][3 - i] = 3;
    }

    // Impressão do tabuleiro
    printf("\n       === BATALHA NAVAL ===\n\n   ");

    // Cabeçalho de letras
    for (i = 0; i < COLUNAS; i++) {
        printf(" %c ", letras[i]);
    }
    printf("\n");

    // Linhas numeradas
    for (i = 0; i < LINHAS; i++) {
        printf("%2d ", i + 1);
        for (j = 0; j < COLUNAS; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
