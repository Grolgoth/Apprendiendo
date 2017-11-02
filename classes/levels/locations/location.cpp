#include "location.h"
#include "hablar.h"

location::location(std::string savegame, View* view, hablar* menu, std::string Name)
{
    name = Name;
}
location::~location()
{
    //dtor
}

std::string location::getName() {
    return name;
}
