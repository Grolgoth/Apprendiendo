#ifndef SAVESTRUCTS_H
#include <iostream>
#include <vector>
#include "iofunctions.h"
#include "View.h"
#define SAVESTRUCTS_H

class hablar;
class location;

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

void fromSave(std::string savegame, personality* p);
location* locationFromSave(std::string savegame, View* view, hablar* menu);

#endif // SAVESTRUCTS_H
