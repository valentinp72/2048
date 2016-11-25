INCLUDE = include/global.h include/display.h include/moves.h

all: display.o moves.o main.o
	gcc $^ -o 2048 -framework SDL2 -framework SDL2_image -framework SDL2_ttf

main.o: src/main.c ${INCLUDE}
	gcc -c $<

display.o: src/display.c
	gcc -c $<

moves.o: src/moves.c
	gcc -c $<

clear:
	rm *.o
