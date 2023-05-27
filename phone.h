#ifndef PHONE_H
#define PHONE_H



typedef struct
{
    SDL_Surface *img[4];
    //SDL_Surface *minijoueur;
    SDL_Rect pos_image_init;
    Mix_Music *lock_phone;
    int phone_state;
    int phone_music_state;
    int phone_notification;
    int num_screen;
    



} phone;

void init_phone(phone *ph);
void aff_phone(phone *ph,SDL_Surface *screen);
void MAJphone(phone *ph);







#endif