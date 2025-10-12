#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

//funções para posicionar os navios
void posicionaNavioHorizontal(int tabuleiro[LINHAS][COLUNAS], int linha, int colunaInicial, int tamanho, int valor) {
    for (int j = colunaInicial; j < colunaInicial + tamanho; j++) {
        tabuleiro[linha][j] = valor;
    }
}

void posicionaNavioVertical(int tabuleiro[LINHAS][COLUNAS], int coluna, int linhaInicial, int tamanho, int valor) {
    for (int i = linhaInicial; i < linhaInicial + tamanho; i++) {
        tabuleiro[i][coluna] = valor;
    }
}

void posicionaNavioDiagonal(int tabuleiro[LINHAS][COLUNAS], int linhaInicial, int colunaInicial, int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linhaInicial + i][colunaInicial + i] = valor;
    }
}

//funções para posicionar as habilidades
void posicionaCone(int tabuleiro[LINHAS][COLUNAS], int linhaInicial, int centro, int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        int linha = linhaInicial + i;
        for (int j = centro - i; j <= centro + i; j++) {
            if (linha >= 0 && linha < LINHAS && j >= 0 && j < COLUNAS) {
                tabuleiro[linha][j] = valor;
            }
        }
    }
}

void posicionaCruz(int tabuleiro[LINHAS][COLUNAS], int linhaCentral, int centro, int tamLinha, int tamColuna, int valor) {
    int metadeLinha = tamLinha / 2;
    int metadeColuna = tamColuna / 2;

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (j == centro && i >= linhaCentral - metadeColuna && i <= linhaCentral + metadeColuna) {
                tabuleiro[i][j] = valor;
            }
            if (i == linhaCentral && j >= centro - metadeLinha && j <= centro + metadeLinha) {
                tabuleiro[i][j] = valor;
            }
        }
    }
}

void posicionaOctaedro(int tabuleiro[LINHAS][COLUNAS], int linhaCentral, int centro, int valor) {
    int metade = 1;
    for (int i = linhaCentral - metade; i <= linhaCentral + metade; i++) {
        for (int j = centro - metade; j <= centro + metade; j++) {
            if (i >= 0 && i < LINHAS && j >= 0 && j < COLUNAS) {
                if (i == linhaCentral || j == centro)
                    tabuleiro[i][j] = valor;
            }
        }
    }
}

//função para iniciar o tabuleiro com 0
void iniciaTabuleiro(int tabuleiro[LINHAS][COLUNAS], char letras[COLUNAS]) {
    for (int i = 0; i < LINHAS; i++)
        for (int j = 0; j < COLUNAS; j++)
            tabuleiro[i][j] = 0;
}

//função para imprimir o tabuleiro completo
void imprimeTabuleiro(int tabuleiro[LINHAS][COLUNAS], char letras[COLUNAS]) {
    printf("\n       === BATALHA NAVAL ===\n\n   ");
    for (int i = 0; i < COLUNAS; i++)
        printf(" %c ", letras[i]);
    printf("\n");

    for (int i = 0; i < LINHAS; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < COLUNAS; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

//Função principal
int main() {
    int tabuleiro[LINHAS][COLUNAS];
    char letras[COLUNAS] = {'A','B','C','D','E','F','G','H','I','J'};

    iniciaTabuleiro(tabuleiro, letras);

    posicionaNavioHorizontal(tabuleiro, 0, 6, 3, 3);
    posicionaNavioVertical(tabuleiro, 0, 0, 3, 3);
    posicionaNavioDiagonal(tabuleiro, 3, 4, 3, 3);
    posicionaNavioDiagonal(tabuleiro, 7, 1, 3, 3);

    posicionaCone(tabuleiro, 2, 2, 3, 5);
    posicionaCruz(tabuleiro, 7, 6, 5, 3, 5);
    posicionaOctaedro(tabuleiro, 4, 7, 5);

    imprimeTabuleiro(tabuleiro, letras);

    return 0;
}
