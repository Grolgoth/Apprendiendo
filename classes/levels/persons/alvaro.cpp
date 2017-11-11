#include "alvaro.h"

Alvaro::Alvaro(View* view, TTF_Font* font)
{

}

Alvaro::~Alvaro()
{
    //dtor
}

void Alvaro::buttonClicked(View* view, event* Event, gameDelegator* gameDelegator, button* Button) {
    Event->eventtype = Event->SPECIAL;
    if (Button->getName() == "Dejar")
        Event->eventtype = Event->QUIT;
}

void Alvaro::checkEvents(View* view, event* Event, gameDelegator* gameDelegator) {
    handleButtons(view, Event, gameDelegator);
}
