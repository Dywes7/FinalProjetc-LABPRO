#ifndef PGM_H
#define PGM_H

#include <stdio.h>
#include <stdlib.h>

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

#endif