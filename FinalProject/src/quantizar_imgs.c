#include "../libs/pgm.h"

void quantizarImagens(char *filename, char *s_filename, int nivel, unsigned char **q_img, unsigned char **q_s_img) {

    struct pgm imagem, s_imagem;

    int intervalo = 256 / nivel;

    readPGMImage(&imagem, filename,0);
    readPGMImage(&s_imagem, s_filename,1);

    *q_img = (unsigned char*) malloc(imagem.r * imagem.c * sizeof(unsigned char));
    *q_s_img = (unsigned char*) malloc(s_imagem.r * s_imagem.c * sizeof(unsigned char));

    for (int i = 0; i < (imagem.r * imagem.c); i++) {
        *((*q_img) + i) = *(imagem.pData + i) / intervalo;
        *((*q_s_img) + i) = *(s_imagem.pData + i) / intervalo;
    }

    // writeImage(*q_img, *q_s_img, nivel, filename, s_filename);

	printf("\n");
}