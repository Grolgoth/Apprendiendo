#ifndef SDLFUNCTIONS_H_INCLUDED
#include "SDL.h"
#include "SDL_ttf.h"
#include <iostream>
#include "stringfunctions.h"
#include <fstream>
#include <vector>
#define SDLFUNCTIONS_H_INCLUDED

SDL_Texture* createTextureFromImage(std::string img, SDL_Renderer* renderer);
SDL_Surface* load_image(std::string filename);
SDL_Surface* fontToSurface(TTF_Font* font, std::string text, SDL_Color C);
SDL_Color createColor(int r, int g, int b, int a);
SDL_Color brightColor(SDL_Color target);
int getImageDimension(std::string source, bool width);
void cleanSurfaces(std::vector<SDL_Surface*>surfaces);
#endif // SDLFUNCTIONS_H_INCLUDED
