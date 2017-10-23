#ifndef HABLAR_H
#include <level.h>
#define HABLAR_H


class hablar : public Level
{
    public:
        hablar(View* view, TTF_Font* font);
        ~hablar();
        virtual void checkEvents(View* view, event* Event, gameDelegator* gameDelegator);
        virtual void buttonClicked(View* view, event* Event, gameDelegator* gameDelegator, button* Button);
    protected:
    private:
};

#endif // HABLAR_H
