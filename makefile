main: main.o jeu.o player.o player_side_scrolling.o input.o RectDimension.o computer.o resize.o background.o sidescrolling_BG.o image.o music.o collision.o textInput.o  jeu.h background.h player.h collision.h computer.h RectDimension.h textInput.h
	gcc main.o jeu.o player_side_scrolling.o background.o input.o resize.o player.o RectDimension.o image.o music.o sidescrolling_BG.o collision.o computer.o textInput.o -lSDL -lSDL_ttf -lSDL_mixer -lSDL_image -lm  -o main -g
sidescrolling_BG.o:sidescrolling_BG.c 
	gcc -c sidescrolling_BG.c -g
input.o:input.c
	gcc -c input.c -g
player_side_scrolling.o:player_side_scrolling.c
	gcc -c player_side_scrolling.c -g 
textInput.o:textInput.c
	gcc -c textInput.c -g 
RectDimension.o:RectDimension.c
	gcc -c RectDimension.c
collision.o:collision.c
	gcc -c collision.c -g 
player.o:player.c
	gcc -c player.c -g 
background.o:background.c 
	gcc -c background.c -g
music.o:music.c
	gcc -c music.c -g
computer.o:computer.c
	gcc -c computer.c 
image.o:image.c
	gcc -c image.c -g
resize.o:resize.c
	gcc -c resize.c -g
main.o:main.c
	gcc -c main.c -g
jeu.o:jeu.c
	gcc -c jeu.c -g
clean:
	rm main
