#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "jeu.h"
#include "music.h"



//music function
    void play_music(Mix_Music *m,char musicpath[])
    {
    m=Mix_LoadMUS(musicpath);
    Mix_VolumeMusic(100);
    Mix_PlayMusic(m,-1);
    }
    void phone_lock_son(Mix_Music *m)
    {
    m=Mix_LoadMUS("mp3/phone_lock.mp3");
    Mix_VolumeMusic(100);
    Mix_PlayMusic(m,0);
    }


