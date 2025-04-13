#include <stdio.h>   // Biblioteca padrão de entrada e saida
#include <stdlib.h>  // Biblioteca pra funções utilitarias
#include <conio.h>   // biblioteca pra getch (entrada de caracteres sem Enter)

// tabuleiro inicial de xadrez letras minusculas são peças pretas, maiúsculas são peças brancas
char tabuleiro[8][8] = {

    { 't', 'c', 'b', 'k', 'q', 'b', 'c', 't' }, 
    { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' }, 
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, 
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, 
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, 
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, 
    { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' }, 
    { 'T', 'C', 'B', 'K', 'Q', 'B', 'C', 'T' }  

};

// Funcao pra exibir o tabuleiro na tela
void exibir_tabuleiro() {

    int i, j;
    char letras[] = "   A   B   C   D   E   F   G   H"; // letras das colunas

    printf("\n%s\n", letras); // imprime o cabeçalho das colunas
    for (i = 0; i < 8; i++) {

        printf("  ---------------------------------\n"); // linha separadora
        printf("%d", 8 - i);  // numeros das linhas (8 ate 1)

        for (j = 0; j < 8; j++) {
            printf("| %c ", tabuleiro[i][j]); // imprime cada peça ou espaço vazio
        }

        printf("|\n"); // Fecha a linha do tabuleiro
    }
    printf("  ---------------------------------\n"); // base do tabuleiro
}

// funçao que move a peça da posição inicial para a posição final
void mover_peca(int r1, int c1, int r2, int c2) {

    char temp = tabuleiro[r1][c1];     // Armazena temporariamente a peça original
    tabuleiro[r1][c1] = ' ';           // remove a peça da posiçao original
    tabuleiro[r2][c2] = temp;          // Coloca a peça na nova posição
}


// Função que executa o turno de um jogador
void turno_jogador(int jogador) {
    char col1, col2;    // colunas das posições (ex: 'E')
    int lin1, lin2;      // Linhas das posições (ex: 2, 4)
    int c1, c2, r1, r2;  // Cordenadas convertidas para indices da matriz

    printf("\nJogador %d", jogador);
    printf("\ndigite a posicao da peca (ex: E2): ");
    scanf(" %c%d", &col1, &lin1); 

    printf("Digite a nova posicao (ex: E4): ");
    scanf(" %c%d", &col2, &lin2); 

    c1 = col1 - 'A';           // converte a letra para indice da coluna
    c2 = col2 - 'A';
    r1 = 8 - lin1;             // converte o numero para indice da linha
    r2 = 8 - lin2;

    // verifica se a posição de origem é valida
    if (r1 < 0 || r1 > 7 || c1 < 0 || c1 > 7 || tabuleiro[r1][c1] == ' ') {
        printf("Posicao invalida!\n");
        return;
    }

    // Verifica se a posição de destino é valida
    if (r2 < 0 || r2 > 7 || c2 < 0 || c2 > 7) {
        printf("Destino invalido!\n");
        return;
    }

    // realiza o movimento
    mover_peca(r1, c1, r2, c2);
}

// função principal
int main() {
    int rodada = 1;  // controla qual rodada está
    char tecla;      // armazena tecla pressionada

    printf("\n\tBEM-VINDO AO JOGO DE XADREZ");
    printf("\nPressione qualquer tecla para iniciar...");
    getch(); // espera o jogador pressionar uma tecla para começar

    do {
        system("cls"); // limpa a tela (no Windows)
        exibir_tabuleiro(); // mostra o tabuleiro
        turno_jogador((rodada % 2 == 1) ? 1 : 2); // alterna entre jogador 1 e 2
        printf("\nPressione ENTER para continuar...\n");
        tecla = getch(); // aguarda o ENTER para continuar
        rodada++;        // Proxima rodada
    } while (tecla == 13); // continua enquanto a tecla for ENTER (codigo ASCII 13)

    return 0;
}


