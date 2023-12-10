#include "../libs/pgm.h"

void readPGMImage(struct pgm *pio, char *filename, int i_path){

	FILE *fp;
	char ch;
	const char *caminhos[] = {"./images/imagens_originais/", "./images/imagens_suavizadas/"};
	char full_path[100];

	// MODIFICANDO CAMINHOS
	if (i_path == 3) {
		strcpy(full_path, filename);
	} else {
		strcpy(full_path, caminhos[i_path]);
		strcat(full_path, filename);
	}
	
	printf("\nFull_path 1: %s\n", full_path);

	if (!(fp = fopen(full_path, "r"))) {
	
		printf("Erro ao encontrar arquivo %s.",full_path);
		exit(1);

	}

	if ( (ch = getc(fp))!='P'){

		puts("A imagem fornecida não está no formato pgm");
		exit(2);

	}
	
	pio->tipo = getc(fp)-48;
	
	fseek(fp,1, SEEK_CUR);

	while((ch=getc(fp)) == '#'){

		while( (ch=getc(fp)) != '\n');

	}

	fseek(fp, -2, SEEK_CUR);

	fscanf(fp, "%d %d",&pio->c,&pio->r);

	if (ferror(fp)) { 

		perror(NULL);
		exit(3);

	}	

	fscanf(fp, "%d", &pio->mv);

	#ifdef __linux__
    	fseek(fp, 1, SEEK_CUR);
  	#elif _WIN32
    	fseek(fp, 0, SEEK_CUR);
  	#elif __APPLE__
    	fseek(fp, 1, SEEK_CUR);
  	#endif

	pio->pData = (unsigned char*) malloc(pio->r * pio->c * sizeof(unsigned char));

	switch(pio->tipo){
		case 2:
			puts("Lendo imagem PGM (dados em texto)");
			for (int k=0; k < (pio->r * pio->c); k++){
				fscanf(fp, "%hhu", pio->pData+k);
			}
		break;	
		case 5:
			puts("Lendo imagem PGM (dados em binário)");
			fread(pio->pData,sizeof(unsigned char),pio->r * pio->c, fp);
		break;
		default:
			puts("Não está implementado");
	}
	
	fclose(fp);

}

void writePGMImage(struct pgm *pio, char *filename){
	FILE *fp;
	char ch;

	if (!(fp = fopen(filename,"wb"))){
		perror("Erro.");
		exit(1);
	}

	fprintf(fp, "%s\n","P5");
	fprintf(fp, "%d %d\n",pio->c, pio->r);
	fprintf(fp, "%d\n", 255);

	fwrite(pio->pData, sizeof(unsigned char),pio->c * pio->r, fp);

	fclose(fp);

}


void viewPGMImage(struct pgm *pio) {

	printf("Tipo: %d\n",pio->tipo);
	printf("Dimensões: [%d %d]\n",pio->c, pio->r);
	printf("Max: %d\n",pio->mv);

	for (int k=0; k < (pio->r * pio->c); k++){

		if (!( k % pio->c)) printf("\n");
		printf("%2hhu ",*(pio->pData+k));
		
	}	

	printf("\n");
}

void writeImage(unsigned char* qtz_img, unsigned char* s_qtz_img, int nivel, char *n_arquivo, char *s_n_arquivo){

	FILE *fp, *sfp;
    char full_path_1[100] = "./images/imagens_quantizadas/";
    char full_path_2[100] = "./images/imagens_quantizadas_suav/";


    //sprintf(full_path_1 + strlen(full_path_1), "%d_", nivel);
    //sprintf(full_path_2 + strlen(full_path_2), "%d_", nivel);

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

void writeSCM(int *matrizSCM, int tam_matriz, char nomeIMG,unsigned int nivel, FILE *arquivo){

    for (int k = 0; k < tam_matriz; k++) {

        if (!(k % tam_matriz)) fprintf(arquivo, "\n");

        fprintf(arquivo, "%d,", *(matrizSCM + k));

    }

    if (nomeIMG == '1') {

        fprintf(arquivo, "stroma\n");

    } else if (nomeIMG == '0') {

        fprintf(arquivo, "epithelium\n");

    } else {

        fprintf(arquivo, "unknown\n");

    }

	// fclose(arquivo);
}