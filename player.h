/**
* @struct personne
* @brief struct for personne
*/
#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "jeu.h"

typedef struct
{
    char *url;
    SDL_Surface *img; /*!< Surface. */
    SDL_Rect pos_image_aff,pos_image_init;
    int nb_vie;
    int direction_axe_x; // 0:no move 1: right  -1:left
    int direction_axe_y; // 0:no move 1: down  -1:up
    
    int last_direction;
   

    int move;
    int col;
    int frame;
    float speed;
    int colright,colleft,coldown,colup;



}personne;



void initPerso(personne *p);
void afficherPerso(personne p, SDL_Surface * screen);
void movePerso (personne *p);
void animerPerso (personne* p);


#endif // PLAYER_H_INCLUDED