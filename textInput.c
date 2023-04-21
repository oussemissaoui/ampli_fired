#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <unistd.h>
#include "textInput.h"
#include "computer.h"


void handleKeyMod(SDL_Event *event,int altgr_held,int shift_held) {
    FILE *fp;
    if (altgr_held) 
                    {  
                     switch(event->key.keysym.sym)
                      {
                        
                        
                        case 34 :
                                fp = fopen("Text_INPUT/file.txt", "a");
                                if (fp != NULL) {
                                    fputc('#', fp);
                                    fclose(fp);
                                }
                        break;
                        case 38 :
                                fp = fopen("Text_INPUT/file.txt", "a");
                                if (fp != NULL) {
                                    fputc('&', fp);
                                    fclose(fp);
                                }
                        break;
                        case 39 :
                                fp = fopen("Text_INPUT/file.txt", "a");
                                if (fp != NULL) {
                                    fputc('{', fp);
                                    fclose(fp);
                                }
                        break;
                        case 40:
                                fp = fopen("Text_INPUT/file.txt", "a");
                                if (fp != NULL) {
                                    fputc('[', fp);
                                    fclose(fp);
                                }
                        break;
                        case 41 :
                                fp = fopen("Text_INPUT/file.txt", "a");
                                if (fp != NULL) {
                                    fputc(']', fp);
                                    fclose(fp);
                                }
                        break;
                        case 45 :
                                fp = fopen("Text_INPUT/file.txt", "a");
                                if (fp != NULL) {
                                    fputc('|', fp);
                                    fclose(fp);
                                }
                        break;
                        case 61 :
                                fp = fopen("Text_INPUT/file.txt", "a");
                                if (fp != NULL) {
                                    fputc('}', fp);
                                    fclose(fp);
                                }
                        break;
                        case 95:
                                fp = fopen("Text_INPUT/file.txt", "a");
                                if (fp != NULL) {
                                    fputc('\\', fp);
                                    fclose(fp);
                                }
                            break;




                      }
                     }
            else if(!altgr_held)
                 {
                         switch(event->key.keysym.sym)
                            {
                                case 34 :
                                fp = fopen("Text_INPUT/file.txt", "a");
                                if (fp != NULL) {
                                    fputc('"', fp);
                                    fclose(fp);
                                }
                        break;
                        case 38 :
                                fp = fopen("Text_INPUT/file.txt", "a");
                                if (fp != NULL) {
                                    fputc('&', fp);
                                    fclose(fp);
                                }
                        break;
                        case 39 :
                                fp = fopen("Text_INPUT/file.txt", "a");
                                if (fp != NULL) {
                                    fputc('\'', fp);
                                    fclose(fp);
                                }
                        break;
                        case 40:
                                fp = fopen("Text_INPUT/file.txt", "a");
                                if (fp != NULL) {
                                    fputc('(', fp);
                                    fclose(fp);
                                }
                        break;
                        case 41 :
                                fp = fopen("Text_INPUT/file.txt", "a");
                                if (fp != NULL) {
                                    fputc(')', fp);
                                    fclose(fp);
                                }
                        break;
                        case 45 :
                                fp = fopen("Text_INPUT/file.txt", "a");
                                if (fp != NULL) {
                                    fputc('-', fp);
                                    fclose(fp);
                                }
                        break;
                        case 61 :
                                fp = fopen("Text_INPUT/file.txt", "a");
                                if (fp != NULL) {
                                    fputc('=', fp);
                                    fclose(fp);
                                }
                        break;
                        case 95:
                                fp = fopen("Text_INPUT/file.txt", "a");
                                if (fp != NULL) {
                                    fputc('_', fp);
                                    fclose(fp);
                                }
                            break;
                            }
                 }
                 if (shift_held) 
                    {
                        switch(event->key.keysym.sym)
                      {
                        case 60 :
                                fp = fopen("Text_INPUT/file.txt", "a");
                                if (fp != NULL) {
                                    fputc('>', fp);
                                    fclose(fp);
                                }
                        break;
                      }
                    }
                else if (!shift_held) 
                    {
                        switch(event->key.keysym.sym)
                      {
                        case 60 :
                                fp = fopen("Text_INPUT/file.txt", "a");
                                if (fp != NULL) {
                                    fputc('<', fp);
                                    fclose(fp);
                                }
                        break;
                      }
                    }
}

void handleKeyPress(SDL_KeyboardEvent key){
    FILE *fp;
    switch (key.keysym.sym) {
        case SDLK_BACKSPACE:
           
            fp = fopen("Text_INPUT/file.txt", "r+");
            if (fp != NULL) {
                fseek(fp, 0, SEEK_END);
                long pos = ftell(fp) - 1;
                if (pos >= 0) {
                    fseek(fp, pos, SEEK_SET);
                    ftruncate(fileno(fp), pos);
                }
                
                fclose(fp);
            }
            break;
        
        case SDLK_SPACE:
            
            fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc(' ', fp);
                fclose(fp);
            }
            break;
	case SDLK_KP0:
            
            fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc('0', fp);
                fclose(fp);
            }
            break;
	case SDLK_KP1:
            
            fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc('1', fp);
                fclose(fp);
            }
            break;
	case SDLK_KP2:
            
            fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc('2', fp);
                fclose(fp);
            }
            break;
	case SDLK_KP3:
            
            fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc('3', fp);
                fclose(fp);
            }
            break;
    case SDLK_KP4:
            
            fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc('4', fp);
                fclose(fp);
            }
            break;
    case SDLK_KP5:
            
            fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc('5', fp);
                fclose(fp);
            }
            break;
    case SDLK_KP6:
            
            fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc('6', fp);
                fclose(fp);
            }
            break;
    case SDLK_KP7:
            
            fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc('7', fp);
                fclose(fp);
            }
            break;
    case SDLK_KP8:
            
            fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc('8', fp);
                fclose(fp);
            }
            break;
    case SDLK_KP9:
            
            fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc('9', fp);
                fclose(fp);
            }
            break;
    case SDLK_KP_PERIOD:
            
            fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc('.', fp);
                fclose(fp);
            }
            break;
    case SDLK_KP_DIVIDE:
            
            fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc('/', fp);
                fclose(fp);
            }
            break;
    case SDLK_KP_MULTIPLY:
            
            fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc('*', fp);
                fclose(fp);
            }
            break;
    case SDLK_KP_MINUS:
            
            fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc('-', fp);
                fclose(fp);
            }
            break;
    case SDLK_KP_PLUS:
            
            fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc('+', fp);
                fclose(fp);
            }
            break;
    case SDLK_EXCLAIM:
         fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc('!', fp);
                fclose(fp);
            }
    break;
    case 13:
            
            fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc('\n', fp);
                fclose(fp);
            }
            break;
    case 249:
         fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc('%', fp);
                fclose(fp);
            }
    break;
    case 59:
         fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc(';', fp);
                fclose(fp);
            }
    break;
    case 44:
         fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc(',', fp);
                fclose(fp);
            }
    break;
    case 58:
         fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                fputc(':', fp);
                fclose(fp);
            }
    break;


        default:
            
            fp = fopen("Text_INPUT/file.txt", "a");
            if (fp != NULL) {
                if(key.keysym.sym>=97&&key.keysym.sym<=122){
                char ch = SDL_GetKeyName(key.keysym.sym)[0];
                
                    fputc(ch, fp);
               
                fclose(fp);
                }
            }
            break;
    }
}

void renderText(SDL_Surface *screen,computer c) {
    
    TTF_Font *font = TTF_OpenFont("FONT/arial.ttf", 24);
    if (font == NULL) {
        fprintf(stderr, "Error: Failed to load font - %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    
    FILE *fp = fopen("Text_INPUT/file.txt", "a+");
    if (fp == NULL) {
        fprintf(stderr, "Error: Failed to open file\n");
        exit(EXIT_FAILURE);
    }

    char *text = NULL;
    size_t len = 0;
    ssize_t read;
    int y = c.pos_image_init.y+200;
    while ((read = getline(&text, &len, fp)) != -1) {
        
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, (SDL_Color) {255, 255, 255});

        
        int textWidth = textSurface->w;
        int textHeight = textSurface->h;

        
        SDL_Rect textLocation = {c.pos_image_init.x +50 , y, textWidth, textHeight};
        SDL_BlitSurface(textSurface, NULL, screen, &textLocation);

        
        //SDL_FreeSurface(textSurface);

        
        y += textHeight-5;
    }

 
    free(text);
    fclose(fp);
    TTF_CloseFont(font);
}
void renderText_by_url(SDL_Surface *screen,computer c,char url[]) {
    
    TTF_Font *font = TTF_OpenFont("FONT/arial.ttf", 24);
    if (font == NULL) {
        fprintf(stderr, "Error: Failed to load font - %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    
    FILE *fp = fopen(url, "a+");
    if (fp == NULL) {
        fprintf(stderr, "Error: Failed to open file\n");
        exit(EXIT_FAILURE);
    }

    char *text = NULL;
    size_t len = 0;
    ssize_t read;
    int y = c.pos_image_init.y+30;
    while ((read = getline(&text, &len, fp)) != -1) {
        
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, (SDL_Color) {255, 255, 255});

        
        int textWidth = textSurface->w;
        int textHeight = textSurface->h;

        
        SDL_Rect textLocation = {c.pos_image_init.x +250 , y, textWidth, textHeight};
        SDL_BlitSurface(textSurface, NULL, screen, &textLocation);

        
        //SDL_FreeSurface(textSurface);

        
        y += textHeight-5;
    }

 
    free(text);
    fclose(fp);
    TTF_CloseFont(font);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_files(const char *filename1, const char *filename2) {
    FILE *file1 = fopen(filename1, "r");
    FILE *file2 = fopen(filename2, "r");
    int lines1=0,lines2=0;
    char ch;

    if (file1 == NULL || file2 == NULL) {
        printf("Error: Unable to open file(s).\n");
        exit(1);
    }

    char line1[100], line2[100];
    int same_text = 1;

    while (fgets(line1, 100, file1) != NULL && fgets(line2, 100, file2) != NULL) {
        int len1 = strlen(line1);
        if (line1[len1-1] == '\n') {
            line1[len1-1] = '\0';
        }
        int len2 = strlen(line2);
        if (line2[len2-1] == '\n') {
            line2[len2-1] = '\0';
        }

        if (strcmp(line1, line2) != 0) {
            same_text = 0;
            break;
        }
    }

    if (fgets(line1, 100, file1) != NULL || fgets(line2, 100, file2) != NULL) {
        same_text = 0;
    }

    fclose(file1);
    fclose(file2);
    return same_text;
}

