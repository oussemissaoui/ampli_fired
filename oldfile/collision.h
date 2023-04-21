#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

SDL_Color GetPixel(SDL_Surface *perso , int x,int y);

int collision_right(SDL_Surface *mask , SDL_Rect posperso ,SDL_Rect posperso_aff);
int collision_left(SDL_Surface *mask , SDL_Rect posperso  ,SDL_Rect posperso_aff);
int collision_up(SDL_Surface *mask , SDL_Rect posperso    ,SDL_Rect posperso_aff);
int collision_down(SDL_Surface *mask , SDL_Rect posperso  ,SDL_Rect posperso_aff);


#endif