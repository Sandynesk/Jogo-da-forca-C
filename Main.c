#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

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
                if (strlen(palavraSecretaPersonalizada) > 0) { // Palavra personalizada foi definida
                    printf("\nIniciando novo jogo com a palavra secreta inserida...\n");
                    iniciarNovoJogoComPalavra(palavraSecretaPersonalizada);
                } else {
                    printf("\nIniciando novo jogo com palavra aleatória...\n");
                    iniciarNovoJogo(escolherDificuldade());
                }
                break;
            case 2:
                printf("\nDigite a palavra secreta: ");
                scanf("%s", palavraSecretaPersonalizada); // Captura a palavra personalizada
                printf("Palavra secreta definida com sucesso!\n");
                break;
            case 3:
                printf("\nEscolher dificuldade...\n");
                escolherDificuldade();
                break;
            case 4:
                printf("\nExibindo pontuação...\n");
                exibirPontuacao();
                break;
            case 5:
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
