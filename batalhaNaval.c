#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.


// Define o tamanho fixo do tabuleiro e dos navios
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define VALOR_NAVIO 3
#define AGUA 0

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se a posição de um navio é válida (dentro dos limites e sem sobreposição)
int podePosicionar(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        if (coluna + TAM_NAVIO > TAM_TABULEIRO) return 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != AGUA) return 0;
        }
    } else if (orientacao == 'V') {
        if (linha + TAM_NAVIO > TAM_TABULEIRO) return 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != AGUA) return 0;
        }
    }
    return 1;
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao) {
    if (podePosicionar(tabuleiro, linha, coluna, orientacao)) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (orientacao == 'H') {
                tabuleiro[linha][coluna + i] = VALOR_NAVIO;
            } else if (orientacao == 'V') {
                tabuleiro[linha + i][coluna] = VALOR_NAVIO;
            }
        }
    } else {
        printf("Erro: posição inválida para o navio em (%d, %d), orientação %c.\n", linha, coluna, orientacao);
    }
}

// Função para exibir o tabuleiro com letras nas colunas e números nas linhas
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("   ");  // Espaço para alinhar com os números das linhas

    // Imprime letras das colunas
    for (char letra = 'A'; letra < 'A' + TAM_TABULEIRO; letra++) {
        printf(" %c", letra);
    }
    printf("\n");

    // Imprime as linhas com números e os valores do tabuleiro
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d ", i);  // Número da linha com alinhamento
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


int main() {
    // Declara o tabuleiro 10x10
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Define coordenadas iniciais dos dois navios (fixas)
    int linhaH = 2, colunaH = 4; // Navio horizontal
    int linhaV = 5, colunaV = 1; // Navio vertical

    // Posiciona os navios no tabuleiro
    posicionarNavio(tabuleiro, linhaH, colunaH, 'H');
    posicionarNavio(tabuleiro, linhaV, colunaV, 'V');

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0


