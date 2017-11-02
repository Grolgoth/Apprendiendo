#include "room.h"
#include "hablar.h"

room::room(std::string savegame, View* view, hablar* menu, std::string Name):location(savegame, view, menu, Name)
{
    //ctor
}

room::~room()
{
    //dtor
}

void room::buttonClicked(std::string buttonName, gameDelegator* gd) {

}
