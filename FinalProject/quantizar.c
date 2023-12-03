void quantizarImg(char *,int,int,int);

void quantizarImg(char *pData, int linha, int coluna, int nivel){
    int m = (256)/nivel;
    for (int i = 0; i < (linha*coluna); i++)
    {
        *(pData + i) = (int)*(pData + i)/m;
    }   
}

