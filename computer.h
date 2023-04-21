#ifndef COMPUTER_H_INCLUDED
#define COMPUTER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "jeu.h"
#include "RectDimension.h"

typedef struct
{
    char *url;
    SDL_Rect pos_image_aff;
    SDL_Rect pos_image_init;
    SDL_Surface *img,*scaled;
    int etat_resize; 

}computer;



liste init_computer(int nb_img,SDL_Surface *s);
liste ajouter_pc_Fin(liste l, int i,SDL_Surface *s);
void computer_img_init(computer *c);
void computer_screen_init(computer *c);
void init_pc_photo_default(computer *c,char path_img[]);
void init_pc_photo_defaultxy(computer *c,char path_img[],int x,int y);

void pop_out_lowbar(computer *pc_lowbar);
void pop_lowbar_win(computer pc_lowbar,computer pc_window,SDL_Surface *screen);

void show_selected_icon(icon *icons,SDL_Event e,int *selected_icon,int *opened_screen_pc);

void move_window(computer *c,int window_in_drag,int *x,int *y);


#endif // COMPUTER_H_INCLUDED