#ifndef TALKING_H_INCLUDED
#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"
#define TALKING_H_INCLUDED

SDL_Surface* talking(std::string message, unsigned int characters,
    TTF_Font* A, SDL_Color C, bool self, std::string imagepath, int WINW, int height);
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* arwclip = NULL);
int getlines(std::string message, unsigned int characters);
#endif // TALKING_H_INCLUDED
