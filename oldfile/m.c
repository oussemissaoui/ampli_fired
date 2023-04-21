#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "j.h"

int main()
{
//init SDL---TTF
TTF_Init();
SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
//declaration variable
int num_i=30,mousex,mousey,i;
int run=1,counterimage=0;
int vol_mus=5,vol_sfx=5;
int screen_num=0;
SDL_Surface *screen=NULL,*bg[num_i],*sbg[num_i],*click;
image set,set1,ext1,ext2,play1,*set_eff[4],*mus_eff[13],notdeveloped,*sfx_eff[13],*start_effect[250];
SDL_Rect clickwindow;
Mix_Music *Music1;
Mix_Chunk *knock;
Uint32 locate; //used for save mouse cord...
for ( i = 0; i < 250; i++) {
    start_effect[i] = malloc(sizeof(image));
	if (start_effect[i]== NULL) {
    // Allocation failed
    printf("Failed to allocate memory.\n");
	}}
for (i = 0; i < 4; i++) {
    set_eff[i] = malloc(sizeof(image));
	if (set_eff[i]== NULL) {
    // Allocation failed
    printf("Failed to allocate memory.\n");
	}
}
for (i = 0; i < 13; i++) {
    mus_eff[i] = malloc(sizeof(image));
	if (mus_eff[i]== NULL) {
    // Allocation failed
    printf("Failed to allocate memory.\n");
	}
}
for (i = 0; i < 13; i++) {
    sfx_eff[i] = malloc(sizeof(image));
	if (sfx_eff[i]== NULL) {
    // Allocation failed
    printf("Failed to allocate memory.\n");
	}
}

//LOAD ALL IMAGE (load image 9bal init  screen to avoid blackscreen  )
load_all_img(bg,num_i);

notdeveloped.img=IMG_Load("IMG/effect_set/UNDER_DEVELOPEMNT.png");
set.img=IMG_Load("MENU/START/SETTINGS/BIG/SETTINGS SELECTED.png");
set1.img=IMG_Load("MENU/START/SETTINGS/BIG/SETTINGS LIGHT.png");
ext1.img=IMG_Load("MENU/START/EXIT/BIG/BUTTON SELECTED.png");
ext2.img=IMG_Load("MENU/START/EXIT/BIG/RED LIGHT.png");
play1.img=IMG_Load("MENU/START/START/BIG/SELECTED.png");
click=IMG_Load("MENU/START/CLICK EFFCETS/BIG/WINDOW.png");
load_all_img_v2(set_eff,4);
load_all_img_v3(mus_eff,13);
load_all_img_v4(sfx_eff,13);
effect_video(start_effect,250);


//load
set.scaled=first_resizeimg(set.img);
 set1.scaled=first_resizeimg(set1.img);
 ext1.scaled=first_resizeimg(ext1.img);
 ext2.scaled=first_resizeimg(ext2.img);
 play1.scaled=first_resizeimg(play1.img);
 for ( i = 0; i < 4; i++) {
    set_eff[i]->scaled=first_resizeimg( set_eff[i]->img);
}
 for ( i = 0; i < 13; i++) {
    mus_eff[i]->scaled=first_resizeimg( mus_eff[i]->img);
}
 for (i = 0; i < 13; i++) {
    sfx_eff[i]->scaled=first_resizeimg( sfx_eff[i]->img);
}


notdeveloped.scaled=first_resizeimg(notdeveloped.img);



//init music
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
printf("Unable init Music %s",Mix_GetError());
}
knock=Mix_LoadWAV("mp3/knock.wav");
play_music(Music1,"mp3/musicbg1.mp3");
//init_screen
screen=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);

if(screen==NULL){
printf("ERROR unable open screen %s",SDL_GetError());

}
//resize image to be compatible with screen resolution xD
resize_allimg(screen,bg,sbg,num_i);
//font
 TTF_Font *chrono;
 chrono=TTF_OpenFont("Karmella.otf",40);
 SDL_Color chronocolor={255,0,0};  
 //surface mouse 
 char posmouse[20];
 SDL_Surface *m;
 m=TTF_RenderText_Blended(chrono,"0,0",chronocolor);
 SDL_Rect mpos;
 mpos.x=50;
 mpos.y=50;
 SDL_BlitSurface(m,NULL,screen,&mpos);
 SDL_Flip(screen);



//game 
while(run==1)
{
	SDL_Event e;
	switch(screen_num){
		case 0 :
		locate=SDL_GetMouseState(&mousex,&mousey);
		SDL_BlitSurface(sbg[counterimage], NULL, screen, NULL);
		//SDL_BlitSurface(m,NULL,screen,&mpos);

		if(mouseinter(screen,47,29,65,47)==1)
		{
			SDL_BlitSurface(play1.scaled,NULL,screen,NULL);
			if(e.type==SDL_MOUSEBUTTONDOWN && e.button.button==SDL_BUTTON_LEFT){
			for(i=0;i<250;i++){

				SDL_BlitSurface(start_effect[i]->scaled,NULL,screen,NULL);
 				SDL_Flip(screen);
				if(i>250){SDL_Delay(50);}}

				screen_num=1;
			break;}
		}
		if(mouseinter(screen,33,10,42,26)==1||mouseinter(screen,27,21,34,31)==1)
		{
			SDL_BlitSurface(set.scaled,NULL,screen,NULL);SDL_BlitSurface(set1.scaled,NULL,screen,NULL);
			if(e.type==SDL_MOUSEBUTTONDOWN && e.button.button){num_i=10;screen_num=2;break;}
		}
		if(mouseinter(screen,81,13,88,31)==1)
		{
			SDL_BlitSurface(ext1.scaled,NULL,screen,NULL);SDL_BlitSurface(ext2.scaled,NULL,screen,NULL);
			if(e.type==SDL_MOUSEBUTTONDOWN && e.button.button){screen_num=-1;run=0;break;}
		}	

		SDL_Flip(screen);
  	    counterimage = (counterimage + 1) % num_i;

		if(SDL_PollEvent(&e)){
			switch(e.type){
				case SDL_QUIT : screen_num=-1;run=0;break;
 					break;

 				case SDL_VIDEORESIZE:
					SDL_FreeSurface(screen);
					screen=SDL_SetVideoMode(e.resize.w,e.resize.h,32,SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
				resize_allimg(screen,bg,sbg,num_i);
				set.scaled=resizeimg(screen, set.img);
				set1.scaled=resizeimg(screen,set1.img);
				ext1.scaled=resizeimg(screen,ext1.img);
				ext2.scaled=resizeimg(screen,ext2.img);
				play1.scaled=resizeimg(screen,play1.img);
					break;

				case SDL_MOUSEBUTTONDOWN : if(mouseinter(screen,4,32,21,68)==1&&e.button.button==SDL_BUTTON_LEFT){clickwindow.x=mousex-25;clickwindow.y=mousey-25;Mix_PlayChannel(-1,knock,0);aff_oneimg_loop(screen,click,70,clickwindow);}
					break;
				  
 				/*case SDL_MOUSEMOTION:sprintf(posmouse,"%d,%d",e.motion.x,e.motion.y);
		    	 m=TTF_RenderText_Blended(chrono,posmouse,chronocolor);
 					break;*/

		}}

		break;
		case 1 :
		
		SDL_BlitSurface(notdeveloped.scaled,NULL,screen,NULL);
		SDL_Flip(screen);
		
		if(SDL_PollEvent(&e))
		{
			switch(e.type)
			{

				case SDL_QUIT : printf("you are in play "); screen_num=-1;run=0;
 					break;
				case SDL_MOUSEBUTTONDOWN : if(e.button.button==SDL_BUTTON_LEFT){ screen_num=0;}
				break;
				
			}

		}
		break;
		case 2 :
		
		locate=SDL_GetMouseState(&mousex,&mousey);
		
		SDL_BlitSurface(sbg[counterimage], NULL, screen, NULL);
		SDL_BlitSurface(set_eff[0]->scaled,NULL,screen,NULL);
		SDL_BlitSurface(mus_eff[vol_mus]->scaled,NULL,screen,NULL);
		SDL_BlitSurface(sfx_eff[vol_sfx]->scaled,NULL,screen,NULL);

		SDL_BlitSurface(set_eff[1]->scaled,NULL,screen,NULL);
		

		SDL_BlitSurface(m,NULL,screen,&mpos);
		if(mouseinter(screen,77,11,80,16)==1)
		{
			SDL_BlitSurface(set_eff[3]->scaled,NULL,screen,NULL);
			if(e.type==SDL_MOUSEBUTTONDOWN && e.button.button==SDL_BUTTON_LEFT){screen_num=0;num_i=30;SDL_Delay(100);;break;}
		}
		else{SDL_BlitSurface(set_eff[2]->scaled,NULL,screen,NULL);}
  	    counterimage = (counterimage + 1) % num_i;
		SDL_Flip(screen);
		if(SDL_WaitEvent(&e))
		{
			switch(e.type)
			{

				case SDL_QUIT :printf("you are in setting "); num_i=30;screen_num=-1;run=0;break;
 					break;
				case SDL_VIDEORESIZE:
					SDL_FreeSurface(screen);
					screen=SDL_SetVideoMode(e.resize.w,e.resize.h,32,SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
				resize_allimg(screen,bg,sbg,30);
				set_eff[0]->scaled=resizeimg(screen, set_eff[0]->img);
				set_eff[1]->scaled=resizeimg(screen, set_eff[1]->img);
				set_eff[2]->scaled=resizeimg(screen, set_eff[2]->img);
				set_eff[3]->scaled=resizeimg(screen, set_eff[3]->img);
				 for (i = 0; i < 13; i++) {
    				sfx_eff[i]->scaled=resizeimg(screen,sfx_eff[i]->img);
					}
					for (i = 0; i < 13; i++) {
    				mus_eff[i]->scaled=resizeimg(screen,mus_eff[i]->img);
					}
					break;
				case SDL_MOUSEMOTION:sprintf(posmouse,"%d,%d",mousex*100/1280,e.motion.y*100/720);
		    	 m=TTF_RenderText_Blended(chrono,posmouse,chronocolor);
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
		
		
		
	}


}//while run=1
	SDL_FreeSurface(screen);
 	for(int fs=0 ;fs<num_i;fs++)
 		{
  			SDL_FreeSurface(bg[fs]);
  			SDL_FreeSurface(sbg[fs]);
		 }
		
Mix_FreeChunk(knock);
for (int i = 0; i < 4; i++) {
    free(set_eff[i]);
}
for (int i = 0; i < 13; i++) {
   free(mus_eff[i]);
}
for (int i = 0; i < 250; i++) {
   free(start_effect[i]);
}


SDL_Quit();
}//int main

































