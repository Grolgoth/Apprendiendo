#ifndef HABLARNEW_H
#include "level.h"
#include "hablarnew_dialog.h"
#define HABLARNEW_H

struct personality{
    std::string name = "";
    std::string gender = "";
    bool funny = false;
    bool noMorning = false;
    bool arrogant = false;
    bool content = false;
    bool nice = false;
    bool shy = false;
    bool patient = false;
    bool aggressive = false;
    bool intelligent = false;
    bool optimistic = false;
    bool sportive = false;
    bool asshole = false;
    bool brave = false;
    bool loyal = false;
    bool chaotic = false;
    bool stubborn = false;
    bool talksalot = false;
    bool humble = false;
    char hobbies[14] = {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'};
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
        void hobbies(std::string hobby);
        void traits(std::string trait);
        void personaityTraits(std::vector<std::string>traits);
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
        std::string texts[10];
};

#endif // HABLARNEW_H
