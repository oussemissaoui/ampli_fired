#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED



/**

    @struct personne
    @brief struct for player character
    */
    struct personne
    {
    char url; /!< URL of player image. /
    SDL_Surface img; /!< Surface of player image. /
    SDL_Rect pos_image_aff; /!< Rectangle for displaying player image. /
    SDL_Rect pos_image_init; /!< Initial rectangle for player image. /
    int nb_vie; /!< Number of lives of the player. /
    int direction_axe_x; /!< X-axis movement direction of the player. 0: no move, 1: right, -1: left. /
    int direction_axe_y; /!< Y-axis movement direction of the player. 0: no move, 1: down, -1: up. /
    int last_direction; /!< Last direction of movement for the player. /
    int move; /!< Movement state of the player. /
    int col; /!< Collision state of the player. /
    int frame; /!< Frame of animation for the player. /
    float speed; /!< Movement speed of the player. /
    int colright; /!< Collision state on the right side of the player. /
    int colleft; /!< Collision state on the left side of the player. /
    int cooldown; /!< Cooldown state of the player. /
    int colup; /!< Collision state on the upper side of the player. */
    };
    typedef struct personne personne;



void initPerso(personne *p);
void afficherPerso(personne p, SDL_Surface * screen);
void movePerso (personne *p);
void animerPerso (personne* p);


#endif // PLAYER_H_INCLUDED