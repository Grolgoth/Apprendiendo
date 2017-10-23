#ifndef HABLARNEW_H
#include "level.h"
#include "hablarnew_dialog.h"
#include "hablar.h"
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
    bool doGooder = false;
    bool realistic = false;
    bool democrat = false;
    bool societyRooted = false;
    bool societyModerateRooted = false;
    bool freeThinking = false;
    bool carrier = false;
    bool love = false;
    bool curious = false;
    char hobbies[14] = {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'};
    std::string genderAdress() {
        if (gender == "M")
            return "o";
        return "a";
    };
    std::string getHobbies() {
        std::string result = "";
        for (int i = 0; i<14; i++) {
            if (hobbies[i] != '#')
                result += hobbies[i];
        }
        return result;
    };
    bool toString(bool state) {
        if(state)
            return "true";
        else
            return "false";
    };
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
