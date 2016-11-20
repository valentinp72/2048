#include "../include/global.h"

int main(){

  SDL_Init (SDL_INIT_VIDEO);

  SDL_Window *screen;
  SDL_Renderer *renderer;

  screen = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
  renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);

  SDL_Surface *logo = IMG_Load("media/logo.png");

  if(logo != NULL) {
    SDL_SetWindowIcon(screen, logo);
  }

  SDL_FreeSurface(logo);

  SDL_Rect rect;
  rect.x = 0;
  rect.y = 0;
  rect.w = 32;
  rect.h = 32;

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_RenderDrawRect(renderer, &rect);

  SDL_RenderPresent(renderer);


  SDL_Quit();

  return 0;

}
