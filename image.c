#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "jeu.h"




//init images
    void init_loading_img(image *i[],int nb_img)
    {
        for (int j=0;j<nb_img;j++)
        {
            sprintf(i[j]->url,"loading_img/%d.png",j);
            i[j]->img=IMG_Load(i[j]->url);
            i[j]->scaled=first_resizeimg(i[j]->img);
        }
    }
    
    void init_bg_img(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load)
    {
        int count=0;
        for (int j=0;j<nb_img;j++)
        {
            sprintf(i[j]->url,"BIG/%d.png",j);
            i[j]->img=IMG_Load(i[j]->url);
            i[j]->scaled=first_resizeimg(i[j]->img);
            SDL_BlitSurface(load[count]->scaled,NULL,s,NULL);
            count = (count+1)% num_load;
            SDL_Flip(s);
            
        }
    }
    void init_start_img(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load)
    {
        int count=0;
        for (int j=0;j<nb_img;j++)
        {
            sprintf(i[j]->url,"loading_img/start/%d.png",j);
            i[j]->img=IMG_Load(i[j]->url);
            i[j]->scaled=first_resizeimg(i[j]->img);
            SDL_BlitSurface(load[count]->scaled,NULL,s,NULL);
            count = (count+1)% num_load;
            SDL_Flip(s);
            
        }
    }
    void init_setting_img(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load)
    {
        int count=0;
        for (int j=0;j<nb_img;j++)
        {
            sprintf(i[j]->url,"loading_img/setting/%d.png",j);
            i[j]->img=IMG_Load(i[j]->url);
            i[j]->scaled=first_resizeimg(i[j]->img);
            SDL_BlitSurface(load[count]->scaled,NULL,s,NULL);
            count = (count+1)% num_load;
            SDL_Flip(s);
            
        }
    }
    void init_exit_img(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load)
    {
        int count=0;
        for (int j=0;j<nb_img;j++)
        {
            sprintf(i[j]->url,"loading_img/exit/%d.png",j);
            i[j]->img=IMG_Load(i[j]->url);
            i[j]->scaled=first_resizeimg(i[j]->img);
            SDL_BlitSurface(load[count]->scaled,NULL,s,NULL);
            count = (count+1)% num_load;
            SDL_Flip(s);
            
        }
    }
    void init_effect_set_img(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load)
    {
        int count=0;
        for (int j=0;j<nb_img;j++)
        {
            sprintf(i[j]->url,"loading_img/eff_set/%d.png",j);
            i[j]->img=IMG_Load(i[j]->url);
            i[j]->scaled=first_resizeimg(i[j]->img);
            SDL_BlitSurface(load[count]->scaled,NULL,s,NULL);
            count = (count+1)% num_load;
            SDL_Flip(s);
            
        }
    }
    void init_mus_eff_img(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load)
    {
        int count=0;
        for (int j=0;j<nb_img;j++)
        {
            sprintf(i[j]->url,"loading_img/mus_eff/%d.png",j);
            i[j]->img=IMG_Load(i[j]->url);
            i[j]->scaled=first_resizeimg(i[j]->img);
            SDL_BlitSurface(load[count]->scaled,NULL,s,NULL);
            count = (count+1)% num_load;
            SDL_Flip(s);
            
        }
    }
    void init_sfx_eff_img(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load)
    {
        int count=0;
        for (int j=0;j<nb_img;j++)
        {
            sprintf(i[j]->url,"loading_img/sfx_eff/%d.png",j);
            i[j]->img=IMG_Load(i[j]->url);
            i[j]->scaled=first_resizeimg(i[j]->img);
            SDL_BlitSurface(load[count]->scaled,NULL,s,NULL);
            count = (count+1)% num_load;
            SDL_Flip(s);
            
        }
    }
    void init_clk_eff_img(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load)
    {
        int count=0;
        for (int j=0;j<nb_img;j++)
        {
            sprintf(i[j]->url,"loading_img/clk_eff/%d.png",j);
            i[j]->img=IMG_Load(i[j]->url);
            SDL_BlitSurface(load[count]->scaled,NULL,s,NULL);
            count = (count+1)% num_load;
            SDL_Flip(s);       
        }
    }
    void init_start_tv_eff(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load)
    {
        int count=0;
        for (int j=0;j<nb_img;j++)
        {
            sprintf(i[j]->url,"loading_img/start_tv/%d.png",j);
            i[j]->img=IMG_Load(i[j]->url);
            i[j]->scaled=first_resizeimg(i[j]->img);
            SDL_BlitSurface(load[count]->scaled,NULL,s,NULL);
            count = (count+1)% num_load;
            SDL_Flip(s);       
        }
    }
    void init_extra(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load)
    {
        int count=0;
        for (int j=0;j<nb_img;j++)
        {
            sprintf(i[j]->url,"loading_img/extra/%d.png",j);
            i[j]->img=IMG_Load(i[j]->url);
            i[j]->scaled=first_resizeimg(i[j]->img);
            SDL_BlitSurface(load[count]->scaled,NULL,s,NULL);
            count = (count+1)% num_load;
            SDL_Flip(s);       
        }
    }
     void init_choice_exit(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load)
    {
        int count=0;
        for (int j=0;j<nb_img;j++)
        {
            sprintf(i[j]->url,"loading_img/choix_leave/%d.png",j);
            i[j]->img=IMG_Load(i[j]->url);
            i[j]->scaled=first_resizeimg(i[j]->img);
            SDL_BlitSurface(load[count]->scaled,NULL,s,NULL);
            count = (count+1)% num_load;
            SDL_Flip(s);       
        }
    }
    

//end of init images
