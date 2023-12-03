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

void gerarImgSuavizada(struct pgm*, char*);
void janelaTresPorTres(struct pgm*, FILE*);

void janelaTresPorTres(struct pgm *imagem, FILE *newArquivo) {
    
    // unsigned char *pDadosSuavizados;

    // pDadosSuavizados = (unsigned char*)malloc(imagem->c * imagem->r * sizeof(unsigned char));

   for (int i = 0; i < (imagem->c * imagem->r); i ++) {

        if (((i % imagem->c) == 0) || ((i % imagem->c) == (imagem->c - 1)) || ((i / imagem->c) == 0) || ((i / imagem->c) == (imagem->r - 1))) {
            
            // CASOS PARA ELEMENTOS DA BORDA DA MATRIZ
            // *(pDadosSuavizados + i) = *(imagem->pData + i);
            // fwrite(pio->pData, sizeof(unsigned char),pio->c * pio->r, fp);
            
           fprintf(newArquivo, "%hhu ", *(imagem->pData + i));
            

        } else {

            int soma = 0;
            int linha = i / imagem->c;
            int coluna = i % imagem->c;

            for (int j = linha - 1; j <= linha + 1; j++) {

                for (int k = coluna - 1; k <= coluna + 1; k++) {

                    soma += *(imagem->pData + (j * imagem->c + k));

                }

            }

            fprintf(newArquivo, "%hhu ", soma / 9);
            // *(pDadosSuavizados + i) = soma / 9;

        }

   }

    // return pDadosSuavizados;

}

void gerarImgSuavizada(struct pgm *pio, char *filename) {

    FILE *fp;

    char ch;
    char nomeImgSuavizada[100] = "suavizado_";
    strcat(nomeImgSuavizada, filename);

    printf("nome arquivo: %s\n", nomeImgSuavizada);

    if (!(fp = fopen(nomeImgSuavizada, "w"))) {
        
		perror("Erro.");
		exit(1);

	}

    // fprintf(fp, "%s\n", (pio->tipo == 2) ? "P2" : "P5");
    fprintf(fp, "%s\n", "P2");
	fprintf(fp, "%d %d\n",pio->c, pio->r);
	fprintf(fp, "%d\n", 255);

    janelaTresPorTres(pio, fp);
    
}