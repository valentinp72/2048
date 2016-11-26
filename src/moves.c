#include "../include/global.h"

void initGame(){
  int i, j;

  for(i = 0 ; i < LINES ; i++){
    for(j = 0 ; j < COLUMNS ; j++){
      game[i][j] = 0;
    }
  }
  placeRandom();
}
int randab(int a, int b) {
	int tmp;

	if(b <= a){
		tmp =   a;
		a   =   b;
		b   = tmp;
	}
	return (rand()%(b-a)) + a;
}

int hasLost(){

  int i, j;

  for(i = 0 ; i < LINES ; i++){
    for(j = 0 ; j < COLUMNS ; j++){
      if(game[i][j] == 0) return FALSE;
    }
  }
  return TRUE;
}

void placeRandom(){
  int i, j;

  if(!hasLost()){
    do{
      i = randab(0, LINES);
      j = randab(0, COLUMNS);
    }while(game[i][j] != 0);

    game[i][j] = 2;
  }

}

void move(t_direction dir){

  int i, j, k;
  int hasMoved = FALSE;

  if(dir == LEFT){
    for(k = 1 ; k <= 4 ; k++){
      for(i = 0 ; i < LINES ; i++){
        for(j = 1 ; j < COLUMNS ; j++){
          if(game[i][j-1] == 0){
            game[i][j-1] = game[i][j];
            game[i][j] = 0;
            hasMoved = TRUE;
          }
          if(game[i][j-1] == game[i][j]){
            game[i][j-1] = game[i][j] * 2;
            game[i][j] = 0;
            hasMoved = TRUE;
          }
        }
      }
    }
  }

  if(dir == RIGHT){
    for(k = 1 ; k <= 4 ; k++){
      for(i = 0 ; i < LINES ; i++){
        for(j = COLUMNS - 2 ; j >= 0 ; j--){
          if(game[i][j+1] == 0){
            game[i][j+1] = game[i][j];
            game[i][j] = 0;
            hasMoved = TRUE;
          }
          if(game[i][j+1] == game[i][j]){
            game[i][j+1] = game[i][j] * 2;
            game[i][j] = 0;
            hasMoved = TRUE;
          }
        }
      }
    }
  }

  if(dir == UP){
    for(k = 1 ; k <= 4 ; k++){
      for(i = 1 ; i < LINES ; i++){
        for(j = 0 ; j < COLUMNS ; j++){
          if(game[i-1][j] == 0){
            game[i-1][j] = game[i][j];
            game[i][j] = 0;
            hasMoved = TRUE;
          }
          if(game[i-1][j] == game[i][j]){
            game[i-1][j] = game[i][j] * 2;
            game[i][j] = 0;
            hasMoved = TRUE;
          }
        }
      }
    }
  }


  if(dir == DOWN){
    for(k = 1 ; k <= 4 ; k++){
      for(i = LINES - 2 ; i >= 0 ; i--){
        for(j = 0 ; j < COLUMNS ; j++){
          if(game[i+1][j] == 0){
            game[i+1][j] = game[i][j];
            game[i][j] = 0;
            hasMoved = TRUE;
          }
          if(game[i+1][j] == game[i][j]){
            game[i+1][j] = game[i][j] * 2;
            game[i][j] = 0;
            hasMoved = TRUE;
          }
        }
      }
    }
  }
  // Empeche de placer un pion si le joueur n'as pas joué un coup valide
  if(hasMoved) placeRandom();

}
