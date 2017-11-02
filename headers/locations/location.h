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
        virtual void buttonClicked(std::string buttonName, gameDelegator* gd) = 0;
    protected:
        std::string name;
    private:
};

#endif // LOCATION_H
