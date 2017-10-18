#ifndef TEXTRENDERER_H
#include "SDL.h"
#include "SDL_ttf.h"
#include <iostream>
#include "talking.h"
#include "View.h"
#include "SDLfunctions.h"
#define TEXTRENDERER_H


class textRenderer
{
    public:
        textRenderer(View* view, TTF_Font* Font);
        virtual ~textRenderer();
        bool getRendering();
        bool getNext();
        void render(std::string text);
        void renderstep(bool all);
        void refreshCurrent();
        SDL_Surface* getCurrent();
    protected:
        int delay = 22;
        SDL_Surface* backGround;
        SDL_Surface* current = nullptr;
        SDL_Color color;
        TTF_Font* font;
        std::string toRender;
        std::string rendered;
        bool rendering = false;
        bool next = true;
        int WINW;
        int WINH;
    private:
};

#endif // TEXTRENDERER_H
