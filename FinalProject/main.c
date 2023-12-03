#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

	struct pgm img;
	char name_img_suavizada[100];

	if (argc != 2){
		printf("Formato: \n\t %s <imagemEntrada.pgm>\n", argv[0]);
		exit(1);
	}

	readPGMImage(&img,argv[1]);

	// writePGMImage(&img, argv[2]);
	// viewPGMImage(&img);

	// printf("TIPO: %d\n", img.tipo);
	// printf("Colunas: %d, Linhas: %d\n", img.c, img.r);
	// printf("MaxValue: %d\n", img.mv);

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

 	gerarImgSuavizada(&img, argv[1], option, name_img_suavizada);

	quantizarImagens(argv[1], name_img_suavizada);

	return 0;

}

