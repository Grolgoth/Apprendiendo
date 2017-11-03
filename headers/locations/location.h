#ifndef LOCATION_H
#include <iostream>
#include "gamedelegator.h"
#define LOCATION_H

class hablar;

class location
{
    public:
        location(std::string savegame, View* view, hablar* menu, std::string Name);
        virtual ~location();
        std::string getName();
        std::vector<std::string> getLElements();
        void settings();
        void setStep(int state);
        View* getView();
        int getStep();
        bool getSpanish();
        virtual void buttonClicked(std::string buttonName, gameDelegator* gd) = 0;
        virtual void handleEvent(event* Event, gameDelegator* gd) = 0;
    protected:
        std::string write;
        std::vector<std::string> elements;
        int textEventType = 0; //0 = Rendering, 1 = writing, 2 is buttonclicking, 3 is multiplebutton clicking
        int step = 0;
        hablar* owner;
        View* view;
        bool spanish = true;
        std::string name;
        std::string gameName;
    private:
};

#endif // LOCATION_H
