#ifndef DER
#define DER


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct
{
  SDL_Surface *BgImg[8];
  SDL_Surface *vies;
  SDL_Surface *scores;

  SDL_Rect PositionBg;
  SDL_Rect positionperso;

  SDL_Rect camera;

  SDL_Rect posVie1;
  SDL_Rect posVie2;
  SDL_Rect posScore;
  
  TTF_Font *police;

  Mix_Music *music;

  int frame;
  int vie;
  int score;

} Background;

typedef struct
{
  char name[10];
  int score;
  int time;

  SDL_Surface *first;
  SDL_Rect pos;

} ScoreInfo;


void init_SDC_Background(Background *B);
void aff_SDC_Background(Background *B, SDL_Surface *screen);
void animer_SDC_Back(Background *B);
void SD_scrolling(Background *B, SDL_Rect posPerso, int direction);
void sauvegarder(ScoreInfo s, char *file);
void bestScore(ScoreInfo s[], int n, char *file);
void freeBackground(Background *B);

#endif
