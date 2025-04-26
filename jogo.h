#ifndef JOGO_H
#define JOGO_H

#define MAX_PALAVRAS 5
#define TAMANHO_MAX 50

void iniciarNovoJogo(int dificuldade);
bool validarEntrada(char letra);
char* escolherPalavraAleatoria(int dificuldade);
void exibirForca(int tentativasErradas);

#endif
