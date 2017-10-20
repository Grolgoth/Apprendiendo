#ifndef BUTTON_H
#include "SDL.h"
#include "SDL_ttf.h"
#include <iostream>
#include "View.h"
#include "SDLfunctions.h"
#include "stringfunctions.h"
#include "talking.h"
#define BUTTON_H


class button
{
    public:
        button(int Xoffst, int Yoffst, View* view, TTF_Font* font, std::string text, std::string bmp, std::string textBmp = "", bool justText = false,
               int r=0, int g=0, int b=0, int a=255);
        ~button();
        button(const button& other);
        bool clicked(int mx, int my);
        void clearSurfaces();
        SDL_Surface* getSurface(bool pressed);
        SDL_Rect getRect();
        std::string getName();
    protected:
    private:
        void determineOffsets(int Xoffst, int Yoffst, View* view);
        SDL_Color color;
        TTF_Font* font;
        SDL_Surface* pressed = nullptr;
        SDL_Surface* unPressed;
        SDL_Surface* assembleSurface(std::string bmp, bool pressed, SDL_Surface* dims, View* view);
        int x;
        int y;
        int w;
        int h;
        std::string name;
};

#endif // BUTTON_H
