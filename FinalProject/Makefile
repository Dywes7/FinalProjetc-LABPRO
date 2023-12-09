all: bin/main.e

bin/main.e: obj/main.o obj/gerar_matriz_scm.o obj/pgm.o obj/quantizar_imgs.o obj/suavizar_img.o obj/menu.o
	gcc -o bin/main.e obj/main.o obj/gerar_matriz_scm.o obj/pgm.o obj/quantizar_imgs.o obj/suavizar_img.o obj/menu.o

obj/main.o: src/main.c 
	gcc -o obj/main.o -c src/main.c

obj/gerar_matriz_scm.o: src/gerar_matriz_scm.c 
	gcc -o obj/gerar_matriz_scm.o -c src/gerar_matriz_scm.c

obj/pgm.o: src/pgm.c 
	gcc -o obj/pgm.o -c src/pgm.c

obj/quantizar_imgs.o: src/quantizar_imgs.c 
	gcc -o obj/quantizar_imgs.o -c src/quantizar_imgs.c

obj/suavizar_img.o: src/suavizar_img.c 
	gcc -o obj/suavizar_img.o -c src/suavizar_img.c

obj/menu.o: src/menu.c 
	gcc -o obj/menu.o -c src/menu.c

clean:
	rm -f obj/*.o bin/main.e
