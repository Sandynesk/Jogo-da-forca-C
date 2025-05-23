#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
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
    
        exibirForca(tentativasErradas);
        printf("\nLetras erradas: %s\n", letrasErradas);
        printf("Tentativas restantes: %d\n", 6 - tentativasErradas);
    
        // Entrada do usuário
        printf("\nDigite uma letra (sem acento ou cedilha) ou '!' para pedir uma dica: ");
        scanf(" %c", &letra);
        letra = toupper(letra);
    
        // Se o jogador solicitar uma dica
        if (letra == '!') {
            fornecerDica(palavraSecreta, letrasAcertadas);
            continue; // Pula para a próxima rodada sem consumir tentativa
        }
    
        // Validar a entrada
        if (!validarEntrada(letra)) {
            printf("Entrada inválida! Por favor, digite apenas letras.\n");
            continue;
        }
    
        // Verificar se a letra já foi usada
        if (strchr(letrasAcertadas, letra) != NULL || strchr(letrasErradas, letra) != NULL) {
            printf("Você já tentou a letra '%c'. Tente outra.\n", letra);
            continue;
        }
    
        // Verificar se a letra está na palavra secreta
        if (strchr(palavraSecreta, letra) != NULL) {
            strncat(letrasAcertadas, &letra, 1);
            printf("Boa! A letra '%c' está correta!\n", letra);
        } else {
            strncat(letrasErradas, &letra, 1);
            tentativasErradas++;
            printf("Ops! A letra '%c' está errada.\n", letra);
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

char* escolherPalavraAleatoria(int dificuldade) {  // Insira aqui as palavras na lista sem cedilha nem acento
    char* palavrasFaceis[MAX_PALAVRAS] = {"UVA", "MACA", "PERA", "KIWI", "LIMA"};
    char* palavrasMedias[MAX_PALAVRAS] = {"BANANA", "MANGA", "LARANJA", "MORANGO", "AMEIXA"};
    char* palavrasDificeis[MAX_PALAVRAS] = {"ABACAXI", "CARAMBOLA", "JABUTICABA", "FRAMBOESA", "TAMARINDO"};

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

        // Entrada do jogador
        printf("\nDigite uma letra ou '!' para pedir uma dica: ");
        scanf(" %c", &letra);

        // Se o jogador solicitar uma dica
        if (letra == '!') {
            fornecerDica(palavraSecreta, letrasAcertadas);
            continue; // Pula para a próxima iteração do loop
        }

        // Validação da entrada
        if (!validarEntrada(letra)) {
            printf("Entrada inválida! Por favor, digite apenas letras.\n");
            continue; // Pede nova entrada sem penalizar o jogador
        }

        // Verificar se a letra já foi usada
        if (strchr(letrasAcertadas, letra) != NULL || strchr(letrasErradas, letra) != NULL) {
            printf("Você já tentou a letra '%c'. Tente outra.\n", letra);
            continue; // Evita penalizar novamente o jogador
        }

        // Verificar se a letra está na palavra secreta
        if (strchr(palavraSecreta, letra) != NULL) {
            strncat(letrasAcertadas, &letra, 1);
            printf("Boa! A letra '%c' está correta!\n", letra);
        } else {
            strncat(letrasErradas, &letra, 1);
            tentativasErradas++;
            printf("Ops! A letra '%c' está errada.\n", letra);
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

    if (!venceu) {
        printf("\nQue pena! Você perdeu. A palavra secreta era: %s\n", palavraSecreta);
        extern int derrotas;
        derrotas++;
    }
}


void fornecerDica(char* palavraSecreta, char* letrasAcertadas) {
    int tamanho = strlen(palavraSecreta);
    char letraDica = '\0';

    // Percorrer todas as letras da palavra
    for (int i = 0; i < tamanho; i++) {
        char tentativa = palavraSecreta[i];
        // Verifica se a letra ainda não foi acertada
        if (strchr(letrasAcertadas, tentativa) == NULL) {
            letraDica = tentativa;
            break;
        }
    }

    // Exibir a dica ou mensagem de que não há mais dicas
    if (letraDica != '\0') {
        printf("Dica: A palavra contém a letra '%c'.\n", letraDica);
    } else {
        printf("Todas as possíveis dicas já foram dadas!\n");
    }
}

