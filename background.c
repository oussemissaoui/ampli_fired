#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "background.h"

void initBack(background * b)
{
            b->url="loading_img/map/towork.png"; //map.png
            b->img=IMG_Load(b->url);
            if(b->img==NULL)
            {
                printf("error laoding map");
            }
            /*b->pos_image_aff.x=4349;
            b->pos_image_aff.y=4605;
            b->pos_image_aff.w=1280;
            b->pos_image_aff.h=720;*/
            b->pos_image_aff.x=0;
            b->pos_image_aff.y=0;
            b->pos_image_aff.w=1280;
            b->pos_image_aff.h=720;

}
void initMask(background * b,background * b1)
{
            b->url="loading_img/map/mask1.png";
            b->img=IMG_Load(b->url);
            if(b->img==NULL)
            {
                printf("error laoding mask");
            }
            b1->url="background/mask_side.png";
            b1->img=IMG_Load(b1->url);
            if(b1->img==NULL)
            {
                printf("error laoding mask_side");
            }
            b->pos_image_init.x=0;
            b->pos_image_init.y=0;
            b->pos_image_init.w=1280;
            b->pos_image_init.h=720;

            b->pos_image_aff.x=0;
            b->pos_image_aff.y=0;
            b->pos_image_aff.w=800;
            b->pos_image_aff.h=336;

            b1->pos_image_init.x=0;
            b1->pos_image_init.y=0;
            b1->pos_image_init.w=1280;
            b1->pos_image_init.h=720;
            
            b1->pos_image_aff.x=0;
            b1->pos_image_aff.y=0;
            b1->pos_image_aff.w=1280;
            b1->pos_image_aff.h=720;

}
void afficherBack(background b, SDL_Surface * screen)
{
    
    SDL_BlitSurface(b.img,&b.pos_image_aff,screen,NULL);
}

 void scrolling (background * b, int direction , int pas)
 {
        
        b->pos_image_aff.y += pas;
 }

 /*
 void scrolling (SDL_Rect * b, int direction, int pas  )
 {

 }
 //end
 void animerBack (Background* b) 
 {

 }
void saveScore(ScoreInfo  s,  char *fileName);
void bestScore(char * filename,  ScoreInfo  t[]);*/