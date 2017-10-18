#include "hablarmain.h"
#include "gamedelegator.h"
#include "hablarnew.h"

hablarMain::hablarMain(View* view, TTF_Font* font)
{
    buttons.push_back(button(-1, 100, view, font, "Nuevo Juego", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(-1, 250, view, font, "Cargar", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(-1, 400, view, font, "Dejar", view->getFilepath() + "img/LB.bmp"));
}

hablarMain::~hablarMain()
{

}

void hablarMain::buttonClicked(View* view, event* Event, gameDelegator* gameDelegator, button* Button) {
    if (Button->getName() == "Dejar")
        Event->eventtype = Event->QUIT;
    else if (Button->getName() == "Cargar") {
        gameDelegator->setStandard(new hablarLoad(view, gameDelegator->getFonts()[0]));
        return;
    }
    else if (Button->getName() == "Nuevo Juego") {
        gameDelegator->setStandard(new hablarNew(view, gameDelegator->getFonts()[0]));
        return;
    }
}

void hablarMain::checkEvents(View* view, event* Event, gameDelegator* gameDelegator) {
    handleButtons(view, Event, gameDelegator);
}
