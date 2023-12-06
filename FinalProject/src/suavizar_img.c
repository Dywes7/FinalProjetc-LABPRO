#include "../include/pgm.h"

void janelaSetePorSete(struct pgm *imagem, FILE *newArquivo) {

    // ITERANDO SOBRE TODOS OS ELEMENTOS DA MATRIZ DA IMAGEM
    for (int i = 0; i < (imagem->c * imagem->r); i ++) {

        int soma = 0;   // Inicializando somatorio
        int linha = i / imagem->c;  // Identificar linha do elemento
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
        int linha = i / imagem->c;  // Identificar linha do elemento
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

void janelaTresPorTres(struct pgm *imagem, FILE *newArquivo, int op) {

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

            fprintf(newArquivo, "%hhu ", soma / (op*op));
 
        }

     }

}

void gerarImgSuavizada(struct pgm *imagem, char *filename, int op, char *nomeImgSuavizada) {

    FILE *fp;
    char ch;
 
    // ALTERANDO NOME DO ARQUIVO A SER GERADO DE ACORDO COM A JANELA ESCOLHIDA
    switch (op) {
        case 3:
            strcpy(nomeImgSuavizada, "suavizado3x3.pgm");
            break;

        case 5:
            strcpy(nomeImgSuavizada, "suavizado5x5.pgm");
            break;
        
        case 7:
            strcpy(nomeImgSuavizada, "suavizado7x7.pgm");

    }

    char path[100] = "./images/imagens_suavizadas/";
    strcat(path,filename);

    if (!(fp = fopen(strcat(path,nomeImgSuavizada), "w"))) {
		perror("Erro 2.");
		exit(1);
	}

    fprintf(fp, "%s\n", "P2");
	fprintf(fp, "%d %d\n",imagem->c, imagem->r);
	fprintf(fp, "%d\n", 255);

    switch (op) {
        case 3:
            janelaTresPorTres(imagem, fp, op);
            break;
        
        case 5:
            janelaCincoPorCinco(imagem, fp);
            break;

        case 7:
            janelaSetePorSete(imagem, fp);

    }
    
    fclose(fp);

}