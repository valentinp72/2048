#include "../include/global.h"

int main(){

  initScreen();

  srand(time(NULL));

  SDL_Event event;
  int quit = FALSE;

  initGame();
  displayGame();

  while(quit == FALSE){
    while(SDL_PollEvent(&event)){

      switch(event.type){
        case SDL_KEYDOWN:
          if(hasLost()) initGame();
          displayGame();
          switch(event.key.keysym.sym){
            case SDLK_UP:    move(UP);    break;
            case SDLK_DOWN:  move(DOWN);  break;
            case SDLK_LEFT:  move(LEFT);  break;
            case SDLK_RIGHT: move(RIGHT); break;

            case SDLK_q:     quit = TRUE;        break;
          }
          displayGame();

          break;

        case SDL_QUIT: quit = TRUE; break;
        default: break;

      }

    }
  }

  exitScreen();

  return 0;

}
