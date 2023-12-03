#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pgm.c"
#include "suavizar_img.c"

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

	if (argc != 2){
		printf("Formato: \n\t %s <imagemEntrada.pgm>\n", argv[0]);
		exit(1);
	}

	readPGMImage(&img,argv[1]);

	// writePGMImage(&img, argv[2]);

	viewPGMImage(&img);

	// printf("TIPO: %d\n", img.tipo);
	// printf("Colunas: %d, Linhas: %d\n", img.c, img.r);
	// printf("MaxValue: %d\n", img.mv);

	gerarImgSuavizada(&img, argv[1]);

	return 0;

}
