#ifndef KEYEVENT_H
#include <iostream>
#define KEYEVENT_H


class keyEvent
{
    public:
        keyEvent(std::string key, bool down);
        ~keyEvent();
        bool getDown();
        bool getRepeat();
        std::string getKey();
        void setRepeat(bool state);
    protected:
    private:
        bool repeat;
        bool down;
        std::string key;
};

#endif // KEYEVENT_H
