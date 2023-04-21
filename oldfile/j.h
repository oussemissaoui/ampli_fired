#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

typedef struct
{
 SDL_Surface *img;
 SDL_Surface *scaled;
}image;

//images
void load_all_img(SDL_Surface *i[],int nb_img);
void load_all_img_v2(image *i[],int nb_img);
void load_all_img_v3(image *i[],int nb_img);
void load_all_img_v4(image *i[],int nb_img);
void effect_video(image *i[],int nb_img);



SDL_Surface* resizeimg(SDL_Surface *s,SDL_Surface *i);
void resize_allimg(SDL_Surface *s,SDL_Surface *i[],SDL_Surface *scaled_i[],int nb_img);
SDL_Surface* first_resizeimg(SDL_Surface *i);

void aff_allimg(SDL_Surface *s,SDL_Surface *scaled_i[],int nb_img);
void aff_oneimg_loop(SDL_Surface *s,SDL_Surface *scaled_i,int nb_img,SDL_Rect m);



//music 
void play_music(Mix_Music *m,char musicpath[]);

int mouseinter(SDL_Surface *s,int x,int y,int w,int h); //mouse controle and instersection

#endif // JEU_H_INCLUDED
