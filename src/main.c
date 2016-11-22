#include "../include/global.h"

int main(){

  SDL_Window *screen;
  SDL_Renderer *renderer;
  SDL_Event event;
  SDL_Surface *texte;
  SDL_Surface *test = NULL;
  SDL_Rect position;

  SDL_Color blackC = {0, 0, 0};

  TTF_Font *roboto = NULL;

  int quit = FALSE;

  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();

  roboto = TTF_OpenFont("media/Roboto-Light.ttf", 65);
  screen = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 700, 0);
  renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);

  SDL_Surface *logo = IMG_Load("media/logo.png");

  if(logo != NULL) {
    SDL_SetWindowIcon(screen, logo);
  }

  SDL_FreeSurface(logo);

  SDL_SetRenderDrawColor(renderer, 228, 241, 254, 255);
  SDL_RenderClear(renderer);

  SDL_Rect rect;
  rect.x = 0;
  rect.y = 0;
  rect.w = 32;
  rect.h = 32;

  SDL_RenderPresent(renderer);

  texte = TTF_RenderText_Blended(roboto, "Hello", blackC);
  position.x = 180;
  position.y = 210;
  SDL_BlitSurface(texte, NULL, test, &position);
  SDL_RenderCopy( renderer, test, NULL, NULL); 

  while(quit == FALSE){

    while(SDL_PollEvent(&event)){

      switch(event.type){
        case SDL_KEYDOWN:

          switch(event.key.keysym.sym){
            case SDLK_UP:    printf("Haut\n");   break;
            case SDLK_DOWN:  printf("Bas\n");    break;
            case SDLK_LEFT:  printf("Gauche\n"); break;
            case SDLK_RIGHT: printf("Droit\n");  break;

            case SDLK_q:     quit = TRUE;        break;
          } break;

        case SDL_QUIT: quit = TRUE; break;
        default: break;

      }
    }
  }

  TTF_CloseFont(roboto);
  TTF_Quit();
  SDL_Quit();

  return 0;

}
