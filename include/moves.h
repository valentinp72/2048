#ifndef MOVES_H
#define MOVES_H

#include "global.h"

typedef enum {UP, DOWN, LEFT, RIGHT} t_direction;

void initGame();
int hasLost();
void placeRandom();
void move(t_direction dir);

#endif
