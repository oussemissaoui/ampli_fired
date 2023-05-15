#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include "sidescrolling_BG.h"
#include "player_side_scrolling.h"




void init_hero(Hero *h)
{

    h->allMvt = IMG_Load("sprites/sprite.png");
    if(h->allMvt==NULL)
    {
        printf("CAN'T LOAD IMAGE");
    }
    h->vies = IMG_Load("HEARTS.png");

    h->frame = 0;
   // h->currentMode = 0;
    
    h->heroPos.x = 100;
    h->heroPos.y = 427;

    h->herosprite.x=0;
    h->herosprite.y=38; 
    h->herosprite.w=133;
    h->herosprite.h=198;

    h->posVie1.x=0;
    h->posVie1.y=0;

    h->velocity = 0;
    h->speed = 0;

    h->xStep = 0;
    h->yStep = 0;
    h->direction =0;
    h->last_direction=1;
    h->col=0;
    h->VarX=0;
    h->score=100;
    h->vie=100;
    h->posScore.x = 0;  
    h->posScore.y = 250;
    TTF_Init();  
    h->police = TTF_OpenFont("font/font.ttf", 50);
    h->col_down=0;
    h->groundd=427;
    h->lastground=427;

    //setrects(h->rects);
}

void afficher_Hero(Hero *h, SDL_Surface *screen)
{
    SDL_BlitSurface(h->allMvt, &h->herosprite, screen, &h->heroPos);
   
    if (h->vie >= 100)
  {
    h->posVie2.x = 749;
    h->posVie2.y = 26;
    h->posVie2.w = 84;
    h->posVie2.h = 213;
  }
  if (h->vie >= 85 && h->vie < 100)
  {
    h->posVie2.x = 633;
    h->posVie2.y = 26;
    h->posVie2.w = 84;
    h->posVie2.h = 213;
  }
  if (h->vie >= 75 && h->vie < 85)
  {
    h->posVie2.x = 516;
    h->posVie2.y = 26;
    h->posVie2.w = 84;
    h->posVie2.h = 213;
  }
  if (h->vie >= 50 && h->vie < 75)
  {
    h->posVie2.x = 402 ;
    h->posVie2.y = 26;
    h->posVie2.w = 84;
    h->posVie2.h = 213;
  }
  if (h->vie >= 25 && h->vie < 50)
  {
    h->posVie2.x = 172;
    h->posVie2.y = 39;
    h->posVie2.w = 87;
    h->posVie2.h = 208;
  }
  if (h->vie >= 0 && h->vie < 25)
  {
    h->posVie2.x = 59;
    h->posVie2.y = 39;
    h->posVie2.w = 87;
    h->posVie2.h = 208;
  }
   SDL_BlitSurface(h->vies,&h->posVie2,screen,&h->posVie1);
   SDL_Color couleur = {255, 255, 255};

 
  char s[20];
  sprintf(s, "Score: %d", h->score);

  
  h->scores = TTF_RenderText_Blended(h->police, s, couleur);

  
  SDL_BlitSurface(h->scores, NULL, screen, &(h->posScore));
}
void idleAnimation(Hero *h)
{
    
    if(h->last_direction == 1 && h->frame>=10)
    {
        if(h->herosprite.y!=38)
        {
            h->herosprite.x=0;
            h->herosprite.y=38;
            h->herosprite.w = 133;
            h->herosprite.h = 198;
        }
        h->herosprite.x+=315;
        if(h->herosprite.x > 1260)
        {
            h->herosprite.x=0;
        }
        h->frame=0;
    }
    else if(h->last_direction == -1 && h->frame>=10)
    {
        if(h->herosprite.y!=276 && h->frame>=10)
        {
            h->herosprite.x=0;
            h->herosprite.y=276;
            h->herosprite.w = 133;
            h->herosprite.h = 198;
        }
        h->herosprite.x+=315;
        if(h->herosprite.x >1260)
        {
             h->herosprite.x=0;
        }
        h->frame=0;
    }

}

void leftAndRightHeroMvtR(Hero *hero,Background B,Input I, Uint32 dt)
{
    if (I.right == 0 && I.left == 0)
    {
        hero->velocity = 0;
        hero->speed =0;
    }
    else{
        if ((hero->direction == 1 || hero->direction == -1))
        {
            if ((I.right == 1 && I.left==0 && hero->heroPos.x<500)||B.camera.x >= 8693 -1500)
            {

                hero->xStep = 0.5 * hero->velocity * dt * dt + hero->speed * dt;
                if(hero->xStep >6)
                {
                    hero->xStep=6;
                }
                hero->heroPos.x += hero->xStep; 
                if (hero->velocity < 8)
                {
                    hero->velocity += 0.5;
                }
                else{
                    hero->velocity=8;
                }
                if(hero->speed <2)
                {
                    hero->speed += 0.2;
                }
                else{
                    hero->speed=2;
                }

            }

            else if ((I.left == 1 && I.right ==0 && hero->heroPos.x>500)||(B.camera.x == 0) && (hero->heroPos.x> 0))
            {
                hero->xStep = 0.5 * hero->velocity * dt * dt + hero->speed * dt;
                if(hero->xStep >6)
                {
                    hero->xStep=6;
                }
                hero->heroPos.x -= hero->xStep;
                if (hero->velocity < 8)
                {
                    hero->velocity += 0.5;
                }
                else{
                    hero->velocity=8;
                }
                if(hero->speed <2)
                {
                    hero->speed += 0.2;
                }
                else{
                    hero->speed=3;
                }
            }
        }
    }
    
}
/*void jumpHeroMvt(Hero *hero, Input *I,Background *B )
{
    ///printf("%f\n",p->VarX);

	int y;
	int Amp = -300;
	float delta = -4 * Amp;
	float x = (sqrt(delta) / 2);
    if(hero.col_down==0 && I->jump==0)
	if ((I->jump == 1) || (hero->col == 0))
	{
		hero->VarX++;
		//p->posScreen.x += (x * p->direction);
		//printf("Jump\n");
	}
	y = (int)((hero->VarX - x) * (hero->VarX - x) + Amp);
	if (y < 0)
	{
		hero->col = 0;
	}
	if (y >= 0)
	{
		y = 0;
		hero->VarX = 0;
		I->jump = 0;
		hero->col = 1;
	}
    if(I->jump==1 && (I->right==1 && I->left==0) )
    {
        //hero->heroPos.x +=5;
        B->camera.x +=5;
    }
    if(I->jump==1 && (I->left==1&&I->right==0))
    {
        //hero->heroPos.x +=5;
        B->camera.x -=5;
    }
	hero->heroPos.y = (int)y + Ground;
}*/
/*void jumpHeroMvt(Hero *hero, Input *I,Background *B )
{
    ///printf("%f\n",p->VarX);
	int y;
	int Amp = -300;
	float delta = -4 * Amp;
	float x = (sqrt(delta) / 3);
    y = (int)((hero->VarX - x) * (hero->VarX - x) + Amp);
    printf("%d\n",y);
    if(hero->col_down==0 && I->jump ==0)
    {
        hero->heroPos.y++;
    }
    
    if(hero->col_down==1 && I->jump ==0)
    {
        hero->groundd=hero->heroPos.y+198;
        printf("ground = %d\n",hero->groundd);
    }
    if(I->jump==1)
    {
        hero->VarX++;
        B->camera.x += (x * hero->direction);
		//printf("Jump\n");
         hero->heroPos.y-=hero->VarX;
         if(hero->heroPos.y<=50)
         {
           I->jump=0;
         }
    }
    y = (int)((hero->VarX - x) * (hero->VarX - x) + Amp);
    if (y < 0)
	{
		hero->col = 0;
	}
	if (y >= 0)
	{
		y = 0;
		hero->VarX = 0;
		I->jump = 0;
		hero->col = 1;
	}


}*/
void jumpHeroMvt(Hero *hero, Input *I)
{
    ///printf("%f\n",p->VarX);
	int y;
	int Amp = -350;
	float delta = -4 * Amp;
	float x = (sqrt(delta) / 2);
	if ((I->jump == 1))
	{
		hero->VarX++;
        
        //hero->Ground=hero->heroPos.y+198;
	}
    
	y = (int)((hero->VarX - x) * (hero->VarX - x) + Amp);
	if (y < 0)
	{
		//hero->col_bas = 0;
	}
	if (y >= 0)
	{
		y = 0;
		hero->VarX = 0;
		I->jump = 0;
		//hero->col_bas = 0;
	}
    if(hero->col_down==1 && I->jump == 1  )
    {
        hero->Ground-=abs(y);
        
    }
    else if(hero->col_down==0 && I->jump==0 )
    {
        hero->groundd+=5;

    }
    else if(I->jump == 0 && hero->col_down==1 )
    {
        //if(her)
        if(hero->groundd!=hero->lastground && hero->heroPos.y+185<427 )
        {
            hero->groundd=hero->heroPos.y+185;
        }
        hero->heroPos.y++;
        
    }
	hero->heroPos.y = (int)y + hero->groundd;
    printf("%d\n",hero->heroPos.y);
    
}
void runAnimation(Hero *h)
{
    if(h->direction == 1 && h->frame>=10)
    {
        if(h->herosprite.y!=523)
        {
            h->herosprite.x=0;
            h->herosprite.y=523;
            h->herosprite.w = 133;
            h->herosprite.h = 198;
        }
        h->herosprite.x+=333;
        if(h->herosprite.x > 2331)
        {
            h->herosprite.x=333;
        }
        h->frame=0;
    }
    else if(h->direction == -1 && h->frame>=10)
    {
        if(h->herosprite.y!=772)
        {
            h->herosprite.x=2324;
            h->herosprite.y=772;
            h->herosprite.w = 133;
            h->herosprite.h = 198;
        }
        h->herosprite.x-=332;
        if(h->herosprite.x < 0)
        {
            h->herosprite.x=2324;
        }
        h->frame=0;
    }
}

void jumpAnimation(Hero *h)
{
    
    if(h->direction == 1 && h->frame>=10)
    {
        if(h->herosprite.y!=963)
        {
            h->herosprite.x=1104;
            h->herosprite.y=963;
            h->herosprite.w = 183;
            h->herosprite.h = 215;
        }
        h->herosprite.x+=374;
        if(h->herosprite.x > 1852 || h->herosprite.x<1104)
        {
            h->herosprite.x=1104;
        }
        h->frame=0;
    }
    else if(h->direction == -1 && h->frame>=10)
    {
        if(h->herosprite.y!=1289)
        {
            h->herosprite.x=354;
            h->herosprite.y=1289;
            h->herosprite.w = 155;
            h->herosprite.h = 206;
        }
        h->herosprite.x+=353;
        if(h->herosprite.x > 1060 || h->herosprite.x<354)
        {
            h->herosprite.x=354;
        }
        h->frame=0;
    }

}
void attackAnimation(Hero *h,Input *I)
{
    if((h->direction == 1 || h->last_direction ==1) && h->frame>=5)
    {
        if(h->herosprite.y!=1606)
        {
            h->herosprite.x=0;
            h->herosprite.y=1606;
            h->herosprite.w = 235;
            h->herosprite.h = 212;
        }
        h->herosprite.x+=352;
        if(h->herosprite.x > 1408 )
        {
            h->herosprite.x=0;
            I->attack=0;
        }
        h->frame=0;
    }
    else if((h->direction == -1 || h->last_direction==-1) && h->frame>=5)
    {
        if(h->herosprite.y!=1870)
        {
            h->herosprite.x=1324;
            h->herosprite.y=1870;
            h->herosprite.w = 235;
            h->herosprite.h = 212;
        }
        h->herosprite.x -=352;
        if(h->herosprite.x < 268 )
        {
            h->herosprite.x=0;
            I->attack=0;
        }
        h->frame=0;
    }

}
