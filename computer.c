#include "computer.h"

liste init_computer(int nb_img,SDL_Surface *s)
{
        liste l=NULL;
        int count=0;
        for (int j=0;j<nb_img;j++)
        {
            l=ajouter_pc_Fin(l,j,s);         
        }
        return (l);
        

}

liste ajouter_pc_Fin(liste l, int i,SDL_Surface *s)
{
    struct cellule * nouv, *parc;
    nouv = (struct cellule*) malloc(sizeof(struct cellule));
    nouv->d.url = (char*)malloc(sizeof(char) * 30);
    sprintf(nouv->d.url,"loading_img/computer/%d.png",i);
    nouv->d.img=IMG_Load(nouv->d.url);
    nouv->d.scaled=first_resizeimg(nouv->d.img);
    nouv->suiv=NULL;
    if(l==NULL)
        { return nouv;}
    else
        {
            parc=l;
            while(parc->suiv!=NULL)
            parc=parc->suiv;
            parc->suiv = nouv;
        }
    if(nouv->d.scaled != NULL)
    SDL_BlitSurface(nouv->d.scaled,NULL,s,NULL);
    SDL_Flip(s);
    SDL_Delay(150);
return(l);
}

void computer_img_init(computer *c)
{
    c->img=IMG_Load("loading_img/AMERICAN.png");
    c->pos_image_init.x=0;
    c->pos_image_init.y=0;

}
void computer_screen_init(computer *c)
{
    c->img=IMG_Load("loading_img/computer/BG.png");
    c->pos_image_init.x=0;
    c->pos_image_init.y=0;  
}
void init_pc_photo_default(computer *c,char path_img[])
{
   c->img=IMG_Load(path_img);
    c->pos_image_init.x=0;
    c->pos_image_init.y=0;  
}
void init_pc_photo_defaultxy(computer *c,char path_img[],int x,int y)
{
   c->img=IMG_Load(path_img);
    c->pos_image_init.x=x;
    c->pos_image_init.y=y;  
}
void pop_out_lowbar(computer *pc_lowbar)
{
    int mousex,mousey;
    SDL_GetMouseState(&mousex,&mousey);
            if(mouse_in_rect(0,656,1276,65,mousex,mousey)==1 && pc_lowbar->pos_image_init.y>0)
			{
				pc_lowbar->pos_image_init.y--;
			}
			else if(mouse_in_rect(0,656,1276,65,mousex,mousey)==0 && pc_lowbar->pos_image_init.y<70)
			{
				pc_lowbar->pos_image_init.y++;
			}
}
void pop_lowbar_win(computer pc_lowbar,computer pc_window,SDL_Surface *screen)
{
    int mousex,mousey;
    SDL_GetMouseState(&mousex,&mousey);
            if(mouse_in_rect(604,664,63,53,mousex,mousey)==1 && pc_lowbar.pos_image_init.y==0)
			{
				SDL_BlitSurface(pc_window.img,NULL,screen,NULL);
			}
			
}
void show_selected_icon(icon *icons,SDL_Event e,int *selected_icon,int *opened_screen_pc)
{
    
    int mousex,mousey;
    SDL_GetMouseState(&mousex,&mousey);
    if(mouse_in_rect(13,12,89,89,mousex,mousey)==1)
			{
				
				*(selected_icon)=1;
				init_icon_pos1(&(*icons));
			}
			else if(mouse_in_rect(13,112,89,89,mousex,mousey)==1)
			{
				*(selected_icon)=2;
				init_icon_pos2(&(*icons));
                 if(e.type==SDL_MOUSEBUTTONDOWN && e.button.button==SDL_BUTTON_LEFT)
				    {
				    	*(opened_screen_pc)=3;
                        
				    }
			}
			else if(mouse_in_rect(13,213,89,89,mousex,mousey)==1)
			{
				*(selected_icon)=3;
				init_icon_pos3(&(*icons));
                if(e.type==SDL_MOUSEBUTTONDOWN && e.button.button==SDL_BUTTON_LEFT)
				    {
				    	*(opened_screen_pc)=2;
                        
				    }
			}
			else if(mouse_in_rect(13,314,89,89,mousex,mousey)==1)
			{
				*(selected_icon)=4;
				init_icon_pos4(&(*icons));
				    if(e.type==SDL_MOUSEBUTTONDOWN && e.button.button==SDL_BUTTON_LEFT)
				    {
				    	*(opened_screen_pc)=1;
                        SDL_EnableKeyRepeat(250,250);
				    	printf("done switch ");
				    }
                
			}
			else 
			{
				init_icon_pos0(&(*icons));
				*(selected_icon)=0;
			}
}

void move_window(computer *c,int window_in_drag,int *x,int *y)
{
    int mousex,mousey;
    SDL_GetMouseState(&mousex,&mousey);
    //printf(" we are in function\n");
    
       


         
            c->pos_image_init.x=(mousex- *x);
            c->pos_image_init.y=(mousey- *y); 
        
        
    
    

}
