#ifndef TEXTINPUT_H_INCLUDED
#define TEXTINPUT_H_INCLUDED

#include "computer.h"
void handleKeyMod(SDL_Event *event,int altgr_held,int shift_held);
void handleKeyPress(SDL_KeyboardEvent key);
void renderText(SDL_Surface *screen,computer c);
void renderText_by_url(SDL_Surface *screen,computer c,char url[]);
int compare_files(const char *filename1, const char *filename2);

#endif