#ifndef PGM_H
#define PGM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

struct pgm{
	int tipo;		// TIPO P2 ou P5
	int c;			// Colunas
	int r;			// Linhas
	int mv;			// MaxValue
	unsigned char *pData;	// Ponteiro para os dados
};

void readPGMImage(struct pgm *, char *, int);
void viewPGMImage(struct pgm *);
void writePGMImage(struct pgm *, char *);
void gerarImgSuavizada(struct pgm*, char*, int, char*);
void janelaTresPorTres(struct pgm*, FILE*);
void janelaCincoPorCinco(struct pgm*, FILE*);
void janelaSetePorSete(struct pgm*, FILE*);
void quantizarImagens(char *, char *, int, unsigned char **, unsigned char **);
void criaArquivosTeste(unsigned char*, unsigned char*, int, char *, char *);
void gerarMatrizSCM(unsigned char *, unsigned char *, struct pgm *,unsigned int, char);
void writeSCM(int *matrizSCM, int tam_matriz, char nomeArquivo,unsigned int nivel);
void writeImage(unsigned char* qtz_img, unsigned char* s_qtz_img, int nivel, char *n_arquivo, char *s_n_arquivo);

#endif