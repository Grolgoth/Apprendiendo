#ifndef ALVARO_H
#include "level.h"
#define ALVARO_H


class Alvaro: public Level
{
    public:
        Alvaro(View* view, TTF_Font* font);
        ~Alvaro();
        virtual void checkEvents(View* view, event* Event, gameDelegator* gameDelegator);
        virtual void buttonClicked(View* view, event* Event, gameDelegator* gameDelegator, button* Button);
    protected:
    private:
};

#endif // ALVARO_H
