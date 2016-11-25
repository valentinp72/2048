#include "../include/global.h"

int main(){

  initScreen();

  SDL_Event event;
  int quit = FALSE;

  initGame();

  while(quit == FALSE){
    while(SDL_PollEvent(&event)){

      switch(event.type){
        case SDL_KEYDOWN:
          switch(event.key.keysym.sym){
            case SDLK_UP:    move(UP);    break;
            case SDLK_DOWN:  move(DOWN);  break;
            case SDLK_LEFT:  move(LEFT);  break;
            case SDLK_RIGHT: move(RIGHT); break;

            case SDLK_q:     quit = TRUE;        break;
          } break;

        case SDL_QUIT: quit = TRUE; break;
        default: break;

      }
      displayGame();

    }
  }

  exitScreen();

  return 0;

}
