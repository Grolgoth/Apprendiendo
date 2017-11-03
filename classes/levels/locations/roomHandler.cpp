#include "roomHandler.h"
#include "iofunctions.h"

std::string result = "";

void nextStep(room* Room) {
    if (!stringContains(result, "${"))
        Room->setStep(Room->getStep() + 1);
}

int ienterPressed(room* Room) {
    result = "";
    std::string file = getBinaryFile(Room->getView()->getFilepath() + "74657874/Secret/Other/public/Not concerning dogs/"
    + SingleElement(Room->getLElements(), "File") + ".2052420");
    int cnt = 0;
    int b = 0;
    for (unsigned int i=0; i<file.length(); i++) {
        if (file[i] == '\n') {
            cnt++;
            i ++;
            if (cnt - 1 == Room->getStep()) {
                result = subString(file, b, i - 1);
                break;
            }
            b = i;
        }
    }
    nextStep(Room);
    if (stringContains(result, "{write}"))
        return 1;
    else if (stringContains(result, "{buttonclick}"))
        return 2;
    else if (stringContains(result, "{multiplebuttonclick}"))
        return 3;
    else
        return 0;
}

std::string getResult() {
    return replaze(subString(replaze(result, "${", "{", true), 0, indexOf(replaze(result, "${", "{", true), "{"))
                   , "\\n", "\n", true);
}

std::string spanish(room* Room, std::string word) {
    if(word == "wall"){
        if(Room->getSpanish())
            return "pared";
        return word;
    }
    else if (stringContains(word, "That doesn't do anything")) {
        if (Room->getSpanish())
            return "No pasa nada.${write}";
        return word;
    }
    return "";
}

int checkAnswer(room* Room, std::string write, gameDelegator* gd, event* Event) {
    if (stringContains(write, spanish(Room, "wall")) && SingleElement(Room->getLElements(), "Wall") == "true"
    && SingleElement(Room->getLElements(), "Neighbour") == "true") {
        result = "Alvaro";
        return 4;
    }
    result = spanish(Room, "That doesn't do anything");
        gd->getTextRenderers()[0]->render(getResult(), Event);
    return 1;
}
