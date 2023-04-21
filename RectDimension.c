#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "RectDimension.h"

void init_icon_pos1(icon *I)
{
    I->pos_icon.x=0;
    I->pos_icon.y=0;
    I->pos_icon.w=113;
    I->pos_icon.h=104;
}
void init_icon_pos2(icon *I)
{
    I->pos_icon.x=0;
    I->pos_icon.y=105;
    I->pos_icon.w=113;
    I->pos_icon.h=104;
}
void init_icon_pos3(icon *I)
{
    I->pos_icon.x=0;
    I->pos_icon.y=203;
    I->pos_icon.w=113;
    I->pos_icon.h=104;
}
void init_icon_pos4(icon *I)
{
    I->pos_icon.x=0;
    I->pos_icon.y=303;
    I->pos_icon.w=113;
    I->pos_icon.h=104;
}
void init_icon_pos0(icon *I)
{
    I->pos_icon.x=0;
    I->pos_icon.y=0;
    I->pos_icon.w=0;
    I->pos_icon.h=0;
}