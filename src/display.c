#include "../include/global.h"

void initColors(){
  BLACK_C.r = 0;
  BLACK_C.g = 0;
  BLACK_C.b = 0;

  WHITE_C.r = 255;
  WHITE_C.g = 255;
  WHITE_C.b = 255;

  BG_COLOR.r = 228;
  BG_COLOR.g = 241;
  BG_COLOR.b = 254;
}

void initScreen(){

  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();

  initColors();

  roboto = TTF_OpenFont("media/Roboto-Light.ttf", 100);

  screen = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
  SDL_SetWindowPosition(screen, 0, 0);
  renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);

  SDL_Surface *logo = IMG_Load("media/logo.png");


  t2 = IMG_LoadTexture(renderer, "media/tiles/2.jpg");;
  t4 = IMG_LoadTexture(renderer, "media/tiles/4.jpg");;
  t8 = IMG_LoadTexture(renderer, "media/tiles/8.jpg");;
  t16 = IMG_LoadTexture(renderer, "media/tiles/16.jpg");;
  t32 = IMG_LoadTexture(renderer, "media/tiles/32.jpg");;
  t64 = IMG_LoadTexture(renderer, "media/tiles/64.jpg");;
  t128 = IMG_LoadTexture(renderer, "media/tiles/128.jpg");;
  t256 = IMG_LoadTexture(renderer, "media/tiles/256.jpg");;
  t512 = IMG_LoadTexture(renderer, "media/tiles/512.jpg");;
  t1024 = IMG_LoadTexture(renderer, "media/tiles/1024.jpg");;
  t2048 = IMG_LoadTexture(renderer, "media/tiles/2048.jpg");;
  tERROR = IMG_LoadTexture(renderer, "media/tiles/error.jpg");;


  if(logo != NULL) {
    SDL_SetWindowIcon(screen, logo);
  }

  SDL_FreeSurface(logo);

  SDL_SetRenderDrawColor(renderer, 228, 241, 254, 255);
  SDL_RenderClear(renderer);

  SDL_RenderPresent(renderer);

}

void exitScreen(){

  SDL_DestroyTexture(t2);
  SDL_DestroyTexture(t4);
  SDL_DestroyTexture(t8);
  SDL_DestroyTexture(t16);
  SDL_DestroyTexture(t32);
  SDL_DestroyTexture(t64);
  SDL_DestroyTexture(t128);
  SDL_DestroyTexture(t256);
  SDL_DestroyTexture(t512);
  SDL_DestroyTexture(t1024);
  SDL_DestroyTexture(t2048);
  SDL_DestroyTexture(tERROR);


  TTF_CloseFont(roboto);
  TTF_Quit();
  SDL_Quit();

}

void displayText(char * msg, TTF_Font *font, SDL_Color color, int x, int y, float size){

  int texW = 0;
  int texH = 0;

  SDL_Surface * surface = TTF_RenderText_Shaded(font, msg, color, BG_COLOR);
  SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);

  SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
  SDL_Rect dstrect = {x, y, texW*size, texH*size};


  SDL_RenderCopy(renderer, texture, NULL, &dstrect);

  SDL_DestroyTexture(texture);
  SDL_FreeSurface(surface);

}

void displayTextCentered(char * msg, TTF_Font *font, SDL_Color color, int y, float size){

  int texW = 0;
  int texH = 0;

  SDL_Surface * surface = TTF_RenderText_Shaded(font, msg, color, BG_COLOR);
  SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);

  SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
  SDL_Rect dstrect = {(WIDTH - texW*size)/2, y, texW*size, texH*size};

  SDL_RenderCopy(renderer, texture, NULL, &dstrect);

  SDL_DestroyTexture(texture);
  SDL_FreeSurface(surface);

}

void displayGame(){

  int i, j;
  SDL_Rect pos;
  SDL_Texture *texture;

  pos.w = 100;
  pos.h = 100;

  SDL_RenderClear(renderer);

  displayTextCentered("2048", roboto, BLACK_C, 0, 1);
  displayText("@valentinp72", roboto, BLACK_C, 10, HEIGHT-40, 0.3);

  for(i = 0 ; i < LINES ; i++){
    for(j = 0 ; j < COLUMNS ; j++){
      pos.x = (j * 100) + 100;
      pos.y = (i * 100) + 200;
      switch (game[i][j]) {
        case 2 : texture = t2;       break;
        case 4 : texture = t4;       break;
        case 8 : texture = t8;       break;
        case 16 : texture = t16;     break;
        case 32 : texture = t32;     break;
        case 64 : texture = t64;     break;
        case 128 : texture = t128;   break;
        case 256 : texture = t256;   break;
        case 512 : texture = t512;   break;
        case 1024 : texture = t1024; break;
        case 2048 : texture = t2048; break;

        default : texture = tERROR;

      }
      SDL_RenderCopy(renderer, texture, NULL, &pos); // Copie du sprite grâce au SDL_Renderer
    }
  }

  SDL_RenderPresent(renderer);

}
