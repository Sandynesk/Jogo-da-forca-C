#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include "jogo.h"
#include "util.h"

// Para rodar o jogo: gcc main.c util.c jogo.c -o jogogcc main.c util.c jogo.c -o jogo

// ./jogo
int pontuacao = 0; 
char palavraSecretaPersonalizada[TAMANHO_MAX] = ""; // Palavra secreta definida pelo usuário


int main() {

    
    setlocale(LC_ALL, "");

    int opcao;
    bool executando = true;

    while (executando) {
        exibirMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nIniciando novo jogo...\n");
                iniciarNovoJogo(escolherDificuldade());
                break;
            case 2:
                printf("\nEscolher dificuldade...\n");
                escolherDificuldade();
                break;
            case 3:
                printf("\nExibindo pontuação...\n");
                exibirPontuacao();
                break;
            case 4:
                printf("\nSaindo do jogo...\n");
                executando = false;
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }
    }

    return 0;
}
