#include "location.h"
#include "hablar.h"
#include "alvaro.h"
#include "savestructs.h"

location::location(std::string savegame, View* view, hablar* menu, std::string Name)
{
    name = Name;
    gameName = savegame;
    this->view = view;
    owner = menu;
    std::string game = getSaveGame(savegame);
    std::string loc = subString(game, indexOf(game, "<Location>") + 10, indexOf(game, "</Location>"));
    elements = getElements(savegame, loc);
    step = stringToInt(SingleElement(elements, "Step"));
}
location::~location()
{
    //dtor
}

std::vector<std::string> location::getLElements() {
    return elements;
}

std::string location::getName() {
    return name;
}

std::string location::getGameName() {
    return gameName;
}

View* location::getView() {
    return view;
}

hablar* location::getOwner() {
    return owner;
}

int location::getStep() {
    return step;
}

void location::setStep(int state) {
    step = state;
}

void location::setLElements(std::vector<std::string> target) {
    elements = target;
}

void location::settings() {
    std::ifstream in(view->getFilepath() + "settings/Settings.txt");
    std::string buffer = "";
    char c;
    while (in >> c) {
        buffer += c;
    }
    if (stringContains(buffer, "Spanish"))
        spanish = true;
    else
        spanish = false;
}

void location::hablarSwap(std::string level, gameDelegator* gd) {
    if (level == "Alvaro") {
        if (SingleElement(getElements(gameName, "Persons"), "Alvaro") == "false") {
            setElement(gameName, "Persons", "Alvaro", "true");
            addElement(gameName, "PAlvaro", "");
        }
        gd->setStandard(new Alvaro(view, gd->getFonts()[0]));
    }
}

bool location::getSpanish() {
    return spanish;
}
