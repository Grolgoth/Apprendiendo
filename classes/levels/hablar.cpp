#include "hablar.h"

hablar::hablar(View* view, TTF_Font* font)
{
    buttons.push_back(button(10, 100, view, font, "Guardar Partida", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(420, 100, view, font, "Cargar", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(-1, 300, view, font, "Hablar con...", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(420, 300, view, font, "Vamos para...", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(-1, 450, view, font, "Dejar", view->getFilepath() + "img/LB.bmp"));
}

hablar::~hablar()
{
    //dtor
}

void hablar::checkEvents(View* view, event* Event, gameDelegator* gameDelegator) {

}

void hablar::buttonClicked(View* view, event* Event, gameDelegator* gameDelegator, button* Button) {

}
