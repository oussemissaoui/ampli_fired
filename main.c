/**

    @file main.c
    @brief This program is a TOP-view && side-scrolling game developed using the SDL library in C.
    The game features a player character that can move left and right, jump, and interact with various objects in the game world.
    @author Pegasus Team
    @version 1.0
    @date mai 01, 2023
    @details This file contains the main function for the game program.
    @return 0 if the program exits successfully, or a non-zero error code if an error occurs.
    @dependencies This program requires the SDL, SDL_image, SDL_ttf, and SDL_mixer libraries to be installed on the system.

*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "jeu.h"
#include "computer.h"
#include "background.h"
#include "player.h"
#include "collision.h"
#include "RectDimension.h"
#include "textInput.h"
#include "sidescrolling_BG.h"
#include "player_side_scrolling.h"
#include "input.h"
#include "arduino.h"
#include "minimap.h"
#include "phone.h"

int main()
{

    //init ALL variable
         //init  image number (backgound , loading etc ):   
             int bg_num=30,load_num=6,start_num=6,set_num=3,ext_num=3,extra_num=1,computer_img_num=40;
             int eff_set_num=4,mus_eff_num=13,sfx_eff_num=13,tv_eff_num=288,choice_num=3;
    int run=1,screen_num=0,last_screen=0;
	int multiplayer_state=0;


	//#########################--Computer--#######################//
	computer pc_error,pc_screen,pc_icons,pc_app,pc_app_coding,pc_chrome,pc_recycle,pc_window;
	computer pc_lowbar;
	int pc_state=0;
	int selected_icon=0;
	icon icons;
	int opened_screen_pc=0;
	int window_in_drag=0;
	int decalagex;
	int decalagey;
	
	//#########################--Computer--#######################//
	int test=0;   //to remove

	//#########################--Player--#######################//
	
	personne perso;
	
	int etat_left=0,etat_right=0,etat_down=0,etat_up=0; // pour sauvegarder l'etat de key est ce que nezelin 3lih wala lee 
	int etat_left_p2=0,etat_right_p2=0,etat_down_p2=0,etat_up_p2=0; // pour sauvegarder l'etat de key est ce que nezelin 3lih wala lee 
	int player_out_home_state=0;
	 Hero hero;
    Input I,I2;
    init_hero(&hero);
    init_input(&I);
	init_input(&I2);

	
	//#########################--Player--#######################//

	//#########################--mouse--########################//

	int mouse_button_left_state=0;
	int mouse_button_right_state=0;
	int mousex_on_click;
	int mousey_on_click;

	//#########################--mouse--########################//

	//#########################--KeyBoard--########################//

	int altgr_held =0;
    int shift_held = 0;

	//#########################--KeyBoard--########################//

	//#########################--Joystick--########################//
	int Joystick_function=0; // ON - OFF player chose from setting if he want to play with joystick or not 
	ArduinoMaster ard_ms;
	InitArduino(&ard_ms);
	int fpressed=0; //detect pressed button same role as F key in jotstick
	
	
	//#########################--Joystick--########################//

	//#########################--multiplayer--########################//
	personne perso2;
	multiplayer_state=0;
	int syncro=0;
	//#########################--multiplayer--########################//
	
	//#########################--background_side_scro--###########//
	Background B; 
	init_SDC_Background(&B); 

	//#########################--background_side_scro--###########//

	//#########################--minimap--###########//
	
	minimap mini;

	//#########################--minimap--###########//

	//#########################--phone--###########//

	phone ph;
	
	SDL_Rect spotify ={1011,291,59,57};
    SDL_Rect sms ={1083,291,59,57};
    SDL_Rect insta ={1160,291,59,57};
    SDL_Rect d17 ={1083,367,59,57} ;
    SDL_Rect home_button = {1084,664,58,19};

	init_phone(&ph);

	//#########################--phone--###########//
	int vol_mus=5,vol_sfx=5;
    int count=0,counterimage=0,mousex,mousey,resized=0,maxresize_num=0;
    int i; //declaration des variable pour les boucle
	
    image *loading[load_num],*bg[bg_num],*start[start_num],*setting[set_num],*exit[ext_num];
    image *eff_set[eff_set_num],*mus_eff[mus_eff_num],*sfx_eff[sfx_eff_num],*extra[extra_num],*exit_yes_no[choice_num];
	background map,mask,mask_side,map_store,mask_store;

	
	
    SDL_Surface *screen;
	Mix_Music *Music1;
	Mix_Chunk *knock;
    Uint32 locate; // use for mouseGetState 
	Uint32 dt, t_prev;
	liste pc=NULL;



for(i=0; i<load_num; i++) {
    loading[i] = (image*)malloc(sizeof(image));
    loading[i]->url = (char*)malloc(sizeof(char) * 30);
}
init_loading_img(loading,load_num);

//init SDL---TTF
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
        if((screen=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF))==NULL)
            {
                 printf("Unable init Screen %s",SDL_GetError());
            }
        if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
            {
                printf("Unable init Music %s",Mix_GetError());
            }
//end init






//allocation dynamique
	for(i=0; i<bg_num; i++) {
	    extra[i] = (image*)malloc(sizeof(image));
	    extra[i]->url = (char*)malloc(sizeof(char) * 30);
	}
	for(i=0; i<bg_num; i++) {
	    bg[i] = (image*)malloc(sizeof(image));
	    bg[i]->url = (char*)malloc(sizeof(char) * 30);
	}
	for(i=0; i<start_num; i++) {
	    start[i] = (image*)malloc(sizeof(image));
	    start[i]->url = (char*)malloc(sizeof(char) * 30);
	}
	for(i=0; i<set_num; i++) {
	    setting[i] = (image*)malloc(sizeof(image));
	    setting[i]->url = (char*)malloc(sizeof(char) * 30);
	}
	for(i=0; i<ext_num; i++) {
	    exit[i] = (image*)malloc(sizeof(image));
	    exit[i]->url = (char*)malloc(sizeof(char) * 30);
	}
	for(i=0; i<eff_set_num; i++) {
	    eff_set[i] = (image*)malloc(sizeof(image));
	    eff_set[i]->url = (char*)malloc(sizeof(char) * 30);
	}
	for(i=0; i<mus_eff_num; i++) {
	    mus_eff[i] = (image*)malloc(sizeof(image));
	    mus_eff[i]->url = (char*)malloc(sizeof(char) * 30);
	}
	for(i=0; i<sfx_eff_num; i++) {
	    sfx_eff[i] = (image*)malloc(sizeof(image));
	    sfx_eff[i]->url = (char*)malloc(sizeof(char) * 30);
	}

	/*for(i=0; i<tv_eff_num; i++) {
	    tv_eff[i] = (image*)malloc(sizeof(image));
	    tv_eff[i]->url = (char*)malloc(sizeof(char) * 30);
	}*/
	for(i=0; i<choice_num; i++) {
	    exit_yes_no[i] = (image*)malloc(sizeof(image));
	    exit_yes_no[i]->url = (char*)malloc(sizeof(char) * 30);
	}
//end of alloc
// start init of image
	init_bg_img(screen,bg,bg_num,loading,load_num);
	init_start_img(screen,start,start_num,loading,load_num);
	init_setting_img(screen,setting,set_num,loading,load_num);
	init_exit_img(screen,exit,ext_num,loading,load_num);
	init_effect_set_img(screen,eff_set,eff_set_num,loading,load_num);
	init_mus_eff_img(screen,mus_eff,mus_eff_num,loading,load_num);
	init_sfx_eff_img(screen,sfx_eff,sfx_eff_num,loading,load_num);

	//init_start_tv_eff(screen,tv_eff,tv_eff_num,loading,load_num);
	liste l=init_start_tv(tv_eff_num,screen,loading,load_num); //replaced table load by LSC load 
	
	init_extra(screen,extra,extra_num,loading,load_num);
	init_choice_exit(screen,exit_yes_no,choice_num,loading,load_num);

	computer_img_init(&pc_error);
	computer_screen_init(&pc_screen);
	init_pc_photo_default(&pc_icons,"loading_img/computer/SELECTICONS.png");
	init_pc_photo_default(&pc_app,"loading_img/computer/ICONS.png");
	init_pc_photo_default(&pc_lowbar,"loading_img/computer/LOWBAR.png");
	init_pc_photo_default(&pc_window,"loading_img/computer/NO INTERNETWINDOWS.png");
	init_pc_photo_defaultxy(&pc_app_coding,"loading_img/computer/CODINGWINDOW.png",267,126);
	init_pc_photo_defaultxy(&pc_chrome,"loading_img/computer/CHROME.png",267,126);
	init_pc_photo_defaultxy(&pc_recycle,"loading_img/computer/RECYCLEBIN.png",267,126);



//end init of image
knock=Mix_LoadWAV("mp3/knock.wav");
//test text 
//font
 TTF_Font *chrono;
 chrono=TTF_OpenFont("Karmella.otf",15);
 SDL_Color chronocolor={255,255,255};  
 //surface mouse 
 char posmouse[20];
 SDL_Surface *m;
 m=TTF_RenderText_Blended(chrono,"Copyright © 2023 Meem entertainment. All rights reserved.",chronocolor);
 SDL_Rect mpos;
 mpos.x=550;
 mpos.y=690;
 SDL_BlitSurface(m,NULL,screen,&mpos);
 SDL_Flip(screen);



//test 

SDL_Surface *msg,*msg1,*msg_store;
SDL_Rect pos_msg,pos_msg1;
msg=IMG_Load("loading_img/msg.png");
msg1=IMG_Load("loading_img/msg1.png");
msg_store=IMG_Load("loading_img/msg_store.png");
int msg_state,msg1_state,msg_store_state;

initMask(&mask,&mask_side);
initMask_store(&mask_store);
init_map(&mini);
initBack_store(&map_store);
//end test
//screen_num=5;
//animation

add_blit_delete(screen);  //animation_cancel


//end animation
play_music(Music1,"mp3/musicbg1.mp3");



while(run==1)
{   
	SDL_Event e;
	
    switch(screen_num)
    {
//case 0
        case 0:
		//SDL_BlitSurface(loading[1]->scaled,NULL,screen,NULL);
		//				SDL_Flip(screen);
		locate=SDL_GetMouseState(&mousex,&mousey);
		SDL_BlitSurface(bg[count]->scaled,NULL,screen,NULL);
		//SDL_BlitSurface(exit_yes_no[1]->scaled,NULL,screen,NULL);

		SDL_BlitSurface(m,NULL,screen,&mpos);

		if(mouseinter(screen,47,29,65,47)==1)
		{
			SDL_BlitSurface(start[1]->scaled,NULL,screen,NULL);
			if(e.type==SDL_MOUSEBUTTONDOWN && e.button.button==SDL_BUTTON_LEFT){
			/*for(i=0;i<tv_eff_num;i++){

				SDL_BlitSurface(tv_eff[i]->scaled,NULL,screen,NULL);
 				SDL_Flip(screen);
				}*/
				parcourir(l,screen); //animation_cancel
				initBack(&map);
				
				initPerso(&perso);
				if(multiplayer_state==1)
				{
					initPerso(&perso2);
					perso2.pos_image_init.x+=50;
					syncro=map.pos_image_aff.y;
				}
				screen_num=1;
				Mix_HaltMusic();
			break;}
		}
		if(mouseinter(screen,33,10,42,26)==1||mouseinter(screen,27,21,34,31)==1)
		{
			SDL_BlitSurface(setting[1]->scaled,NULL,screen,NULL);SDL_BlitSurface(setting[2]->scaled,NULL,screen,NULL);
			if(e.type==SDL_MOUSEBUTTONDOWN && e.button.button==SDL_BUTTON_LEFT){bg_num=10;screen_num=2;break;}
		}
		if(mouseinter(screen,81,13,88,31)==1)
		{
			SDL_BlitSurface(exit[1]->scaled,NULL,screen,NULL);SDL_BlitSurface(exit[2]->scaled,NULL,screen,NULL);
			if(e.type==SDL_MOUSEBUTTONDOWN && e.button.button==SDL_BUTTON_LEFT)
				{
					screen_num=3; break;
				}
		}	
		SDL_Flip(screen);
  	    count = (count + 1) % bg_num;
		if(SDL_PollEvent(&e)){
			switch(e.type){
				case SDL_QUIT : screen_num=-1;run=0;break;
 					break;
                case SDL_VIDEORESIZE:
					if(maxresize_num<2){
				   SDL_FreeSurface(screen);
				   if(maxresize_num==1){
				   screen=SDL_SetVideoMode(e.resize.w,e.resize.h,32,SDL_HWSURFACE|SDL_DOUBLEBUF);}
				   else{screen=SDL_SetVideoMode(e.resize.w,e.resize.h,32,SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);}
				   		maxresize_num++;
						screen_num=911;}
                    break;
				/*case SDL_MOUSEBUTTONDOWN : if(mouseinter(screen,4,32,21,68)==1&&e.button.button==SDL_BUTTON_LEFT){clickwindow.x=mousex-25;clickwindow.y=mousey-25;Mix_PlayChannel(-1,knock,0);aff_oneimg_loop(screen,click,70,clickwindow);}
					break;*/
		}}
        break; // first case 
//endcase0
		case 911 : 
				   //resize_5images(screen,loading,load_num,bg,bg_num,start,start_num,setting,set_num,exit,ext_num);
				   //resize_4images(screen,eff_set,eff_set_num,mus_eff,mus_eff_num,sfx_eff,sfx_eff_num,tv_eff,tv_eff_num);
				   //resize_1image(screen,extra,extra_num);
				   mpos.x=screen->w*43/100;
				   mpos.y=screen->h*95/100;
				   //resize_1image(screen,mus_eff,mus_eff_num);				   
				   //resize_1image(screen,sfx_eff,sfx_eff_num);				   
				   //resize_1image(screen,tv_eff,tv_eff_num);
				   screen_num=0;
				
		break;
//case 1
		case 1 :
		locate=SDL_GetMouseState(&mousex,&mousey);

	//affichage
		afficherBack(map,screen); //to edit map,screen
		afficherPerso(perso,screen);
		if(syncro!=map.pos_image_aff.y){
		perso2.pos_image_init.y-=(map.pos_image_aff.y-syncro);
		syncro=map.pos_image_aff.y;
		
		}
		if(multiplayer_state==1)
		afficherPerso(perso2,screen);
		if(msg_state==1)
		{
			SDL_BlitSurface(msg,NULL,screen,&pos_msg);
		}
		afficherminimap(mini,map, screen);
		//if(ph.phone_state==1)
		aff_phone(&ph,screen);

		SDL_Flip(screen);
	//end affichage
		if(Joystick_function==1)
		read_from_arduino(&ard_ms);
		if(Joystick_function==1)
			{
				if(ArduinoKeyCheck(&ard_ms,"right_start")  )
					{
						etat_right=1;
						perso.direction_axe_x=1;
						perso.move=1;
					}
				if(ArduinoKeyCheck(&ard_ms,"left_start")  )
					{
						etat_left=1;
						perso.direction_axe_x=-1;
						perso.move=1;
						
					}
				if(ArduinoKeyCheck(&ard_ms,"left_right_null") && (etat_right != 0 || etat_left != 0) )				
					{
						if(etat_right==1)
            			perso.last_direction=1;
						if(etat_left==1)
						perso.last_direction=2;

						etat_right=0;
						etat_left=0;
						perso.direction_axe_x =0;
						
					}
				if(ArduinoKeyCheck(&ard_ms,"up_start")  )
					{
						etat_up=1;
						perso.direction_axe_y=-1;
						perso.move=1;
					}
				if(ArduinoKeyCheck(&ard_ms,"down_start")  )
					{
						etat_down=1;
						perso.direction_axe_y=1;
						perso.move=1;
					}
				if(ArduinoKeyCheck(&ard_ms,"up_down_null") && (etat_down != 0 || etat_up != 0) )
					{
						if(etat_down==1)
            			perso.last_direction=3;
						if(etat_up==1)
						perso.last_direction=4;

						etat_down=0;
						etat_up=0;
						perso.direction_axe_y=0;
					}
					if(ArduinoKeyCheck(&ard_ms,"fpressed")  )
					{
						fpressed=1;
						if((fpressed ==1) && msg_state ==1 )
					{
						while(pc_state==0)
						{
							if(SDL_PollEvent(&e)){
								switch(e.key.keysym.sym)
								{
									case 282:
										pc_state=1;
									break;
								}
							}
							SDL_BlitSurface(pc_error.img,NULL,screen,NULL);
							SDL_Flip(screen);
						}
						
						if(pc==NULL)
						pc=init_computer(computer_img_num,screen);
						else
						parcourir_with_Delay(pc,screen,150);
						screen_num=4;
						fpressed=0;
						
					}
					}
				if(etat_down ==0 && etat_up ==0 && etat_right ==0 && etat_left==0)
						{
						perso.move=0;
						}
			}


			if(intersection_souris(spotify,mousex,mousey)==1 )
            			{
            			    
							printf("hello there is interaction\n");
            			}
		if(SDL_PollEvent(&e))
		{
			switch(e.type)
			{

				case SDL_QUIT : screen_num=-1;run=0;
 					break;
				case SDL_KEYDOWN :
					if(e.key.keysym.sym==SDLK_RIGHT)
					{
						
						etat_right=1;
						perso.direction_axe_x=1;
						perso.move=1;

					}
					if(e.key.keysym.sym==SDLK_LEFT)
					{
						etat_left=1;
						perso.direction_axe_x=-1;
						perso.move=1;
						
					}
					if(e.key.keysym.sym==SDLK_DOWN)
					{
						etat_down=1;
						perso.direction_axe_y=1;
						perso.move=1;
					}
					if(e.key.keysym.sym==SDLK_UP)
					{
						etat_up=1;
						perso.direction_axe_y=-1;
						perso.move=1;
					}
					if(e.key.keysym.sym==SDLK_d)
					{
						
						etat_right_p2=1;
						perso2.direction_axe_x=1;
						perso2.move=1;

					}
					if(e.key.keysym.sym==SDLK_q)
					{
						etat_left_p2=1;
						perso2.direction_axe_x=-1;
						perso2.move=1;
						
					}
					if(e.key.keysym.sym==SDLK_s)
					{
						etat_down_p2=1;
						perso2.direction_axe_y=1;
						perso2.move=1;
					}
					if(e.key.keysym.sym==SDLK_z)
					{
						etat_up_p2=1;
						perso2.direction_axe_y=-1;
						perso2.move=1;
					}
					if((e.key.keysym.sym == SDLK_f || fpressed ==1) && msg_state ==1 )
					{
						while(pc_state==0)
						{
							if(SDL_PollEvent(&e)){
								switch(e.key.keysym.sym)
								{
									case 282:
										pc_state=1;
									break;
								}
							}
							SDL_BlitSurface(pc_error.img,NULL,screen,NULL);
							SDL_Flip(screen);
						}
						
						if(pc==NULL)
						pc=init_computer(computer_img_num,screen);
						else
						parcourir_with_Delay(pc,screen,150);
						screen_num=4;
						fpressed=0;
						
					}
				
				break;
				case SDL_KEYUP:
					if(e.key.keysym.sym==SDLK_RIGHT ||e.key.keysym.sym==SDLK_LEFT || e.key.keysym.sym==SDLK_UP || e.key.keysym.sym==SDLK_DOWN   )
					{
					if(e.key.keysym.sym==SDLK_RIGHT)
					{
						etat_right=0;
						perso.direction_axe_x =0;
						perso.last_direction=1;
					}
					if(e.key.keysym.sym==SDLK_LEFT)
					{
						etat_left=0;
						perso.direction_axe_x =0;
						perso.last_direction=2;				
					}
					if(e.key.keysym.sym==SDLK_DOWN)
					{
						etat_down=0;
						perso.direction_axe_y=0;
						perso.last_direction=3;
					}
					if(e.key.keysym.sym==SDLK_UP)
					{
						etat_up=0;	
						perso.direction_axe_y=0;
						perso.last_direction=4;		
					}  	
						if(etat_down ==0 && etat_up ==0 && etat_right ==0 && etat_left==0)
						{
						perso.move=0;
						}
					}
					if(e.key.keysym.sym==SDLK_p)
					{
						if(ph.phone_state==1)
						{
							ph.phone_state=0;
						}
						else
							ph.phone_state=1;
					}
					// player 2 
					if(multiplayer_state==1)
					{
						if(e.key.keysym.sym==SDLK_d ||e.key.keysym.sym==SDLK_q || e.key.keysym.sym==SDLK_z || e.key.keysym.sym==SDLK_s   )
					{
					if(e.key.keysym.sym==SDLK_d)
					{
						etat_right=0;
						perso2.direction_axe_x =0;
						perso2.last_direction=1;
					}
					if(e.key.keysym.sym==SDLK_q)
					{
						etat_left=0;
						perso2.direction_axe_x =0;
						perso2.last_direction=2;				
					}
					if(e.key.keysym.sym==SDLK_s)
					{
						etat_down=0;
						perso2.direction_axe_y=0;
						perso2.last_direction=3;
					}
					if(e.key.keysym.sym==SDLK_z)
					{
						etat_up=0;	
						perso2.direction_axe_y=0;
						perso2.last_direction=4;		
					}  	
						if(etat_down_p2 ==0 && etat_up_p2 ==0 && etat_right_p2 ==0 && etat_left_p2==0)
						{
						perso2.move=0;
						}
					}

					}
					
				break;
				case SDL_MOUSEBUTTONDOWN :
					if(e.button.button==SDL_BUTTON_RIGHT)
					{
						
					}
				break;
				case SDL_MOUSEBUTTONUP :
					if(e.button.button==SDL_BUTTON_RIGHT)
					{
						perso.move=0;
						perso.direction_axe_x=0;
						perso.direction_axe_y=0;
					}
				break;
				
			}

		}
	//phone
		if(ph.phone_state==1)
		{
			SDL_GetMouseState(&mousex,&mousey);
        		if(intersection_souris(spotify,mousex,mousey)==1 && e.button.button==SDL_BUTTON_LEFT)
        		{
        		    ph.num_screen=1;
        		}
        		if(intersection_souris(sms,mousex,mousey)==1 && e.button.button==SDL_BUTTON_LEFT)
        		{
        		    ph.num_screen=2;
        		}
        		if(intersection_souris(insta,mousex,mousey)==1 && e.button.button==SDL_BUTTON_LEFT)
        		{
        		    ph.num_screen=3;
        		}
        		if(intersection_souris(home_button,mousex,mousey)==1 && e.button.button==SDL_BUTTON_LEFT)
        		{
        		    ph.num_screen=0;
        		}
		}
	//collision
		if(collision_parfaite_right(mask.img,perso.pos_image_init,0,map.pos_image_aff.y)==1){
					 perso.colright=1;
					}
		else{
			perso.colright=0;
		}
		if(collision_parfaite_left(mask.img,perso.pos_image_init,0,map.pos_image_aff.y)==1){
					 perso.colleft=1;
					}
		else{
			perso.colleft=0;
		}
		if(collision_parfaite_down(mask.img,perso.pos_image_init,0,map.pos_image_aff.y)==1){
					 perso.coldown=1;
					}
		else{
			perso.coldown=0;
		}
		if(collision_parfaite_up(mask.img,perso.pos_image_init,0,map.pos_image_aff.y)==1){
					 perso.colup=1;
					}
		else{
			perso.colup=0;
		}
		if(collision_all_body(mask.img,perso.pos_image_init,0,map.pos_image_aff.y)==1)
		{
			//printf("press f to open computer");
			msg_state=1;
		}
		else
		{
			msg_state=0;
			
		}
		if(collision_out_home(mask.img,perso.pos_image_init,0,map.pos_image_aff.y)==1)
		{
			player_out_home_state=1; //not finished need add the condition when return home (player_out_home_state=0)
		}

	//end collision 
	
	//scrolling 

		if(perso.pos_image_init.y>=720*3/4)
		{
			map.direction_axe_y=1;
			printf("scrolling down : %d\n",map.direction_axe_y);
		}
		else if(perso.pos_image_init.y<=720*1/4)
		{
			map.direction_axe_y=-1;;
			printf("scrolling up : %d\n",map.direction_axe_y);
		}
		else 
		{
			map.direction_axe_y=0;
			//printf("pas scrolling : %d\n",map.direction_axe_y);
		}
		pos_msg.x=perso.pos_image_init.x;   // to review
		pos_msg.y=perso.pos_image_init.y-50;

	//end scrolling

		movePerso(&perso);
		movePerso(&perso2);
		/*if((perso.pos_image_init.y>=720*3/4 || perso.pos_image_init.y<=720*1/4) && map.pos_image_aff.x>=0 && map.pos_image_aff.x<=579)
		{
			
			scrolling(&map,0, (perso.speed * perso.direction_axe_y));
			perso.pos_image_init.y -= perso.speed * perso.direction_axe_y;
		}*/

		if(perso.pos_image_init.y<=720/4 && perso.direction_axe_y==-1)
		{
			scrolling(&map,0, (perso.speed * perso.direction_axe_y));
			perso.pos_image_init.y -= perso.speed * perso.direction_axe_y;
		}
		else if (perso.pos_image_init.y>=720*3/4 && perso.direction_axe_y==1)
		{
			scrolling(&map,0, (perso.speed * perso.direction_axe_y));
			perso.pos_image_init.y -= perso.speed * perso.direction_axe_y;
		}
		if(player_out_home_state==1)
		{
			screen_num=5;

		}
		MAJMinimap(perso.pos_image_init, &mini, map.pos_image_aff, 20); 
		MAJphone(&ph);
		
		//printf(" Perso:%d---%d\n",perso.pos_image_init.x,perso.pos_image_init.y);
		//printf(" BACKk:%d---%d\n",map.pos_image_aff.x,map.pos_image_aff.y);

		printf("player pos x: %d , pos y: %d \n",perso.pos_image_init.x,perso.pos_image_init.y);
		printf("miniplayer x : %d , y %d \n",mini.positionminijoueur.x,mini.positionminijoueur.y);
		


		animerPerso(&perso);
		animerPerso(&perso2);
		
		break;

//endcase1




		//case of setting button
		case 2 :
		
			locate=SDL_GetMouseState(&mousex,&mousey);

			if(last_screen==0)
			{
				SDL_BlitSurface(bg[counterimage]->scaled, NULL, screen, NULL);
			}
			if(last_screen==5)
			{
				aff_SDC_Background(&B, screen);
				afficher_Hero(&hero,screen);
			}
			SDL_BlitSurface(eff_set[0]->scaled,NULL,screen,NULL);
			SDL_BlitSurface(eff_set[1]->scaled,NULL,screen,NULL);
			SDL_BlitSurface(mus_eff[vol_mus]->scaled,NULL,screen,NULL);
			SDL_BlitSurface(sfx_eff[vol_sfx]->scaled,NULL,screen,NULL);


			//SDL_BlitSurface(m,NULL,screen,&mpos);
			if(mouseinter(screen,77,11,80,16)==1)
			{
				SDL_BlitSurface(eff_set[3]->scaled,NULL,screen,NULL);
				if(e.type==SDL_MOUSEBUTTONDOWN && e.button.button==SDL_BUTTON_LEFT)
				{
					screen_num=last_screen;
					bg_num=30;
					break;
				}
			}
			else
			{
				SDL_BlitSurface(eff_set[2]->scaled,NULL,screen,NULL);
			}
  	    	counterimage = (counterimage + 1) % bg_num;
			SDL_Flip(screen);
			if(SDL_PollEvent(&e))
			{
			switch(e.type)
			{

				case SDL_QUIT : bg_num=30;screen_num=-1;run=0;break;
 					break;

				case SDL_MOUSEBUTTONDOWN :if((e.button.button==SDL_BUTTON_LEFT)){
	  											    if(mouseinter(screen,35,31,38,37)==1){vol_mus=0;}
													else if(mouseinter(screen,39,31,42,37)==1){vol_mus=1;}
													else if(mouseinter(screen,42,31,45,37)==1){vol_mus=2;}
													else if(mouseinter(screen,45,31,48,37)==1){vol_mus=3;}
													else if(mouseinter(screen,48,31,51,37)==1){vol_mus=4;}
													else if(mouseinter(screen,51,31,54,37)==1){vol_mus=5;}
													else if(mouseinter(screen,54,31,58,37)==1){vol_mus=6;}
													else if(mouseinter(screen,57,31,61,37)==1){vol_mus=7;}
													else if(mouseinter(screen,61,31,64,37)==1){vol_mus=8;}
													else if(mouseinter(screen,64,31,67,37)==1){vol_mus=9;}
													else if(mouseinter(screen,67,31,70,37)==1){vol_mus=10;}
													else if(mouseinter(screen,70,31,73,37)==1){vol_mus=11;}
													else if(mouseinter(screen,73,31,75,37)==1){vol_mus=12;}
													Mix_VolumeMusic(vol_mus*(100/12));
										}	
										if(e.button.button==SDL_BUTTON_LEFT)
										{
	    											if(mouseinter(screen,35,46,38,54)==1){vol_sfx=0;}
													else if(mouseinter(screen,39,46,42,54)==1){vol_sfx=1;}
													else if(mouseinter(screen,42,46,45,54)==1){vol_sfx=2;}
													else if(mouseinter(screen,45,46,48,54)==1){vol_sfx=3;}
													else if(mouseinter(screen,48,46,51,54)==1){vol_sfx=4;}
													else if(mouseinter(screen,51,46,54,54)==1){vol_sfx=5;}
													else if(mouseinter(screen,54,46,58,54)==1){vol_sfx=6;}
													else if(mouseinter(screen,58,46,61,54)==1){vol_sfx=7;}
													else if(mouseinter(screen,61,46,64,54)==1){vol_sfx=8;}
													else if(mouseinter(screen,64,46,67,54)==1){vol_sfx=9;}
													else if(mouseinter(screen,67,46,70,54)==1){vol_sfx=10;}
													else if(mouseinter(screen,70,46,73,54)==1){vol_sfx=11;}
													else if(mouseinter(screen,73,46,75,54)==1){vol_sfx=12;}
													Mix_VolumeChunk(knock,vol_sfx*(100/12));
										}									
										break;
			}
		}
		break ;
		//case of exit button
		case 3 :		locate=SDL_GetMouseState(&mousex,&mousey);
						SDL_BlitSurface(bg[count]->scaled,NULL,screen,NULL);
						if(mouseinter(screen,32,50,49,58)==1)
						{
							SDL_BlitSurface(exit_yes_no[2]->scaled,NULL,screen,NULL);
							if(e.type==SDL_MOUSEBUTTONDOWN && e.button.button==SDL_BUTTON_LEFT)
							{
								screen_num=-1;run=0;
							}
						}
						else if(mouseinter(screen,51,50,67,58)==1)
						{
							SDL_BlitSurface(exit_yes_no[1]->scaled,NULL,screen,NULL);
							if(e.type==SDL_MOUSEBUTTONDOWN && e.button.button==SDL_BUTTON_LEFT)
							{
								screen_num=0;break;
							}
						}
						else{SDL_BlitSurface(exit_yes_no[0]->scaled,NULL,screen,NULL);}
						SDL_Flip(screen);
						count = (count + 1) % bg_num;
					if(SDL_PollEvent(&e))
					{
						switch(e.type)
						{

							case SDL_QUIT : screen_num=-1;run=0;
 								break;
							
				
						}

					}
				
					
		break;
		//case of computer 
		case 4 :
			switch(opened_screen_pc)
			{
			case 0:
						SDL_BlitSurface(pc_screen.img,NULL,screen,NULL);
						SDL_BlitSurface(pc_icons.img,&icons.pos_icon,screen,&icons.pos_icon);
						SDL_BlitSurface(pc_app.img,NULL,screen,NULL);
						SDL_BlitSurface(pc_lowbar.img,NULL,screen,&pc_lowbar.pos_image_init);
						pop_lowbar_win(pc_lowbar,pc_window,screen);
						SDL_Flip(screen);
						if(SDL_PollEvent(&e))
						{
							switch(e.type)
							{
								case SDL_QUIT:
									screen_num=-1;
									run=0;
								break;
								case SDL_KEYUP :
									if(e.key.keysym.sym==SDLK_ESCAPE)
									{
										screen_num=1;
										pc_state=0;
									}
								break;
							}
						}
						show_selected_icon(&icons,e,&selected_icon,&opened_screen_pc);
						pop_out_lowbar(&pc_lowbar);
						
			break;
			//case of application code HUB (application in computer)
			case 1: //coding interface
				SDL_BlitSurface(pc_screen.img,NULL,screen,NULL);
				SDL_BlitSurface(pc_icons.img,&icons.pos_icon,screen,&icons.pos_icon);
						SDL_BlitSurface(pc_app.img,NULL,screen,NULL);
						SDL_BlitSurface(pc_lowbar.img,NULL,screen,&pc_lowbar.pos_image_init);
						
				SDL_BlitSurface(pc_app_coding.img,NULL,screen,&pc_app_coding.pos_image_init);
				renderText_by_url(screen,pc_app_coding,"code_with_correction/wrong/q0.txt");
				renderText(screen,pc_app_coding);
				pop_lowbar_win(pc_lowbar,pc_window,screen);
				SDL_Flip(screen);
				if(SDL_PollEvent(&e))
				{
					switch(e.type)
					{
						case SDL_QUIT : 
							screen_num=-1;run=0;

 						break;
						case SDL_MOUSEBUTTONDOWN:
							if(e.button.button==SDL_BUTTON_LEFT)
							{
							mouse_button_left_state=1;
							SDL_GetMouseState(&mousex,&mousey);
							if(mouse_in_rect(pc_app_coding.pos_image_init.x,pc_app_coding.pos_image_init.y,708,29,mousex,mousey)==1)
							 {
								window_in_drag=1;
								decalagex=mousex-pc_app_coding.pos_image_init.x;
								decalagey=mousey-pc_app_coding.pos_image_init.y;
							 }
							if(mouse_in_rect(pc_app_coding.pos_image_init.x+707,pc_app_coding.pos_image_init.y+4,30,28,mousex,mousey)==1)
							{
								opened_screen_pc=0;
								SDL_EnableKeyRepeat(0, 0);
							}

							}
						break;
						case SDL_MOUSEBUTTONUP:
							if(e.button.button==SDL_BUTTON_LEFT )
							window_in_drag=0;
							if(compare_files("Text_INPUT/file.txt","code_with_correction/correct/q0.txt")==1)
							{
								printf("good job you earn +100$ and 50 exp\n");
							}
							else{printf("echec \n");}

						break;
						case SDL_KEYUP :
								if (e.key.keysym.sym == 313) {  // altgr update
                         			 altgr_held = 0;
                   				  }
                   				 if (e.key.keysym.sym == 304) {  // shift  update
                     				shift_held = 0;
								 }
						break;
						case SDL_KEYDOWN:
                			if (e.key.keysym.sym == 313) {  // ALTGR in hold
                			     altgr_held = 1;
                			 }
                			if (e.key.keysym.sym == 304) {  //  shift in hold
                			     shift_held = 1;
                			 }
							
                			handleKeyPress(e.key);
                			handleKeyMod(&e,altgr_held,shift_held) ;
						break;
					}
				}
				if(e.type==SDL_MOUSEBUTTONUP&&e.button.button==SDL_BUTTON_LEFT)
				window_in_drag=0;
				if(window_in_drag==1)
				move_window(&pc_app_coding,window_in_drag,&decalagex,&decalagey);
				show_selected_icon(&icons,e,&selected_icon,&opened_screen_pc);
				pop_out_lowbar(&pc_lowbar);				

			
			break;
			case 2://chrome case
				SDL_BlitSurface(pc_screen.img,NULL,screen,NULL);
				SDL_BlitSurface(pc_icons.img,&icons.pos_icon,screen,&icons.pos_icon);
				SDL_BlitSurface(pc_app.img,NULL,screen,NULL);
				SDL_BlitSurface(pc_lowbar.img,NULL,screen,&pc_lowbar.pos_image_init);
				SDL_BlitSurface(pc_chrome.img,NULL,screen,&pc_chrome.pos_image_init);
				pop_lowbar_win(pc_lowbar,pc_window,screen);
				SDL_Flip(screen);
				if(SDL_PollEvent(&e))
				{
					switch(e.type)
					{
						case SDL_QUIT:
							run=0;
						break;
						case SDL_MOUSEBUTTONDOWN:
							if(e.button.button==SDL_BUTTON_LEFT)
							{
							mouse_button_left_state=1;
							SDL_GetMouseState(&mousex,&mousey);
							if(mouse_in_rect(pc_chrome.pos_image_init.x,pc_chrome.pos_image_init.y,708,29,mousex,mousey)==1)
							 {
								window_in_drag=1;
								decalagex=mousex-pc_chrome.pos_image_init.x;
								decalagey=mousey-pc_chrome.pos_image_init.y;
							 }
							if(mouse_in_rect(pc_chrome.pos_image_init.x+709,pc_chrome.pos_image_init.y+4,30,28,mousex,mousey)==1)
							{
								opened_screen_pc=0;
							}

							}
						break;
						case SDL_MOUSEBUTTONUP:
							if(e.button.button==SDL_BUTTON_LEFT )
							window_in_drag=0;
						break;
						
					}
				}
				//update
				if(window_in_drag==1)
				move_window(&pc_chrome,window_in_drag,&decalagex,&decalagey);
				show_selected_icon(&icons,e,&selected_icon,&opened_screen_pc);
						pop_out_lowbar(&pc_lowbar);


			break;
			case 3://case recycle bin
				SDL_BlitSurface(pc_screen.img,NULL,screen,NULL);
				SDL_BlitSurface(pc_icons.img,&icons.pos_icon,screen,&icons.pos_icon);
						SDL_BlitSurface(pc_app.img,NULL,screen,NULL);
						SDL_BlitSurface(pc_lowbar.img,NULL,screen,&pc_lowbar.pos_image_init);
				SDL_BlitSurface(pc_recycle.img,NULL,screen,&pc_recycle.pos_image_init);
				pop_lowbar_win(pc_lowbar,pc_window,screen);
				SDL_Flip(screen);
				if(SDL_PollEvent(&e))
				{
					switch(e.type)
					{
						case SDL_QUIT:
							run=0;
						break;
						case SDL_MOUSEBUTTONDOWN:
							if(e.button.button==SDL_BUTTON_LEFT)
							{
							mouse_button_left_state=1;
							SDL_GetMouseState(&mousex,&mousey);
							if(mouse_in_rect(pc_recycle.pos_image_init.x,pc_recycle.pos_image_init.y,708,29,mousex,mousey)==1)
							 {
								window_in_drag=1;
								decalagex=mousex-pc_recycle.pos_image_init.x;
								decalagey=mousey-pc_recycle.pos_image_init.y;
							 }
							if(mouse_in_rect(pc_recycle.pos_image_init.x+709,pc_recycle.pos_image_init.y+4,30,28,mousex,mousey)==1)
							{
								opened_screen_pc=0;
							}

							}
						break;
						case SDL_MOUSEBUTTONUP:
							if(e.button.button==SDL_BUTTON_LEFT )
							window_in_drag=0;
						break;
						
					}
				}

				if(window_in_drag==1)
				move_window(&pc_recycle,window_in_drag,&decalagex,&decalagey);

				show_selected_icon(&icons,e,&selected_icon,&opened_screen_pc);
						pop_out_lowbar(&pc_lowbar);

			break;
			}
		break;

		//side scrolling game 
		case 5 :
			if(Joystick_function==1)
			read_from_arduino(&ard_ms);
			t_prev = SDL_GetTicks();
			aff_SDC_Background(&B, screen);
			if(test==1)
			SDL_BlitSurface(mask_side.img,&B.camera,screen,NULL);
			afficher_Hero(&hero,screen);
			if(msg1_state==1)
			{
				SDL_BlitSurface(msg1,NULL,screen,&pos_msg1);
			}
			if(msg_store_state==1)
			{
			SDL_BlitSurface(msg_store,NULL,screen,&pos_msg1);
			}
			
			SDL_Flip(screen);
			if(Joystick_function==1)
			{
				if(ArduinoKeyCheck(&ard_ms,"right_start")  )
					{
						I.right=1;
					hero.direction=1;
					}
				if(ArduinoKeyCheck(&ard_ms,"left_start")  )
					{
						I.left = 1;
            		    hero.direction=-1;
					}
				if(ArduinoKeyCheck(&ard_ms,"left_right_null") && (I.right != 0 || I.left != 0) )				
					{
						if(I.right==1)
            			hero.last_direction=1;
						if(I.left==1)
						hero.last_direction=-1;

						I.right = 0;
						I.left = 0 ;
					}
				if(ArduinoKeyCheck(&ard_ms,"up_start")  )
					{
						I.jump = 1;
					}
				/*if(ArduinoKeyCheck(&ard_ms,"down_start")  )
					{
						I.left = 1;
            		    hero.direction=-1;
					}
				if(ArduinoKeyCheck(&ard_ms,"up_down_null") && (I.right != 0 || I.left != 0) )
					{
						if(I.right==1)
            			hero.last_direction=1;
						if(I.left==1)
						hero.last_direction=-1;

						I.right = 0;
						I.left = 0 ;


					}*/
			}
			
			
			/*if(ArduinoKeyCheck(&ard_ms,"right_end") )
			{
  			if(I.right==1)
			{
				 I.right = 0;
                hero.last_direction=1;

                if(I.left == 1)
                hero.direction=-1;
			}
			}*/
			if(SDL_PollEvent(&e))
			{
				switch(e.type)
				{

					case SDL_QUIT : screen_num=-1;run=0;break;

 						break;
					case SDL_KEYDOWN:
					switch(e.key.keysym.sym)
                    {
                        case SDLK_SPACE:
						if(hero.col_down==1 && I.jump==0)
                            I.jump = 1;
                        break;
                        case SDLK_RIGHT:
                            I.right = 1;
                            hero.direction=1;
                            
                         break;

                        case SDLK_LEFT:
                          I.left = 1;
                          hero.direction=-1;
                          
                         break;
                        case SDLK_x :
                            I.attack = 1;
                            printf("%d",I.attack);
							if(test==0)
							test=1;
							else
							test=0;
                        break;
						case SDLK_ESCAPE :
							screen_num=2;
							last_screen=5;
						break;


                    }
					break;
					case SDL_KEYUP:
                    switch (e.key.keysym.sym)
                    {
                         /*case SDLK_SPACE:
                         I.jump = 0;
                            break;*/

                        case SDLK_RIGHT:
                            I.right = 0;
                            hero.last_direction=1;

                            if(I.left == 1)
                            hero.direction=-1;


                            break;

                        case SDLK_LEFT:
                            I.left = 0;
                            hero.last_direction=-1;
                            
                            if(I.right == 1)
                            hero.direction=1;

                            break;
                        
                }
                break;
                }
				switch(e.key.keysym.sym)
				{
					case SDLK_f:
					if(hero.heroPos.x>135 && hero.heroPos.x<135+279 && B.camera.x==0){
			
					perso.pos_image_init.x=325;
					perso.pos_image_init.y=395;
					map.pos_image_aff.x=0;
					map.pos_image_aff.y=580;
					player_out_home_state=0;
					etat_left=0;etat_right=0;etat_down=0;etat_up=0;
					perso.direction_axe_y=0;
					perso.direction_axe_x=0;
					perso.last_direction=1;
					perso.move=0;

						
					screen_num=1;
					}
					if(msg_store_state==1){
			
					perso.pos_image_init.x=627;
					perso.pos_image_init.y=508;
					map.pos_image_aff.x=0;
					map.pos_image_aff.y=580;
					//player_out_home_state=0;
					etat_left=0;etat_right=0;etat_down=0;etat_up=0;
					perso.direction_axe_y=0;
					perso.direction_axe_x=0;
					perso.last_direction=1;
					perso.move=0;

						
					screen_num=6;
					}
					break;
				}
				
					
			}
			// update player position and animation 
	// update caractere position and animation 
        if(I.right == 0 && I.left == 0)
        {
            hero.direction=0;
        }
        if(hero.direction ==0)
        {
        idleAnimation(&hero);           
        }


        else if((hero.direction ==1 || hero.direction ==-1)&& I.jump==0 && I.attack ==0)
        {
        runAnimation(&hero);
        }
        else if((hero.direction ==1 || hero.direction ==-1)&& (I.jump==1 || I.jump==-1) && I.attack ==0)
        {
            jumpAnimation(&hero);
        }
        if(I.attack==1)
        {
            attackAnimation(&hero,&I);
        }
		dt = (SDL_GetTicks()/10) - (t_prev/10);
		leftAndRightHeroMvtR(&hero,B, I, dt);


		if(SS_collision_parfaite_down(mask_side.img,hero.heroPos, B.camera.x,0)==1) 
		{
			hero.col_down=1;
		}
		else
		hero.col_down=0;

        jumpHeroMvt(&hero, &I,&B);
		if(hero.col_down==1 && I.jump==0)
		perfect_placement_player_above_mask(mask_side.img,hero.heroPos, B.camera.x,B.camera.y,&hero);


		hero.frame++;
	//end update player 
	//update SDC_background 
	animer_SDC_Back(&B);
	SD_scrolling(&B, hero.heroPos, hero.direction);
	if(hero.heroPos.x>135 && hero.heroPos.x<135+279 && B.camera.x==0)
	{
		pos_msg1.x=hero.heroPos.x-20;
		pos_msg1.y=hero.heroPos.y-20;
		msg1_state=1;
	}
	else
	msg1_state=0;


	if(SS_collision_store_enter(mask_side.img,hero.heroPos, B.camera.x,B.camera.y)==1)
	{
		pos_msg1.x=hero.heroPos.x-20;
		pos_msg1.y=hero.heroPos.y-20;
		hero.last_direction=
		msg_store_state=1;
		
	}
	else{
		msg_store_state=0;
	}

	//end update background
		

		break;
		case 6:
		locate=SDL_GetMouseState(&mousex,&mousey);

	//affichage
		afficherBack(map_store,screen); //to edit map,screen
		afficherPerso(perso,screen);
		if(syncro!=map.pos_image_aff.y){
		perso2.pos_image_init.y-=(map.pos_image_aff.y-syncro);
		syncro=map.pos_image_aff.y;
		
		}
		if(multiplayer_state==1)
		afficherPerso(perso2,screen);
		if(msg_state==1)
		{
			SDL_BlitSurface(msg,NULL,screen,&pos_msg);
		}
		//afficherminimap(mini,map, screen);
		//if(ph.phone_state==1)
		aff_phone(&ph,screen);

		SDL_Flip(screen);
	//end affichage
		if(Joystick_function==1)
		read_from_arduino(&ard_ms);
		if(Joystick_function==1)
			{
				if(ArduinoKeyCheck(&ard_ms,"right_start")  )
					{
						etat_right=1;
						perso.direction_axe_x=1;
						perso.move=1;
					}
				if(ArduinoKeyCheck(&ard_ms,"left_start")  )
					{
						etat_left=1;
						perso.direction_axe_x=-1;
						perso.move=1;
						
					}
				if(ArduinoKeyCheck(&ard_ms,"left_right_null") && (etat_right != 0 || etat_left != 0) )				
					{
						if(etat_right==1)
            			perso.last_direction=1;
						if(etat_left==1)
						perso.last_direction=2;

						etat_right=0;
						etat_left=0;
						perso.direction_axe_x =0;
						
					}
				if(ArduinoKeyCheck(&ard_ms,"up_start")  )
					{
						etat_up=1;
						perso.direction_axe_y=-1;
						perso.move=1;
					}
				if(ArduinoKeyCheck(&ard_ms,"down_start")  )
					{
						etat_down=1;
						perso.direction_axe_y=1;
						perso.move=1;
					}
				if(ArduinoKeyCheck(&ard_ms,"up_down_null") && (etat_down != 0 || etat_up != 0) )
					{
						if(etat_down==1)
            			perso.last_direction=3;
						if(etat_up==1)
						perso.last_direction=4;

						etat_down=0;
						etat_up=0;
						perso.direction_axe_y=0;
					}
					/*if(ArduinoKeyCheck(&ard_ms,"fpressed")  )
					{
						fpressed=1;
						if((fpressed ==1) && msg_state ==1 )
					{
						while(pc_state==0)
						{
							if(SDL_PollEvent(&e)){
								switch(e.key.keysym.sym)
								{
									case 282:
										pc_state=1;
									break;
								}
							}
							SDL_BlitSurface(pc_error.img,NULL,screen,NULL);
							SDL_Flip(screen);
						}
						
						if(pc==NULL)
						pc=init_computer(computer_img_num,screen);
						else
						parcourir_with_Delay(pc,screen,150);
						screen_num=4;
						fpressed=0;
						
					}
					}*/
				if(etat_down ==0 && etat_up ==0 && etat_right ==0 && etat_left==0)
						{
						perso.move=0;
						}
			}


			
			if(SDL_PollEvent(&e))
		{
			switch(e.type)
			{

				case SDL_QUIT : screen_num=-1;run=0;
 					break;
				case SDL_KEYDOWN :
					if(e.key.keysym.sym==SDLK_ESCAPE)
					{
						screen_num=5;
					}
					if(e.key.keysym.sym==SDLK_RIGHT)
					{
						
						etat_right=1;
						perso.direction_axe_x=1;
						perso.move=1;

					}
					if(e.key.keysym.sym==SDLK_LEFT)
					{
						etat_left=1;
						perso.direction_axe_x=-1;
						perso.move=1;
						
					}
					if(e.key.keysym.sym==SDLK_DOWN)
					{
						etat_down=1;
						perso.direction_axe_y=1;
						perso.move=1;
					}
					if(e.key.keysym.sym==SDLK_UP)
					{
						etat_up=1;
						perso.direction_axe_y=-1;
						perso.move=1;
					}
					if(e.key.keysym.sym==SDLK_d)
					{
						
						etat_right_p2=1;
						perso2.direction_axe_x=1;
						perso2.move=1;

					}
					if(e.key.keysym.sym==SDLK_q)
					{
						etat_left_p2=1;
						perso2.direction_axe_x=-1;
						perso2.move=1;
						
					}
					if(e.key.keysym.sym==SDLK_s)
					{
						etat_down_p2=1;
						perso2.direction_axe_y=1;
						perso2.move=1;
					}
					if(e.key.keysym.sym==SDLK_z)
					{
						etat_up_p2=1;
						perso2.direction_axe_y=-1;
						perso2.move=1;
					}
					if((e.key.keysym.sym == SDLK_f || fpressed ==1) && msg_state ==1 )
					{
						while(pc_state==0)
						{
							if(SDL_PollEvent(&e)){
								switch(e.key.keysym.sym)
								{
									case 282:
										pc_state=1;
									break;
								}
							}
							SDL_BlitSurface(pc_error.img,NULL,screen,NULL);
							SDL_Flip(screen);
						}
						
						if(pc==NULL)
						pc=init_computer(computer_img_num,screen);
						else
						parcourir_with_Delay(pc,screen,150);
						screen_num=4;
						fpressed=0;
						
					}
				
				break;
				case SDL_KEYUP:
					if(e.key.keysym.sym==SDLK_RIGHT ||e.key.keysym.sym==SDLK_LEFT || e.key.keysym.sym==SDLK_UP || e.key.keysym.sym==SDLK_DOWN   )
					{
					if(e.key.keysym.sym==SDLK_RIGHT)
					{
						etat_right=0;
						perso.direction_axe_x =0;
						perso.last_direction=1;
					}
					if(e.key.keysym.sym==SDLK_LEFT)
					{
						etat_left=0;
						perso.direction_axe_x =0;
						perso.last_direction=2;				
					}
					if(e.key.keysym.sym==SDLK_DOWN)
					{
						etat_down=0;
						perso.direction_axe_y=0;
						perso.last_direction=3;
					}
					if(e.key.keysym.sym==SDLK_UP)
					{
						etat_up=0;	
						perso.direction_axe_y=0;
						perso.last_direction=4;		
					}  	
						if(etat_down ==0 && etat_up ==0 && etat_right ==0 && etat_left==0)
						{
						perso.move=0;
						}
					}
					if(e.key.keysym.sym==SDLK_p)
					{
						if(ph.phone_state==1)
						{
							ph.phone_state=0;
						}
						else
							ph.phone_state=1;
					}
					// player 2 
					if(multiplayer_state==1)
					{
						if(e.key.keysym.sym==SDLK_d ||e.key.keysym.sym==SDLK_q || e.key.keysym.sym==SDLK_z || e.key.keysym.sym==SDLK_s   )
					{
					if(e.key.keysym.sym==SDLK_d)
					{
						etat_right=0;
						perso2.direction_axe_x =0;
						perso2.last_direction=1;
					}
					if(e.key.keysym.sym==SDLK_q)
					{
						etat_left=0;
						perso2.direction_axe_x =0;
						perso2.last_direction=2;				
					}
					if(e.key.keysym.sym==SDLK_s)
					{
						etat_down=0;
						perso2.direction_axe_y=0;
						perso2.last_direction=3;
					}
					if(e.key.keysym.sym==SDLK_z)
					{
						etat_up=0;	
						perso2.direction_axe_y=0;
						perso2.last_direction=4;		
					}  	
						if(etat_down_p2 ==0 && etat_up_p2 ==0 && etat_right_p2 ==0 && etat_left_p2==0)
						{
						perso2.move=0;
						}
					}

					}
					
				break;
				case SDL_MOUSEBUTTONDOWN :
					if(e.button.button==SDL_BUTTON_RIGHT)
					{
						
					}
				break;
				case SDL_MOUSEBUTTONUP :
					if(e.button.button==SDL_BUTTON_RIGHT)
					{
						perso.move=0;
						perso.direction_axe_x=0;
						perso.direction_axe_y=0;
					}
				break;
				
			}

		}
		if(ph.phone_state==1)
		{
			SDL_GetMouseState(&mousex,&mousey);
        		if(intersection_souris(spotify,mousex,mousey)==1 && e.button.button==SDL_BUTTON_LEFT)
        		{
        		    ph.num_screen=1;
        		}
        		if(intersection_souris(sms,mousex,mousey)==1 && e.button.button==SDL_BUTTON_LEFT)
        		{
        		    ph.num_screen=2;
        		}
        		if(intersection_souris(insta,mousex,mousey)==1 && e.button.button==SDL_BUTTON_LEFT)
        		{
        		    ph.num_screen=3;
        		}
        		if(intersection_souris(home_button,mousex,mousey)==1 && e.button.button==SDL_BUTTON_LEFT)
        		{
        		    ph.num_screen=0;
        		}
		}
	//collision
		if(collision_parfaite_right(mask_store.img,perso.pos_image_init,0,0)==1){
					 perso.colright=1;
					}
		else{
			perso.colright=0;
		}
		if(collision_parfaite_left(mask_store.img,perso.pos_image_init,0,0)==1){
					 perso.colleft=1;
					}
		else{
			perso.colleft=0;
		}
		if(collision_parfaite_down(mask_store.img,perso.pos_image_init,0,0)==1){
					 perso.coldown=1;
					}
		else{
			perso.coldown=0;
		}
		if(collision_parfaite_up(mask_store.img,perso.pos_image_init,0,0)==1){
					 perso.colup=1;
					}
		else{
			perso.colup=0;
		}
		/*if(collision_all_body(mask_store.img,perso.pos_image_init,0,map.pos_image_aff.y)==1)
		{
			//printf("press f to open computer");
			msg_state=1;
		}
		else
		{
			msg_state=0;
			
		}
		if(collision_out_home(mask.img,perso.pos_image_init,0,map.pos_image_aff.y)==1)
		{
			player_out_home_state=1; //not finished need add the condition when return home (player_out_home_state=0)
		}*/

	//end collision 
	
	//scrolling 

		if(perso.pos_image_init.y>=720*3/4)
		{
			map.direction_axe_y=1;
			printf("scrolling down : %d\n",map.direction_axe_y);
		}
		else if(perso.pos_image_init.y<=720*1/4)
		{
			map.direction_axe_y=-1;;
			printf("scrolling up : %d\n",map.direction_axe_y);
		}
		else 
		{
			map.direction_axe_y=0;
			//printf("pas scrolling : %d\n",map.direction_axe_y);
		}
		pos_msg.x=perso.pos_image_init.x;   // to review
		pos_msg.y=perso.pos_image_init.y-50;

	//end scrolling

		movePerso(&perso);
		//movePerso(&perso2);
		/*if((perso.pos_image_init.y>=720*3/4 || perso.pos_image_init.y<=720*1/4) && map.pos_image_aff.x>=0 && map.pos_image_aff.x<=579)
		{
			
			scrolling(&map,0, (perso.speed * perso.direction_axe_y));
			perso.pos_image_init.y -= perso.speed * perso.direction_axe_y;
		}*/

		/*if(perso.pos_image_init.y<=720/4 && perso.direction_axe_y==-1)
		{
			scrolling(&map,0, (perso.speed * perso.direction_axe_y));
			perso.pos_image_init.y -= perso.speed * perso.direction_axe_y;
		}
		else if (perso.pos_image_init.y>=720*3/4 && perso.direction_axe_y==1)
		{
			scrolling(&map,0, (perso.speed * perso.direction_axe_y));
			perso.pos_image_init.y -= perso.speed * perso.direction_axe_y;
		}
		if(player_out_home_state==1)
		{
			screen_num=5;

		}
		MAJMinimap(perso.pos_image_init, &mini, map.pos_image_aff, 20); */
		MAJphone(&ph);
		
		//printf(" Perso:%d---%d\n",perso.pos_image_init.x,perso.pos_image_init.y);
		//printf(" BACKk:%d---%d\n",map.pos_image_aff.x,map.pos_image_aff.y);

		printf("player pos x: %d , pos y: %d \n",perso.pos_image_init.x,perso.pos_image_init.y);
		printf("miniplayer x : %d , y %d \n",mini.positionminijoueur.x,mini.positionminijoueur.y);
		


		animerPerso(&perso);
		//animerPerso(&perso2);


		break;

        default : printf("Game Propobly CLosed");
        break;
    }
	






}//end of loop RUN=0!!!













for (i = 0; i < load_num; i++) {
    free(loading[i]->url);
    SDL_FreeSurface(loading[i]->img);
    SDL_FreeSurface(loading[i]->scaled);
    free(loading[i]);
}

for (i = 0; i < bg_num; i++) {
    free(bg[i]->url);
    SDL_FreeSurface(bg[i]->img);
    SDL_FreeSurface(bg[i]->scaled);
    free(bg[i]);
}

for (i = 0; i < start_num; i++) {
    free(start[i]->url);
    SDL_FreeSurface(start[i]->img);
    SDL_FreeSurface(start[i]->scaled);
    free(start[i]);
}

for (i = 0; i < set_num; i++) {
    free(setting[i]->url);
    SDL_FreeSurface(setting[i]->img);
    SDL_FreeSurface(setting[i]->scaled);
    free(setting[i]);
}

for (i = 0; i < ext_num; i++) {
    free(exit[i]->url);
    SDL_FreeSurface(exit[i]->img);
    SDL_FreeSurface(exit[i]->scaled);
    free(exit[i]);
}

// Freeing effect arrays
for (i = 0; i < eff_set_num; i++) {
    free(eff_set[i]->url);
    SDL_FreeSurface(eff_set[i]->img);
    SDL_FreeSurface(eff_set[i]->scaled);
    free(eff_set[i]);
}

for (i = 0; i < mus_eff_num; i++) {
    free(mus_eff[i]->url);
    SDL_FreeSurface(mus_eff[i]->img);
    SDL_FreeSurface(mus_eff[i]->scaled);
    free(mus_eff[i]);
}

for (i = 0; i < sfx_eff_num; i++) {
    free(sfx_eff[i]->url);
    SDL_FreeSurface(sfx_eff[i]->img);
    SDL_FreeSurface(sfx_eff[i]->scaled);
    free(sfx_eff[i]);
}



/*for (i = 0; i < tv_eff_num; i++) {
    free(tv_eff[i]->url);
    SDL_FreeSurface(tv_eff[i]->img);
    SDL_FreeSurface(tv_eff[i]->scaled);
    free(tv_eff[i]);
}*/
SDL_FreeSurface(screen);
SDL_Quit();


}
