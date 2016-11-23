INCLUDE = include/global.h include/display.h

all: display.o main.o
	gcc $^ -o 2048 -framework SDL2 -framework SDL2_image -framework SDL2_ttf

main.o: src/main.c ${INCLUDE}
	gcc -c $<

display.o: src/display.c
	gcc -c $<

clear:
	rm *.o
