
#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h> 
/**
* @struct minimap
* @brief struct for minimap
*/
typedef struct{
SDL_Surface *image[125];
SDL_Rect position;
SDL_Surface *bonhomme;
SDL_Rect PositionBonhomme;
int minimap_width;
int minimap_height;
SDL_Surface *anim[10];
SDL_Rect pos;
int frames;
}minimap;
typedef struct temps
{
SDL_Surface *screen;
SDL_Rect timepose;
TTF_Font *police;
char timeText[20];
}temps;
/*typedef struct {
    SDL_Surface* sprite;    // image du sprite sheet
    int direction;          // direction de déplacement
    SDL_Rect postScreen;    // position par rapport à l'écran
    SDL_Rect posSprite;     // position par rapport au sprite sheet
}Entity;*/
void initmap(minimap *m); 
void MAJMinimap (SDL_Rect posJoueur,minimap *m,int redimensionement);
void afficherMinimap(minimap m,SDL_Surface *screen); 
void afficherTemps (int temps,SDL_Surface *screen);
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);
int collision_parfaite(SDL_Surface *mask , SDL_Rect posjoueur );
/*void initializeEntity(Entity* entity, SDL_Surface* sprite, int x, int y);
void animateEntity(Entity* entity);*/
void animateminimap(minimap* m);
#endif
