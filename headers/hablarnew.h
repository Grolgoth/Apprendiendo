#ifndef HABLARNEW_H
#include "level.h"
#include "hablarnew_dialog.h"
#include "hablar.h"
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
        void wrapup(View* view, gameDelegator* gd);
        void hobbies(std::string hobby);
        void traits(std::string trait);
        void personaityTraits(std::vector<std::string>traits);
        void step21(View* view, gameDelegator* gd, event* Event);
        void step19(gameDelegator* gd, button* Button, event* Event);
        void step18(View* view, gameDelegator* gd);
        void step17(View* view, gameDelegator* gd, button* Button, event* Event);
        void step16(View* view, gameDelegator* gd);
        void step15(gameDelegator* gd, button* Button, event* Event);
        void step14(View* view, gameDelegator* gd);
        void step13(gameDelegator* gd, button* Button, event* Event);
        void step12(View* view, gameDelegator* gd);
        void step11(gameDelegator* gd, button* Button, event* Event);
        void step10(View* view, gameDelegator* gd);
        void step9(gameDelegator* gd, event* Event);
        void step8(View* view, gameDelegator* gd, event* Event);
        void step7(gameDelegator* gd, event* Event);
        void step6(View* view, gameDelegator* gd, event* Event);
        void step5(button* Button);
        void step4(View* view, gameDelegator* gd);
        void step2(event* Event, gameDelegator* gd);
        void checkName(std::string name);
        int step;
        personality p;
        std::string getP();
};

#endif // HABLARNEW_H
