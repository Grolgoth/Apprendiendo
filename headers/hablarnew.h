#ifndef HABLARNEW_H
#include "level.h"
#include "hablarnew_dialog.h"
#define HABLARNEW_H

struct personality{
    std::string name = "";
    std::string gender = "";

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
        void step6(View* view, gameDelegator* gd);
        void step5(button* Button);
        void step4(View* view, gameDelegator* gd);
        void checkName(std::string name);
        int step;
        personality p;
        std::string texts[10];
};

#endif // HABLARNEW_H
