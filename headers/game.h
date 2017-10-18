#ifndef GAME_H
#include "SDL.h"
#include <iostream>
#include "SDL_opengl.h"
#include "SDL_ttf.h"
#include <sstream>
#include <windows.h>
#include <mmsystem.h>
#include <shellapi.h>
#include <tchar.h>
#include <ctime>
#include <vector>
#include "math.h"
#include <fstream>
#include "view.h"
#include "container.h"
#include "sdlKeyz.h"
#include "gamedelegator.h"
#define GAME_H

void run();
void loop(View* view, container* bin);
#endif // GAME_H
