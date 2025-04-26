#include <stdio.h>
#include "util.h"


void exibirMenu() {
    printf("╔═══════════════════════╗\n");
    printf("║ Bem-vindo ao jogo! ⚔️  ║\n");
    printf("╚═══════════════════════╝\n");
    

    printf("\n===== Menu Inicial =====\n");
    printf("1. Iniciar novo jogo\n");
    printf("2. Inserir palavra secreta\n");
    printf("3. Escolher dificuldade\n");
    printf("4. Exibir pontuação\n");
    printf("5. Sair do jogo\n");
    printf("=========================\n");
}

int escolherDificuldade() {
    int dificuldade;
    printf("\nEscolha uma dificuldade:\n");
    printf("1. Fácil (palavra curta)\n");
    printf("2. Médio (palavra média)\n");
    printf("3. Difícil (palavra longa)\n");
    scanf("%d", &dificuldade);

    switch (dificuldade) {
        case 1:
            printf("Dificuldade definida: Fácil\n");
            break;
        case 2:
            printf("Dificuldade definida: Médio\n");
            break;
        case 3:
            printf("Dificuldade definida: Difícil\n");
            break;
        default:
            printf("Opção inválida, definindo para Fácil.\n");
            dificuldade = 1;
            break;
    }
    return dificuldade;
}

void exibirPontuacao() {
    extern int pontuacao, vitorias, derrotas;
    printf("Sua pontuação atual é: %d\nVocê tem %d vitorias e %d derrotas\n", pontuacao, vitorias, derrotas);
}
