#include "../include/pgm.h"
void gerarMatrizSCM(unsigned char *qtz_img, unsigned char *qtz_s_img, struct pgm *imagem, int level, char nameFile) {

    int *matrizSCM;
    int tam_matriz = level * level;

    matrizSCM = (int*)malloc(tam_matriz * sizeof(int));

    for (int i = 0; i < tam_matriz; i++) {
        *(matrizSCM + i) = 0;
    }

    for (int i = 0; i < (imagem->c * imagem->r); i++) {
        int linha = *(qtz_img + i);
        int coluna = *(qtz_s_img + i);

        (*(matrizSCM + (linha * level + coluna)))++;
    }

    FILE *arquivo = fopen("matriz_scm.txt", "a+");

    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo para escrita.\n");
        exit(1);
    }

    for (int k = 0; k < tam_matriz; k++) {
        if (!(k % tam_matriz)) fprintf(arquivo, "\n");
        fprintf(arquivo, "%d, ", *(matrizSCM + k));
    }

    if (nameFile == '1') {
        fprintf(arquivo, "stroma\n");
    } else if (nameFile == '0') {
        fprintf(arquivo, "epithelium\n");
    } else {
        fprintf(arquivo, "unknown\n");
    }
}
