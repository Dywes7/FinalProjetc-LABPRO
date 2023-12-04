#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "pgm.c"
#include "suavizar_img.c"
#include "quantizar_imgs.c"
#include "gerar_matriz_scm.c"

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
	
	// Estrutura para imagem
	struct pgm img;

	// Nome para o arquivo da imagem suvizada gerada
	char name_img_suavizada[100];

	// Ponteiros para elementos das matrizes quantizadas
	unsigned char *quant_img, *quant_s_img;

	if (argc != 2){

		printf("Formato: \n\t %s <quantidade de niveis>\n", argv[0]);
		exit(1);

	}

	int nivel = atoi(argv[1]);

	// readPGMImage(&img, argv[1]);
	// writePGMImage(&img, argv[2]);
	// viewPGMImage(&img);

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
	


	/************* LOOPING DE DIRETORIO *************/
	DIR *d;
    struct dirent *dir;
    d = opendir("./imagens_originais");

    if (d) {

        while ((dir = readdir(d)) != NULL) {

			if(dir->d_name[0] == '.' ){

        		continue;

      		}

            printf("%s\n", dir->d_name);

			// printf("\n*****CHEGOU ATE AQUI 1\n");
			readPGMImage(&img, dir->d_name, 0);

			// printf("\n*****CHEGOU ATE AQUI 2\n");
			gerarImgSuavizada(&img, dir->d_name, option, name_img_suavizada);

			// printf("\n*****CHEGOU ATE AQUI 3\n");
			quantizarImagens(dir->d_name, name_img_suavizada, nivel, &quant_img, &quant_s_img);

			// printf("\n*****CHEGOU ATE AQUI 4\n");
			gerarMatrizSCM(quant_img, quant_s_img, &img, nivel);	
        }

        closedir(d);

    }

	return 0;

}

