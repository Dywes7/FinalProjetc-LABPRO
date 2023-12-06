#include "../include/pgm.h"

void criaArquivosTeste(unsigned char* qtz_img, unsigned char* s_qtz_img, int nivel, char *n_arquivo, char *s_n_arquivo){

	FILE *fp, *sfp;
    char full_path_1[100] = "./images/imagens_quantizadas/q";
    char full_path_2[100] = "./images/imagens_quantizadas/q";

    sprintf(full_path_1 + strlen(full_path_1), "%d_", nivel);
    sprintf(full_path_2 + strlen(full_path_2), "%d_", nivel);

    strcat(full_path_1, n_arquivo);
    strcat(full_path_2, s_n_arquivo);

	if (!(fp = fopen(full_path_1,"w"))){
		perror("Erro.");
		exit(1);
	}

    if (!(sfp = fopen(full_path_2,"w"))){
		perror("Erro.");
		exit(1);
	}

	fprintf(fp, "%s\n","P2");
	fprintf(fp, "%d %d\n", 256, 256);
	fprintf(fp, "%d\n", (nivel - 1));

    fprintf(sfp, "%s\n","P2");
	fprintf(sfp, "%d %d\n", 256, 256);
	fprintf(sfp, "%d\n", (nivel - 1));

    for (int k = 0; k < (256 * 256); k++) {

        fprintf(fp, "%hhu ", *(qtz_img + k));
        fprintf(sfp, "%hhu ", *(s_qtz_img + k));

    }

	fclose(fp);
    fclose(sfp);

}

void quantizarImagens(char *filename, char *s_filename, int nivel, unsigned char **q_img, unsigned char **q_s_img) {

    struct pgm imagem, s_imagem;

    int intervalo = 256 / nivel;

    readPGMImage(&imagem, filename);
    readPGMImage(&s_imagem, s_filename);

    *q_img = (unsigned char*) malloc(imagem.r * imagem.c * sizeof(unsigned char));
    *q_s_img = (unsigned char*) malloc(s_imagem.r * s_imagem.c * sizeof(unsigned char));

    for (int i = 0; i < (imagem.r * imagem.c); i++) {

        *((*q_img) + i) = *(imagem.pData + i) / intervalo;
        *((*q_s_img) + i) = *(s_imagem.pData + i) / intervalo;

    }

    criaArquivosTeste(*q_img, *q_s_img, nivel, filename, s_filename);

	printf("\n");
}