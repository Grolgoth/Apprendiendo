#include "location.h"
#include "hablar.h"
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

View* location::getView() {
    return view;
}

int location::getStep() {
    return step;
}

void location::setStep(int state) {
    step = state;
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

bool location::getSpanish() {
    return spanish;
}
