#ifndef player_H_INCLUDED
#define player_H_INCLUDED
#include "input.h"
//#define Ground 427
#include <SDL/SDL_ttf.h>
#include "background.h"

typedef struct
{
    SDL_Surface *allMvt;
     SDL_Surface *vies;
     SDL_Surface *scores;
    SDL_Rect heroPos;
    SDL_Rect herosprite;

    int frame;
    float xStep, yStep;
    float velocity, speed;
    int direction; // 0: no move 1:right move -1: left move (num kima repere fel math )
    int last_direction; // 1 or -1 we will save the last direction  right or left 
    int col;
    int col_down;
    float VarX;
    int Ground;


    SDL_Rect posVie1;
    SDL_Rect posVie2;
    SDL_Rect posScore;
 
    TTF_Font *police;
    int vie;
    int score;
    int groundd,lastground;



}Hero;




void init_hero(Hero *h);
void afficher_Hero(Hero *h, SDL_Surface *screen);
void idleAnimation(Hero *h);
void leftAndRightHeroMvtR(Hero *hero,Background B,Input I, Uint32 dt);
void runAnimation(Hero *h);
//void jumpHeroMvt(Hero *hero, Input *I);
void jumpHeroMvt(Hero *hero, Input *I,Background *B);
void jumpAnimation(Hero *h);
void attackAnimation(Hero *h,Input *I);



#endif
