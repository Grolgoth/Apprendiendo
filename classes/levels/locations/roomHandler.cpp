#include "roomHandler.h"
#include "iofunctions.h"
#include "hablar.h"

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

std::string getResult(room* Room) {
    result = replaze(result, "{g}", Room->getOwner()->getP().genderAdress(), true);
    result = replaze(result, "{name}", Room->getOwner()->getP().name, true);
    return replaze(subString(replaze(result, "${", "{", true), 0, indexOf(replaze(result, "${", "{", true), "{"))
                   , "\\n", "\n", true);
}

std::string spanish(room* Room, std::string word) {
    if (!Room->getSpanish())
        return word;
    if (word == "wall")
        return "pared";
    else if (word == "door")
        return "puerta";
    else if (stringContains(word, "That doesn't do anything"))
        return "No pasa nada.";
    else if (word == "look")
        return "mir";
    else if (word == "search")
        return "busc";
    else if (word == "investigate")
        return "investigo";
    return "";
}

std::string fromFile(room* Room, std::string key) {
    std::string file = getBinaryFile(Room->getView()->getFilepath() + "74657874/Secret/Other/public/Not concerning dogs/"
    + SingleElement(Room->getLElements(), "File") + ".2052420");
    file = subString(file, indexOf(file, key), 0);
    return replaze(subString(file, 0, indexOf(file, "\n")), key, "", false);
}

int checkAnswer(room* Room, std::string write, gameDelegator* gd, event* Event) {
    if (stringContains(write, spanish(Room, "wall")) && SingleElement(Room->getLElements(), "Wall") == "true"
    && SingleElement(Room->getLElements(), "Neighbour") == "true") {
        result = "Alvaro";
        return 4;
    }
    if (stringContains(write, spanish(Room, "door"))) {
        result = "Hallway";
        return 4;
    }
    if (stringContains(write, spanish(Room, "look")) || stringContains(write, spanish(Room, "search"))
        || stringContains(write, spanish(Room, "investigate"))) {
        if ( SingleElement(Room->getLElements(), "Unsearched") == "true") {
            setElement(Room->getGameName(), "Room", "Unsearched", "false");
            Room->setLElements(getElements(Room->getGameName(), "Room"));
            result = fromFile(Room, "{search}");
        }
        else
            result = fromFile(Room, "{search1}");
        gd->getTextRenderers()[0]->render(result, Event);
        return 0;
    }
    result = spanish(Room, "That doesn't do anything");
        gd->getTextRenderers()[0]->render(result, Event);
    return 1;
}
