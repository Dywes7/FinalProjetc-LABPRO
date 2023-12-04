all: main.e

main.e: main.o gerar_matriz_scm.o pgm.o quantizar_imgs.o suavizar_img.o menu.o
	gcc -o main.e main.o gerar_matriz_scm.o pgm.o quantizar_imgs.o suavizar_img.o menu.o

main.o: main.c 
	gcc -o main.o -c main.c

gerar_matriz_scm.o: gerar_matriz_scm.c
	gcc -o gerar_matriz_scm.o -c gerar_matriz_scm.c

quantizar_imgs.o: quantizar_imgs.c
	gcc -o quantizar_imgs.o -c quantizar_imgs.c

suavizar_img.o : suavizar_img.c
	gcc -o suavizar_img.o -c suavizar_img.c

menu.o : menu.c
	gcc -o menu.o -c menu.c

clean:
	rm -f *.o main.e