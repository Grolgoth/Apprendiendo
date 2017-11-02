#include "hablar.h"
#include "gamedelegator.h"

hablar::hablar(View* view, TTF_Font* font, std::string gameName)
{
    buttons.push_back(button(10, 10, view, font, "Guardar Partida", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(290, 10, view, font, "Cargar", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(10, 160, view, font, "Vamos Hablar Con...", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(420, 160, view, font, "Vamos Para...", view->getFilepath() + "img/LB.bmp"));
    buttons.push_back(button(550, 10, view, font, "Dejar", view->getFilepath() + "img/LB.bmp"));
    backGround = SDL_CreateRGBSurface(SDL_SWSURFACE,view->WINW,view->WINH,32,0xff000000,0x00ff0000,0x0000ff00,0x000000ff);
    fromSave(gameName, &p);
    Location = locationFromSave(gameName, view, this);
}

hablar::~hablar()
{
    if (Location != nullptr)
        delete Location;
}

void hablar::checkEvents(View* view, event* Event, gameDelegator* gd) {
    handleButtons(view, Event, gd);
    if (justcreated) {
        gd->getTextRenderers()[0]->setRendered("(Ubicación: " + Location->getName() + ")\n");
        gd->getTextRenderers()[0]->writing("");
        justcreated = false;
    }
}

void hablar::buttonClicked(View* view, event* Event, gameDelegator* gameDelegator, button* Button) {
    if (Button->getName() == "Cargar") {
        gameDelegator->setStandard(new hablarLoad(view, gameDelegator->getFonts()[0]));
        return;
    }
    else if (Button->getName() == "Dejar")
        Event->eventtype = Event->QUIT;
    else {
        Location->buttonClicked(Button->getName(), gameDelegator);
    }
}
