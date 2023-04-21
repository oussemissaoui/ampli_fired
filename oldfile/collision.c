#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "collision.h"




SDL_Color GetPixel(SDL_Surface *perso ,int x,int y)
{
    SDL_Color color;
    Uint32 col=0;
    char *pPosition = (char *) perso -> pixels;
    pPosition+=(perso->pitch *y);
    pPosition+=(perso ->format->BytesPerPixel *x);
    memcpy (&col,pPosition,perso ->format ->BytesPerPixel);

SDL_GetRGB(col,perso -> format,&color.r ,&color.g ,&color.b);
return (color);
}



int collision_right(SDL_Surface *mask , SDL_Rect posperso ,SDL_Rect posperso_aff)
{  
SDL_Color col;
SDL_Color colp;
SDL_Rect pos[8];
int collision = 0;
int i,w,h;

col.r=0;
col.g=0;
col.b=0;

w=42;
h=64;

/*-------coordonnes d point n°1-------*/
pos[5].x = posperso.x;
pos[5].y = posperso.y;
printf("\n %d \n",pos[5].x);
printf("\n %d \n ",pos[5].y);

/*-------coordonnes d point n°2-------*/
pos[6].x = posperso.x;
pos[6].y = posperso.y;


/*-------coordonnes d point n°3-------*/
pos[7].x = posperso.x ;
pos[7].y = posperso.y ;



for (i =5;(i < 8)&&(collision == 0); i++)
{
    colp = GetPixel(mask,pos[i].x ,pos[i].y);
   // printf("%d \n %d \n %d \n",colp.r,colp.b,colp.g);
    if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
    collision = 1;
}
printf("%d\n",collision);

return (collision);

}

int collision_left(SDL_Surface *mask , SDL_Rect posperso  ,SDL_Rect posperso_aff)
{
SDL_Color col;
SDL_Color colp;
SDL_Rect pos[8];
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;


w=posperso_aff.w;
h=posperso_aff.h;


pos[0].x = posperso.x;
pos[0].y = posperso.y;

pos[1].x = posperso.x;
pos[1].y = posperso.y + h /2;

pos[2].x = posperso.x;
pos[2].y = posperso.y + h;


for (i =0;(i < 3)&&(collision == 0); i++)
{
colp = GetPixel(mask,pos[i].x ,pos[i].y);
if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
collision = 1;
}
    return (collision);
}


int collision_up(SDL_Surface *mask , SDL_Rect posperso    ,SDL_Rect posperso_aff)
{
SDL_Color col,colp;
SDL_Rect pos;
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;


w=posperso_aff.w;
h=posperso_aff.h;



pos.x = posperso.x + w/2;
pos.y = posperso.y;

col = GetPixel(mask,pos.x ,pos.y);


if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))   collision = 1;


return (collision);
}




int collision_down(SDL_Surface *mask , SDL_Rect posperso  ,SDL_Rect posperso_aff)
{
SDL_Color col,colp;
SDL_Rect pos;
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;


w=posperso_aff.w;
h=posperso_aff.h;



pos.x = posperso.x+ w /2;
pos.y = posperso.y +h;


col = GetPixel(mask,pos.x ,pos.y);

if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b)) collision = 1;

return (collision);
}
