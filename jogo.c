#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "jogo.h"

void iniciarNovoJogo(int dificuldade) {
    char* palavraSecreta = escolherPalavraAleatoria(dificuldade);
    char letrasAcertadas[TAMANHO_MAX] = "";
    char letrasErradas[TAMANHO_MAX] = "";
    int tentativasErradas = 0;
    char letra;
    bool venceu = false;

    while (tentativasErradas < 6) {
        printf("\nProgresso: ");
        for (int i = 0; i < strlen(palavraSecreta); i++) {
            if (strchr(letrasAcertadas, palavraSecreta[i]) != NULL) {
                printf("%c ", palavraSecreta[i]);
            } else {
                printf("_ ");
            }
        }
    
        // Adicione a chamada aqui para exibir o estado atual da forca
        exibirForca(tentativasErradas);
    
        printf("\nLetras erradas: %s\n", letrasErradas);
        printf("Tentativas restantes: %d\n", 6 - tentativasErradas);
    
        // Ler a entrada do usuário e validar
        do {
            printf("\nDigite uma letra: ");
            scanf(" %c", &letra);
            if (!validarEntrada(letra)) {
                printf("Entrada inválida! Por favor, digite apenas letras.\n");
            }


        // Verifique se a letra já foi digitada
        if (strchr(letrasAcertadas, letra) != NULL || strchr(letrasErradas, letra) != NULL) {
            printf("Você já digitou a letra '%c'. Tente outra.\n", letra);
            letra = '\0'; // Reseta a entrada para forçar outra tentativa
        }

        } while (!validarEntrada(letra));
    
        // Verificar se a letra está na palavra secreta
        if (strchr(palavraSecreta, letra) != NULL) {
            if (strchr(letrasAcertadas, letra) == NULL) {
                strncat(letrasAcertadas, &letra, 1);
                printf("Boa! A letra '%c' está correta!\n", letra);
            }
        } else {
            if (strchr(letrasErradas, letra) == NULL) {
                strncat(letrasErradas, &letra, 1);
                tentativasErradas++;
                printf("Ops! A letra '%c' está errada.\n", letra);
            }
        }
    
        // Verificar vitória
        venceu = true;
        for (int i = 0; i < strlen(palavraSecreta); i++) {
            if (strchr(letrasAcertadas, palavraSecreta[i]) == NULL) {
                venceu = false;
                break;
            }
        }
        if (venceu) {
            printf("\nParabéns! Você acertou a palavra secreta: %s\n", palavraSecreta);
            extern int pontuacao;
            extern int vitorias;
            vitorias++;
            pontuacao += 10;
            return;
        }
    }
    
    // Se o jogador não venceu
    if (!venceu) {
        printf("\nQue pena! Você perdeu. A palavra secreta era: %s\n", palavraSecreta);
        extern int derrotas;
        derrotas++;
    }
}    

bool validarEntrada(char letra) {
    return ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z'));
}

char* escolherPalavraAleatoria(int dificuldade) {
    char* palavrasFaceis[MAX_PALAVRAS] = {"uva", "maça", "pêra", "kiwi", "lima"};
    char* palavrasMedias[MAX_PALAVRAS] = {"banana", "manga", "laranja", "morango", "ameixa"};
    char* palavrasDificeis[MAX_PALAVRAS] = {"abacaxi", "carambola", "jabuticaba", "framboesa", "tamarindo"};

    srand(time(NULL));
    int indice = rand() % MAX_PALAVRAS;

    switch (dificuldade) {
        case 1:
            return palavrasFaceis[indice];
        case 2:
            return palavrasMedias[indice];
        case 3:
            return palavrasDificeis[indice];
        default:
            return palavrasFaceis[indice];
    }
}

void exibirForca(int tentativasErradas) {
    switch (tentativasErradas) {
        case 0:
            printf("\n   +---+\n       |\n       |\n       |\n      ===\n");
            break;
        case 1:
            printf("\n   +---+\n   O   |\n       |\n       |\n      ===\n");
            break;
        case 2:
            printf("\n   +---+\n   O   |\n   |   |\n       |\n      ===\n");
            break;
        case 3:
            printf("\n   +---+\n   O   |\n  /|   |\n       |\n      ===\n");
            break;
        case 4:
            printf("\n   +---+\n   O   |\n  /|\\  |\n       |\n      ===\n");
            break;
        case 5:
            printf("\n   +---+\n   O   |\n  /|\\  |\n  /    |\n      ===\n");
            break;
        case 6:
            printf("\n   +---+\n   O   |\n  /|\\  |\n  / \\  |\n      ===\n");
            printf("\nVocê perdeu! A forca foi completada.\n");
            break;
        default:
            printf("Erro: número de tentativas inválido.\n");
            break;
    }
}


void iniciarNovoJogoComPalavra(char* palavraSecreta) {
    char letrasAcertadas[TAMANHO_MAX] = "";
    char letrasErradas[TAMANHO_MAX] = "";
    int tentativasErradas = 0;
    char letra;
    bool venceu = false;

    while (tentativasErradas < 6) {
        printf("\nProgresso: ");
        for (int i = 0; i < strlen(palavraSecreta); i++) {
            if (strchr(letrasAcertadas, palavraSecreta[i]) != NULL) {
                printf("%c ", palavraSecreta[i]);
            } else {
                printf("_ ");
            }
        }

        exibirForca(tentativasErradas);
        printf("\nLetras erradas: %s\n", letrasErradas);
        printf("Tentativas restantes: %d\n", 6 - tentativasErradas);

        // Entrada e validação
        do {
            printf("\nDigite uma letra: ");
            scanf(" %c", &letra);
            if (!validarEntrada(letra)) {
                printf("Entrada inválida! Por favor, digite apenas letras.\n");
            }
        } while (!validarEntrada(letra));

        if (strchr(palavraSecreta, letra) != NULL) {
            if (strchr(letrasAcertadas, letra) == NULL) {
                strncat(letrasAcertadas, &letra, 1);
                printf("Boa! A letra '%c' está correta!\n", letra);
            }
        } else {
            if (strchr(letrasErradas, letra) == NULL) {
                strncat(letrasErradas, &letra, 1);
                tentativasErradas++;
                printf("Ops! A letra '%c' está errada.\n", letra);
            }
        }

        venceu = true;
        for (int i = 0; i < strlen(palavraSecreta); i++) {
            if (strchr(letrasAcertadas, palavraSecreta[i]) == NULL) {
                venceu = false;
                break;
            }
        }
        if (venceu) {
            printf("\nParabéns! Você acertou a palavra secreta: %s\n", palavraSecreta);
            extern int pontuacao;
            extern int vitorias;
            vitorias++;
            pontuacao += 10;
            return;
        }
    }

    if (!venceu) {
        printf("\nQue pena! Você perdeu. A palavra secreta era: %s\n", palavraSecreta);
        extern int derrotas;
        derrotas++;
    }
}
