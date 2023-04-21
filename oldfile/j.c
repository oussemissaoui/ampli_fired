#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "j.h"




void load_all_img(SDL_Surface *i[],int nb_img)
{
    char filename[10];
    for (int j=0;j<nb_img;j++)
    {
        sprintf(filename,"BIG/%d.png",j);
        i[j]=IMG_Load(filename);
        /*if(i[j]==NULL)
        {
            printf("Error can't Load img : %s",SDL_GetError());
        }*/
    }
}
void load_all_img_v2(image *i[],int nb_img)
{
    char filename[30];
    for (int j=0;j<nb_img;j++)
    {
        sprintf(filename,"IMG/effect_set/%d.png",j);
        i[j]->img=IMG_Load(filename);
        /*if(i[j]->img==NULL)
        {
            printf("Error can't Load img : %s",SDL_GetError());
        }*/
    }
}
void load_all_img_v3(image *i[],int nb_img)
{
    char filename[50];
    for (int j=0;j<nb_img;j++)
    {
        sprintf(filename,"IMG/effect_set/Music settings/%d.png",j);
        i[j]->img=IMG_Load(filename);
        /*if(i[j]->img==NULL)
        {
            printf("Error can't Load img : %s",SDL_GetError());
        }*/
    }
}
void load_all_img_v4(image *i[],int nb_img)
{
    char filename[50];
    for (int j=0;j<nb_img;j++)
    {
        sprintf(filename,"IMG/effect_set/Effects settings/%d.png",j);
        i[j]->img=IMG_Load(filename);
       /* if(i[j]->img==NULL)
        {
            printf("Error can't Load img : %s",SDL_GetError());
        }*/
    }
}

SDL_Surface* first_resizeimg(SDL_Surface *i)
{
 SDL_Surface *scaled_i;
 scaled_i=SDL_CreateRGBSurface(SDL_SWSURFACE,1280,720,i->format->BitsPerPixel,i->format->Rmask,i->format->Gmask,i->format->Bmask,i->format->Amask);
 /*if(scaled_i==NULL)
 {
    printf("Error can't resize img : %s",SDL_GetError());
 }*/
    SDL_SoftStretch(i,NULL,scaled_i,NULL);
    return scaled_i;
}

void effect_video(image *i[],int nb_img)
{
    
    char filename[25];
    for (int j=0;j<nb_img;j++)
    {
        sprintf(filename,"IMG/gif_start/%d.png",j);
        i[j]->img=IMG_Load(filename);
        /*if(i[j]->img==NULL)
        {
            printf("Error can't Load img : %s",SDL_GetError());
        }*/
        i[j]->scaled=first_resizeimg( i[j]->img);
        
    }
}



SDL_Surface* resizeimg(SDL_Surface *s,SDL_Surface *i)
{
 SDL_Surface *scaled_i;
 scaled_i=SDL_CreateRGBSurface(SDL_SWSURFACE,s->w,s->h,i->format->BitsPerPixel,i->format->Rmask,i->format->Gmask,i->format->Bmask,i->format->Amask);
 if(scaled_i==NULL)
 {
    printf("Error can't resize img : %s",SDL_GetError());
 }
    SDL_SoftStretch(i,NULL,scaled_i,NULL);
    SDL_BlitSurface(scaled_i,NULL,s,NULL);
    SDL_UpdateRect(s,0,0,0,0);
    return scaled_i;
}


/*SDL_Surface* resize_per_percentage(SDL_Surface *s,SDL_Surface *i,int perc)
{
 SDL_Surface *scaled_i;
 scaled_i=SDL_CreateRGBSurface(SDL_SWSURFACE,s->w*perc/100,s->h*perc/100,i->format->BitsPerPixel,i->format->Rmask,i->format->Gmask,i->format->Bmask,i->format->Amask);
 if(scaled_i==NULL)
 {
    printf("Error can't resize img : %s",SDL_GetError());
 }
    SDL_SoftStretch(i,NULL,scaled_i,NULL);
    SDL_BlitSurface(scaled_i,NULL,s,NULL);
    SDL_UpdateRect(s,0,0,0,0);
    return scaled_i;
}*/



void resize_allimg(SDL_Surface *s,SDL_Surface *i[],SDL_Surface *scaled_i[],int nb_img)
{
    for(int j=0;j<nb_img;j++)
    {
        scaled_i[j]=SDL_CreateRGBSurface(SDL_SWSURFACE,s->w,s->h,i[j]->format->BitsPerPixel,i[j]->format->Rmask,i[j]->format->Gmask,i[j]->format->Bmask,i[j]->format->Amask);
        SDL_SoftStretch(i[j],NULL,scaled_i[j],NULL);
        SDL_BlitSurface(scaled_i[j],NULL,s,NULL);
        SDL_UpdateRect(s,0,0,0,0);
    }
}







void aff_allimg(SDL_Surface *s,SDL_Surface *scaled_i[],int nb_img)
{
 for(int j=0 ;j<nb_img;j++)
 {
  SDL_BlitSurface(scaled_i[j],NULL,s,NULL);
  SDL_Flip(s);
  
 }
}



void aff_oneimg_loop(SDL_Surface *s,SDL_Surface *scaled_i,int nb_img,SDL_Rect m)
{
    for(int j=0 ;j<nb_img;j++)
    {
        SDL_BlitSurface(scaled_i,NULL,s,&m);
        SDL_Flip(s); 
    }
}

void play_music(Mix_Music *m,char musicpath[])
{
    m=Mix_LoadMUS(musicpath);
    Mix_VolumeMusic(42);
    Mix_PlayMusic(m,-1);
}

int mouseinter(SDL_Surface *s,int x,int y,int w,int h)
{
    int width,height,posx,posy,posw,posh;
    int mousex,mousey;
    width=s->w;
    height=s->h;
    posx=(x*width)/100;
    posw=(w*width)/100;
    posy=(y*height)/100;
    posh=(h*height)/100;
    Uint32 locate=SDL_GetMouseState(&mousex,&mousey);
    if((posx<mousex && posw>mousex)&&(posy<mousey && posh>mousey))
        {
            return 1;
        }
    else{
         return 0;
        }
}





































