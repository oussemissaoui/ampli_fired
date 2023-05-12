/**
* @file minimap.c
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"
/**
* @brief To initialize the minimap m .
* @param m the minimap
* @param url the url of the image
* @return Nothing
*/
void initmap(minimap *m)
{
    int i;
    char url[25];
    
    for(i=0;i<125;i++)
    {
    
        sprintf(url,"images/%d.png",i);
        m->image[i]=IMG_Load(url);
    }
    
	m->image[0] = IMG_Load("minimap.jpg");
    
	m->bonhomme = IMG_Load("per.png");
	m->position.x =516;
	m->position.y =0;
	m->position.w=m->image[0]->w;
	m->position.h=m->image[0]->h;
    m->PositionBonhomme.x = 516;
	m->PositionBonhomme.y = 50;
    m->frames=0;
}
/**
* @brief To show the minimap .
* @param scren the screen
* @param m the minimap
* @return Nothing
*/
void afficherMinimap(minimap m, SDL_Surface *screen)
{
	SDL_BlitSurface(m.image[m.frames], NULL, screen, &m.position);
	SDL_BlitSurface(m.bonhomme, NULL, screen, &m.PositionBonhomme);
}
/**
* @brief update minimap .
* @param posJoueur position of player
* @param m the minimap
* @param redimensionnement resize player variable 
* @return Nothing
*/
void MAJMinimap(SDL_Rect posJoueur ,minimap *m , int redimensionnement)
{
	
	m->PositionBonhomme.x = (posJoueur.x *redimensionnement/100)+516;
	m->PositionBonhomme.y = (posJoueur.y *redimensionnement/100)+5;
}

/**
* @brief To show the time .
* @param temps temp variable
* @param screen the screen
* @return Nothing
*/
void afficherTemps (int temps, SDL_Surface *screen)
{
        if (temps>=1000)
		temps=temps/1000;
        else 
        temps=0;
	TTF_Font *fontTest=TTF_OpenFont("police.ttf",100);
	SDL_Color colortime={0,0,0};
	char timeText[20];
	SDL_Surface *time;
	sprintf(timeText,"%d",temps);
	time=TTF_RenderText_Blended(fontTest,timeText,colortime);
	SDL_Rect timepose;
	timepose.x=0;
	timepose.y=50;
	SDL_BlitSurface(time,NULL,screen,&timepose);
	SDL_FreeSurface(time);
        TTF_CloseFont(fontTest);	
}
/**
* @brief To get pixel color  .
* @param pSurface surface of player
* @return Nothing
*/
SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y)
{
    	SDL_Color color;
    	Uint32 col = 0;
    	
   
        	
        	char *pPosition = (char *)pSurface->pixels;
	
        	
       		pPosition += (pSurface->pitch * y);

        	
        	pPosition += (pSurface->format->BytesPerPixel * x);

        	
        	memcpy(&col, pPosition, pSurface->format->BytesPerPixel);

        	
   
   	 SDL_GetRGB(col, pSurface->format, &color.r, &color.g, &color.b);
   	 return (color);
}



/**
* @brief detect collision
* @param mask the mask of background
* @param posjoueur  player position
* @return collision state
*/
int collision_parfaite(SDL_Surface *mask , SDL_Rect posjoueur )
{  SDL_Color col,colp;
SDL_Rect pos[12];
int collision = -1;
int i,w,h;

col.r=0;
col.g=0;
col.b=0;

w=70;
h=70;

pos[0].x = posjoueur.x +w;
pos[0].y = posjoueur.y;



pos[1].x = posjoueur.x +w;
pos[1].y = posjoueur.y+ h/2;



pos[2].x = posjoueur.x +w;
pos[2].y = posjoueur.y +h;
pos[3].x = posjoueur.x;
pos[3].y = posjoueur.y;

pos[4].x = posjoueur.x;
pos[4].y = posjoueur.y + h /2;

pos[5].x = posjoueur.x;
pos[5].y = posjoueur.y + h;

pos[6].x = posjoueur.x;
pos[6].y = posjoueur.y;

pos[7].x = posjoueur.x+w/2;
pos[7].y = posjoueur.y ;

pos[8].x = posjoueur.x+w;
pos[8].y = posjoueur.y ;

pos[9].x = posjoueur.x;
pos[9].y = posjoueur.y+h;

pos[10].x = posjoueur.x+w/2;
pos[10].y = posjoueur.y + h;

pos[11].x = posjoueur.x +w;
pos[11].y = posjoueur.y + h;



for (i =0;(i < 12)&&(collision == -1); i++)
{
    colp = GetPixel(mask,pos[i].x ,pos[i].y);
    
    if((col.r==colp.r) && (col.g == colp.g) && (col.b ==colp.b))
    {
        if(i>=0 &&  i<=2)
    collision = 3;
        else if(i>2 && i<=5)
        collision = 1;
        else if(i>5 && i<=8)
        collision =2;
        else if(i>8 && i<=11)
        collision =4; 
    }
}


return (collision);
}

void animateminimap(minimap *m){
    m->frames++;  

    if(m->frames>124)
    {
        m->frames=0;
    }


}









