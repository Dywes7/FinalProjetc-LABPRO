#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "pgm.c"
#include "suavizar_img.c"
#include "quantizar.c"

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

	//struct pgm img;

	// if (argc != 2){
	// 	printf("Formato: \n\t %s <Nivel de Quantização>\n", argv[0]);
	// 	exit(1);
	// }

	DIR *d;
	struct dirent *dir;
	struct pgm img_original;
	struct pgm img_suavizada;
	d = opendir("./images");
	int nivel;

	if(d) {
		
		printf("nivel de quantização: ");
		scanf("%d",&nivel);
		while ((dir = readdir(d)) != NULL){

			if(dir->d_name[0] == '.' ){
        		continue;
      		}

			printf("%s\n", dir->d_name);
			readPGMImage(&img_original,dir->d_name);
			quantizarImg(img_original.pData,img_original.r, img_original.c,nivel);

			char nome[100] = {"./imgsQuantizadas/quantizada_"};
			strcat(nome,dir->d_name);
			writePGMImage(&img_original,nome);

			//viewPGMImage(&img);
			gerarImgSuavizada(&img_suavizada, dir->d_name);

		}
		closedir(d);
	}
	
	return 0;
}
