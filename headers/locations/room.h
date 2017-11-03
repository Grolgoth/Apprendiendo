#ifndef ROOM_H
#include "location.h"
#define ROOM_H


class room : public location
{
    public:
        room(std::string savegame, View* view, hablar* menu, std::string Name);
        ~room();
        virtual void buttonClicked(std::string buttonName, gameDelegator* gd);
        virtual void handleEvent(event* Event, gameDelegator* gd);
    protected:
    private:
};

#endif // ROOM_H
