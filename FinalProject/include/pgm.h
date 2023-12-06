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

void readPGMImage(struct pgm *, char *);
void viewPGMImage(struct pgm *);
void writePGMImage(struct pgm *, char *);
void gerarImgSuavizada(struct pgm*, char*, int, char*);
void janelaTresPorTres(struct pgm*, FILE*, int);
void janelaCincoPorCinco(struct pgm*, FILE*);
void janelaSetePorSete(struct pgm*, FILE*);
void quantizarImagens(char *, char *, int, unsigned char **, unsigned char **);
void criaArquivosTeste(unsigned char*, unsigned char*, int, char *, char *);
void gerarMatrizSCM(unsigned char *, unsigned char *, struct pgm *, int);

#endif