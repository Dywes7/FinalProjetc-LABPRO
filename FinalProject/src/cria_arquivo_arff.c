#include "../libs/pgm.h"

FILE *initArquivoARFF(int nivel) {

    char nomeArquivoSCM[20];

	sprintf(nomeArquivoSCM, "%u_matriz_scm.arff", nivel);

	FILE *arquivo = fopen(nomeArquivoSCM, "a+");

    if (arquivo == NULL) {

        fprintf(stderr, "Erro ao abrir o arquivo para escrita.\n");
        exit(1);

    }

	fprintf(arquivo, "%s\n", "@relation matrizes");
	
	for (int i = 0; i < (nivel * nivel); i++) {

		fprintf(arquivo, "%s%d %s\n", "@attribute p", i, "numeric");

	}

	fprintf(arquivo, "%s\n", "@attribute class {stroma,epithelium,unknown}");
	fprintf(arquivo, "%s\n", "@data");

    return arquivo;

}