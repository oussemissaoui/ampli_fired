/**

    @file player.c
    @brief This program is a TOP-view and side-scrolling game developed using the SDL library in C.
    The game features a player character that can move left and right, jump, and interact with various objects in the game world.
    @author Pegasus Team
    @version 1.0
    @date May 01, 2023
    @details This file contains functions and data structures for the player character in the game.
    @return 0 if the program exits successfully, or a non-zero error code if an error occurs.
    @dependencies This program requires the SDL, SDL_image, SDL_ttf, and SDL_mixer libraries to be installed on the system.
    */
#include "player.h"
/**

    @brief Initializes a "personne" struct with default values.

    @param p Pointer to the "personne" struct to be initialized.
    */
void initPerso(personne *p)
{
     p->url="loading_img/player/SPRITESHEET WALK1.png";
            p->img=IMG_Load(p->url);
            if(p->img==NULL)
            {
                printf("error laoding player");
            }
            p->pos_image_init.x=1280/2;
            p->pos_image_init.y=720/2;
            p->pos_image_aff.x=0;
            p->pos_image_aff.y=0;
            p->pos_image_aff.w=42;
            p->pos_image_aff.h=64;
            p->speed=0;
            p->frame=0;
            p->direction_axe_x=0;
            p->direction_axe_y=0;
            p->move=0;
            p->colright=0;
            p->colleft=0;
            p->coldown=0;
            p->colup=0;
            
}


/**

    @brief Renders the player on the screen.
    This function uses the SDL library to render the player on the screen.
    @param p A pointer to the person struct that holds the information about the player.
    @param screen A pointer to the SDL surface representing the screen.
    @return void.
    */
void afficherPerso(personne p, SDL_Surface * screen)
{
    SDL_BlitSurface(p.img,&p.pos_image_aff ,screen,&p.pos_image_init);
}

/**

    @brief Moves a given person object based on its current speed and direction

    @param p Pointer to the person object to move
    */
void movePerso (personne *p)
{
    Uint32 locate;
    int mousex ,mousey;
    if((p->move==1 && p->speed< 2) || (p->move==2 && p->speed< 2))
    {
        
        p->speed+=0.2;
    }
    if(p->move==0 && p->speed >0)
    {
        p->speed-=0.5;
    }
    if(p->speed <=0)
    {
        p->speed=0;
    }
    if (p->speed>2)
    {
        p->speed=2;     // to review
    }



    if(p->direction_axe_x==-1 && p->colleft==0)
    {
        p->pos_image_init.x += p->speed * p->direction_axe_x;
    }
    if((p->direction_axe_x==1 && p->colright == 0 ) )
    {
        p->pos_image_init.x += p->speed * p->direction_axe_x;
    }
    if(p->direction_axe_y==-1 && p->colup==0)
    {
        p->pos_image_init.y += p->speed * p->direction_axe_y;
    }
    if((p->direction_axe_y==1 && p->coldown == 0 ) )
    {
        p->pos_image_init.y += p->speed * p->direction_axe_y;
    }


    if(p->move==2)
    {
        locate=SDL_GetMouseState(&mousex,&mousey);
        //printf("x:%d    y=%d\n",mousex,mousey);
        if(mousex<p->pos_image_init.x)
        {
            p->direction_axe_x=-1;
            if(mousey<p->pos_image_init.y)
            {
                   p->direction_axe_y=-1;
                   p->pos_image_init.x += p->speed * p->direction_axe_x;
                   p->pos_image_init.y += p->speed * p->direction_axe_y; 
            }
            else if(mousey >p->pos_image_init.y && mousey< p->pos_image_init.y+p->pos_image_aff.h)
            {
                   p->direction_axe_y=0;
                   p->pos_image_init.x += p->speed * p->direction_axe_y;
                   p->pos_image_init.y += p->speed * p->direction_axe_y; 
            }
            else{
                   p->direction_axe_y=1;
                   p->pos_image_init.x += p->speed * p->direction_axe_y;
                   p->pos_image_init.y += p->speed * p->direction_axe_y; 
            }

        }
        else if(mousex >= p->pos_image_init.x && mousex<= p->pos_image_init.x+p->pos_image_aff.w)
        {
            p->direction_axe_x=0;
            if(mousey<p->pos_image_init.y)
            {
                   p->direction_axe_y=-1;
                   p->pos_image_init.x += p->speed * p->direction_axe_x;
                   p->pos_image_init.y += p->speed * p->direction_axe_y; 
            }
            else if(mousey >=p->pos_image_init.y && mousey<= p->pos_image_init.y+p->pos_image_aff.h)
            {
                   p->direction_axe_y=0;
                   p->pos_image_init.x += p->speed * p->direction_axe_x;
                   p->pos_image_init.y += p->speed * p->direction_axe_y; 
            }
            else{
                   p->direction_axe_y=1;
                   p->pos_image_init.x += p->speed * p->direction_axe_x;
                   p->pos_image_init.y += p->speed * p->direction_axe_y; 
            }

        }
        else
        {
            p->direction_axe_x=1;
            if(mousey<p->pos_image_init.y)
            {
                   p->direction_axe_y=-1;
                   p->pos_image_init.x += p->speed * p->direction_axe_x;
                   p->pos_image_init.y += p->speed * p->direction_axe_y; 
            }
            else if(mousey >p->pos_image_init.y && mousey< p->pos_image_init.y+p->pos_image_aff.h)
            {
                   p->direction_axe_y=0;
                   p->pos_image_init.x += p->speed * p->direction_axe_x;
                   p->pos_image_init.y += p->speed * p->direction_axe_y; 
            }
            else{
                   p->direction_axe_y=1;
                   p->pos_image_init.x += p->speed * p->direction_axe_x;
                   p->pos_image_init.y += p->speed * p->direction_axe_y; 
            }
            

        }
       
        


    }

}

/**


@brief Updates the animation frame of a given player object based on its current movement direction and speed

@param player Pointer to the player object to update
*/

void animerPerso (personne* p)
{
    p->frame++;
    //printf("%d",p->frame);
    if((p->move==1||p->move==2) && p->direction_axe_x==1 && p->frame>=5)
    {
        if(p->pos_image_aff.y !=0 ||  p->pos_image_aff.h !=64 || p->pos_image_aff.w !=42 )
        {
           p->pos_image_aff.x=0;
           p->pos_image_aff.y=0;
           p->pos_image_aff.w=42;
           p->pos_image_aff.h=64; 
        }
        p->pos_image_aff.x += 42;
          
        p->frame =0 ;
        if(p->pos_image_aff.x>=294)
        {
            p->pos_image_aff.x=0;
        }
    }
    else if((p->move==1||p->move==2) && p->direction_axe_x==-1 &&  p->frame>=5)
    {
        if(p->pos_image_aff.y !=64)
        {
           p->pos_image_aff.x=294;
           p->pos_image_aff.y=64;
           p->pos_image_aff.w=42;
           p->pos_image_aff.h=64; 
        }
        
        p->pos_image_aff.x -= 42;
        p->pos_image_aff.y =64;
        p->pos_image_aff.w=42;
        p->pos_image_aff.h=64;
        if(p->pos_image_aff.x<=42)
        {
            p->pos_image_aff.x=42*7;
        }
        p->frame =0 ;
        
    }
    else if((p->move==1||p->move==2) && p->direction_axe_y==1 &&  p->frame>=5)
    {
        p->pos_image_aff.x = 0;
        p->pos_image_aff.y +=42;
        p->pos_image_aff.w=64;
        p->pos_image_aff.h=42;
        if(p->pos_image_aff.y<128 || p->pos_image_aff.y>422)
        {
            p->pos_image_aff.y=128;
        }
        
        
        p->frame =0 ;
        
    }
    else if((p->move==1||p->move==2) && p->direction_axe_y==-1 &&  p->frame>=5)
    {
        p->pos_image_aff.x = 64;
        p->pos_image_aff.y +=42;
        p->pos_image_aff.w=64;
        p->pos_image_aff.h=42;
        if(p->pos_image_aff.y<128 || p->pos_image_aff.y>422)
        {
            p->pos_image_aff.y=128;
        }
        
        
        p->frame =0 ;
        
    }
    if(p->move==0 ||(p->direction_axe_x==0&&p->direction_axe_y==0) )
    {
            if(p->last_direction==1)
            {
                p->pos_image_aff.x=0;
                p->pos_image_aff.y=0;
                p->pos_image_aff.w=42;
                p->pos_image_aff.h=64;
            }
            if(p->last_direction==2)
            {
                p->pos_image_aff.x=294;
                p->pos_image_aff.y=64;
                p->pos_image_aff.w=42;
                p->pos_image_aff.h=64; 
            }
            if(p->last_direction==3)
            {
                p->pos_image_aff.x = 0;
                p->pos_image_aff.y=128;
                p->pos_image_aff.w =64;
                p->pos_image_aff.h =42;
            }
            if(p->last_direction==4)
            {
                p->pos_image_aff.x = 64;
                p->pos_image_aff.y=128;
                p->pos_image_aff.w =64;
                p->pos_image_aff.h =42;
            }
            
    }
    
}

