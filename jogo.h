#ifndef JOGO_H
#define JOGO_H

#define MAX_PALAVRAS 5
#define TAMANHO_MAX 50

void iniciarNovoJogo(int dificuldade);
void iniciarNovoJogoComPalavra(char* palavraSecreta); 
bool validarEntrada(char letra);
char* escolherPalavraAleatoria(int dificuldade);
void exibirForca(int tentativasErradas);
void fornecerDica(char* palavraSecreta, char* letrasAcertadas);


#endif
