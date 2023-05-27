#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

typedef struct
{
char *url;
SDL_Rect pos_image_aff;
SDL_Rect pos_image_init;
SDL_Surface *img,*scaled;
int etat_resize;
}image;

typedef struct cellule cellule;
struct cellule
{
    image d;
    cellule *suiv;
};
typedef struct cellule *liste;

//resize image functions
SDL_Surface* first_resizeimg(SDL_Surface *i);
SDL_Surface* resizeimg(SDL_Surface *s,SDL_Surface *i);
void resize_5images(SDL_Surface *s,image *a[],int nb_imga,image *b[],int nb_imgb,image *c[],int nb_imgc,image *d[],int nb_imgd,image *e[],int nb_imge);
void resize_4images(SDL_Surface *s,image *a[],int nb_imga,image *b[],int nb_imgb,image *c[],int nb_imgc,image *d[],int nb_imgd);
void resize_1image(SDL_Surface *s,image *a[],int nb_imga);


//end of resize images functions
//load all image
    void init_loading_img(image *i[],int nb_img);
    void init_bg_img(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load);
    void init_start_img(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load);
    void init_setting_img(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load);
    void init_exit_img(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load);
    void init_effect_set_img(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load);
    void init_mus_eff_img(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load);
    void init_sfx_eff_img(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load);

    void init_start_tv_eff(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load);
    void init_extra(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load);
    void init_choice_exit(SDL_Surface *s,image *i[],int nb_img,image *load[],int num_load);

//end of function of Load all IMG 

void play_music(Mix_Music *m,char musicpath[]);



//intesection function 
int mouseinter(SDL_Surface *s,int x,int y,int w,int h);
int mouse_in_rect(int rect_x,int rect_y,int rect_w,int rect_h,int mousex,int mousey);
int intersection_souris(SDL_Rect poscarre,int mousex,int mousey);


//end of function of intersection

liste init_start_tv(int nb_img,SDL_Surface *s,image *load[],int num_load);
liste ajouter_Fin(liste l, int val);
void parcourir(liste l,SDL_Surface* screen);
void parcourir_with_Delay(liste l,SDL_Surface* screen,int Delay);
void add_blit_delete(SDL_Surface *screen);


#endif // JEU_H_INCLUDED