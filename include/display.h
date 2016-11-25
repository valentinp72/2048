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
SDL_Surface *ecran;
SDL_Rect position;
TTF_Font *roboto;

SDL_Texture *t2;
SDL_Texture *t4;
SDL_Texture *t8;
SDL_Texture *t16;
SDL_Texture *t32;
SDL_Texture *t64;
SDL_Texture *t128;
SDL_Texture *t256;
SDL_Texture *t512;
SDL_Texture *t1024;
SDL_Texture *t2048;
SDL_Texture *tERROR;


SDL_Color BLACK_C;
SDL_Color WHITE_C;
SDL_Color BG_COLOR;

void initScreen();
void exitScreen();
void displayText(char * msg, TTF_Font *font, SDL_Color color, int x, int y, float size);
void displayTextCentered(char * msg, TTF_Font *font, SDL_Color color, int y, float size);
void displayGame();

#endif
