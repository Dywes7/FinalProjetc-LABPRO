#include "../include/pgm.h"
void gerarMatrizSCM(unsigned char *qtz_img, unsigned char *qtz_s_img, struct pgm *imagem, int level, char nameFile) {

    // printf("\n*****CHEGOU ATE AQUI 10\n");
    int *matrizSCM;
    int tam_matriz = level * level;

    // printf("\n*****CHEGOU ATE AQUI 11\n");
    matrizSCM = (int*)malloc(tam_matriz * sizeof(int));

    // printf("\n*****CHEGOU ATE AQUI 12\n");
    // Inicilizar matrizSCM
    for (int i = 0; i < tam_matriz; i++) {

        *(matrizSCM + i) = 0;

    }

    // soma += *(imagem->pData + (j * imagem->c + k));
    // printf("M[2][3]: %d\n", matriz[2 * COL + 3]); matriz + (Lin * nCOL + col)

    // printf("\n*****CHEGOU ATE AQUI 13\n");
    for (int i = 0; i < (imagem->c * imagem->r); i++) {

        // printf("\n*****CHEGOU ATE AQUI 13.25\n");
        int linha = *(qtz_img + i);
        // printf("\n*****CHEGOU ATE AQUI 13.50\n");
        int coluna = *(qtz_s_img + i);

        // printf("\n*****CHEGOU ATE AQUI 13.75\n");
        (*(matrizSCM + (linha * level + coluna)))++;

		// printf("A. %hhu ",*(qtz_img + i));
        // printf("B. %hhu ",*(qtz_s_img + i));
        // printf("SCM[%d][%d]: %d\n", linha, coluna, (*(matrizSCM + (linha * (imagem->mv + 1) + coluna))));

    }

    printf("\n*****CHEGOU ATE AQUI 14\n");
    printf("MATRIZ SCM...\n");
    for (int k = 0; k < tam_matriz; k++){

		if (! (k % level)) printf("\n");
		printf("%d ",*(matrizSCM + k));
		
	}

    FILE *arquivo = fopen("matriz_scm.txt", "a+");

    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo para escrita.\n");
        exit(1);
    }

    // Adicionar valores da matrizSCM ao arquivo
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


    fclose(arquivo);


    //  for (int k = 0; k < (imagem->c * imagem->r); k++){

    //     int linha = *(qtz_img + k);
    //     int coluna = *(qtz_s_img + k);

    //     // printf("\n*****CHEGOU ATE AQUI 15\n");
	// 	printf("A. %hhu ",*(qtz_img + k));
    //     printf("B. %hhu ",*(qtz_s_img + k));
    //     printf("SCM[%d][%d]: %d\n", linha, coluna, (*(matrizSCM + (linha * level + coluna))));

		
	//  }


}