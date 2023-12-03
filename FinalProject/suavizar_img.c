// #include <stdio.h>
// #include <stdlib.h>

// struct pgm {

// 	int tipo;		// TIPO P2 ou P5
// 	int c;			// Colunas
// 	int r;			// Linhas
// 	int mv;			// MaxValue
// 	unsigned char *pData;	// Ponteiro para os dados

// };

// **************** REMOVER ACIMA ****************************

void gerarImgSuavizada(struct pgm*, char*, int, char*);
void janelaTresPorTres(struct pgm*, FILE*);
void janelaCincoPorCinco(struct pgm*, FILE*);
void janelaSetePorSete(struct pgm*, FILE*);

void janelaSetePorSete(struct pgm *imagem, FILE *newArquivo) {

    // ITERANDO SOBRE TODOS OS ELEMENTOS DA MATRIZ DA IMAGEM
    for (int i = 0; i < (imagem->c * imagem->r); i ++) {

        int soma = 0;   // Inicializando somatorio
        int linha = i / imagem->c;  // Identificar linha o elemento
        int coluna = i % imagem->c; // Identificar coluna do elemento

        // CASO PARA ELEMENTO DA MATRIZ QUE NÃO ESTÁ NAS DUAS CAMADAS MAIS EXTERNAS
        if (linha > 2 && linha < imagem->r -3 && coluna > 2 && coluna < imagem->c -3) {

            for (int j = linha - 3; j <= linha + 3; j++) {

                for (int k = coluna - 3; k <= coluna + 3; k++) {

                    soma += *(imagem->pData + (j * imagem->c + k));

                }

            }

            fprintf(newArquivo, "%hhu ", soma / 42);

        } else {    // CASO RESTANTE, ELEMENTOS DA BORDA (DUAS CAMADAS MAIS EXTERNAS)

            fprintf(newArquivo, "%hhu ", *(imagem->pData + i));

        }


   }


}

void janelaCincoPorCinco(struct pgm *imagem, FILE *newArquivo) {

    // ITERANDO SOBRE TODOS OS ELEMENTOS DA MATRIZ DA IMAGEM
    for (int i = 0; i < (imagem->c * imagem->r); i ++) {

        int soma = 0;   // Inicializando somatorio
        int linha = i / imagem->c;  // Identificar linha o elemento
        int coluna = i % imagem->c; // Identificar coluna do elemento

        // CASO PARA ELEMENTO DA MATRIZ QUE NÃO ESTÁ NAS DUAS CAMADAS MAIS EXTERNAS
        if (linha > 1 && linha < imagem->r -2 && coluna > 1 && coluna < imagem->c -2) {

            for (int j = linha - 2; j <= linha + 2; j++) {

                for (int k = coluna - 2; k <= coluna + 2; k++) {

                    soma += *(imagem->pData + (j * imagem->c + k));

                }

            }

            fprintf(newArquivo, "%hhu ", soma / 25);

        } else {    // CASO RESTANTE, ELEMENTOS DA BORDA (DUAS CAMADAS MAIS EXTERNAS)

            fprintf(newArquivo, "%hhu ", *(imagem->pData + i));

        }


   }


}

void janelaTresPorTres(struct pgm *imagem, FILE *newArquivo) {

    // ITERANDO SOBRE TODOS OS ELEMENTOS DA MATRIZ DA IMAGEM
   for (int i = 0; i < (imagem->c * imagem->r); i ++) {

        // CASOS PARA ELEMENTOS DA BORDA DA MATRIZ
        if (((i % imagem->c) == 0) || ((i % imagem->c) == (imagem->c - 1)) || ((i / imagem->c) == 0) || ((i / imagem->c) == (imagem->r - 1))) {
            
           fprintf(newArquivo, "%hhu ", *(imagem->pData + i));

        } else { // CASO PARA ELEMENTOS QUE NÃO ESTAO NA BORDA

            int soma = 0;
            int linha = i / imagem->c;
            int coluna = i % imagem->c;

            for (int j = linha - 1; j <= linha + 1; j++) {

                for (int k = coluna - 1; k <= coluna + 1; k++) {

                    soma += *(imagem->pData + (j * imagem->c + k));

                }

            }

            fprintf(newArquivo, "%hhu ", soma / 9);

        }

     }

    // return pDadosSuavizados;

}

void gerarImgSuavizada(struct pgm *pio, char *filename, int op, char *nomeImgSuavizada) {

    FILE *fp;
    char ch;

    // ALTERANDO NOME DO ARQUIVO A SER GERADO DE ACORDO COM A JANELA ESCOLHIDA
    switch (op) {
        case 0:
            strcpy(nomeImgSuavizada, "suavizado3x3_");
            break;

        case 1:
            strcpy(nomeImgSuavizada, "suavizado5x5_");
            break;
        
        case 2:
            strcpy(nomeImgSuavizada, "suavizado7x7_");

    }

    //char path[100] = {"imgSuavizadas/"};
    // JUTANDO O NOME 'suavizadoYxY_' com o nome original da imagem

    nomeImgSuavizada = strcat(nomeImgSuavizada,filename);


    printf("Nova imagem (%s) a ser criada.\n", nomeImgSuavizada);


    if (!(fp = fopen(nomeImgSuavizada, "w"))) {
        
		perror("Erro.");
		exit(1);

	}

    //fprintf(fp, "%s\n", (pio->tipo == 2) ? "P2" : "P5");
    fprintf(fp, "%s\n", "P2");
	fprintf(fp, "%d %d\n",pio->c, pio->r);
	fprintf(fp, "%d\n", 255);


    janelaTresPorTres(pio, fp);

    switch (op) {
        case 0:
            janelaTresPorTres(pio, fp);
            break;
        
        case 1:
            janelaCincoPorCinco(pio, fp);
            break;

        case 2:
            janelaSetePorSete(pio, fp);

    }

    fclose(fp);
    
}