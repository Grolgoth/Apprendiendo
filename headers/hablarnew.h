#ifndef HABLARNEW_H
#include "level.h"
#define HABLARNEW_H


class hablarNew: public Level
{
    public:
        hablarNew(View* view, TTF_Font* font);
        ~hablarNew();
        virtual void checkEvents(View* view, event* Event, gameDelegator* gameDelegator);
        virtual void buttonClicked(View* view, event* Event, gameDelegator* gameDelegator, button* Button);
    protected:
    private:
        std::string texts[10];
};

#endif // HABLARNEW_H
