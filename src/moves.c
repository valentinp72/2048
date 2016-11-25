#include "../include/global.h"

void initGame(){
  int i, j;

  for(i = 0 ; i < LINES ; i++){
    for(j = 0 ; j < COLUMNS ; j++){
      game[i][j] = 0;
    }
  }

  game[0][0] = 2;
  game[0][3] = 4;
  game[1][0] = 8;


}

void move(t_direction dir){

  int i, j;

  switch (dir) {
    case UP    :  break;
    case DOWN  :  break;
    case LEFT  :  break;
    case RIGHT :  break;
  }

  if(dir == RIGHT){
    for(i = 0 ; i < LINES ; i++){
      for(j = COLUMNS - 2 ; j >= 0 ; j++){
        if(game[i][j+1] == 0){
          //game[i][j+1] = game[i][j];
          //game[i][j] = 0;
        }
      }
    }
  }

}
