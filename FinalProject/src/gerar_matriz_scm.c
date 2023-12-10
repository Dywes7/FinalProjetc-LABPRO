
#include "../libs/pgm.h"
void gerarMatrizSCM(unsigned char *qtz_img, unsigned char *qtz_s_img, struct pgm *imagem,unsigned int nivel, char nomeArquivo, FILE *arq) {

    unsigned int *matrizSCM;
    int tam_matriz = nivel * nivel;

    matrizSCM = (int*)malloc(tam_matriz * sizeof(int));

    for (int i = 0; i < tam_matriz; i++) {
        *(matrizSCM + i) = 0;
    }

    for (int i = 0; i < (imagem->c * imagem->r); i++) {
        int linha = *(qtz_img + i);
        int coluna = *(qtz_s_img + i);

        (*(matrizSCM + (linha * nivel + coluna)))++;
    }

    writeSCM(matrizSCM, tam_matriz, nomeArquivo, nivel, arq);
}