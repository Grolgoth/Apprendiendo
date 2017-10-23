#include "hablar.h"

hablar::hablar(View* view, TTF_Font* font)
{
    buttons.push_back(button(-1, 100, view, font, "CHECK", view->getFilepath() + "img/LB.bmp"));
}

hablar::~hablar()
{
    //dtor
}

void hablar::checkEvents(View* view, event* Event, gameDelegator* gameDelegator) {

}

void hablar::buttonClicked(View* view, event* Event, gameDelegator* gameDelegator, button* Button) {

}
