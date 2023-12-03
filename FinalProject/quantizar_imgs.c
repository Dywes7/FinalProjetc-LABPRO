// #include <stdio.h>
// #include <stdlib.h>

// struct pgm {

// 	int tipo;		// TIPO P2 ou P5
// 	int c;			// Colunas
// 	int r;			// Linhas
// 	int mv;			// MaxValue
// 	unsigned char *pData;	// Ponteiro para os dados

// };

void criaArquivosTeste(unsigned char* qtz_img, unsigned char* s_qtz_img, int nivel){

	FILE *fp, *sfp;
	char ch;

	if (!(fp = fopen("qtz.pgm","w"))){
		perror("Erro.");
		exit(1);
	}

    if (!(sfp = fopen("suav_qtz.pgm","w"))){
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

void quantizarImagens(char *filename, char *s_filename ) {

    int nivel;
    struct pgm imagem, s_imagem;
    unsigned char *q_img, *q_s_img;

    printf("Escolha o nivel de quantizacao...\n");
    printf("Numero entre 2 e 128 divisivel por 2^x...\n");
    printf("Nivel: ");
    scanf("%d", &nivel);

    int intervalo = 256 / nivel;

    readPGMImage(&imagem, filename);
    readPGMImage(&s_imagem, s_filename);

    q_img = (unsigned char*) malloc(imagem.r * imagem.c * sizeof(unsigned char));
    q_s_img = (unsigned char*) malloc(s_imagem.r * s_imagem.c * sizeof(unsigned char));

    for (int i = 0; i < (imagem.r * imagem.c); i++) {

        *(q_img + i) = *(imagem.pData + i) / intervalo;
        *(q_s_img + i) = *(s_imagem.pData + i) / intervalo;

    }

    criaArquivosTeste(q_img, q_s_img, nivel);
	

	printf("\n");

}