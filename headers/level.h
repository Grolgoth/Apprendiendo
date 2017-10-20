#ifndef LEVEL_H
#include "View.h"
#include "SDL.h"
#include "button.h"
#include <vector>
#include "SDL_ttf.h"
#include "event.h"
#include <fstream>
#include <textrenderer.h>
#define LEVEL_H

class gameDelegator;

class Level
{
    public:
        Level();
        virtual ~Level();
        void show(View* view, event* Event);
        std::vector<button>* getButtons();
        virtual void checkEvents(View* view, event* Event, gameDelegator* gameDelegator) = 0;
        virtual void buttonClicked(View* view, event* Event, gameDelegator* gameDelegator, button* Button) = 0;
        void setViewOffset(int offset);
        int getViewOffset();
    protected:
        bool scrollArrowButtonPressed(button* button);
        bool buttonsBelowScreen();
        void scrollBackground(View* view, bool withTextBox);
        void clearButtons(bool onlyScrollable = false);
        int keyrepeatdelay = 0;
        textRenderer* TextRenderer;
        void handleButtons(View* view, event* Event, gameDelegator* gameDelegator);
        int viewOffset = 0;
        button* checkButtons(int x, int y);
        std::vector<button> buttons;
        SDL_Surface* backGround = nullptr;
    private:
};

#endif // LEVEL_H
