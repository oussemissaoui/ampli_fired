#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
typedef struct
{
    char *url;
    SDL_Surface *img;
    SDL_Rect pos_image_aff,pos_image_init;
    int direction_axe_x; // 0:no move 1: right  -1:left
    int direction_axe_y; // 0:no move 1: down  -1:up
    int xOffset;
    int yOffset;

}background;
void initBack(background * b);
void initMask(background * b);
void afficherBack(background b, SDL_Surface * screen);
void scrolling (background * b, int direction , int pas);
/*void scrolling (SDL_Rect * b, int direction, int pas );
void animerBack (background* b);*/



#endif // BACKGROUND_H_INCLUDED