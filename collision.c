#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "collision.h"



SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y, int xOffset, int yOffset)
{
    SDL_Color color = {0, 0, 0, 255};
    if (x < 0 || x >= pSurface->w || y < 0 || y >= pSurface->h) {
        return color;
    }
    Uint32 col=0;
    char *pPosition = (char *) pSurface->pixels;
    pPosition += (pSurface->pitch * (y + yOffset));
    pPosition += (pSurface->format->BytesPerPixel * (x + xOffset));
    memcpy(&col, pPosition, pSurface->format->BytesPerPixel);

    SDL_GetRGB(col, pSurface->format, &color.r, &color.g, &color.b);
    return color;
}

/*SDL_Color GetPixel(SDL_Surface *pSurface ,int x,int y)
{
    SDL_Color color = {0, 0, 0, 255};
    if (x < 0 || x >= pSurface->w || y < 0 || y >= pSurface->h) {
        return color;
    }
    Uint32 col=0;
    char *pPosition = (char *) pSurface -> pixels;
    pPosition+=(pSurface->pitch *y);
    pPosition+=(pSurface ->format->BytesPerPixel *x);
    memcpy (&col,pPosition,pSurface ->format ->BytesPerPixel);

SDL_GetRGB(col,pSurface -> format,&color.r ,&color.g ,&color.b);
return (color);
}*/



int collision_parfaite_right(SDL_Surface *mask , SDL_Rect posjoueur , int xOffset,int yOffset)
{  SDL_Color col,colp;
SDL_Rect pos[8];
int collision = 0;
int i,w,h;

col.r=0;
col.g=0;
col.b=0;// cad : col c'est le couleur noir 

w=0;
h=0;

/*-------coordonnes d point n°1-------*/
pos[5].x = posjoueur.x +37;
pos[5].y = posjoueur.y;


/*-------coordonnes d point n°2-------*/
pos[6].x = posjoueur.x +37;
pos[6].y = posjoueur.y+ 32/2;


/*-------coordonnes d point n°3-------*/
pos[7].x = posjoueur.x +37;
pos[7].y = posjoueur.y +32;



for (i =5;(i < 8)&&(collision == 0); i++)
{
    colp = GetPixel(mask,pos[i].x ,pos[i].y,xOffset,yOffset );
    
    if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
    collision = 1;
}


return (collision);
}

int collision_parfaite_left(SDL_Surface *mask , SDL_Rect posjoueur  , int xOffset,int yOffset)
{
SDL_Color col,colp;
SDL_Rect pos[8];
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;


w=44;
h=70;


pos[0].x = posjoueur.x+10;
pos[0].y = posjoueur.y+7;

pos[1].x = posjoueur.x+10;
pos[1].y = posjoueur.y+7+ (49/2);

pos[2].x = posjoueur.x+10;
pos[2].y = posjoueur.y + 49;


for (i =0;(i < 3)&&(collision == 0); i++)
{
colp = GetPixel(mask,pos[i].x ,pos[i].y,xOffset,yOffset);
if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
collision = 1;
}
    return (collision);
}


int collision_parfaite_up(SDL_Surface *mask , SDL_Rect posjoueur    , int xOffset,int yOffset)
{
SDL_Color col,colp;
SDL_Rect pos[3];
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;


w=48;
h=28;



pos[0].x = posjoueur.x+8;
pos[0].y = posjoueur.y +9;

pos[1].x = posjoueur.x + 8 + (w/2);
pos[1].y = posjoueur.y + 9;

pos[2].x = posjoueur.x + 8 + w;
pos[2].y = posjoueur.y + 9;




for (i =0;(i < 3)&&(collision == 0); i++)
{
colp = GetPixel(mask,pos[i].x ,pos[i].y,xOffset,yOffset );
if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
collision = 1;
}


return (collision);
}




int collision_parfaite_down(SDL_Surface *mask , SDL_Rect posjoueur  , int xOffset,int yOffset)
{
SDL_Color col,colp;
SDL_Rect pos[3];
int collision = 0;
int i,w,h;
col.r=0;
col.g=0;
col.b=0;


w=48;
h=28;



pos[0].x = posjoueur.x+8;
pos[0].y = posjoueur.y +9 +h;

pos[1].x = posjoueur.x + 8 + (w/2);
pos[1].y = posjoueur.y + 9+h;

pos[2].x = posjoueur.x + 8 + w;
pos[2].y = posjoueur.y + 9 +h;




for (i =0;(i < 3)&&(collision == 0); i++)
{
colp = GetPixel(mask,pos[i].x ,pos[i].y,xOffset,yOffset );
if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
collision = 1;
}

return (collision);
}


int collision_all_body(SDL_Surface *mask , SDL_Rect posjoueur  , int xOffset,int yOffset)
{
    SDL_Color col,colp;
    SDL_Rect pos[12];
    int collision = 0;
    int i,w,h;
    col.r=255;
    col.g=0;
    col.b=0;


    w=48;
    h=28;

    //left side
    pos[0].x = posjoueur.x+10;
    pos[0].y = posjoueur.y+7;

    pos[1].x = posjoueur.x+10;
    pos[1].y = posjoueur.y+7+ (49/2);

    pos[2].x = posjoueur.x+10;
    pos[2].y = posjoueur.y + 49;


    //right side
    pos[3].x = posjoueur.x +37;
    pos[3].y = posjoueur.y;

    pos[4].x = posjoueur.x +37;
    pos[4].y = posjoueur.y+ 32/2;

    pos[5].x = posjoueur.x +37;
    pos[5].y = posjoueur.y +32;

    //up side
    pos[6].x = posjoueur.x+8;
    pos[6].y = posjoueur.y +9;

    pos[7].x = posjoueur.x + 8 + (w/2);
    pos[7].y = posjoueur.y + 9;

    pos[8].x = posjoueur.x + 8 + w;
    pos[8].y = posjoueur.y + 9;

    //down side
    pos[9].x = posjoueur.x+8;
    pos[9].y = posjoueur.y +9 +h;

    pos[10].x = posjoueur.x + 8 + (w/2);
    pos[10].y = posjoueur.y + 9+h;

    pos[11].x = posjoueur.x + 8 + w;
    pos[11].y = posjoueur.y + 9 +h;



    for (i =0;(i < 12)&&(collision == 0); i++)
    {
    colp = GetPixel(mask,pos[i].x ,pos[i].y,xOffset,yOffset);
    if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
    collision = 1;
    }
        return (collision);
}

int collision_out_home(SDL_Surface *mask , SDL_Rect posjoueur  , int xOffset,int yOffset)
{
    SDL_Color col,colp;
    SDL_Rect pos[12];
    int collision = 0;
    int i,w,h;
    col.r=0;
    col.g=255;
    col.b=0;


    w=48;
    h=28;

    //left side
    pos[0].x = posjoueur.x+10;
    pos[0].y = posjoueur.y+7;

    pos[1].x = posjoueur.x+10;
    pos[1].y = posjoueur.y+7+ (49/2);

    pos[2].x = posjoueur.x+10;
    pos[2].y = posjoueur.y + 49;


    //right side
    pos[3].x = posjoueur.x +37;
    pos[3].y = posjoueur.y;

    pos[4].x = posjoueur.x +37;
    pos[4].y = posjoueur.y+ 32/2;

    pos[5].x = posjoueur.x +37;
    pos[5].y = posjoueur.y +32;

    //up side
    pos[6].x = posjoueur.x+8;
    pos[6].y = posjoueur.y +9;

    pos[7].x = posjoueur.x + 8 + (w/2);
    pos[7].y = posjoueur.y + 9;

    pos[8].x = posjoueur.x + 8 + w;
    pos[8].y = posjoueur.y + 9;

    //down side
    pos[9].x = posjoueur.x+8;
    pos[9].y = posjoueur.y +9 +h;

    pos[10].x = posjoueur.x + 8 + (w/2);
    pos[10].y = posjoueur.y + 9+h;

    pos[11].x = posjoueur.x + 8 + w;
    pos[11].y = posjoueur.y + 9 +h;



    for (i =0;(i < 12)&&(collision == 0); i++)
    {
    colp = GetPixel(mask,pos[i].x ,pos[i].y,xOffset,yOffset);
    if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
    collision = 1;
    }
        return (collision);
}



////////////////////////////////////////////////////////////////////////////////////////////////Side scrolling collision check ///

int SS_collision_parfaite_down(SDL_Surface *mask , SDL_Rect posjoueur , int xOffset,int yOffset)
{  SDL_Color col,colp;
SDL_Rect pos[3];
int collision = 0;
int i,w,h;

col.r=0;
col.g=0;
col.b=0;// cad : col c'est le couleur noir 

w=0;
h=0;

/*-------coordonnes d point n°1-------*/
pos[0].x = posjoueur.x +37;
pos[0].y = posjoueur.y+185;


/*-------coordonnes d point n°2-------*/
pos[1].x = posjoueur.x +70;
pos[1].y = posjoueur.y+ 185;


/*-------coordonnes d point n°3-------*/
pos[2].x = posjoueur.x +92;
pos[2].y = posjoueur.y +185;



for (i =0;(i < 3)&&(collision == 0); i++)
{
    colp = GetPixel(mask,pos[i].x ,pos[i].y,xOffset,yOffset );
    
    if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
    collision = 1;
}


return (collision);
}


int SS_collision_green_zone(SDL_Surface *mask , SDL_Rect posjoueur , int xOffset,int yOffset)
{  SDL_Color col,colp;
SDL_Rect pos[3];
int collision = 0;
int i,w,h;

col.r=0;
col.g=0;
col.b=0;// cad : col c'est le couleur noir 

w=0;
h=0;

/*-------coordonnes d point n°1-------*/
pos[0].x = posjoueur.x +37;
pos[0].y = posjoueur.y+183;


/*-------coordonnes d point n°2-------*/
pos[1].x = posjoueur.x +70;
pos[1].y = posjoueur.y+ 183;


/*-------coordonnes d point n°3-------*/
pos[2].x = posjoueur.x +92;
pos[2].y = posjoueur.y +183;



for (i =0;(i < 3)&&(collision == 0); i++)
{
    colp = GetPixel(mask,pos[i].x ,pos[i].y,xOffset,yOffset );
    
    if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
    collision = 1;
}


return (collision);
}