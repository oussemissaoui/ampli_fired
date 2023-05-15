#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y, int xOffset, int yOffset);
int collision_parfaite_right(SDL_Surface *mask , SDL_Rect posjoueur , int xOffset,int yOffset);
int collision_parfaite_left(SDL_Surface *mask , SDL_Rect posjoueur  , int xOffset,int yOffset);
int collision_parfaite_up(SDL_Surface *mask , SDL_Rect posjoueur    , int xOffset,int yOffset);
int collision_parfaite_down(SDL_Surface *mask , SDL_Rect posjoueur  , int xOffset,int yOffset);
int collision_all_body(SDL_Surface *mask , SDL_Rect posjoueur  , int xOffset,int yOffset);
int collision_out_home(SDL_Surface *mask , SDL_Rect posjoueur  , int xOffset,int yOffset);

////////////////out side collision///////////////////////
int SS_collision_parfaite_down(SDL_Surface *mask , SDL_Rect posjoueur , int xOffset,int yOffset);
int SS_collision_green_zone(SDL_Surface *mask , SDL_Rect posjoueur , int xOffset,int yOffset);



#endif

