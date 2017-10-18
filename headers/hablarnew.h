#ifndef HABLARNEW_H
#include "level.h"
#define HABLARNEW_H

struct personality{
    std::string name = "";

};

class hablarNew: public Level
{
    public:
        hablarNew(View* view, TTF_Font* font);
        ~hablarNew();
        virtual void checkEvents(View* view, event* Event, gameDelegator* gameDelegator);
        virtual void buttonClicked(View* view, event* Event, gameDelegator* gameDelegator, button* Button);
    protected:
    private:
        void checkName(std::string name);
        int step;
        personality p;
        std::string texts[10];
};

#endif // HABLARNEW_H
