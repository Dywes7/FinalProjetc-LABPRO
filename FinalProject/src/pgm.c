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
			//Lendo imagem PGM (dados em texto)
			for (int k=0; k < (pio->r * pio->c); k++){
				fscanf(fp, "%hhu", pio->pData+k);
			}
		break;	
		case 5:
			//"Lendo imagem PGM (dados em binário)"
			fread(pio->pData,sizeof(unsigned char),pio->r * pio->c, fp);
		break;
		default:
			puts("Não está implementado");
	}
	
	fclose(fp);

}

void writeSCM(unsigned int *matrizSCM, int tam_matriz, char nomeIMG,unsigned int nivel, FILE *arquivo){

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
}