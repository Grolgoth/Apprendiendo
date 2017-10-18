#include "level.h"
#include "gamedelegator.h"

Level::Level() {
    //ctor
}

Level::~Level() {
    if (backGround != nullptr)
        SDL_FreeSurface(backGround);
     for (unsigned int i=0; i<buttons.size(); i++)
        buttons[i].clearSurfaces();
    buttons.clear();
}

void Level::show(View* view, event* Event) {
    if (backGround != nullptr)
        SDL_BlitSurface(backGround, NULL, view->getTarget(), NULL);
    Click* click = nullptr;
    std::vector<button>* buttons = getButtons();
    if (Event->eventtype == Event->CLICK)
            click = Event->getClick();
    for (unsigned int i=0; i<buttons->size(); i++) {
        SDL_Rect R = buttons->operator[](i).getRect();
        R.y += viewOffset;
        if (Event->eventtype == Event->CLICK) {
            if (buttons->operator[](i).clicked(click->getX(), click->getY())) {
                SDL_BlitSurface(buttons->operator[](i).getSurface(true), NULL, view->getTarget() ,&R);
                continue;
            }
        }
        SDL_BlitSurface(buttons->operator[](i).getSurface(false), NULL, view->getTarget() ,&R);
    }
}

std::vector<button>* Level::getButtons() {
    return &buttons;
}

button* Level::checkButtons(int x, int y){
    for (unsigned int i=0; i<buttons.size(); i++)
        if (buttons[i].clicked(x, y))
            return &(buttons[i]);
    return nullptr;
}

void Level::handleButtons(View* view, event* Event, gameDelegator* gameDelegator) {
button* Button = nullptr;
    if (Event->eventtype == Event->CLICK)
        Button = checkButtons(Event->getClick()->getX(), Event->getClick()->getY());
    if (Button != nullptr)
        buttonClicked(view, Event, gameDelegator, Button);
}

void Level::setViewOffset(int offset) {
    viewOffset = offset;
}
