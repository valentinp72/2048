#include "../include/global.h"
#include "../include/display.h"


void initScreen(){

  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();

  roboto = TTF_OpenFont("media/Roboto-Light.ttf", 65);

  screen = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
  renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);

  SDL_Surface *logo = IMG_Load("media/logo.png");

  if(logo != NULL) {
    SDL_SetWindowIcon(screen, logo);
  }

  SDL_FreeSurface(logo);

  SDL_SetRenderDrawColor(renderer, 228, 241, 254, 255);
  SDL_RenderClear(renderer);

  SDL_RenderPresent(renderer);

}

void exitScreen(){

  TTF_CloseFont(roboto);
  TTF_Quit();
  SDL_Quit();

}

void displayText(char * msg, TTF_Font *font, SDL_Color color){

  int texW = 0;
  int texH = 0;

  SDL_Surface * surface = TTF_RenderText_Blended(font, msg, color);
  SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);

  SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
  SDL_Rect dstrect = {(WIDTH - texW)/2, 0, texW, texH };


  SDL_RenderCopy(renderer, texture, NULL, &dstrect);
  SDL_RenderPresent(renderer);

  SDL_DestroyTexture(texture);
  SDL_FreeSurface(surface);

}
