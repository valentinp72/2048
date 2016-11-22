INCLUDE = include/global.h

all: main.o
	gcc $^ -o 2048 -framework SDL2 -framework SDL2_image -framework SDL2_ttf

main.o: src/main.c ${INCLUDE}
	gcc -c $<
