#ifndef HABLARMAIN_H
#include "level.h"
#include "hablarload.h"
#define HABLARMAIN_H


class hablarMain : public Level
{
    public:
        hablarMain(View* view, TTF_Font* font);
        ~hablarMain();
        virtual void checkEvents(View* view, event* Event, gameDelegator* gameDelegator);
        virtual void buttonClicked(View* view, event* Event, gameDelegator* gameDelegator, button* Button);
    protected:
    private:
};

#endif // HABLARMAIN_H
