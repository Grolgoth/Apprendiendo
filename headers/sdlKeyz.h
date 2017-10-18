#ifndef SDLKEYZ_H_INCLUDED
#include "SDL.h"
#include <iostream>
#include <vector>
#define SDLKEYZ_H_INCLUDED

std::string whichkey(SDL_Keycode key);
bool keyCheck(std::string key, std::vector<std::string> keys);
std::string written(std::string key);
#endif // SDLKEYZ_H_INCLUDED
