#include "../libs/pgm.h"

void filtroMedia(struct pgm *imagem, FILE *newArquivo, int operation) {

    int gap = operation / 2;

    // ITERANDO SOBRE TODOS OS ELEMENTOS DA MATRIZ DA IMAGEM
   for (int i = 0; i < (imagem->c * imagem->r); i++) {

            int soma = 0;
            int linha = i / imagem->c;
            int coluna = i % imagem->c;

            for (int j = linha - gap; j <= linha + gap; j++) {

                for (int k = coluna - gap; k <= coluna + gap; k++) {

                    if (j < 0 || j >= imagem->r || k < 0 || k >= imagem->c) continue;

                    soma += *(imagem->pData + (j * imagem->c + k));

                }

            }

            fprintf(newArquivo, "%hhu ", soma / (operation * operation));

   }

}

void gerarImgSuavizada(struct pgm *pio, char *filename, int op, char *nomeImgSuavizada) {

    FILE *fp;
    char ch;
    // char nomeImgSuavizada[100];

    // ALTERANDO NOME DO ARQUIVO A SER GERADO DE ACORDO COM A JANELA ESCOLHIDA
    // switch (op) {
    //     case 3:
    //         strcpy(nomeImgSuavizada, "suavizado3x3_");
    //         break;

    //     case 5:
    //         strcpy(nomeImgSuavizada, "suavizado5x5_");
    //         break;
        
    //     case 7:
    //         strcpy(nomeImgSuavizada, "suavizado7x7_");

    // }

    // JUTANDO O NOME 'suavizadoYxY_' com o nome original da imagem
    strcpy(nomeImgSuavizada, filename);
    char path[100] = "./images/imagens_suavizadas/";


    if (!(fp = fopen(strcat(path, nomeImgSuavizada), "w"))) {
        
		perror("Erro.");
		exit(1);

	}

    fprintf(fp, "%s\n", "P2");
	fprintf(fp, "%d %d\n",pio->c, pio->r);
	fprintf(fp, "%d\n", 255);

    filtroMedia(pio, fp, op);

    fclose(fp);
}