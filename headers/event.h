#ifndef EVENT_H
#include "click.h"
#include "keyevent.h"
#include <iostream>
#include <vector>
#define EVENT_H


class event
{
    public:
        event();
        ~event();
        enum type
        {
            CLICK,
            RCLICK,
            KEYEVENT,
            SPECIAL,
            QUIT
        };
        type eventtype;
        void setClick(int x, int y, bool left = true);
        void setKeyEvent(std::string key, bool down);
        keyEvent* getKeyEvent();
        Click* getClick();
        std::vector<std::string> getKeysDown();
    protected:
    private:
        bool keyIsInKeysDown(std::string key);
        void removeKeyFromKeysDown(std::string key);
        void checkKeySequences();
        void shiftKeySequence(std::string secondKey);
        std::vector<std::string> keysDown;
        keyEvent* keyevent;
        Click* clickobj;
};

#endif // EVENT_H
