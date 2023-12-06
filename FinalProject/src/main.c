#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>

#include "../include/pgm.h"
#include "../include/menu.h"

int main(int argc, char *argv[]){
	
	// Estrutura para imagem
	struct pgm img;

	// Nome para o arquivo da imagem suvizada gerada
	char name_img_suavizada[100];

	// Ponteiros para elementos das matrizes quantizadas
	unsigned char *quant_img, *quant_s_img;
	
	int k;
	clock_t begin, end;
	double time_per_img, time_total=0;
	long long int a = 999999999;


	if (argc != 2){
		printf("Formato: \n\t %s <Quantidade de Níveis>\n", argv[0]);
		exit(1);
	}

	int nivel = atoi(argv[1]);

	int option;
	
	menuFiltroMedio();
    scanf("%d", &option);

	if (option != 3 && option != 5 && option != 7) {
		printf("Operação inválida.\n");
		exit(2);
	}
	
	/************* LOOPING DE DIRETORIO *************/
	DIR *d;
    struct dirent *dir;
    d = opendir("./images/imagens_originais");

    if (d) {
        while ((dir = readdir(d)) != NULL) {

			if(dir->d_name[0] == '.'){
        		continue;
      		}

			begin = clock();

            printf("%s\n", dir->d_name);

			char nome[100] = {"./images/imagens_originais/"};
			strcat(nome,dir->d_name);
			readPGMImage(&img, nome);
        
			gerarImgSuavizada(&img, dir->d_name, option, name_img_suavizada);

			//quantizarImagens(dir->d_name, name_img_suavizada, nivel, &quant_img, &quant_s_img);
			//gerarMatrizSCM(quant_img, quant_s_img, &img, nivel);	

			end = clock();

			time_total = (double)(end - begin) / CLOCKS_PER_SEC;

        }

		printf("Tempo Total: %lf\n",time_total);

        closedir(d);
    }

	return 0;
}