#ifndef minimap_H
#define minimao_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "background.h"
typedef struct
{
    SDL_Surface *map;
    SDL_Surface *minijoueur;
    SDL_Rect positionmap;
    SDL_Rect positionminijoueur;
} minimap;
void init_map(minimap *m);
void init_map2(minimap *m);
void MAJMinimap(SDL_Rect posJoueur, minimap *m, SDL_Rect camera, int redimensionnement);
void MAJMinimap2(SDL_Rect posJoueur, minimap *m, SDL_Rect camera, int redimensionnement);
void afficherminimap(minimap m,background b, SDL_Surface *screen);
void afficherminimap2(minimap m,background b, SDL_Surface *screen);

#endif