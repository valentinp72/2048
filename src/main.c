#include "../include/global.h"
#include "../include/display.h"

int main(){

  initScreen();

  SDL_Event event;
  int quit = FALSE;

  displayText("2048", roboto, BLACK_C, 0, 0);
  displayTextCentered("2048", roboto, BLACK_C, 0);

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

  exitScreen();

  return 0;

}
