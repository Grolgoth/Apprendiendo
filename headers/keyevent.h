#ifndef KEYEVENT_H
#include <iostream>
#define KEYEVENT_H


class keyEvent
{
    public:
        keyEvent(std::string key, bool down);
        ~keyEvent();
        bool getDown();
        std::string getKey();
    protected:
    private:
        bool down;
        std::string key;
};

#endif // KEYEVENT_H
