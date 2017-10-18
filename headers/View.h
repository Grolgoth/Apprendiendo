#ifndef VIEW_H
#include "SDL.h"
#include "SDL_ttf.h"
#include <iostream>
#include <windows.h>
#define VIEW_H


class View
{
    public:
        View();
        ~View();
        View(const View& other);
        bool hale;
        SDL_Window* getWindow();
        SDL_Renderer* getRenderer();
        SDL_Event* getEvent();
        std::string getFilepath();
        void setFilepath();
        SDL_Surface* getTarget();
        void render();
        const int WINH = 600;
        const int WINW = 800;
    protected:
    private:
        std::string filepath;
        bool init();
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event event;
        SDL_Surface* target;
};

#endif // VIEW_H
