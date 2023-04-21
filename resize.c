#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "jeu.h"
//resize function
SDL_Surface* first_resizeimg(SDL_Surface *i)
{
    SDL_Surface *scaled_i;
        scaled_i=SDL_CreateRGBSurface(SDL_SWSURFACE,1280,720,i->format->BitsPerPixel,i->format->Rmask,i->format->Gmask,i->format->Bmask,i->format->Amask);
        SDL_SoftStretch(i,NULL,scaled_i,NULL);
        
    return scaled_i;
}
SDL_Surface* resizeimg(SDL_Surface *s,SDL_Surface *i)
{
        SDL_Surface *scaled_i;
        scaled_i=SDL_CreateRGBSurface(SDL_SWSURFACE,s->w,s->h,i->format->BitsPerPixel,i->format->Rmask,i->format->Gmask,i->format->Bmask,i->format->Amask);
        SDL_SoftStretch(i,NULL,scaled_i,NULL);
        return scaled_i;
}
    //this function need to be updated everytime i add new images etc ..
void resize_5images(SDL_Surface *s,image *a[],int nb_imga,image *b[],int nb_imgb,image *c[],int nb_imgc,image *d[],int nb_imgd,image *e[],int nb_imge)
{
    for (int j=0;j<nb_imga;j++)
    {
        free(a[j]->scaled);
        a[j]->scaled=resizeimg(s,a[j]->img);
    } 
    for (int j=0;j<nb_imgb;j++)
    {
        
        free(b[j]->scaled);
        b[j]->scaled=resizeimg(s,b[j]->img);
    }
    for (int j=0;j<nb_imgc;j++)
    {
        
        free(c[j]->scaled);
        c[j]->scaled=resizeimg(s,c[j]->img);
    }
    for (int j=0;j<nb_imgd;j++)
    {
       
        free(d[j]->scaled);
        d[j]->scaled=resizeimg(s,d[j]->img);
    }
    for (int j=0;j<nb_imge;j++)
    {
        
        free(e[j]->scaled);
        e[j]->scaled=resizeimg(s,e[j]->img);
    }
}
void resize_4images(SDL_Surface *s,image *a[],int nb_imga,image *b[],int nb_imgb,image *c[],int nb_imgc,image *d[],int nb_imgd)
{
    for (int j=0;j<nb_imga;j++)
    {
        a[j]->scaled=resizeimg(s,a[j]->img);
    } 
    for (int j=0;j<nb_imgb;j++)
    {
        
        
        b[j]->scaled=resizeimg(s,b[j]->img);
    }
    for (int j=0;j<nb_imgc;j++)
    {
        
        
        c[j]->scaled=resizeimg(s,c[j]->img);
    }
    for (int j=0;j<nb_imgd;j++)
    {
        
        d[j]->scaled=resizeimg(s,d[j]->img);
    }
}
void resize_1image(SDL_Surface *s,image *a[],int nb_imga)
{
    
    for (int j=0;j<nb_imga;j++)
    {
        free(a[j]->scaled);
        a[j]->scaled=resizeimg(s,a[j]->img);
    } 
}
//end of resize Funtion ::()