#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "pgm.c"
#include "suavizar_img.c"
#include "quantizar_imgs.c"


/* 

1. GERAR DADOS DA IMAGEM PGM (pgm.c)
    Usar função disponibilizada e guardar elementos da matriz num arquivo texto.

2. SUAVIZAR IMAGEM (http://www.dpi.inpe.br/~carlos/Academicos/Cursos/Pdi/pdi_filtros.htm)
    Gerar arquivo com imagem suavizada usando filtro da média (passa-baixas) utilizando o 
    3x3, 5x5, 7x7.

3. QUANTIZAR IMAGEM E A VERSAO SUAVIZADA
    Gerar arquivos de texto e realizar quantização em N níveis da imagem original e suavizada

4. GERAR MATRIZ SCM (C:\Users\GREAT\Pictures\scm.jpeg) (C:\Users\GREAT\Pictures\scm_2.png)
    Utilizar dos arquivos dos elementos da matriz e da suavizada para gerar matriz SCM
    e gravar em arquivo de texto como vetor.

*/

int main(int argc, char *argv[]){

	char name_img_suavizada[100];

	DIR *d;
	struct dirent *dir;
	struct pgm img_original;
	struct pgm img_suavizada;
	d = opendir("./images");
	int nivel;

	if(d) {
		int option;
		printf("Selecionar Filtro da Media...\n");
    	printf("Digite 0 para janela 3x3.\n");
    	printf("Digite 1 para janela 5x5.\n");
		printf("Digite 2 para janela 7x7.\n");
    	printf("Valor (0-1-2): ");
    	scanf("%d", &option);

		if (option < 0 || option > 2) {
			printf("Operacao invalida.\n");
			exit(2);
		}

		
    	printf("Escolha o nivel de quantizacao...\n");
    	printf("Numero entre 2 e 128 divisivel por 2^x...\n");
    	printf("Nivel: ");
    	scanf("%d", &nivel);
	
		while ((dir = readdir(d)) != NULL){

			if(dir->d_name[0] == '.' ){
        		continue;
      		}

			printf("Nome imagem original:  %s\n\n", dir->d_name);

			char path[50] = {"images/"};
			strcat(path,dir->d_name);
			readPGMImage(&img_original,path);
			

			gerarImgSuavizada(&img_original,dir->d_name , option, name_img_suavizada);

		
			quantizarImagens(path, name_img_suavizada,nivel);

			// char nome[100] = {"./imgsQuantizadas/quantizada_"};
			// strcat(nome,dir->d_name);
			// writePGMImage(&img_original,nome);

			// char nome[100] = {"./imgsQuantizadas/quantizada_"};
			// strcat(nome,dir->d_name);
			// writePGMImage(&img_original,nome);


			// //quantizarImg(img_original.pData,img_original.r, img_original.c,nivel);

			// char nome[100] = {"./imgsQuantizadas/quantizada_"};
			// strcat(nome,dir->d_name);
			// writePGMImage(&img_original,nome);

			// gerarImgSuavizada(&img_original, argv[1], option, name_img_suavizada);
			// quantizarImagens(argv[1], name_img_suavizada);

			// gerarImgSuavizada(&img_suavizada, dir->d_name);

		}
		closedir(d);
	}
	
	return 0;
}
