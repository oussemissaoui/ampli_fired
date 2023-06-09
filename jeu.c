#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "jeu.h"






// intersection mouse with percentage of screen :()
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
int mouse_in_rect(int rect_x,int rect_y,int rect_w,int rect_h,int mousex,int mousey)
{
    if((mousex>rect_x && mousex < rect_x+rect_w) && (mousey>rect_y && mousey<rect_y+rect_h) )
    {
        return 1; // if cursor intersects, return 1
    }
    else 
    {
        return 0; // if cursor doesn't intersect, return 0
    }
}
int intersection_souris(SDL_Rect poscarre,int mousex,int mousey)
{
	if((mousex>poscarre.x && mousex < poscarre.x+poscarre.w) && (mousey>poscarre.y && mousey<poscarre.y+poscarre.h) )
	{
		return 1;
	}
	else 
    {
    return 0;
    }
}

liste init_start_tv(int nb_img,SDL_Surface *s,image *load[],int num_load)
{
        liste l=NULL;
        int count=0;
        for (int j=0;j<nb_img;j++)
        {

            l=ajouter_Fin(l,j);
            SDL_BlitSurface(load[count]->scaled,NULL,s,NULL);
            count = (count+1)% num_load;
            SDL_Flip(s); 
            
        }
        return (l);
        

}

liste ajouter_Fin(liste l, int j)
{
    struct cellule * nouv, *parc;
    nouv = (struct cellule*) malloc(sizeof(struct cellule));
    nouv->d.url = (char*)malloc(sizeof(char) * 30);
    sprintf(nouv->d.url,"loading_img/start_tv/%d.png",j);
    nouv->d.img=IMG_Load(nouv->d.url);
    nouv->d.scaled=first_resizeimg(nouv->d.img);
    nouv->suiv=NULL;
    SDL_FreeSurface(nouv->d.img); // to review
    if(l==NULL)
        { return nouv;}
    else
        {
            parc=l;
            while(parc->suiv!=NULL)
            parc=parc->suiv;
            parc->suiv = nouv;
        }
    
return(l);
}

void parcourir(liste l,SDL_Surface* screen)
{
    struct cellule* tmp=l;
    while (tmp!=NULL)
    {
    SDL_BlitSurface(tmp->d.scaled,NULL,screen,NULL);
    SDL_Flip(screen);
    tmp=tmp->suiv;}
}
void parcourir_with_Delay(liste l,SDL_Surface* screen,int Delay)
{
    struct cellule* tmp=l;
    while (tmp!=NULL)
    {
    SDL_BlitSurface(tmp->d.scaled,NULL,screen,NULL);
    SDL_Flip(screen);
    tmp=tmp->suiv;
    SDL_Delay(Delay);
    }
}

void add_blit_delete(SDL_Surface *screen)
{
    int j,button,timer=0;
    int start,now;
    char url[30];
    SDL_Event e;
    SDL_Surface *img;
    Mix_Music *mus;
    start=SDL_GetTicks();
    play_music(mus,"mp3/trailer_son.mp3");
    for(j=0;j<694;j++){
        if(SDL_PollEvent(&e))
        {
            switch(e.type)
            {
                case SDL_KEYDOWN:
                    if(e.key.keysym.sym==SDLK_SPACE)
                    button=1;
                break;
                case SDL_KEYUP:
                    if(e.key.keysym.sym==SDLK_SPACE)
                    button=0;
                break;

                
            }
        }
        if(button==1)
        {
            timer++;
        }
        
        sprintf(url,"loading_img/trailer/%d.png",j);
        img=IMG_Load(url);
        if(img==NULL)
        {
            printf("ERROR");
        }
        SDL_BlitSurface(img,NULL,screen,NULL);
        SDL_Flip(screen);
        if(timer>=30)
        {
            j=694;
        }
        if(j==693)
        Mix_HaltMusic();
        SDL_Delay(21);
        
        

        
    }
    
}

