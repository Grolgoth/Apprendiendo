#ifndef SAVESTRUCTS_H
#include <iostream>
#include <vector>
#include "iofunctions.h"
#include "View.h"
#include <ctime>
#include <stdlib.h>
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
        else if (gender == "N") {
            srand(time(nullptr));
            if (rand() % 2 == 0)
                return "o";
            else
                return "a";
        }
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

std::string SingleElement(std::vector<std::string> elements, std::string element);
std::vector<std::string> getElements(std::string savegame, std::string element);
void fromSave(std::string savegame, personality* p);
location* locationFromSave(std::string savegame, View* view, hablar* menu);
void setElement(std::string savegame, std::string name, std::string element, std::string state);
void addElement(std::string savegame, std::string name, std::string content);
#endif // SAVESTRUCTS_H
