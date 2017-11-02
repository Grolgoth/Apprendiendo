#ifndef HABLAR_H
#include <level.h>
#include "location.h"
#define HABLAR_H


class hablar : public Level
{
    public:
        hablar(View* view, TTF_Font* font, std::string gameName);
        ~hablar();
        virtual void checkEvents(View* view, event* Event, gameDelegator* gameDelegator);
        virtual void buttonClicked(View* view, event* Event, gameDelegator* gameDelegator, button* Button);
    protected:
    private:
        bool justcreated = true;
        location* Location = nullptr;
};

#endif // HABLAR_H
