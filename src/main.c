#include "../include/global.h"

int main(){

  initScreen();

  srand(time(NULL));

  SDL_Event event;
  int quit = FALSE;

  initGame();
  displayGame();
  saveGame();

  while(quit == FALSE){
    if(SDL_WaitEvent(&event) != 0){

      switch(event.type){
        case SDL_KEYDOWN:

          switch(event.key.keysym.sym){
            case SDLK_UP:    move(UP);    break;
            case SDLK_DOWN:  move(DOWN);  break;
            case SDLK_LEFT:  move(LEFT);  break;
            case SDLK_RIGHT: move(RIGHT); break;

            case SDLK_q:     quit = TRUE;        break;
          }
          displayGame();
          saveGame();
          
          if(hasLost()) quit = TRUE;


          break;

        case SDL_QUIT: quit = TRUE; break;
        default: break;

      }

    }
  }

  exitScreen();

  return 0;

}
