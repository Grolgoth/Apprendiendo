#ifndef TEXTRENDERER_H
#include "SDL.h"
#include "SDL_ttf.h"
#include <iostream>
#include "talking.h"
#include "View.h"
#include "SDLfunctions.h"
#include "event.h"
#define TEXTRENDERER_H


class textRenderer
{
    public:
        textRenderer(View* view, TTF_Font* Font);
        virtual ~textRenderer();
        bool getRendering();
        bool getNext();
        void setNext(bool state);
        void render(std::string text, event* Event);
        void renderstep(bool all);
        void refreshCurrent();
        void writing(std::string text);
        void setRendered(std::string state);
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
