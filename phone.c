#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "jeu.h"
#include "phone.h"
#include "music.h"

void init_phone(phone *ph)
{
    ph->img[0]=IMG_Load("loading_img/phone/phone0.png");
    ph->img[1]=IMG_Load("loading_img/phone/phone1.png");
    ph->img[2]=IMG_Load("loading_img/phone/phone2.png");
    ph->img[3]=IMG_Load("loading_img/phone/phone3.png");
    if(ph->img[0] == NULL || ph->img[1] == NULL || ph->img[2] == NULL || ph->img[3] == NULL )
    {
        printf("can't load phone image");
    }
    ph->pos_image_init.x=0;
    ph->pos_image_init.y=0;
    ph->num_screen=0;
    ph->phone_state=0;
}
void aff_phone(phone *ph,SDL_Surface *screen)
{
    SDL_BlitSurface(ph->img[ph->num_screen],NULL,screen,&ph->pos_image_init);
}
void MAJphone(phone *ph)
{
    if(ph->phone_state==0 && ph->pos_image_init.y==0)
    {
        phone_lock_son(ph->lock_phone);
    }
  if(ph->phone_state==0 && ph->pos_image_init.y <750 )
  {
    ph->pos_image_init.y+=6;
  }
  if(ph->phone_state==1 && ph->pos_image_init.y>0)
  {
    ph->pos_image_init.y-=4;
  }
  if(ph->phone_state==1 && ph->pos_image_init.y<0)
  {
    ph->pos_image_init.y=0;
  }


  
  
}