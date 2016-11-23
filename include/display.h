#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

#define HEIGHT 700
#define WIDTH  600

SDL_Window *screen;
SDL_Renderer *renderer;
SDL_Surface *texte;
SDL_Rect position;
TTF_Font *roboto = NULL;

SDL_Color BLACK_C = {0, 0, 0};
SDL_Color WHITE_C = {255, 255, 255};

void initScreen();
void exitScreen();
void displayText(char * msg, TTF_Font *font, SDL_Color color);

#endif
